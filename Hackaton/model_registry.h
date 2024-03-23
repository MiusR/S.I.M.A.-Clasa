#pragma once

#include <raylib.h>
#include <unordered_map>
#include <iostream>

class ModelRegistry {

private:
    std::unordered_map<std::string, Model> models;

    static ModelRegistry* instancePtr;

    void LoadMdl(std::string);

    ModelRegistry() {}

public:
    ModelRegistry(const ModelRegistry& obj) = delete;

    static ModelRegistry* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new ModelRegistry();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    Model GrabModel(std::string);
    Model GrabModel(int, float, float, float);

    ~ModelRegistry() {
        for (auto i = models.begin(); i != models.end(); i++)
            UnloadModel(i->second);
    }
};