#include "Monster.h"
#include "../Scene/Scene.h"
#include "Bullet.h"

CMonster::CMonster()
{
	SetTypeID<CMonster>();
}

CMonster::CMonster(const CMonster& Obj) :
	CCharacter(Obj)
{
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	m_MoveSpeed = 300.f;
	m_FireTime = 0.f;
	m_Dir = 1;


	SetPos(900.f, 100.f);
	SetSize(100.f, 100.f);
	SetPivot(0.5f, 0.5f);


	return true;
}

void CMonster::Update(float DeltaTime)
{
	m_Pos.y += m_Dir * m_MoveSpeed * DeltaTime;

	if (m_Pos.y + (1.f - m_Pivot.y) * m_Size.y >= 720.f)
	{
		m_Pos.y = 720.f - (1.f - m_Pivot.y) * m_Size.y;
		m_Dir = -1;
	}

	else if (m_Pos.y - m_Pivot.y * m_Size.y <= 0.f)
	{
		m_Pos.y = m_Pivot.y * m_Size.y;
		m_Dir = 1;
	}

	m_FireTime += DeltaTime;

	if (m_FireTime >= 0.5f)
	{
		m_FireTime -= 0.5f;

		CBullet* Bullet = m_Scene->CreateObject<CBullet>("Bullet");
	
		float BulletX = m_Pos.x - m_Pivot.x * m_Size.x -
			(1.f - Bullet->GetPivot().x) * Bullet->GetSize().x;

		Bullet->SetPos(BulletX, m_Pos.y);
	
	}
}

void CMonster::Render(HDC hDC, float DeltaTime)
{
	Vector2 RenderLT;

	RenderLT = m_Pos - m_Pivot * m_Size;

	Rectangle(hDC, (int)RenderLT.x, (int)RenderLT.y,
		(int)(RenderLT.x + m_Size.x), (int)(RenderLT.y + m_Size.y));


}
