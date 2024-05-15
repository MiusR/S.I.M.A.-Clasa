#pragma once
#include "app_state.h"
#include "system_manager.h"

class ContextState{
private: 
	AppState* currentstate;

    std::vector<AppState*> previous_states;

    ContextState() { currentstate = nullptr; }
    static ContextState* instancePtr;

public:
    bool exitWindow = false;

    ContextState(const ContextState& obj) = delete;

    static ContextState* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new ContextState();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

	void SetState(AppState* state1)
	{
        previous_states.push_back(currentstate);

		currentstate = state1;
	}

    void RegressState() {
        delete currentstate;

        currentstate = previous_states.at(previous_states.size() - 1);
        
        previous_states.erase(previous_states.end()-1);
    }

	void InitState(){ 
        SystemManager::getInstance()->CleanSystem();
    
        currentstate->InitState(); 
    }

    ~ContextState() {
        delete currentstate;

        for (int i = 0; i < previous_states.size(); i++)
            delete previous_states[i];
    }

};