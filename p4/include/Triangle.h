#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(double base, double height);
    double GetBase() const;
    double GetHeight() const;
    double GetArea() override;

private:
    double _base;
    double _height;
};

#endif
