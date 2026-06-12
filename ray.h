//
// Created by Christiano Christakou on 10/06/2026.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "vec3.h"



class ray {
public:
    ray() = default;
    ray(const vec3& origin, const vec3& direction): _origin(origin), _direction(direction) {}


    [[nodiscard]] point3 at(const double t) const {
        return _origin + t*_direction;
    }

    [[nodiscard]] point3 origin() const {
        return _origin;
    }
    [[nodiscard]] vec3 direction() const {
        return _direction;
    }

private:
    vec3 _origin;
    vec3 _direction;
};

#endif //RAYTRACING_RAY_H