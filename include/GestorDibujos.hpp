#pragma once
#include <algorithm>
#include <vector>
#include "Dibujo.hpp"
#include <ftxui/screen/screen.hpp>

// Clase para gestionar los dibujos en la pantalla: moverlos, agregarlos
class GestorDibujos
{
public:
    std::vector<Dibujo> dibujos; // vector para almacenar los dibujos que se van a mostrar en la pantalla

    void Agregar(const Dibujo &dibujo)
    {
        dibujos.emplace_back(dibujo);
    }
    void AgregarDibujo(const Dibujo &dibujo)
    {
        Agregar(dibujo);
    }
    size_t Size() const noexcept
    {
        return dibujos.size();
    }
    const Dibujo *ObtenerDibujo(size_t idx) const
    {
        if (idx < dibujos.size())
            return &dibujos[idx];
        return nullptr;
    }
    bool SetPositionClamped(size_t idx, int x, int y, int max_x, int max_y)
    {
        if (idx >= dibujos.size())
            return false;
        int nx = std::clamp(x, 0, max_x);
        int ny = std::clamp(y, 0, max_y);
        dibujos[idx].x = nx;
        dibujos[idx].y = ny;
        return true;
    }
    void Mover(size_t idx, int dx, int dy)
    {
        if (idx < dibujos.size())
        {
            dibujos[idx].x += dx;
            dibujos[idx].y += dy;
        }
    }
    void MoverClamped(size_t idx, int dx, int dy, int max_x, int max_y)
    {
        if (idx < dibujos.size())
        {
            int nx = std::clamp(dibujos[idx].x + dx, 0, max_x);
            int ny = std::clamp(dibujos[idx].y + dy, 0, max_y);
            dibujos[idx].x = nx;
            dibujos[idx].y = ny;
        }
    }

    void DibujarTodos(ftxui::Screen &screen) const
    {
        for (const auto &dibujo : dibujos)
        {
            dibujo.Dibujar(screen);
        }
    }
};
