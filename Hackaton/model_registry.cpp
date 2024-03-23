#include "model_registry.h"

ModelRegistry* ModelRegistry::instancePtr = NULL;

void ModelRegistry::LoadMdl(std::string path) {

	Model pot = LoadModel(path.c_str());

	models[path] = pot;
}

Model ModelRegistry::GrabModel(std::string path) {

	if (models.find(path) == models.end()) {
		ModelRegistry::getInstance()->LoadMdl(path);
	}
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return models[path];
}

Model ModelRegistry::GrabModel(int type, float a, float b, float c) {

	/*std::string shape;

	Mesh mesh;

	switch (type) {
		case 1:
		default:
			shape = "sphere";
			mesh = GenMeshSphere(a, b, c);
			break;
	}

	if (models.find(shape.c_str()) == models.end()) {
		models[shape.c_str()] = LoadModelFromMesh(GenMeshSphere(a, b, c));
	}*/
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return LoadModelFromMesh(GenMeshSphere(a, b, c));
}