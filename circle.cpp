#include "circle.h"
#include <math.h>
Circle::Circle()
{
}
Circle::Circle(int x, int y, int r)
{
    _center = Point(double(x), double(y));
    _radius = double(r);
}
Circle::Circle(const Point& c, double r)
{
    _center = c;
    _radius = r;
}
Circle::Circle(double x, double y, double r)
{
    _center = Point(x, y);
    _radius = r;
}
Circle::Circle(const Circle& c)
{
    _center = c.center();
    _radius = c.radius();
}
Circle::~Circle()
{
    std::cout << "Object has been deleted" << std::endl;
}
double Circle::radius() const
{
    return _radius;
}
Point& Circle::center() const
{
    Point* c = new Point(_center);
    return *c;
}
void Circle::setRadius(double r)
{
    _radius = r;
}
void Circle::setCenter(const Point &c)
{
    _center = c;
}
std::ostream& operator<<(std::ostream& out, const Circle& c)
{
    out << c._center.x() << ' ' << c._center.y() << ' ' << c._radius;
    return out;
}
std::istream& operator>>(std::istream& in, Circle& c)
{
    double x, y, r;
    in >> x >> y >> r;
    c._center = Point(x, y);
    c._radius = r;
    return in;
}
double Circle::x() const
{
    return _center.x();
}
double Circle::y() const
{
    return _center.y();
}
double Circle::area() const
{
    return M_PI * _radius * _radius;
}
bool Circle::operator==(const Circle& other) const
{
    return ((fabs(x() - other.x()) < EPS) && (fabs(y() - other.y()) < EPS) && fabs(radius() - other.radius()) < EPS);
}
bool Circle::operator!=(const Circle& other) const
{
    return !((*this) == other);
}
bool Circle::operator>(const Circle& other) const
{
    return (area() > other.area());
}
bool Circle::operator>=(const Circle& other) const
{
    return (area() >= other.area());
}
bool Circle::operator<(const Circle& other) const
{
    return (area() < other.area());
}
bool Circle::operator<=(const Circle& other) const
{
    return (area() <= other.area());
}
double Circle::circumference() const
{
    return M_PI * _radius * 2;
}
void Circle::setX(double x)
{
    _center.setX(x);
}
void Circle::setY(double y)
{
    _center.setY(y);
}
void Circle::multiplyByConstant(double k)
{
    _radius *= sqrt(k);
}
bool Circle::pointBelongsToCircle(const Point& p)
{
    return (fabs(squaredDistance(_center, p) - (_radius * _radius)) < EPS);
}
double squaredDistance(const Point& a, const Point& b)
{
    double dx = a.x() - b.x();
    double dy = a.y() - b.y();
    return (dx * dx + dy * dy);
}
double distance(const Point& a, const Point& b)
{
    return sqrt(squaredDistance(a, b));
}
double centersDist(const Circle& a, const Circle& b)
{
    return distance(a.center(), b.center());
}
int intersections(const Circle& a, const Circle& b)
{
    if (a == b)
    {
        return -1;
    }
    double dist = centersDist(a, b);
    double rSum = (a.radius() + b.radius());
    if(dist > rSum)
    {
        return 0;
    }
    if(dist < rSum)
    {
        return 2;
    }
    if(fabs(dist - rSum) < Circle::EPS)
    {
        return 1;
    }
}
