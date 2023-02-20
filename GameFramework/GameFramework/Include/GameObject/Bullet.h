#pragma once

#include "GameObject.h"

class CBullet :
    public CGameObject
{

	friend class CScene;

protected:
	CBullet();
	CBullet(const CBullet& Obj);
	virtual ~CBullet();

private:
	float	m_MoveSpeed;
	int		m_Dir;
	// ÃÑ¾Ë »ç°Å¸®
	float	m_Distance;

public:
	void SetDistance(float Dist)
	{
		m_Distance = Dist;
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void Render(HDC hDC, float DeltaTime);



};

