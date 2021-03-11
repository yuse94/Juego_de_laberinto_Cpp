#include <iostream>
#include "../include/Player.h"

using namespace std;

Player::Player()
{
    x = 1;
    y = 1;
}

void Player::CallInput()
{
    char UserInput = ' ';
    cin >> UserInput;

    lastY=y;
    lastX=x;

    UserInput = tolower(UserInput);
    switch(UserInput)
    {
    case 'w':
        y = ((y - 1)%20+20)%20;
        //cout << "El jugador se mueve arriba" << endl;
        break;
    case 's':
        y = (y + 1)%20;
        //cout << "El jugador se mueve abajo" << endl;
        break;
    case 'd':
        x = (x + 1)%60;
        //cout << "El jugador se mueve derecha" << endl;
        break;
    case 'a':
        x = ((x - 1)%60+60)%60;
        //cout << "El jugador se mueve izquierda" << endl;
        break;
    }

    //cout << "mi jugador esta en x: " << x << ", y: " << y << endl;
}

void Player::ResetToSafePosition()
{
    x = lastX;
    y = lastY;
}
