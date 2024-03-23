#include "spawn_planets_system.h"

void SpawnPlanetsSystem::doLogic(std::vector<Actor*> actors, int current) {
	if (isSpawning) {

		CameraComponent* camera = actors[current]->GetComponent<CameraComponent>();

		Ray ray = GetMouseRay(GetMousePosition(), camera->camera);

		RayCollision hit = GetRayCollisionBox(ray, BoundingBox{ -100,0,-100,100,0,100 });
		
		if (IsMouseButtonReleased(0)) {

			addCelestialBody(Vector3Add(hit.point, { 0,1,0 }), { 0,0,0 }, 10000, 1, "textura");
			
			isSpawning = false;
		}
		else if (IsMouseButtonDown(0)) {
			
			BeginMode3D(camera->camera);

			DrawSphereWires(Vector3Add(hit.point, {0,1,0}), 1, 20, 20, GREEN);

			EndMode3D();
		}
	}
}