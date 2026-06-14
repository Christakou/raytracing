//
// Created by Christiano Christakou on 14/06/2026.
//

#ifndef RAYTRACING_INTERVAL_H
#define RAYTRACING_INTERVAL_H

#include "utils.h"
class interval {
public:
    double min, max;

    interval() :min(infinity), max(-infinity) {}
    interval(double a, double b) :min(a), max(b) {}
    interval(long double a, long double b) :min(a), max(b) {}

    double size() const {return max - min;}

    bool contains(double x) const {return min <= x && x <= max;}

    bool surrounds(double x) const {
        return min < x && x <max;
    }

    static const interval empty, universe;
};

const interval interval::empty(infinity, -infinity);
const interval interval::universe(-infinity, infinity);

#endif //RAYTRACING_INTERVAL_H