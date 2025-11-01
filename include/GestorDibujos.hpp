#pragma once//indica que este archivo solo se incluirá una vez durante la compilación para evitar errores de redefinición
#include <vector>//incluye la biblioteca vector para usar vetores en el programa
#include "Dibujo.hpp"//incluye la clase dibujo para guardar cadenas de texto y dibujar figuras en la pantalla
#include <ftxui/screen/screen.hpp>//incluye la biblioteca ftxui para crear una pantalla en la consola

class GestorDibujos {//clase para gestionar los dibujos en la pantalla: moverlos, agregarlos 
public:
    std::vector<Dibujo> dibujos;//vector para almacenar los dibujos que se van a mostrar en la pantalla

    void Agregar(const Dibujo& dibujo) {//funcion para agregar un dibujo al vector de dibujos
        dibujos.push_back(dibujo);//permite el desplazamiento del dibujo en la pantalla
    }

    void Mover(size_t idx, int dx, int dy) {//funcion para desplazar un dibujo en la pantalla
        if (idx < dibujos.size()) {//verifica que el indice del dibujo a mover sea valido
            dibujos[idx].x += dx;//desplaza el dibujo en el eje x sumando el valor de dx al valor actual de x del dibujo
            dibujos[idx].y += dy;//desplaza el dibujo en el eje y sumando el valor de dy al valor actual de y del dibujo
        }
    }

    void DibujarTodos(ftxui::Screen& screen) const {//funcion para dibujar todos los dibujos almacenados 
        for (const auto& dibujo : dibujos) {//ciclo para recorrer cada dibujo almacenado en el vector de dibujos
            dibujo.Dibujar(screen);//llama a la funcion Dibujar de cada dibujo para mostrarlo en la pantalla usando el objeto screen
        }
    }
};