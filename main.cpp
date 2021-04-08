#include <iostream>
#include "include/Enemy.h"
#include "include/Enemy.h"
#include "include/MapCell.h"
#include "include/GameMap.h"
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
    system("color F0");     //Color de la ventana
    system("MODE 80, 35");  // Tamanio de la pantalla MODE <columnas>,<líneas>

    GameMap Map;
    Player Hero;
    Enemy EnemyUno;
    Enemy EnemyDos;
    Enemy EnemyTres;
    Enemy EnemyCuatro;
    Enemy EnemyCinco;
    Map.DrawIntro();

    ///////////// LEVEL 1 //////////////
    EnemyUno.x=31;
    EnemyUno.y=7  ;

    EnemyDos.x=31;
    EnemyDos.y=11;

    EnemyTres.x=31;
    EnemyTres.y=16;

    Map.SetPlayerCell(Hero.x, Hero.y);
    Map.Draw();

    // Aqui es el loop del juego
    while(Map.GetLevel()==1)
    {
        cout << endl << "Ingresa el movimeinto: ";
        Hero.CallInput();

        if(Map.isGameOver)
        {
            break;
        }
        //Actualizar la informacion de Hero a Mapa
        if(Map.SetPlayerCell(Hero.x, Hero.y))
        {
            if(!Map.isGameOver)
            {
                // Aqui dibujamos el mapa
                Map.Draw();
            }
        }
        else
        {
            Hero.ResetToSafePosition();
            Map.Draw();
        }

        EnemyUno.Move(2,Map.SetEnemyCell(EnemyUno.x, EnemyUno.y, EnemyUno.lastX, EnemyUno.lastY));
        EnemyDos.Move(2,Map.SetEnemyCell(EnemyDos.x, EnemyDos.y, EnemyDos.lastX, EnemyDos.lastY));
        EnemyTres.Move(2,Map.SetEnemyCell(EnemyTres.x, EnemyTres.y, EnemyTres.lastX, EnemyTres.lastY));

        if(Map.isGameOver)
        {
            break;
        }
    }

    /////Level 2
    if(!Map.isGameOver)
    {
        cout << endl << "Presiona euna tecla para el siguiete nivel... ";
        getch();

        Hero.x = 1;
        Hero.y = 1;

        EnemyUno.x=31;
        EnemyUno.y=8  ;

        EnemyDos.x=32;
        EnemyDos.y=8;

        EnemyTres.x=31;
        EnemyTres.y=11;

        EnemyCuatro.x=32;
        EnemyCuatro.y=11;

        Map.SetPlayerCell(Hero.x, Hero.y);
        Map.Draw();
    }

    while(Map.GetLevel()==2)
    {
        cout << endl << "Ingresa el movimeinto: ";
        Hero.CallInput();

        if(Map.isGameOver)
        {
            break;
        }
        //Actualizar la informacion de Hero a Mapa
        if(Map.SetPlayerCell(Hero.x, Hero.y))
        {
            if(!Map.isGameOver)
            {
                // Aqui dibujamos el mapa
                Map.Draw();
            }
        }
        else
        {
            Hero.ResetToSafePosition();
            Map.Draw();
        }

        EnemyUno.Move(3,Map.SetEnemyCell(EnemyUno.x, EnemyUno.y, EnemyUno.lastX, EnemyUno.lastY));
        EnemyDos.Move(4,Map.SetEnemyCell(EnemyDos.x, EnemyDos.y, EnemyDos.lastX, EnemyDos.lastY));
        EnemyTres.Move(4,Map.SetEnemyCell(EnemyTres.x, EnemyTres.y, EnemyTres.lastX, EnemyTres.lastY));
        EnemyCuatro.Move(3,Map.SetEnemyCell(EnemyCuatro.x, EnemyCuatro.y, EnemyCuatro.lastX, EnemyCuatro.lastY));

        if(Map.isGameOver)
        {
            break;
        }
    }

    /////Level 3

    if(!Map.isGameOver)
    {
        cout << endl << "Presiona euna tecla para el siguiete nivel... ";
        getch();

        Hero.x = 1;
        Hero.y = 1;

        EnemyUno.x=36;
        EnemyUno.y=8  ;

        EnemyDos.x=37;
        EnemyDos.y=6;

        EnemyTres.x=31;
        EnemyTres.y=11;

        EnemyCuatro.x=32;
        EnemyCuatro.y=11;

        EnemyCinco.x=24;
        EnemyCinco.y=1;

        Map.SetPlayerCell(Hero.x, Hero.y);
        Map.Draw();
    }

    while(Map.GetLevel()==3)
    {
        cout << endl << "Ingresa el movimeinto: ";
        Hero.CallInput();

        if(Map.isGameOver)
        {
            break;
        }
        //Actualizar la informacion de Hero a Mapa
        if(Map.SetPlayerCell(Hero.x, Hero.y))
        {
            if(!Map.isGameOver)
            {
                // Aqui dibujamos el mapa
                Map.Draw();
            }
        }
        else
        {
            Hero.ResetToSafePosition();
            Map.Draw();
        }

        EnemyUno.Move(1,Map.SetEnemyCell(EnemyUno.x, EnemyUno.y, EnemyUno.lastX, EnemyUno.lastY));
        EnemyDos.Move(1,Map.SetEnemyCell(EnemyDos.x, EnemyDos.y, EnemyDos.lastX, EnemyDos.lastY));
        EnemyTres.Move(4,Map.SetEnemyCell(EnemyTres.x, EnemyTres.y, EnemyTres.lastX, EnemyTres.lastY));
        EnemyCuatro.Move(3,Map.SetEnemyCell(EnemyCuatro.x, EnemyCuatro.y, EnemyCuatro.lastX, EnemyCuatro.lastY));
        EnemyCinco.Move(2,Map.SetEnemyCell(EnemyCinco.x, EnemyCinco.y, EnemyCinco.lastX, EnemyCinco.lastY));

        if(Map.isGameOver)
        {
            break;
        }
    }
    return 0;
}
