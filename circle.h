#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"
#include <iostream>
class Circle
{
private:
    Point _center;
    double _radius;
public:
    static constexpr double EPS = 1e-3;
    Circle();
    Circle(const Circle& c);
    Circle(const Point&, double);
    Circle(double, double, double);
    Circle(int, int, int);
    ~Circle();

    double x() const;
    double y() const;
    void setX(double x);
    void setY(double y);
    void multiplyByConstant(double k);

    double radius() const;
    Point& center() const;
    void setRadius(double);
    void setCenter(const Point&);

    friend std::ostream& operator<<(std::ostream& out, const Circle& c);
    friend std::istream& operator>>(std::istream& in, Circle& c);
    bool operator==(const Circle&) const;
    bool operator!=(const Circle&) const;

    bool operator>(const Circle&) const;
    bool operator>=(const Circle&) const;
    bool operator<(const Circle&) const;
    bool operator<=(const Circle&) const;

    double area() const;
    double circumference() const;

    bool pointBelongsToCircle(const Point& p);
};
double squaredDistance(const Point& a, const Point& b);
double distance(const Point& a, const Point& b);
double centersDist(const Circle& a, const Circle& b);
int intersections(const Circle& a, const Circle& b);
#endif // CIRCLE_H
