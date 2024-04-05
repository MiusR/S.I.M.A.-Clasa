#include "click_learn_system.h"

void ClickLearnSystem::doLogic(std::vector<Actor*> actors, int current) {
    
    ModelComponent* model = actors[current]->GetComponent<ModelComponent>();

    if (IsKeyPressed(KEY_C)) {
        user->GetComponent<DataTransferComponent>()->actor = NULL;
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
}