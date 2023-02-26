#include "Player.h"
#include "..//Scene/Scene.h"
#include "Bullet.h"
#include "Tornado.h"
#include "AurelionSol.h"
#include "../Input.h"
#include "../GameManager.h"

CPlayer::CPlayer()
{
	SetTypeID<CPlayer>();
}

CPlayer::CPlayer(const CPlayer& Obj)	:
	CCharacter(Obj) 
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_GunAngle = 0.f;
	m_GunLength = 70.f;


	SetPos(100.f, 100.f);
	SetSize(100.f, 100.f);
	SetPivot(0.5f, 0.5f);

	m_SolAngle[0] = 0.f;
	m_SolAngle[1] = 120.f;
	m_SolAngle[2] = 240.f;

	m_SolLength = 100.f;
	m_SolRotationSpeed = 60.f;
	m_SolSkillOn = false;

	m_SolLengthMin = 100.f;
	m_SolLengthMax = 200.f;

	m_SolSkillTime = 0.f;
	m_SolSkillDir = 1.f;

	
	// 위성 객체 3개를 생성한다.
	for (int i = 0; i < 3; ++i)
	{
		m_Sol[i] = m_Scene->CreateObject<CAurelionSol>("Sol");
		
		Vector2 Pos;
		Pos.x = m_Pos.x + cosf(DegreeToRadian(m_SolAngle[i])) * m_SolLength;
		Pos.y = m_Pos.y + sinf(DegreeToRadian(m_SolAngle[i])) * m_SolLength;
	
		m_Sol[i]->SetPos(Pos);
	}

	CInput::GetInst()->AddBindFunction<CPlayer>("MoveFront",
		Input_Type::Push,this,&CPlayer::MoveFront);
	
	CInput::GetInst()->AddBindFunction<CPlayer>("MoveBack",
		Input_Type::Push,this,&CPlayer::MoveBack);
	
	CInput::GetInst()->AddBindFunction<CPlayer>("GunRotion",
		Input_Type::Push,this,&CPlayer::GunRotion);
	
	CInput::GetInst()->AddBindFunction<CPlayer>("GunRotionInv",
		Input_Type::Push,this,&CPlayer::GunRotionInv);

	return true;
} 

void CPlayer::Update(float DeltaTime)
{
	// VK_RETRUN : Enter키
	// VK_F1 : F1키
	// VK_LBUTTON : 왼쪽 마우스 버튼
	// GetAsyncKeyState : 키의 상태를 체크할 수 있다.
	// 반환값
	// 0 : 해당 키가 눌러진 상태가 아니다.
	// 0x8000 : 해당 키를 누르고 있는 상태이다.
	// 0x1 : 해당 키를 이전 프레임에 눌렀다.

	if (GetAsyncKeyState('A') & 0x8000)
	{
		// m_Pos.x -= 400.f * DeltaTime;
		m_GunAngle -= 180.f * DeltaTime;
	}

	// VK_RIGHT
	if (GetAsyncKeyState('D') & 0x8000)
	{
		// m_Pos.x += 400.f * DeltaTime;
		m_GunAngle += 180.f * DeltaTime;
	}

	m_GunPos.x = m_Pos.x + cosf(DegreeToRadian(m_GunAngle)) * m_GunLength;
	m_GunPos.y = m_Pos.y + sinf(DegreeToRadian(m_GunAngle)) * m_GunLength;

	if (GetAsyncKeyState('W') & 0x8000)
	{
		Vector2 Dir;
		Dir.x = cosf(DegreeToRadian(m_GunAngle));
		Dir.y = sinf(DegreeToRadian(m_GunAngle));


		m_Pos += Dir * 400.f * DeltaTime;
		// m_Pos.y -= 400.f * DeltaTime;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Vector2 Dir;
		Dir.x = cosf(DegreeToRadian(m_GunAngle));
		Dir.y = sinf(DegreeToRadian(m_GunAngle));


		m_Pos -= Dir * 400.f * DeltaTime;
		// m_Pos.y += 400.f * DeltaTime;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		CBullet* Bullet = m_Scene->CreateObject<CBullet>("Bullet");

		Bullet->SetAngle(m_GunAngle);

		Bullet->SetPos(m_GunPos);
	}

	if (GetAsyncKeyState('1') & 0x8000)
	{
		CTornado* Bullet = m_Scene->CreateObject<CTornado>("Tornado");

		Bullet->SetAngle(m_GunAngle);

		Bullet->SetPos(m_GunPos);
	}

	if (GetAsyncKeyState('2') & 0x8000)
	{
		m_SolSkillOn = true;

		m_SolRotationSpeed = 180.f;

		m_SolSkillTime = 0.f;
		m_SolSkillDir = 1.f;
	}
	
	if (m_SolSkillOn)
	{
		m_SolLength += m_SolSkillDir *(m_SolLengthMax - m_SolLengthMin) / 2.f * DeltaTime;
		
		if (m_SolLength >= m_SolLengthMax)
			m_SolLength = m_SolLengthMax;

		else if (m_SolLength <= m_SolLengthMin)
		{
			m_SolRotationSpeed = 60.f;
			m_SolLength = m_SolLengthMin;
			m_SolSkillOn = false;
		}

		m_SolSkillTime += DeltaTime;

		if (m_SolSkillTime >= 5.f)
		{
			m_SolSkillDir = -1.f;
		}
	
	}

	for (int i = 0; i < 3; ++i)
	{
		m_SolAngle[i] += m_SolRotationSpeed * DeltaTime;

		Vector2 Pos;
		Pos.x = m_Pos.x + cosf(DegreeToRadian(m_SolAngle[i])) * m_SolLength;
		Pos.y = m_Pos.y + sinf(DegreeToRadian(m_SolAngle[i])) * m_SolLength;

		m_Sol[i]->SetPos(Pos);
	}
}

void CPlayer::Render(HDC hDC, float DeltaTime)
{
	Vector2 RenderLT;

	RenderLT = m_Pos - m_Pivot * m_Size;

	Ellipse(hDC, (int)RenderLT.x, (int)RenderLT.y, 
		(int)(RenderLT.x + m_Size.x), (int)(RenderLT.y + m_Size.y));


	MoveToEx(hDC, (int)m_Pos.x, (int)m_Pos.y, nullptr);
	LineTo(hDC, (int)m_GunPos.x, (int)m_GunPos.y);
}

void CPlayer::MoveFront()
{ 
	Vector2 Dir;
	Dir.x = cosf(DegreeToRadian(m_GunAngle));
	Dir.y = sinf(DegreeToRadian(m_GunAngle));


	m_Pos += Dir * 400.f * DELTA_TIME;
}

void CPlayer::MoveBack()
{
}

void CPlayer::GunRotion()
{
}

void CPlayer::GunRotionInv()
{
}
