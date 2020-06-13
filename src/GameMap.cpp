#include "GameMap.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

GameMap::GameMap()
{
    PlayerCell = NULL;
    EnemyCell = NULL;
    level = 1;
    LoadMapFromFile(level);
    isGameOver = false;
}

int GameMap::GetLevel()
{
    return level;
}

void GameMap::Draw()
{
    system("cls");
    cout << endl << "Inicia el Juego" << endl << endl;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            cout << cells[i][j].id;
        }
    cout << endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    //Beep(1000, 300);
    if(!cells[PlayerY][PlayerX].IsBlocked())
    {
        if(cells[PlayerY][PlayerX].id == '$')
        {
            level++;
            if(level < 4)
            {
                LoadMapFromFile(level);
            }else{
                DrawVictory();
                isGameOver = true;
            }
        }
        else if(cells[PlayerY][PlayerX].id == 2)
        {
            system("color 0F");
            system("color F0");
            system("color 0F");
            Beep(750, 300);

            DrawGameOver();
            isGameOver = true;
        }else{
            if(PlayerCell != NULL)
            {
                PlayerCell->id = 0;
            }
            PlayerCell = &cells[PlayerY][PlayerX];
            PlayerCell->id = 1;
            //cout << "Las del jugador estan en: " << PlayerX << ", " << PlayerY;
        }
        return true;

    }else{
        return false;
    }
}

bool GameMap::SetEnemyCell(int EnemyX, int EnemyY, int lastX, int lastY)
{
    if(!cells[EnemyY][EnemyX].IsBlocked())
    {
        if(cells[EnemyY][EnemyX].id == 1)
        {
            system("color 0F");
            system("color F0");
            system("color 0F");
            Beep(750, 300);

            DrawGameOver();
            isGameOver = true;
        }
        EnemyCell = &cells[lastY][lastX];
        EnemyCell->id = 0;
        EnemyCell = &cells[EnemyY][EnemyX];
        EnemyCell->id = 2;
        return false;
    }else{
        EnemyCell = &cells[lastY][lastX];
        EnemyCell->id = 2;
        EnemyCell = &cells[EnemyY][EnemyX];
        EnemyCell->id = 176;
        return true;
    }
}

void GameMap::DrawIntro()
{
    string line;
    ifstream MyFile("Intro.txt");

    if(MyFile.is_open())
    {
        //cout << "Inicio prueba de dibujado" << endl;
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }
        musicaJuego();
        getch();
    }
    else{
        cout << "No pude cargar el intro" << endl;
    }
}

void GameMap::DrawVictory()
{
    string line;
    ifstream MyFile("Victory.txt");

    if(MyFile.is_open())
    {
        //cout << "Inicio prueba de dibujado" << endl;
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }
        musicaJuego();
        getch();
    }
    else{
        cout << "No pude cargar el victory :C" << endl;
    }
}

void GameMap::DrawGameOver()
{
    string line;
    ifstream MyFile("GameOver.txt");

    if(MyFile.is_open())
    {
        //cout << "Inicio prueba de dibujado" << endl;
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }
        getch();
    }
    else{
        cout << "No pude cargar el GameOver :C" << endl;
    }
}

void GameMap::LoadMapFromFile(int level)
{
    string line;
    string levelGame = "MapUno.txt";
    int i = 0;

    if(level == 1)
    {
        levelGame = "MapUno.txt";
    }

    else if(level == 2)
    {
        levelGame = "MapDos.txt";
    }

    else if(level == 3)
    {
        levelGame = "MapTres.txt";
    }

    else
    {
        levelGame = "Map.txt";
    }

    ifstream MyFile(levelGame.c_str());

    if(MyFile.is_open())
    {
        //cout << "Inicio prueba de dibujado" << endl;
        while(getline(MyFile, line))
        {

            for(int j = 0; j < 60; j++)
            {
                if(line[j] == 'E')
                {
                    cells[i][j].id = 2;
                }
                else if(line[j] == '.')
                {
                    cells[i][j].id = 0;
                }else if(line[j] == '*')
                {
                    cells[i][j].id = 176;
                }else{
                    cells[i][j].id = line[j];
                }
            }
            i++;
        }
        //cout << "Final prueba de dibujado" << endl;
    }
    else{
        cout << "FATAL ERROR: Archivo de mapa no se pudo cargar" << endl;
    }
}

void GameMap::musicaJuego()
{
	unsigned char i;
	unsigned int notas[8]={294,247,330,330,330,220,392};
	unsigned int tiempo[8]={294,247,330,330,330,220,392};

	for(i = 0; i < 8; i++)
	{
		Beep (notas[i],tiempo[i]);
	}
}
