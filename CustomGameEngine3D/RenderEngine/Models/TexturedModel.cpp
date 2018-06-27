#include "TexturedModel.h"

TexturedModel::TexturedModel(RawModel _model, ModelTexture _texture):
	m_rawModel(_model),
	m_texture(_texture)
{

}

TexturedModel::~TexturedModel()
{

}

const RawModel& TexturedModel::GetRawModel() const
{
	return m_rawModel;
}

const ModelTexture& TexturedModel::GetTexture() const
{
	return m_texture;
}
