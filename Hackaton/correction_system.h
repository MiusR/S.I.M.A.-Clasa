#pragma once
#include "system.h"
#include "physics_component.h"
#include "position_component.h"
#include "model_component.h"
#include "util.h"

class CorrectionSystem : public System {
public:

    CorrectionSystem() {
        requirements.push_back(typeid(PositionComponent).name());
        requirements.push_back(typeid(PhysicsComponent).name());
        requirements.push_back(typeid(ModelComponent).name());
    }

    void Update() override {
        for (int k = 0; k < actors.size(); k++) {
            const long double G = 6.67 * 0.0001; /// 10 ^ 3

            PositionComponent* actor_position_a = actors[k]->GetComponent<PositionComponent>();

            PhysicsComponent* actor_pshysics_a = actors[k]->GetComponent<PhysicsComponent>();

            if (actor_pshysics_a->skip_attraction) {
                actor_pshysics_a->skip_attraction = false;
                return;
            }

            Vector3 rez = actor_pshysics_a->velocity;

            for (int i = 0; i < actors.size(); i++) {
                if (i == k || actors[i]->markDeletion)
                    continue;

                PositionComponent* actor_position_b = actors[i]->GetComponent<PositionComponent>();

                PhysicsComponent* actor_pshysics_b = actors[i]->GetComponent<PhysicsComponent>();

                double distance = distanceVectors(actor_position_a->transform.translation, actor_position_b->transform.translation);

                double force = 0;

                force = -G * actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance);

                Vector3 vector = toScalarVector(subtractVectors(actor_position_a->transform.translation, actor_position_b->transform.translation), 1 / distance);

                vector = toScalarVector(vector, force);

                rez = addVectors(rez, vector);
            }

            Vector3 vel = actor_pshysics_a->velocity;
            // Inertia?
            rez.x = Lerp(vel.x, rez.x, 1 / actor_pshysics_a->mass);
            rez.y = Lerp(vel.y, rez.y, 1 / actor_pshysics_a->mass);
            rez.z = Lerp(vel.z, rez.z, 1 / actor_pshysics_a->mass);


            actor_pshysics_a->velocity = rez;
        }


        for (int i = 0; i < actors.size(); i++) {
            PositionComponent* actor_position_a = actors[i]->GetComponent<PositionComponent>();

            PhysicsComponent* actor_pshysics_a = actors[i]->GetComponent<PhysicsComponent>();

            actor_position_a->transform.translation = addVectors(actor_position_a->transform.translation, toScalarVector(actor_pshysics_a->velocity, GetFrameTime()));

        }

    }
};



