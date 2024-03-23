#include "actor.h"

std::vector<const char*> Actor::GetComponents(){
    std::vector<const char*> ret;
    for(auto key : components){
        ret.push_back(key.first);
    }
    return ret;
}