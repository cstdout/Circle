#include "point.h"

Point::Point(double x, double y)
{
    _x = x;
    _y = y;
}
Point::Point(const Point& p)
{
    _x = p.x();
    _y = p.y();
}
void Point::setX(double x)
{
    _x = x;
}
void Point::setY(double y)
{
    _y = y;
}
double Point::x() const
{
    return _x;
}
double Point::y() const
{
    return _y;
}
