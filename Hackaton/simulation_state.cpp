#include "simulation_state.h"


void SimulationState::InitState() {
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
	DataTransferComponent* transfer = new DataTransferComponent();


	player->AddComponent(camera);
	player->AddComponent(transfer);

	CameraControlsSystem* camera_control = new CameraControlsSystem();

	SystemManager::getInstance()->AddSystem(camera_control);

	SystemManager::getInstance()->AddActor(player);


	// ADD UI BUTTONS
	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor, std::vector<Actor*>) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});




	CreateTextInput(GetScreenWidth() - buttonWidth, 100, buttonWidth, buttonHeight, "mass", [transfer](std::string string) {
		if (transfer->actor != nullptr)
			transfer->actor->GetComponent<PhysicsComponent>()->mass = atoi(string.c_str());
		});

	CreateTextInput(GetScreenWidth() - buttonWidth, 200, buttonWidth, buttonHeight, "x", [transfer](std::string string) {
		if (transfer->actor != nullptr)
			transfer->actor->GetComponent<PhysicsComponent>()->velocity.x = atoi(string.c_str());
		});

	CreateTextInput(GetScreenWidth() - buttonWidth, 300, buttonWidth, buttonHeight, "y", [transfer](std::string string) {
		if (transfer->actor != nullptr)
			transfer->actor->GetComponent<PhysicsComponent>()->velocity.y = atoi(string.c_str());
		});

	CreateTextInput(GetScreenWidth() - buttonWidth, 400, buttonWidth, buttonHeight, "z", [transfer](std::string string) {
		if (transfer->actor != nullptr)
			transfer->actor->GetComponent<PhysicsComponent>()->velocity.z = atoi(string.c_str());
		});




	// ADD SYSTEMS
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	ModelRendererSystem* renderer_3d = new ModelRendererSystem(&(camera->camera));

	SystemManager::getInstance()->AddSystem(renderer_3d);

	GridSystem* grid = new GridSystem();

	SystemManager::getInstance()->AddSystem(grid);

	PhysicsSystem* physics_system = new PhysicsSystem();

	physics_system->active = false;

	SystemManager::getInstance()->AddSystem(physics_system);

	SpawnPlanetsSystem* spawn_planets = new SpawnPlanetsSystem();

	SystemManager::getInstance()->AddSystem(spawn_planets);

	TextInputSystem* txt_inp = new TextInputSystem();

	SystemManager::getInstance()->AddSystem(txt_inp);

	ClickSystem* click = new ClickSystem(player);

	SystemManager::getInstance()->AddSystem(click);



	CreateButton(GetScreenWidth() / 16 - buttonWidthSq / 2, GetScreenHeight() / 25, buttonWidthSq, buttonHeightSq, "", "button_planeta", [spawn_planets](Actor* actor2, std::vector<Actor*> actors)
		{
			spawn_planets->isSpawning = true;
		});

	CreateButton(GetScreenWidth() / 1.12 - buttonWidth / 2 + 12, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, "", "button_play", [physics_system](Actor* actor, std::vector<Actor*> actors)
		{
			physics_system->active = !physics_system->active;
		});




}