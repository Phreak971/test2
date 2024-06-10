#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double radius);
    double GetRadius() const;
    double GetArea() override;

private:
    double _radius;
};

#endif
