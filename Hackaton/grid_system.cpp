#include "grid_system.h"

void GridSystem::doLogic(std::vector<Actor*> actors, int current) {

	CameraComponent* camera = actors[current]->GetComponent<CameraComponent>();
	
	BeginMode3D(camera->camera);
	
	DrawGrid(100,1);

	EndMode3D();
}