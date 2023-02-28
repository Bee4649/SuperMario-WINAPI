#pragma once

#include "../GameInfo.h"

class CSceneResource
{
	friend class CScene;

	

private:
	CSceneResource();
	~CSceneResource();


private:
	std::unordered_map<std::string, CSharedPtr<class CTexture>> m_mapTexture;


public: // =============== Texture ==================
	bool LoadTexture(const std::string& Name, const TCHAR* FileName,
		const std::string& PathName = TEXTURE_PATH);
	class CTexture* FindTexture(const std::string& Name);






};

