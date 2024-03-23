#pragma once
#include "app_state.h"
#include "ui_util.h"
#include "simulation_state.h"
#include "context_state.h"
#include "button_menu_system.h"
#include "sprite_renderer_system.h"
#include "learning_state.h"

class StartMenuState : public AppState {
public:
	void InitState() override;
	
};