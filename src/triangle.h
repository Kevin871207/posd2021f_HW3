#pragma once
#include <sstream>
#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
        _vec1 = new TwoDimensionalVector(vec1.x(), vec1.y());
        _vec2 = new TwoDimensionalVector(vec2.x(), vec2.y());
    }

    double area() const {
        return abs(_vec1->cross(*_vec2)) / 2.0;
    }

    double perimeter() const {
      return _vec1->length() + _vec2->length() +
             _vec1->subtract(*_vec2).length();
     }

    std::string info() const {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Triangle ([" << _vec1->x() << "," << _vec1->y() << "] ["
           << _vec2->x() << "," << _vec2->y() << "]\n";
        return ss.str();
     }

private:
    TwoDimensionalVector *_vec1;
    TwoDimensionalVector *_vec2;
};