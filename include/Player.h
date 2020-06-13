#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();

        void CallInput();
        void ResetToSafePosition();

        int x, y; // Deberian ir en protected
        //En este caso por ser una prueba lo dejaremos aca
        int lastX, lastY;
    protected:


    private:
};

#endif // PLAYER_H
