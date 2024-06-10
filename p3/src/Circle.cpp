#include "Circle.h"
#include <cmath>

Circle::Circle(double radius) : Shape(Shapes::Circle), _radius(radius) {}

double Circle::GetRadius() const {
    return _radius;
}

double Circle::GetArea() {
    return M_PI * _radius * _radius;
}
