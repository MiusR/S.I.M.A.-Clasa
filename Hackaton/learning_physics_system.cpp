#include "learning_physics_system.h"

void LearningPhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {

    PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

    PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

    Vector3 rez = actor_pshysics_a->velocity;

    for (int i = 0; i < actors.size(); i++) {
        if (i == current)
            continue;

        PositionComponent* actor_position_b = actors[i]->GetComponent<PositionComponent>();

        PhysicsComponent* actor_pshysics_b = actors[i]->GetComponent<PhysicsComponent>();

        float distance = (float)distanceVectors(actor_position_a->transform.translation, actor_position_b->transform.translation);

        float force = -1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance);


        Vector3 vector = toScalarVector(subtractVectors(actor_position_a->transform.translation, actor_position_b->transform.translation), 1 / distance);

        vector = toScalarVector(vector, force);

        rez = addVectors(rez, vector);
    }

    actor_pshysics_a->velocity = rez;

    rez = addVectors(actor_position_a->transform.translation, toScalarVector(rez, GetFrameTime()));

    bool isColliding = false;

    for (int i = 0; i < actors.size(); i++) {

        if (i == current)
            continue;

        PositionComponent* actor_position_b = actors[i]->GetComponent<PositionComponent>();

        PhysicsComponent* actor_pshysics_b = actors[i]->GetComponent<PhysicsComponent>();

        if (distanceVectors(rez, actor_position_b->transform.translation) < (actor_pshysics_a->radius + actor_pshysics_b->radius)) {
            isColliding = true;
            break;
        }
    }

    if (!isColliding) {
        actor_position_a->transform.translation = rez;
    }
    else {
        actor_pshysics_a->velocity = { 0 };
    }

    //TODO : ON COLLISION MERGE THE PLANETS

}