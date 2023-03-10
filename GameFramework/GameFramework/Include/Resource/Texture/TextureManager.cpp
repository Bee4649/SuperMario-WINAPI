#include "TextureManager.h"
#include "Texture.h"



CTextureManager::CTextureManager()
{

}
CTextureManager::~CTextureManager()
{

}

bool CTextureManager::Init()
{
	return true;
}

bool CTextureManager::LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	// 같은 이름으로 저장된게 있다면 잘못된것이다.
	CTexture* Texture = FindTexture(Name);

	if (Texture)
		return true;

	Texture = new CTexture;

	if (!Texture->LoadTexture(FileName, PathName))
	{
		SAFE_RELEASE(Texture);
		return false;
	}

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

bool CTextureManager::LoadTextureFullPath(const std::string& Name, 
	const TCHAR* FullPath)
{
	// 같은 이름으로 저장된게 있다면 잘못된것이다.
	CTexture* Texture = FindTexture(Name);

	if (Texture)
		return true;

	Texture = new CTexture;

	if (!Texture->LoadTextureFullPath(FullPath))
	{
		SAFE_RELEASE(Texture);
		return false;
	}

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}
#ifdef UNICODE


bool CTextureManager::LoadTexture(const std::string& Name, 
	const std::vector<std::wstring>& vecFileName, const std::string& PathName)
{
	// 같은 이름으로 저장된게 있다면 잘못된것이다.
	CTexture* Texture = FindTexture(Name);

	if (Texture)
		return true;

	Texture = new CTexture;

	if (!Texture->LoadTexture(vecFileName, PathName))
	{
		SAFE_RELEASE(Texture);
		return false;
	}

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

bool CTextureManager::LoadTextureFullPath(const std::string& Name,
	const std::vector<std::wstring>& vecFullPath)
{
	// 같은 이름으로 저장된게 있다면 잘못된것이다.
	CTexture* Texture = FindTexture(Name);

	if (Texture)
		return true;

	Texture = new CTexture;

	if (!Texture->LoadTextureFullPath(vecFullPath))
	{
		SAFE_RELEASE(Texture);
		return false;
	}

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

#else
bool CTextureManager::LoadTexture(const std::string& Name,
	const std::vector<std::string>& vecFileName, const std::string& PathName)
{
	// 같은 이름으로 저장된게 있다면 잘못된것이다.
	CTexture* Texture = FindTexture(Name);

	if (Texture)
		return true;

	Texture = new CTexture;

	if (!Texture->LoadTexture(vecFileName, PathName))
	{
		SAFE_RELEASE(Texture);
		return false;
	}

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}


bool CTextureManager::LoadTextureFullPath(const std::string& Name,
	const std::vector<std::string>& vecFullPath)
{
	// 같은 이름으로 저장된게 있다면 잘못된것이다.
	CTexture* Texture = FindTexture(Name);

	if (Texture)
		return true;

	Texture = new CTexture;

	if (!Texture->LoadTextureFullPath(vecFullPath))
	{
		SAFE_RELEASE(Texture);
		return false;
	}

	m_mapTexture.insert(std::make_pair(Name, Texture));

	return true;
}

#endif // UNICODE


bool CTextureManager::SetColorKey(const std::string& Name, unsigned char r, unsigned char g, unsigned char b, int Index)
{
	CTexture* Texture = FindTexture(Name);

	if (!Texture)
		return false;

	Texture->SetColorKey(r, g, b, Index);

	return true;
}

bool CTextureManager::SetColorKeyAll(const std::string& Name, unsigned char r, unsigned char g, unsigned char b)
{
	CTexture* Texture = FindTexture(Name);

	if (!Texture)
		return false;

	Texture->SetColorKeyAll(r, g, b);

	return true;
}

CTexture* CTextureManager::FindTexture(const std::string& Name)
{

	auto	iter = m_mapTexture.find(Name);

	if (iter == m_mapTexture.end())
		return nullptr;

	return iter->second;

}

void CTextureManager::RelaeseTexture(const std::string& Name)
{
	auto	iter = m_mapTexture.find(Name);

	if (iter == m_mapTexture.end())
		return;
		
	if (iter->second->GetRefCount() == 1)
		m_mapTexture.erase(iter);

}




