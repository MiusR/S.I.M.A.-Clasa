#pragma once
#include "learning_state.h"
#include "learning_physics_system.h"

class HyperbolicState : public LearningState {
public:
	void InitState() override;
};
