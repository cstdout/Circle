#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double _x, _y;
public:
    Point(const Point& p);
    Point(double x = 0, double y = 0);
    double x() const;
    double y() const;
    void setX(double x);
    void setY(double y);
};

#endif // POINT_H
