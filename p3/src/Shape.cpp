#include "Shape.h"

Shape::Shape(Shapes type) : _shapeType(type)
{
}

Shapes Shape::GetType()
{
    return _shapeType;
}