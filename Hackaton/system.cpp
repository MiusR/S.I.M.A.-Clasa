#include "system.h"


 bool System::AddActor(Actor* actor){
    if(std::find(this->actors.begin(), this->actors.end(), actor) != this->actors.end()){
                std::cout<<"Error: Tried to add multiple instances of the same actor to the system!\n";
                return false;
            }

    actors.push_back(actor);

    std::cout << actors.size();

    return true;
 }

 bool System::RemoveActor(Actor* actor){
        
        auto it = std::find(this->actors.begin(), this->actors.end(), actor);

        if(it == this->actors.end()){
            std::cout<< "Error: Tried to remove instances of the non-existent actor from the system!\n";
            return false;
        }

        this->actors.erase(it);

        return true;
 }