#include "learning_state.h"
#include "solar_system_state.h"
#include "binary_system_state.h"
#include "planets_state.h"
#include "cristi_state.h"

void LearningState::InitState(){

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("SIMA")),0);

	TextureRegistry::getInstance()->GrabTexture("texture_mercur");
	TextureRegistry::getInstance()->GrabTexture("texture_venus");
	TextureRegistry::getInstance()->GrabTexture("texture_pamant");
	TextureRegistry::getInstance()->GrabTexture("texture_marte");
	TextureRegistry::getInstance()->GrabTexture("texture_jupiter");
	TextureRegistry::getInstance()->GrabTexture("texture_saturn");
	TextureRegistry::getInstance()->GrabTexture("texture_uranus");
	TextureRegistry::getInstance()->GrabTexture("texture_neptun");

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);
	
	float buttonWidth = 200, buttonHeight = 100;
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-150, GetScreenHeight() / 2-100, buttonWidth, buttonHeight, 20,"Planete", "button", [](Actor* actor, std::vector<Actor*> actors) {
		ContextState::getInstance()->SetState(new PlanetState()); 
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-150, GetScreenHeight() / 2+100, buttonWidth, buttonHeight, 20,"Sistem Solar", "button", [](Actor* actor, std::vector<Actor*> actors) {
		ContextState::getInstance()->SetState(new SolarSystemState());
		ContextState::getInstance()->InitState();
		});
	
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+150, GetScreenHeight() / 2-100, buttonWidth, buttonHeight, 20,"Sistem Binar", "button", [](Actor* actor, std::vector<Actor*> actors) {
		ContextState::getInstance()->SetState(new BinarySystemState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+150, GetScreenHeight() / 2+100, buttonWidth, buttonHeight, 20, "Elipsa Planetelor", "button", [](Actor* actor, std::vector<Actor*> actors) {
		ContextState::getInstance()->SetState(new CristiState());
		ContextState::getInstance()->InitState();
		});

	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor, std::vector<Actor*> actors) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});

	
	
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);
}