#include <iostream>
using namespace std;
//ctrl+k+f
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;
main()
{
    auto pantalla = screen::Create(
        Dimension::Full(0),
        Dimension::Fixed(10)
    );

    int x = 0;
    int y = 0;
    auto pixel = pantalla.pixelAt(1,1);
    pixel.blink = true;
    pixel.background_color = color::Blue;
    pixel.background_color = color::Red;
    pixel.character = 'A';

    Render(pantalla);
    pantalla.print();
    cout<<endl;
}    