#include "Bullet.h"

CBullet::CBullet()
{
	SetTypeID<CBullet>();
}

CBullet::CBullet(const CBullet& Obj) :
	CGameObject(Obj),
	m_MoveSpeed(Obj.m_MoveSpeed),
	m_Dir(Obj.m_Dir),
	m_Distance(Obj.m_Distance)
{
}

CBullet::~CBullet()
{
}

bool CBullet::Init()
{
	m_MoveSpeed = 700.f;
	m_Distance = 600.f;
	m_Dir = -1;


	SetPos(900.f, 100.f);
	SetSize(50.f, 50.f);
	SetPivot(0.5f, 0.5f);


	return true;
}

void CBullet::Update(float DeltaTime)
{
	m_Pos.x += m_Dir * m_MoveSpeed * DeltaTime;

	
}

void CBullet::Render(HDC hDC, float DeltaTime)
{
	Vector2 RenderLT;

	RenderLT = m_Pos - m_Pivot * m_Size;

	Ellipse(hDC, (int)RenderLT.x, (int)RenderLT.y,
		(int)(RenderLT.x + m_Size.x), (int)(RenderLT.y + m_Size.y));


}
