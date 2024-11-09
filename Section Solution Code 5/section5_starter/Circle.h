#pragma once 

#include <iostream>

class Circle {

public:
    // constructs a new circle with the given radius
    Circle(double r);
    // returns the area occupied by the circle
    double area() const;
    // returns the distance around the circle 
    double circumference() const;

    // returns the radius as a real number
    double getRadius() const;

    // returns a string representation such as "Circle{radius=2.5}"
    std::string toString() const;

private:
    // TODO: Include any private member functions
    // or member variables here as you deem appropriate.
    // Then, delete these lines.
};
