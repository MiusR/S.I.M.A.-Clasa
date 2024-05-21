#include "physics_system.h"

void PhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {

    const long double G = 6.67 * 0.01; /// 10 ^ 5

    PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

    PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

    if (actor_pshysics_a->skip_attraction) {
        actor_pshysics_a->skip_attraction = false;
        return;
    }

    Vector3 rez = actor_pshysics_a->velocity;
    std::cout << rez.x << " " << rez.y << " " << rez.z << "\n";
    for (int i = 0; i < actors.size(); i++) {
        if (i == current || actors[i]->markDeletion)
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

    if (distanceVectors(rez,vel) > 1) {
        rez = toScalarVector(rez, 1.0 / (actor_pshysics_a->mass /1.0)); // 10 ^ 3
        /*rez.x = Lerp(vel.x, rez.x, 1 / actor_pshysics_a->mass);
        rez.y = Lerp(vel.y, rez.y, 1 / actor_pshysics_a->mass);
        rez.z = Lerp(vel.z, rez.z, 1 / actor_pshysics_a->mass);*/
    }
    std::cout << rez.x << " " << rez.y << " " << rez.z << " !! \n";
    actor_pshysics_a->velocity = rez;


}