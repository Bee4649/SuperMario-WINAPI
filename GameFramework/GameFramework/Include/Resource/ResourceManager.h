#pragma once

#include "../GameInfo.h"
#include "../SingletonMacro.h"

class CResourceManager
{

private:
	class CTextureManager*	m_TextureManager;


public:
	bool Init();
	void Update();

public: // =============== Texture ==================
	bool LoadTexture(const std::string& Name, const TCHAR* FileName,
		const std::string& PathName = TEXTURE_PATH);
	class CTexture* FindTexture(const std::string& Name);

	void RelaeseTexture(const std::string& Name);
	
	DECLARE_SINGLE(CResourceManager)


};
