/*#include "transition_state.h"

void TransitionState::InitState() {

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("SIMA"), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);


}*/