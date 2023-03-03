#pragma once

#include "../../GameInfo.h"

class CAnimationManager
{
	friend class CResourceManager;

private:
	CAnimationManager();
	~CAnimationManager();

private:
	std::unordered_map<std::string, CSharedPtr<class CAnimationSequence>>	m_mapSequence;


public:
	bool Init();

public:
	bool CreateAnimationSequence(const std::string& Name, class CTexture* Texture);
	bool AddAnimationFram(const std::string& Name, const Vector2& Start,
		const Vector2& End);
	bool AddAnimationFram(const std::string& Name, 
		float PosX, float PosY, float SizeX, float SizeY);


	class CAnimationSequence* FindAnimation(const std::string& Name);
	void RelaeseAnimation(const std::string& Name);



	

};

