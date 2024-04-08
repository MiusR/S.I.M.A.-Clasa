#include "label_draw_system.h"

void LabelDrawSystem::doLogic(std::vector<Actor*> actors, int current) {

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	LabelComponent* label_comp = actors[current]->GetComponent<LabelComponent>();
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();

	char* s_copy = new char[label_comp->label_text.size()+1], *cuv;
	strcpy(s_copy, label_comp->label_text.c_str());
	
	cuv = strtok(s_copy, " ");

	int font_size = label_comp->font_size;
	int length = 0 , drop = font_size;

	while (cuv != NULL) {

		int new_lenght = MeasureText(cuv, font_size) + MeasureText(" ", font_size);

		if (button_poz->transform.translation.x + length + new_lenght >= GetScreenWidth())
		{
			length = 0;
			drop += font_size * 2;
		}
		
		DrawText(cuv, button_poz->transform.translation.x + 25 + length, button_poz->transform.translation.y + drop, label_comp->font_size, label_comp->text_color);
		
		length += new_lenght;
		
		cuv = strtok(NULL, " ");
	}


	//int size = MeasureText(label_comp->label_text.c_str(), label_comp->font_size);

	delete[] s_copy;
}
