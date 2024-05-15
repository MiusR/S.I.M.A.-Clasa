#pragma once

#include <raylib.h>
#include <cmath>
#include <raymath.h>
#include "position_component.h"
#include "model_component.h"
#include "rotate_around_axis_component.h"
#include "physics_component.h"
#include "model_registry.h"
#include "texture_registry.h"
#include "system_manager.h"

inline Vector3 addVectors(Vector3 v1, Vector3 v2) {
	Vector3 rez;

	rez.x = v1.x + v2.x;
	rez.y = v1.y + v2.y;
	rez.z = v1.z + v2.z;

	return rez;
}

inline Vector3 subtractVectors(Vector3 v1, Vector3 v2) {
	Vector3 rez;

	rez.x = v1.x - v2.x;
	rez.y = v1.y - v2.y;
	rez.z = v1.z - v2.z;

	return rez;
}


inline double distanceVectors(Vector3 v1, Vector3 v2) {
	return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
}

inline Vector3 toScalarVector(Vector3 v, double s) {
	Vector3 rez;

	rez.x = v.x * s;
	rez.y = v.y * s; 
	rez.z = v.z * s; 

	return rez;
}

static Actor* addCelestialBody(Vector3 position, Quaternion rotation, Vector3 inital_vel, float mass, float radius, std::string texture, bool is_black_hole = false) {
	Actor* actor = new Actor();

	PositionComponent* position_component = new PositionComponent(position, rotation, { radius,radius,radius });

	PhysicsComponent* physiscs_component = new PhysicsComponent(mass, radius, inital_vel);

	ModelComponent* model_component = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, radius, 30, 30), TextureRegistry::getInstance()->GrabTexture(texture));

	physiscs_component->is_black_hole = true;

	actor->AddComponent(position_component);
	actor->AddComponent(physiscs_component);
	actor->AddComponent(model_component);

	SystemManager::getInstance()->AddActor(actor);  

	return actor;
}
static Actor* addCelestialBody(Vector3 position,Vector3 inital_vel, float mass, float radius, std::string texture, bool is_black_hole=false) {

	float i = GetRandomValue(1,360);
	return addCelestialBody(position, {1,(float)GetRandomValue(0,1),0,i}, inital_vel, mass, radius, texture, is_black_hole);
}

