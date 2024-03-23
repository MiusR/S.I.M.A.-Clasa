/*#include "black_hole_physics_system.h"

void BlackHolePhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {

    const long double G = 6.67 * 0.0000001;

	PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

	PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

	ModelComponent* model_component_a = actors[current]->GetComponent<ModelComponent>();

	Vector3 rez = actor_pshysics_a->velocity;

	//if(actor_pshysics_a->density > )

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
			if (actor_pshysics_a->radius >= actor_pshysics_b->radius)//&& !actors[current]->markDeletion
			{
				
				if (!actor_pshysics_a->is_black_hole && !actor_pshysics_b->is_black_hole) {

					float aux = actor_pshysics_a->mass;
					actor_pshysics_a->mass = actor_pshysics_a->mass + actor_pshysics_b->mass;
					//actor_pshysics_a->radius = ((-1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance)) * actor_pshysics_a->radius) / force;
					//actor_pshysics_a->volume = (4 * PI * (actor_pshysics_a->radius * actor_pshysics_a->radius * actor_pshysics_a->radius)) / 3;
					//actor_pshysics_a->density = actor_pshysics_a->mass / actor_pshysics_a->volume;
					rez = toScalarVector(Vector3Add(toScalarVector(rez, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)), 1 / actor_pshysics_a->mass);
					//rez = toScalarVector(rez, 10);
					actor_position_a->transform.scale = Vector3Add(actor_position_a->transform.scale, toScalarVector(actor_position_b->transform.scale, 1.0 / 2.0));
					if (!actors[current]->markDeletion)
						actors[i]->markDeletion = true;
				}
				else if (actor_pshysics_a->is_black_hole == true)
				{
					actors[i]->markDeletion = true;
					actor_position_a->transform.scale = Vector3Add(actor_position_a->transform.scale, toScalarVector(actor_position_b->transform.scale, 1.0 / 2.0));

				}
			}
		}
	}

	if (actor_pshysics_a->is_black_hole)
	{
		rez = { 0,0,0 };

		actor_pshysics_a->velocity = rez;

		actor_position_a->transform.translation = rez;

	}
	else {
		actor_pshysics_a->velocity = rez;

		rez = addVectors(actor_position_a->transform.translation, toScalarVector(rez, GetFrameTime()));


		actor_position_a->transform.translation = rez;
	}
    

    //TODO : ON COLLISION MERGE THE PLANETS 

}*/

#include "black_hole_physics_system.h"

//CC Seby


void BlackHolePhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {

	const long double G = 6.67 * 0.0000001;

	PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

	PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

	ModelComponent* model_component_a = actors[current]->GetComponent<ModelComponent>();

	Vector3 rez = actor_pshysics_a->velocity;

	//if(actor_pshysics_a->density > )

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
			if (actor_pshysics_a->radius >= actor_pshysics_b->radius)//&& !actors[current]->markDeletion
			{
				if ( !actor_pshysics_a->is_black_hole && !actor_pshysics_b->is_black_hole) {

					float aux = actor_pshysics_a->mass;
					actor_pshysics_a->mass = actor_pshysics_a->mass + actor_pshysics_b->mass;
					//actor_pshysics_a->radius = ((-1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance)) * actor_pshysics_a->radius) / force;
					//actor_pshysics_a->volume = (4 * PI * (actor_pshysics_a->radius * actor_pshysics_a->radius * actor_pshysics_a->radius)) / 3;
					//actor_pshysics_a->density = actor_pshysics_a->mass / actor_pshysics_a->volume;
					rez = toScalarVector(Vector3Add(toScalarVector(rez, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)), 1 / actor_pshysics_a->mass);
					//rez = toScalarVector(rez, 10);
					actor_position_a->transform.scale = Vector3Add(actor_position_a->transform.scale, toScalarVector(actor_position_b->transform.scale, 1.0 / 2.0));
					if (!actors[current]->markDeletion)
						actors[i]->markDeletion = true;
				}
				else if (actor_pshysics_a->is_black_hole == true)
				{


					actors[i]->markDeletion = true;
					actor_position_a->transform.scale = Vector3Add(actor_position_a->transform.scale, toScalarVector(actor_position_b->transform.scale, 1.0 / 2.0));

				}
			}
			/*if (actor_pshysics_a->type == GAS && actor_pshysics_b->type == SOLID)
			{
				float aux = actor_pshysics_a->mass;
				actor_pshysics_a->mass += actor_pshysics_b->mass;
				actor_pshysics_a->radius = ((-1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance)) * actor_pshysics_a->radius) / force;
				actor_pshysics_a->volume = (4 * PI * (actor_pshysics_a->radius * actor_pshysics_a->radius * actor_pshysics_a->radius)) / 3;
				actor_pshysics_a->density = actor_pshysics_a->mass / actor_pshysics_a->volume;
				actor_pshysics_a->velocity = toScalarVector(Vector3Add(toScalarVector(actor_pshysics_a->velocity, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)),  1/actor_pshysics_a->mass);

			}

			/*if (model_component_a->radius >= model_component_b->radius) {
				int aux = actor_pshysics_a->mass;
				actor_pshysics_a->mass += actor_pshysics_b->mass;
				actor_pshysics_a->radius = ((-1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance)) * model_component_a->radius) / force;
				actor_pshysics_a->velocity = toScalarVector(Vector3Add(toScalarVector(actor_pshysics_a->velocity, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)), 1/actor_pshysics_a->mass);
				actors[i]->markDeletion = true;
				*/
		}
	}

	if (actor_pshysics_a->is_black_hole == true)
	{
		rez = { 0,0,0 };

		actor_pshysics_a->velocity = rez;

		actor_position_a->transform.translation = rez;



	}
	else {
		actor_pshysics_a->velocity = rez;

		rez = addVectors(actor_position_a->transform.translation, toScalarVector(rez, GetFrameTime()));


		actor_position_a->transform.translation = rez;
	}



	//TODO : ON COLLISION MERGE THE PLANETS       distanceVectors(rez ,actor_position_b->transform.translation) > (actor_pshysics_a->radius + actor_pshysics_b->radius

}