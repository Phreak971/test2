#ifndef SHAPE_H
#define SHAPE_H

enum class Shapes
{
    Circle,
    Rectangle,
    Triangle
};

class Shape
{
public:
    Shape(Shapes type);
    virtual double GetArea() = 0;
    Shapes GetType();
private:
   Shapes _shapeType;
};

#endif