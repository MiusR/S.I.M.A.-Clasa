#include "physics_system.h"

void PhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {

    const long double G = 6.67 * 0.0000001;

    PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

    PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

    Vector3 rez = actor_pshysics_a->velocity;

    for (int i = 0; i < actors.size(); i++) {
        if (i == current)
            continue;

        PositionComponent* actor_position_b = actors[i]->GetComponent<PositionComponent>();

        PhysicsComponent* actor_pshysics_b = actors[i]->GetComponent<PhysicsComponent>();

        float distance = (float)distanceVectors(actor_position_a->transform.translation, actor_position_b->transform.translation);

        float force = 0;

        if (!CheckCollisionSpheres(actor_position_a->transform.translation, actor_pshysics_a->radius, actor_position_b->transform.translation, actor_pshysics_a->radius)) {
            force = -G * actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance);

            Vector3 vector = toScalarVector(subtractVectors(actor_position_a->transform.translation, actor_position_b->transform.translation), 1 / distance);

            vector = toScalarVector(vector, force);

            rez = addVectors(rez, vector);
        }
        else {
            if (actor_pshysics_a->radius >= actor_pshysics_b->radius) {
                bool  collide = true;

                if (collide) {
                    float aux = actor_pshysics_a->mass;
                    actor_pshysics_a->mass = actor_pshysics_a->mass + actor_pshysics_b->mass;
                    rez = toScalarVector(Vector3Add(toScalarVector(rez, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)), 1 / actor_pshysics_a->mass);
                    actor_position_a->transform.scale = Vector3Add(actor_position_a->transform.scale, toScalarVector(actor_position_b->transform.scale, 1.0 / 2.0));
                    if (!actors[current]->markDeletion)
                        actors[i]->markDeletion = true;
                }
            }
        }

    }
    actor_pshysics_a->velocity = rez;

    rez = addVectors(actor_position_a->transform.translation, toScalarVector(rez, GetFrameTime()));


    actor_position_a->transform.translation = rez;

    //TODO : ON COLLISION MERGE THE PLANETS

}