#include "hyperbolic_state.h"


void HyperbolicState::InitState() {
	float buttonWidth = 128, buttonHeight = 64;
	float buttonWidthSq = 64, buttonHeightSq = 64;

	// ADD BACKGROUND
	Actor* actor;
	actor = new Actor();

	SpriteComponent* model = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("cosmos"), 0);
	PositionComponent* pos = new PositionComponent({ 0,0,0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	actor->AddComponent(model);
	actor->AddComponent(pos);

	SystemManager::getInstance()->AddActor(actor);



	// ADD PLAYER CAMERA
	Actor* player = new Actor();

	CameraComponent* camera = new CameraComponent({ -15, 5, 0 }, { 0,-10,0 }, 90.0f);

	player->AddComponent(camera);

	CameraControlsSystem* camera_control = new CameraControlsSystem();

	SystemManager::getInstance()->AddSystem(camera_control);

	SystemManager::getInstance()->AddActor(player);


	// ADD UI BUTTONS
	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor, std::vector<Actor*>) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});


	// ADD SYSTEMS
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	GridSystem* grid = new GridSystem();

	SystemManager::getInstance()->AddSystem(grid);

	ModelRendererSystem* renderer_3d = new ModelRendererSystem(&(camera->camera));

	SystemManager::getInstance()->AddSystem(renderer_3d);

	LearningPhysicsSystem* learning_physics_system = new LearningPhysicsSystem();

	learning_physics_system->active = false;

	SystemManager::getInstance()->AddSystem(learning_physics_system);

	SpawnPlanetsSystem* spawn_planets = new SpawnPlanetsSystem();

	SystemManager::getInstance()->AddSystem(spawn_planets);

	CreateButton(GetScreenWidth() / 16 - buttonWidthSq / 2, GetScreenHeight() / 25, buttonWidthSq, buttonHeightSq, "", "button_planeta", [spawn_planets](Actor* actor2, std::vector<Actor*>)
		{
			spawn_planets->isSpawning = true;
		});

	CreateButton(GetScreenWidth() / 1.12 - buttonWidth / 2 + 12, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, "", "button_play", [learning_physics_system](Actor* actor, std::vector<Actor*>)
		{
			learning_physics_system->active = !learning_physics_system->active;
		});



	/*addCelestialBody({0,0, 0}, {0,0,0}, 80000, 1.5, "texture_sun");
	addCelestialBody({ 0,0,22 }, { 10,0,0 }, 2000, 0.65, "texture_pamant");
	addCelestialBody({ 0,0,24.8 }, { 1,0,0 }, 300, 0.45, "texture_mercur");*/

	/*addCelestialBody({0,0, 0}, {0,0,0}, 30000, 1.5, "texture_sun");
	addCelestialBody({ 0,0,20 }, { 7,0,0 }, 2000, 0.65, "texture_pamant");
	addCelestialBody({ 0,0,17 }, { 0.5,0,0 }, 600, 0.45, "texture_mercur");*/

	addCelestialBody({ 0,0, 0 }, { 0,0,0 }, 40000, 1.5, "texture_sun");
	addCelestialBody({ -5,0,-15 }, { 0,0,20.2 }, 800, 0.65, "texture_neptun");
	addCelestialBody({ -10,0,-15 }, { 0,0,20 }, 800, 0.65, "texture_marte");
	addCelestialBody({ -15,0,-15 }, { 0,0,20 }, 800, 0.65, "texture_mercur");

}
