#pragma once

#include "GameInfo.h"
#include "SingletonMacro.h"

/*
게임의 흐름을 구성하는 단계
1. 사용자의 입력
2. 입력받은 내용에 대해서 데이터 업데이트
   인공지능들의 데이터 업데이트
3. 업데이트된 다음 데이터를 토대로 충돌을 수행.
4. 출력이 되어야 하는 물체들을 판단.
5. 화면에 출력이 되어야 하는 물체들을 출력.
*/



// 윈도운 창을 생성하고 전체 게임을 관리하는 클래스이다.

class CGameManager
{ 
private:
	HINSTANCE	m_hInst;
	HWND		m_hWnd;
	HDC			m_hDC;
	
	
	class CTimer* m_Timer;
	float		m_FrameLimitTime;
	// class CPlayer* m_Player;

	 // RECT		m_TestRC;
	 // int			m_Dir;

	// 이 변수가 static 멤버변수로 설정된 이유는 wndProc static 멤버
	// 함수에서 이 변수를 윈도우가 종료될때 false로 마들어주기 위해서
	// static 멤버변수로 만들어주었다.
	static bool m_Loop;


public:
	bool Init(HINSTANCE hInst);
	int Run();

private:
	void Logic();
	void Input(float DeltaTime);
	bool Update(float DeltaTime);
	void Collision(float DeltaTime);
	void Render(float DeltaTime);
	
private:
	void Register();
	bool Create();

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParm, LPARAM lParam);

	DECLARE_SINGLE(CGameManager)
};

