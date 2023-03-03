#include "ResourceManager.h"
#include "Texture/TextureManager.h"
#include "Animation/AnimationManager.h"



DEFINITION_SINGLE(CResourceManager)

CResourceManager::CResourceManager()
{
	
	m_TextureManager = new CTextureManager;

	m_TextureManager->Init();

	m_AnimationManager = new CAnimationManager;

	m_AnimationManager->Init();

}

CResourceManager::~CResourceManager()
{
	SAFE_DELETE(m_AnimationManager);
	SAFE_DELETE(m_TextureManager);
	
}

bool CResourceManager::Init()
{
	LoadTexture("Player", TEXT("koopa4.bmp"));
	
	

		return true;
}

void CResourceManager::Update()
{
}

bool CResourceManager::LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	return m_TextureManager->LoadTexture(Name, FileName, PathName);
}

bool CResourceManager::LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath)
{
	return m_TextureManager->LoadTextureFullPath(Name, FullPath);
}

#ifdef UNICODE

bool CResourceManager::LoadTexture(const std::string& Name,
	const std::vector<std::wstring>& vecFileName, const std::string& PathName)
{
	return m_TextureManager->LoadTexture(Name, vecFileName, PathName);
}

bool CResourceManager::LoadTextureFullPath(const std::string& Name,
	const std::vector<std::wstring>& vecFullPath)
{
	return m_TextureManager->LoadTextureFullPath(Name, vecFullPath);
}

#else

bool CResourceManager::LoadTexture(const std::string& Name,
	const std::vector<std::string>& vecFileName, const std::string& PathName)
{
	return m_TextureManager->LoadTexture(Name, vecFileName, PathName);
}

bool CResourceManager::LoadTextureFullPath(const std::string& Name,
	const std::vector<std::string>& vecFullPath)
{
	return m_TextureManager->LoadTextureFullPath(Name, vecFullPath);
}

#endif


bool CResourceManager::SetColorKey(const std::string& Name, unsigned char r, unsigned char g, unsigned char b, int Index)
{
	return m_TextureManager->SetColorKey(Name, r, g, b, Index);
}

bool CResourceManager::SetColorKeyAll(const std::string& Name, unsigned char r, unsigned char g, unsigned char b)
{
	return m_TextureManager->SetColorKeyAll(Name, r, g, b);
}

CTexture* CResourceManager::FindTexture(const std::string& Name)
{
	return m_TextureManager-> FindTexture(Name);
}

void CResourceManager::RelaeseTexture(const std::string& Name)
{
	m_TextureManager->RelaeseTexture(Name);

}
