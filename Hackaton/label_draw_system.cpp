#include "label_draw_system.h"



void LabelDrawSystem::doLogic(std::vector<Actor*> actors, int current) {

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	LabelComponent* label_comp = actors[current]->GetComponent<LabelComponent>();
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();

	label_comp->scroll += GetMouseWheelMove() * 20;

	char* s_copy = new char[strlen(label_comp->label_text.c_str())+10], *cuv;
	strcpy(s_copy, label_comp->label_text.c_str());
	
	if (label_comp->scroll < 0)
		label_comp->scroll = 0;


	cuv = strtok(s_copy, " ");

	int font_size = label_comp->font_size;
	int length = 0;
	float drop = font_size - label_comp->scroll;
	
	const int new_line = MeasureText("\n", font_size);
	const int space = MeasureText(" ", font_size);

	while (cuv != NULL) {

		int new_lenght = MeasureText(cuv, font_size) + space;

		int i = 0, k = 0;

		char* cuv_copy = new char[strlen(cuv)+10];
		while (i < strlen(cuv)) {
			if (i+1 < strlen(cuv) && cuv[i] == '\\' && cuv[i + 1] == 'n') {
				drop += font_size * 3;
				length = 0;
				i += 2;
				//strcpy(cuv + i, cuv + i + 2); // FRAGMENTATION ERROR
			}
			else {
				cuv_copy[k] = cuv[i];
				k++;
			}
			i++;
		}

		cuv_copy[k] = '\0';

		if (button_poz->transform.translation.x + length + new_lenght + 2 * space>= GetScreenWidth())
		{
			length = 0;
			drop += font_size * 2;

		}
		
		DrawText(cuv_copy, button_poz->transform.translation.x + 25 + length, button_poz->transform.translation.y + drop, label_comp->font_size, label_comp->text_color);
		
		delete[] cuv_copy;

		length += new_lenght;
		
		cuv = strtok(NULL, " ");
	}

	if (label_comp->scroll > drop)
		label_comp->scroll = drop;
	//int size = MeasureText(label_comp->label_text.c_str(), label_comp->font_size);

	delete[] s_copy;
}
