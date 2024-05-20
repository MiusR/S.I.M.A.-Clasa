#include "click_learn_system.h"

void ClickLearnSystem::doLogic(std::vector<Actor*> actors, int current) {
    
    ModelComponent* model = actors[current]->GetComponent<ModelComponent>();

    if (IsKeyPressed(KEY_C)) {
        user->GetComponent<DataTransferComponent>()->actor = NULL;
        return;
    }
    if (user->GetComponent<DataTransferComponent>()->actor != NULL)
        return;
    PositionComponent* position = actors[current]->GetComponent<PositionComponent>();

    Ray ray = GetMouseRay(GetMousePosition(), user->GetComponent<CameraComponent>()->camera);

    RayCollision hit = GetRayCollisionSphere(ray, position->transform.translation, position->transform.scale.x * 2.5);

    if (hit.hit){

        if (IsMouseButtonDown(0)) {
            user->GetComponent<DataTransferComponent>()->actor = actors[current];
        }
    }
}