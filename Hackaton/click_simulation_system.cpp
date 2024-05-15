#include "click_simulation_system.h"

void ClickSimulationSystem::doLogic(std::vector<Actor*> actors, int current) {

    ModelComponent* model = actors[current]->GetComponent<ModelComponent>();

    if (IsKeyPressed(KEY_C)) {
        user->GetComponent<DataTransferComponent>()->actor = nullptr;
        return;
    }

    if (IsMouseButtonDown(0)) {
        PositionComponent* position = actors[current]->GetComponent<PositionComponent>();

        PhysicsComponent* physiscs = actors[current]->GetComponent<PhysicsComponent>();

        Ray ray = GetMouseRay(GetMousePosition(), user->GetComponent<CameraComponent>()->camera);

        RayCollision hit = GetRayCollisionSphere(ray, position->transform.translation, physiscs->radius);

        if (hit.hit) {
            user->GetComponent<DataTransferComponent>()->actor = actors[current];
        }
    }

    if (user->GetComponent<DataTransferComponent>()->actor == actors[current]) {
        model->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = TextureRegistry::getInstance()->GrabTexture("textura2");

    }
    else
        model->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = model->texture;

}