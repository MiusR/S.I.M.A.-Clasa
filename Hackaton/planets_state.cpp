#include "planets_state.h"
void PlanetState::InitState() {

	///BACKGROUND 
	Actor* actor;
	actor = new Actor();

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("cosmos")), 0);

	BackgroundComponent* bg = new BackgroundComponent();

	actor->AddComponent(sprite);

	actor->AddComponent(bg);

	SystemManager::getInstance()->AddActor(actor);
	///CAMERA
	Actor* player = new Actor();

	CameraComponent* camera = new CameraComponent({ 0, 100, -20 }, { 0,0,0 }, 90.0f);

	player->AddComponent(camera);

	DataTransferComponent* transfer = new DataTransferComponent();

	player->AddComponent(transfer);

	SystemManager::getInstance()->AddActor(player);


	float buttonWidth = 128, buttonHeight = 64;
	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor, std::vector<Actor*>) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});

	actor = new Actor();

	PositionComponent* position = new PositionComponent(Vector3{ 10, 0, 3 }, Quaternion{ 0.0, 1.0, 0.0, 3 }, Vector3{ 0.1,0.1,0.1 });


	///SYSTEMS

	BackgroundDrawSystem* background_renderer = new BackgroundDrawSystem();

	SystemManager::getInstance()->AddSystem(background_renderer);

	ModelRendererSystem* renderer_3d = new ModelRendererSystem(&(camera->camera));

	SystemManager::getInstance()->AddSystem(renderer_3d);

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	LabelDrawSystem* label_draw = new LabelDrawSystem();

	SystemManager::getInstance()->AddSystem(label_draw);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	SpinActorSystem* spin_system = new SpinActorSystem;

	SystemManager::getInstance()->AddSystem(spin_system);

	ClickLearnSystem* click_system = new ClickLearnSystem(player);

	SystemManager::getInstance()->AddSystem(click_system);

	FocusSystem* focus_system = new FocusSystem();

	SystemManager::getInstance()->AddSystem(focus_system);


	///MERCUR
	Actor* actor1;
	actor1 = new Actor();

	RotateAroundAxisComponent* spin2 = new RotateAroundAxisComponent(0.05);

	ModelComponent* model2 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_mercur"));

	PositionComponent* position2 = new PositionComponent(Vector3{ 140, 0, -20 }, { 0, 0, 1, 0 }, { 2.4,2.4,2.4 });

	position2->observation_pos = { -8, 10, -3 };

	LabelComponent* label1 = new LabelComponent("Buna dimineata la mos ajun ne dati sau nu ne dati slanina si carnati carnati carnati CARNATI", 40, WHITE);


	actor1->AddComponent(model2);

	actor1->AddComponent(position2);

	actor1->AddComponent(spin2);

	actor1->AddComponent(label1);

	SystemManager::getInstance()->AddActor(actor1);

	///VENUS
	Actor* actor2;
	actor2 = new Actor();

	ModelComponent* model3 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_venus"));

	PositionComponent* position3 = new PositionComponent(Vector3{ 110, 0, -20 }, { 0, 0, -1, 0 }, { 0.94,0.94,0.94 });

	position3->observation_pos = { -14, 25, -3 };

	RotateAroundAxisComponent* spin3 = new RotateAroundAxisComponent(0.004);

	LabelComponent* label2 = new LabelComponent("Buna dimineata la mos ajun ne dati sau nu ne dati slanina si carnati carnati carnati CARNATI", 40, WHITE);

	actor2->AddComponent(model3);

	actor2->AddComponent(position3);

	actor2->AddComponent(spin3);

	actor2->AddComponent(label2);

	SystemManager::getInstance()->AddActor(actor2);

	///PAMANT
	Actor* actor3;
	actor3 = new Actor();

	ModelComponent* model4 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_pamant"));

	PositionComponent* position4 = new PositionComponent(Vector3{ 90, 0, -20 }, { 0, 0, 1, 0 }, { 5.67, 5.67, 5.67 });

	position4->observation_pos = { -14, 25, -3 };

	RotateAroundAxisComponent* spin4 = new RotateAroundAxisComponent(0.5);

	LabelComponent* label3 = new LabelComponent("Buna dimineata la mos ajun ne dati sau nu ne dati slanina si carnati carnati carnati CARNATI", 40, WHITE);


	actor3->AddComponent(model4);

	actor3->AddComponent(position4);

	actor3->AddComponent(spin4);

	actor3->AddComponent(label3);

	SystemManager::getInstance()->AddActor(actor3);

	///MARTE
	Actor* actor4;
	actor4 = new Actor();

	ModelComponent* model5 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_marte"));

	PositionComponent* position5 = new PositionComponent(Vector3{ 70, 0, -20 }, { 0, 0, 1, 0 }, { 0.53, 0.53, 0.53 });

	RotateAroundAxisComponent* spin5 = new RotateAroundAxisComponent(0.48);

	actor4->AddComponent(model5);

	actor4->AddComponent(position5);

	actor4->AddComponent(spin5);

	SystemManager::getInstance()->AddActor(actor4);

	///JUPITER
	Actor* actor5;
	actor5 = new Actor();

	ModelComponent* model6 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_jupiter"));

	PositionComponent* position6 = new PositionComponent(Vector3{ 30, 0, -20 }, { 0, 0, 1, 0 }, { 10.97,10.97,10.97 });

	position6->observation_pos = { -20, 36, -5 };

	RotateAroundAxisComponent* spin6 = new RotateAroundAxisComponent(1.2);

	LabelComponent* label6 = new LabelComponent("Buna dimineata la mos ajun ne dati sau nu ne dati slanina si carnati carnati carnati CARNATI", 40, WHITE);

	actor5->AddComponent(model6);

	actor5->AddComponent(position6);

	actor5->AddComponent(spin6);

	actor5->AddComponent(label6);

	SystemManager::getInstance()->AddActor(actor5);

	///SATURN
	Actor* actor6;
	actor6 = new Actor();

	ModelComponent* model7 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_saturn"));

	PositionComponent* position7 = new PositionComponent(Vector3{ -30, 0, -20 }, { 0, 0, 1, 0 }, { 9.14, 9.14, 9.14 });

	RotateAroundAxisComponent* spin7 = new RotateAroundAxisComponent(1.09);

	actor6->AddComponent(model7);

	actor6->AddComponent(position7);

	actor6->AddComponent(spin7);

	SystemManager::getInstance()->AddActor(actor6);

	///URANUS
	Actor* actor7;
	actor7 = new Actor();

	ModelComponent* model8 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_uranus"));

	PositionComponent* position8 = new PositionComponent(Vector3{ -70, 0, -20 }, { 1, 0, 0, 0 }, { 3.98,3.98,3.98 });

	RotateAroundAxisComponent* spin8 = new RotateAroundAxisComponent(-0.7);

	actor7->AddComponent(model8);

	actor7->AddComponent(position8);

	actor7->AddComponent(spin8);

	SystemManager::getInstance()->AddActor(actor7);

	///NEPTUN
	Actor* actor8;
	actor8 = new Actor();

	ModelComponent* model9 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_neptun"));

	PositionComponent* position9 = new PositionComponent(Vector3{ -100, 0, -20 }, { 0, 0, 1, 0 }, { 3.86,3.86,3.86 });

	RotateAroundAxisComponent* spin9 = new RotateAroundAxisComponent(0.75);

	actor8->AddComponent(model9);

	actor8->AddComponent(position9);

	actor8->AddComponent(spin9);

	SystemManager::getInstance()->AddActor(actor8);
}
