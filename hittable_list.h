//
// Created by Christiano Christakou on 10/06/2026.
//

#ifndef RAYTRACING_HITTABLE_LIST_H
#define RAYTRACING_HITTABLE_LIST_H
#include <vector>
#include "hittable.h"



using std::vector;


class hittable_list : public hittable {
    public:
    vector<shared_ptr<hittable>> objects;
    hittable_list() = default;

    explicit hittable_list(const shared_ptr<hittable>& object) {
        add(object);
    }
    void clear() {
        objects.clear();
    }
    void add(const shared_ptr<hittable>& object) {
        objects.push_back(object);

    }

    bool hit(const ray& r, const interval ray_t, hit_record& rec) const override {
        hit_record tempt_rec;
        auto closest_so_far = ray_t.max;
        bool hit_anything = false;
        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), tempt_rec)) {
                hit_anything = true;
                closest_so_far = tempt_rec.t;
                rec = tempt_rec;
            }
        }
        return hit_anything;
    }
};


#endif //RAYTRACING_HITTABLE_LIST_H