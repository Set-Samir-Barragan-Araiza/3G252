#pragma once
#include <vector>
#include <string>
#include "Dibujo.hpp"
#include <algorithm>

class Piso{
public:
int x,y,ancho,largo;//posicion en x y, ancho y alto del piso
Dibujo dibujo_Piso;//objeto dibujo para el piso
std::vector<Dibujo> Objeto;//vector para almacenar las coordenadas

Piso(int x_,int y_,int ancho_,int largo_, ftxui::Color color=ftxui::Color::Green)//constructor de la clase  piso
    :x(x_),y(y_),ancho(ancho_),largo(largo_),//inicializa las variables de la clase 
    dibujo_Piso(x_,y_,GenerarPiso(ancho_,largo_),color){}//inicializa el objeto dibujo del piso con su posicion, figura y color

static std::vector<std::u32string> GenerarPiso(int ancho,int largo){//funcion para generar la figura del piso
        std::vector<std::u32string> figura;
        if (ancho < 1) ancho = 1;
        if (largo < 1) largo = 1;

        std::u32string empty_row(ancho, U' ');
        const std::u32string tile= U"~";
        std::u32string floor_row;
        floor_row.reserve(ancho);
        while (floor_row.size()< static_cast<size_t>(ancho)) {
            floor_row += tile;
        }

        floor_row.resize(ancho);
        for (int i=0;i<largo-1;++i)
        {
            figura.push_back(empty_row);
        }
        figura.push_back(floor_row);
        return figura;
    }

void AgregarObjetos(const Dibujo& obj){
    int ax = std::clamp(obj.x, x, x + ancho - 1);
    int ay = std::clamp(obj.y, y, y + largo - 1);
    Objeto.emplace_back(ax, ay, obj.figura, obj.color);
}

void Dibujar(ftxui::Screen& screen) const{
    dibujo_Piso.Dibujar(screen);
    for(const auto& o : Objeto){
        o.Dibujar(screen);
    }
} 
};