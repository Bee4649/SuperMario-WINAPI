#pragma once

#include "../GameInfo.h"


class CAnimation
{
	friend class CGameObject;

private:
	CAnimation();
	~CAnimation();

private:
	class CGameObject* m_Owner;
	class CSecene* m_Scene;
	std::unordered_map<std::string, class CAnimationInfo*>	m_mapAnimation;
	class CAnimation* m_CurrentAnimation; // ���� �������ִ� �ִϸ��̼� �ּ�








};

