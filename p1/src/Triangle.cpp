#include "Triangle.h"

Triangle::Triangle(double base, double height) : Shape(Shapes::Triangle), _base(base), _height(height) {}

double Triangle::GetBase() const {
    return _base;
}

double Triangle::GetHeight() const {
    return _height;
}

double Triangle::GetArea() {
    return 0.5 * _base * _height;
}
