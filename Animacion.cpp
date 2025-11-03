#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <algorithm>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"
#include "Piso.hpp"
using namespace ftxui;
using namespace std;

int main() {

    auto screen = Screen::Create(
        Dimension::Fixed(120),
        Dimension::Fixed(100)
    );

    const std::vector<std::u32string> Astronauta_Figura =
    { 
UR"(         _..._           )",  
UR"(       .'     '.      _  )",
UR"(      /    .-""-\\   _/  )",
UR"(    .-|   /:.   |  |   | )",
UR"(    |  \\  |:.   /.-'-./  )",
UR"(    | .-'-;:__.'    =/   )",
UR"(    .'=  *=|NASA _.='    )",
UR"(   /   _.  |    ;        )",
UR"(  ;-.-'|    \\   |        )",
UR"( /   | \\    _\\  _\\       )",
UR"( \\__/'._;.  ==' ==\\      )",
UR"(          \\    \\   |     )",
UR"(          /    /   /     )",
UR"(          /-._/-._/      )",
UR"(          \\   `\\  \\      )",
UR"(           `-._/._/      )"};
    const std::vector<std::u32string> Star_Figura =
{
UR"(       ,    )",
UR"(    __/ \__ )",
UR"(    \     / )",
UR"(    /_   _\ )",
UR"(      \ /   )",
UR"(       '    )"};

GestorDibujos gestor;
gestor.Agregar(Dibujo(10,5,Astronauta_Figura,Color::Green));
gestor.Agregar(Dibujo(50,50,Star_Figura,Color::Yellow));
gestor.Agregar(Dibujo(70,70,Star_Figura,Color::White));
gestor.Agregar(Dibujo(90,40,Star_Figura,Color::Yellow));
gestor.Agregar(Dibujo(30,35,Star_Figura,Color::Magenta));
gestor.Agregar(Dibujo(20,45,Star_Figura,Color::Yellow));
gestor.Agregar(Dibujo(80,20,Star_Figura,Color::Blue));
gestor.Agregar(Dibujo(60,60,Star_Figura,Color::Red));

Piso piso(0, 30,120,10, Color::White);

int frames = 60;
for (int frame=0; frame < frames; frame++)
{
    screen.Clear();

    //movimiento de los dibujos
    if(gestor.dibujos.size()>=8){
        int max_x = static_cast<int>(screen.dimx())-1;
        auto safe_x = [&](int v){return std::clamp(v, 0, max_x); };

    gestor.dibujos[0].x = 4 + (frame % 10);
    gestor.dibujos[1].x = 7 + (frame %20);
    gestor.dibujos[2].x = 5 + (frame %15);
    gestor.dibujos[3].x = 3 + (frame %25);
    gestor.dibujos[4].x = 6 + (frame %10);
    gestor.dibujos[5].x = 8 + (frame %20);
    gestor.dibujos[6].x = 3 + (frame %15);
    gestor.dibujos[7].x = 5 + (frame %30);
    }

    piso.Dibujar(screen);
    gestor.DibujarTodos(screen);

    std::cout << screen.ToString();
    std::cout << "\033[H";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
}
    return 0;
}
