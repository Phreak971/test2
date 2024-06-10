#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double GetWidth() const;
    double GetHeight() const;
    double GetArea() override;

private:
    double _width;
    double _height;
};

#endif
