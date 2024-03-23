#pragma once

#include "system.h"
#include "actor.h"
#include <assert.h>
#include <vector>
#include <iostream>
#include <cstring>

class SystemManager{

    private:
        std::vector<System*> systems;
        std::vector<Actor*> actors;

        void UpdateSystems(); 

        static SystemManager* instancePtr;

        SystemManager() {}

    public:

        SystemManager(const SystemManager& obj)= delete;

        static SystemManager* getInstance()
        {
            if (instancePtr == NULL)
            {
                instancePtr = new SystemManager();
                return instancePtr;
            }
            else
            {
                return instancePtr;
            }
        }

        void AddActor(Actor*);
        void RemoveActor(Actor*);
        void AddSystem(System*);
        void RemoveSystem(System*);

        void Update();
        void CleanSystem();

        ~SystemManager();

};
