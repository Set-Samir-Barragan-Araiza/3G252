#pragma once
#include <vector>
#include <string>
#include <ftxui/screen/screen.hpp>

// Clase para dibujar figuras ASCII en la pantalla usando FTXUI
class Dibujo {
public:
    int x, y; // posición en x y
    std::vector<std::u32string> figura; // almacena las líneas del dibujo (UTF-32)
    ftxui::Color color; // color del dibujo

Dibujo(int x, int y, const std::vector<std::u32string>& figura, ftxui::Color color = ftxui::Color::White)
: x(x), y(y), figura(figura), color(color) {}

void Dibujar(ftxui::Screen& screen) const {
    for (size_t row = 0; row < figura.size(); ++row) {
        for (size_t col = 0; col < figura[row].size(); ++col) {
            int px = x + static_cast<int>(col);
            int py = y + static_cast<int>(row);
            if (px < screen.dimx() && py < screen.dimy() && figura[row][col] != U' ') {
                auto& pixel = screen.PixelAt(px, py);
                pixel.character = figura[row][col];
                pixel.bold = true;
                pixel.foreground_color = color;
                }
            }
        }
    }
};
