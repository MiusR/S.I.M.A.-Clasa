#include "label_draw_system.h"

void LabelDrawSystem::doLogic(std::vector<Actor*> actors, int current) {

	Vector2 mousePosition = GetMousePosition();

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	LabelComponent* label_comp = actors[current]->GetComponent<LabelComponent>();
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();


	Rectangle button_rectangle = { button_poz->transform.translation.x, button_poz->transform.translation.y, button_poz->transform.scale.x, button_poz->transform.scale.y };


	int size = MeasureText(label_comp->label_text.c_str(), label_comp->font_size);

	DrawText(label_comp->label_text.c_str(), button_poz->transform.translation.x + 10, button_poz->transform.translation.y + 10, label_comp->font_size, label_comp->text_color);
}
