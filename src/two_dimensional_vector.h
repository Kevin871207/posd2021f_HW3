#pragma once
#include <cmath>
#include <sstream>
#include <string>

class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y) {
        _x = x;
        _y = y;
    }

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double length() const {
        return sqrt(pow(_x, 2.0) + pow(_y, 2.0));
    }

    double dot(TwoDimensionalVector vec) const {
        return _x * vec._x() + _y * vec._y();
    }

    double cross(TwoDimensionalVector vec) const {
        return _x * vec._y() - _y * vec._x();
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
        return TwoDimensionalVector(_x - vec.y(), _y - vec.y());
    }

    std::string info() const {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "[" << _x << "," << _y << "]\n";
        return ss.str();
    }

private:
    double _x = 0.0;
    double _y = 0.0;
};