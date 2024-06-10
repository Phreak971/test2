#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() 
{
    // Create a Circle with radius 5
    Circle circle(5.0);
    std::cout << "Circle:" << std::endl;
    std::cout << "Radius: " << circle.GetRadius() << std::endl;
    std::cout << "Area: " << circle.GetArea() << std::endl;

    // Create a Rectangle with width 4 and height 6
    Rectangle rectangle(4.0, 6.0);
    std::cout << "\nRectangle:" << std::endl;
    std::cout << "Width: " << rectangle.GetWidth() << ", Height: " << rectangle.GetHeight() << std::endl;
    std::cout << "Area: " << rectangle.GetArea() << std::endl;

    // Create a Triangle with base 3 and height 8
    Triangle triangle(3.0, 8.0);
    std::cout << "\nTriangle:" << std::endl;
    std::cout << "Base: " << triangle.GetBase() << ", Height: " << triangle.GetHeight() << std::endl;
    std::cout << "Area: " << triangle.GetArea() << std::endl;

    return 0;
}
