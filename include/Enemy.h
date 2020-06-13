#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

class Enemy
{
    public:
        Enemy();
        void Move(int MoveType, bool IsBlocked); // MoveType: 1= | , 2 = -, 3 = /, 4 = \ .
        int x, y;
        int lastX, lastY;
        bool TurnMove;

    protected:

    private:
};

#endif // ENEMY_H
