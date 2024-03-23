#include "text_input_system.h"


void TextInputSystem::doLogic(std::vector<Actor*> actors, int current) {
    TextuInputComponent* input = actors[current]->GetComponent<TextuInputComponent>();

    if (input->mark_writing) {

        MenuButtonComponent* menuButton = actors[current]->GetComponent<MenuButtonComponent>();

        for (int i = 0; i < actors.size(); i++) {
            if (i == current)
                continue;
            TextuInputComponent* tmp = actors[i]->GetComponent<TextuInputComponent>();
            tmp->mark_writing = false;
            actors[i]->GetComponent<MenuButtonComponent>()->text = tmp->org;
        }

        int a = GetKeyPressed();

        if (a == KEY_C) {
            input->mark_writing = false;
            menuButton->text = input->org;
            return;
        }

        if (menuButton->text.size() > 0)
            input->onEnter(menuButton->text);

        if (a == KEY_BACKSPACE) {
            menuButton->text = input->org;
        }
        else if (a != 0)
            menuButton->text += a;
    }
}