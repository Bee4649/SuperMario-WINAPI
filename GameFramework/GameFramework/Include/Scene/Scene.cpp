#include "Scene.h"
#include "../GameObject/GameObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::SetPlayer(CGameObject* Player)
{
	m_Player = Player;
}

bool CScene::Init()
{
    return true;
}

void CScene::Update(float DeltaTime)
{
	// 이렇게 꼭 연습하세요 제발....
	// std::list<CSharedPtr<class CGameObject>>::iterator;

	// auto : 선언과 동시에 무조건 대입을 해주어야 한다.
	// 대입된 타입으로 타입이 선언된다.
	auto iter = m_ObjList.begin();
	auto iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{ 
		if (!(*iter)->GetActive())
		{
			// 리스트에서 제거하는 순간 SharedPtr의 소멸자가 호출되어
			// 카운트가 감소한다.
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}
		else if(!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->Update(DeltaTime);
		
		++iter;

	}
}

void CScene::Render(HDC hDC, float DeltaTime)
{

	auto iter = m_ObjList.begin();
	auto iterEnd = m_ObjList.end();

	for (; iter != iterEnd;)
	{
		// GetActive 알아서 Scene에서 지우게 만들어 놓음.
		if (!(*iter)->GetActive())
		{
			// 리스트에서 제거하는 순간 SharedPtr의 소멸자가 호출되어
			// 카운트가 감소한다.
			iter = m_ObjList.erase(iter);
			iterEnd = m_ObjList.end();
			continue;
		}
		else if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->Render(hDC, DeltaTime);

		++iter;

	}
}