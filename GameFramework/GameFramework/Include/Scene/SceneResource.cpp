#include "SceneResource.h"
#include "../Resource/Texture/Texture.h"

CSceneResource::CSceneResource()
{
}

CSceneResource::~CSceneResource()
{
}

bool CSceneResource::LoadTexture(const std::string& Name, const TCHAR* FileName,
	const std::string& PathName)
{


	return true;
}

CTexture* CSceneResource::FindTexture(const std::string& Name)
{
	auto iter = m_mapTexture.find(Name);
	
	if(iter == m_mapTexture.end())
		return nullptr;

	return iter->second;
}
