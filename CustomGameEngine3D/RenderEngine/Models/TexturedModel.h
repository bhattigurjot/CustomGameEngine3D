#pragma once

#include "RawModel.h"
#include "../Textures/ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel _model, ModelTexture _texture);
	~TexturedModel();

	const RawModel& GetRawModel() const;
	const ModelTexture& GetTexture() const;

private:
	RawModel m_rawModel;
	ModelTexture m_texture;
};