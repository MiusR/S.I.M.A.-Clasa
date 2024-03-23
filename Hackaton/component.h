#pragma once

// Marker class

#include <typeinfo>
#include <iostream>

class Component{
    public:
        bool active = true;

        bool operator==(Component* comp) {
            std::cout << typeid(this).name() << " " << typeid(&comp).name() << "\n";
            return typeid(this).name() == typeid(&comp).name();
        }
}; 
