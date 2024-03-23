#include "spin_actor_system.h"

void SpinActorSystem::doLogic(std::vector<Actor*> actors, int current) {
	RotateAroundAxisComponent* spin = actors[current]->GetComponent<RotateAroundAxisComponent>();
	PositionComponent* position = actors[current]->GetComponent<PositionComponent>();
	position->transform.rotation.w += spin->angle;
	if (position->transform.rotation.w >= 360)
	{
		position->transform.rotation.w = (int)(position->transform.rotation.w) % 360;
	}
}