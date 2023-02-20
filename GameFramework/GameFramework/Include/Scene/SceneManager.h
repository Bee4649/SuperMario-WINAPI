#pragma once

#include "../GameInfo.h"
#include "../SingletonMacro.h"

class CSceneManager
{
private:
	class CScene* m_Scene;

public:
	bool Init();
	// 반환 타입을 bool로 하는 이유는 Scene이 교체되는지 아닌지를
	// 판단하기 위해서이다.
	bool Update(float DeltaTime);
	void Render(HDC hDC, float DeltaTime);


public:
	template<typename T>
	bool CreateScene()
	{
		T* Scene = new T;

		if (!Scene->Init())
		{
			SAFE_DELETE(Scene);
			return false;
		}
		if (!m_Scene)
			m_Scene = (CScene*)Scene;
		
		return true;
	}

	DECLARE_SINGLE(CSceneManager)


};

