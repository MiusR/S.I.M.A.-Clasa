#pragma once

#include <raylib.h>
#include "component.h"

class PositionComponent : public Component{
        
    public:
        Transform transform;
        Vector3 observation_pos;

        PositionComponent(Vector3 position, Quaternion rotation, Vector3 scale) {
            this->transform.translation = position;
            this->transform.rotation = rotation;
            this->transform.scale = scale;
        }

        PositionComponent(Vector3 position, Vector3 scale) {
            this->transform.translation = position;
            this->transform.rotation = Quaternion{ 0,0,0,0 };
            this->transform.scale = scale;
        }

        PositionComponent(Vector3 position, float scale) {
            this->transform.translation = position;
            this->transform.rotation = Quaternion{ 0,0,0,0 };
            this->transform.scale = Vector3{ scale,scale,scale };
        }

        PositionComponent(Vector3 position) {
            this->transform.translation = position;
            this->transform.rotation = Quaternion{ 0,0,0,0 };
            this->transform.scale = Vector3{ 1,1,1 };
        }
};
