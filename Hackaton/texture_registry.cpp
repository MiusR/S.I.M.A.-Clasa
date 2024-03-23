#include "texture_registry.h"

TextureRegistry* TextureRegistry::instancePtr = NULL;

void TextureRegistry::LoadImg(std::string path) {

	std::string a = path;

	Texture2D pot = LoadTexture(a.append(".png").c_str());

	this->textures[path.c_str()] = pot;
}

Texture2D TextureRegistry::GrabTexture(std::string path) {


	/// For some reason find has issues in comparing DONT KNOW WHY
	if (this->textures.find(path) == this->textures.end()) {
		TextureRegistry::getInstance()->LoadImg(path);
	}

	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return this->textures[path];
}