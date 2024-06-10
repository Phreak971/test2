#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : Shape(Shapes::Rectangle), _width(width), _height(height) {}

double Rectangle::GetWidth() const {
    return _width;
}

double Rectangle::GetHeight() const {
    return _height;
}

double Rectangle::GetArea() {
    return _width * _height;
}
