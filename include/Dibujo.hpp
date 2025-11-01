Clase para dibujar figuras ASCII en la pantalla usando FTXUI
#pragma once

#include <vector>//permite usar vectores en el programa
#include <string>//permite guardar cadenas de texto
#include <ftxui/screen/screen.hpp>//permite crear una pantalla en la consola

class Dibujo {
public:
    int x, y;//posicion en x y
    std::vector<std::u32string> figura;//permite almacenar grandes cadenas de caracteres
    ftxui::Color color;//permite definir el color del dibujo

    Dibujo(int x, int y, const std::vector<std::u32string>& figura, ftxui::Color color = ftxui::Color::White)//usa las caracteristicas de otro archivo para dibujarlo el la pantala
        : x(x), y(y), figura(figura), color(color) {}//valores que se usaran en la funcion

    void Dibujar(ftxui::Screen& screen) const {//desarrollo de la funcion para crear una pantalla en la consola
        for (size_t row = 0; row < figura.size(); ++row) {//ciclo para recorrer las filas
            for (size_t col = 0; col < figura[row].size(); ++col) {//ciclo para recorrer las columnas 
                int px = x + col;//dibuja el simbolo que se ubica en ese punto y lo recorre un espacio
                int py = y + row;//dibuja el simbolo que se ubica en ese punto y lo recorre un espacio
                if (px < screen.dimx() && py < screen.dimy() && figura[row][col] != U' ') {//asigna los vectores del tamaño del dibujo en la pantalla
                    auto& pixel = screen.PixelAt(px, py);//permite el desplazamiento del dibujo
                    pixel.character = figura[row][col];//permite leer los caracteres que se imprimiran en la pantalla
                    pixel.bold = true;//detecta el pixel y lo remarca como si fuera negrita para asignarle un color
                    pixel.foreground_color = color;//cambia el color del pixel por el color asignado
                }
            }
        }
    }
};
