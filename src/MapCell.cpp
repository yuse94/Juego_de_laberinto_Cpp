#include "MapCell.h"
#include "Enemy.h"

MapCell::MapCell()
{
    id = 0;
}

bool MapCell::IsBlocked()
{
    if(id == 176)
    {
        return true;
    }else{
        return false;
    }
}
