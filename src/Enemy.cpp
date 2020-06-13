#include "Enemy.h"


Enemy::Enemy()
{
    x = 1;
    y = 2;
    lastX = x;
    lastY = y;
    TurnMove = false;
}

void Enemy::Move(int MoveType, bool IsBlocked) // MoveType: 1= - , 2 = |, 3 = \, 4 = / .
{
    lastX = x;
    lastY = y;
    switch(MoveType)
    {
    case 1:
        if(!TurnMove)
        {
            if (!IsBlocked)
            {
                x = (x + 1)%60;
            }else{
                TurnMove = !TurnMove;
                // Al momento de cambiar de sentido se debe invertir los posiciones
                lastX = x - 2;
                x = ((x - 1)%60+60)%60;
            }
        }
        else
        {
            if(!IsBlocked)
            {
                x = ((x - 1)%60+60)%60;
            }else{
                TurnMove = !TurnMove;
                lastX = x + 2;
                x = (x + 1)%60;
            }
        }
        break;
    case 2:
        if(!TurnMove)
        {
            if (!IsBlocked)
            {
                y = (y + 1)%20;
            }else{
                TurnMove = !TurnMove;
                lastY = y - 2;
                y = ((y - 1)%20+20)%20;
            }
        }
        else
        {
            if(!IsBlocked)
            {
                y = ((y - 1)%20+20)%20;
            }else{
                TurnMove = !TurnMove;
                lastY = y + 2;
                y = (y + 1)%20;
            }
        }
        break;

    case 3:
        if(!TurnMove)
        {
            if (!IsBlocked)
            {
                x = (x + 1)%60;
                y = (y + 1)%20;
            }else{
                TurnMove = !TurnMove;
                lastX = x - 2;
                lastY = y - 2;
                x = ((x - 1)%60+60)%60;
                y = ((y - 1)%20+20)%20;
            }
        }
        else
        {
            if(!IsBlocked)
            {
                x = ((x - 1)%60+60)%60;
                y = ((y - 1)%20+20)%20;
            }else{
                TurnMove = !TurnMove;
                lastX = x + 2;
                lastY = y + 2;
                x = (x + 1)%60;
                y = (y + 1)%20;
            }
        }
        break;

    case 4:
        if(!TurnMove)
        {
            if (!IsBlocked)
            {
                x = (x + 1)%60;
                y = ((y - 1)%20+20)%20;
            }else{
                TurnMove = !TurnMove;
                lastX = x -2;
                lastY = y + 2;
                x = ((x - 1)%60+60)%60;
                y = (y + 1)%20;
            }
        }
        else
        {
            if(!IsBlocked)
            {
                x = ((x - 1)%60+60)%60;
                y = (y + 1)%20;
            }else{
                TurnMove = !TurnMove;
                lastX = x + 2;
                lastY = y - 2;
                x = (x + 1)%60;
                y = ((y - 1)%20+20)%20;
            }
        }
        break;
    }
}
