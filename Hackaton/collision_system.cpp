#include "collision_system.h"

void CollisionSystem::Update() {

    for (int i = 0; i < actors.size(); i++) {
        PositionComponent* actor_position_a = actors[i]->GetComponent<PositionComponent>();

        PhysicsComponent* actor_pshysics_a = actors[i]->GetComponent<PhysicsComponent>();
        
        actor_position_a->transform.translation = addVectors(actor_position_a->transform.translation, toScalarVector(actor_pshysics_a->velocity, GetFrameTime()));
       
        if (actor_pshysics_a->skip_attraction)
            actor_pshysics_a->skip_attraction = false;
    }

    for (int i = 0; i < actors.size(); i++) {
        PositionComponent* actor_position_a = actors[i]->GetComponent<PositionComponent>();

        PhysicsComponent* actor_physics_a = actors[i]->GetComponent<PhysicsComponent>();
        

        Vector3 rez = {0,0,0};
        float og_mass = actor_physics_a->mass;
        bool collided = false;

        for (int j = 0; j < actors.size(); j++) {

            if (i == j) continue;

            PositionComponent* actor_position_b = actors[j]->GetComponent<PositionComponent>();

            PhysicsComponent* actor_physics_b = actors[j]->GetComponent<PhysicsComponent>();


            if (CheckCollisionSpheres(actor_position_a->transform.translation, actor_physics_a->radius, actor_position_b->transform.translation, actor_physics_a->radius) && actor_physics_a->radius >= actor_physics_b->radius && (actors[i]->markDeletion != true && actors[j]->markDeletion != true)) {
                collided = true;

                Vector3 velocity_a = actor_physics_a->velocity, velocity_b = actor_physics_b->velocity;
  
                rez = toScalarVector(Vector3Add(toScalarVector(velocity_a, actor_physics_a->mass), toScalarVector(velocity_b, actor_physics_b->mass)), 10000000 / (actor_physics_a->mass + actor_physics_b->mass));
                //rez = toScalarVector(Vector3Add(toScalarVector(rez, actor_pshysics_a->mass - actor_pshysics_b->mass), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)), 1.0 / aux); // Collision formula
                
                actor_position_a->transform.scale = Vector3Add(actor_position_a->transform.scale, toScalarVector(actor_position_b->transform.scale, 1.0 / 2.0));
                if (!actors[i]->markDeletion) // Check if same size ( maybe use actual same size check instead of deletion )
                   actors[j]->markDeletion = true;
                
                actor_physics_a->mass = actor_physics_a->mass + actor_physics_b->mass;
            }
        }

        if (collided) {
            actor_physics_a->skip_attraction = true;
                rez = toScalarVector(rez, 0.5 / (actor_physics_a->mass * 2));
               // rez = toScalarVector(rez, 1.0 / og_mass);

            actor_physics_a->velocity = rez;
        }

    }
}