#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"
#include <iostream>

class GameMap
{
    public:
        GameMap();

        MapCell* PlayerCell;
        MapCell* EnemyCell;
        MapCell cells[20][60];

        void DrawIntro();
        void DrawVictory();
        void DrawGameOver();
        void Draw();

        //Obtiene las coordenadas de Palayer y actualiza el mapa
        bool SetPlayerCell(int PlayerX, int PlayerY);
        bool SetEnemyCell(int EnemyX, int EnemyY, int lastX, int lastY);

        bool isGameOver;

        int GetLevel();

    protected:
        //Protegida porq solo la va usar mapa
        void LoadMapFromFile(int level);
        void musicaJuego();
        int level;

    private:
};

#endif // GAMEMAP_H
