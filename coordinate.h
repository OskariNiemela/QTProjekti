#ifndef COORDINATE_H
#define COORDINATE_H

namespace mapSpace
{
struct Coordinate
{
    int x;
    int y;

    Coordinate(int newX,int newY)
    {
        x = newX;
        y = newY;
    }

    Coordinate(){}

    bool operator < (const Coordinate& comp) const
    {
        if(y != comp.y)
        {
            return (this->y < comp.y);
        }
        else
        {
            return (this->x < comp.x);
        }
    }

    bool operator == (const Coordinate& comp) const
    {
        return (this->x == comp.x and this->y == comp.y);
    }
};
}


#endif // COORDINATE_H
