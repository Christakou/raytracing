//
// Created by Christiano Christakou on 10/06/2026.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H
#include "hittable.h"

class sphere :public hittable {
public:
    sphere(const point3 center, double radius): center(center), radius(std::fmax(0, radius)){}

    bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override {
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;
        auto discriminant = h*h - a*c;
        if (discriminant < 0) {
            return false;
        }
        auto sqrtd = std::sqrt(discriminant);
        auto root = (h-sqrtd)/a;
        if (root < t_min || t_max <= root) {
            return false;
        }
        rec.t = root;
        rec.p = r.at(rec.t);
        const vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        return true;
    }
private:
    point3 center;
    double radius;
};

#endif //RAYTRACING_SPHERE_H