#pragma once

#include "component.h"
#include <raylib.h>

class LabelComponent : public Component {
public:
	std::string label_text;

	int font_size;

	Color text_color;

	float scroll = 0;
	
	LabelComponent(std::string label_text, int font_size, Color color) {
		this->label_text = label_text;
		this->font_size = font_size;
		this->text_color = color;
	}
};