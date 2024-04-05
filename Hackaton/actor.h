#pragma once

#include <unordered_map>
#include <assert.h>
#include <typeinfo>
#include <iostream>
#include "component.h"
#include <vector>

class Actor{
    private:
    std::unordered_map<const char*, Component*> components;

    public:
    bool flagged = false;
    bool markDeletion = false;
    int systems = 0;

    template<typename T>
    void AddComponent(T* comp) {
        const char* component_Id = typeid(T).name();
        if (this->components.find(component_Id) != this->components.end()) {
            std::cout << "Error: Tried to register duplicate component!\n";
        }
        else {

            this->components[component_Id] = comp;

            flagged = true;
        }
    }

    std::vector<const char*> GetComponents();


    bool operator==(const Actor& actor) {
        return this == &actor;
    }
    
    // Using typename for easy search by passing <> param
    // Put this here to avoid compiler LNK2019 Error
   
    template<typename T> inline T* GetComponent() {
        const char* component_Id = typeid(T).name();

        if (this->components.find(component_Id) == this->components.end()) {
            std::cout << "Error: Component does not exist on this entity\n";
            return NULL;
        }

        return (T*) this->components[component_Id];
    }


    ~Actor(){
        for(auto it = this->components.begin(); it != this->components.end(); it++){
            delete it->second;
        }

        this->components.clear();
    }
};
