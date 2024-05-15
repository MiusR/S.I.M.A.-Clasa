#include "background_draw_system.h"


void BackgroundDrawSystem::doLogic(std::vector<Actor*> actors, int current) {
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();

	Texture2D texture = sprite->texture;

	DrawTexturePro(texture, { 0.0f,0.0f,(float)texture.width, (float)texture.height }, { 0.0f,0.0f,(float)GetScreenWidth(),(float) GetScreenHeight()}, Vector2{0, 0}, 0, Color{255,255,255,255});
}


void BackgroundDrawSystem::Update() {
	EndMode3D();
	for (int j = 0; j < actors.size(); j++)
			doLogic(actors, j);
}