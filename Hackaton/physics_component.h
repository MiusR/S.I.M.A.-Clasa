#pragma once
#include <raylib.h>
#include "component.h"

class PhysicsComponent : public Component{
        
    public:

        float mass, radius;
        Vector3 velocity;
        bool is_black_hole, skip_attraction = false;

        PhysicsComponent(float mass, float radius, Vector3 velocity) {
            this->mass = mass;
            this->radius = radius;
            this->velocity = velocity;
        };
};