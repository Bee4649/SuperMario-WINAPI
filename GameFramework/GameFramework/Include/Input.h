#pragma once

#include "GameInfo.h"
#include "SingletonMacro.h"
#include "Ref.h"



// 함수 포인터를 이용해서 키를 등록하는 시스템을 만들것이다.

struct KeyState
{
	unsigned char key;
	bool Down;	// 누르기 시작할때
	bool Push;	// 누르고 있을때
	bool Up;	// 누르고 있던 키가 올라올때

	KeyState() :
		key(0),
		Down(false),
		Push(false),
		Up(false)
	{}

};

struct BindFunction
{
	void* Obj;
	std::function<void()>	func;

	BindFunction() :
		Obj(nullptr)
	{

	}
};

struct BindKey
{
	// 이름
	std::string Name;
	// 어떤 키를 사용하는지.
	KeyState* key;
	bool Ctrl;
	bool Alt;
	bool Shift;

	std::vector<BindFunction*>	vecFunction;
	
	BindKey() :
		key(nullptr),
		Ctrl(false),
		Alt(false),
		Shift(false)
	{}

};


class CInput
{

private:
	// unorderd_map 같은 경우 키 중복이 전혀 안된다.
	// 키 중복하려면 multimap 이용해야 한다.

	std::unordered_map<unsigned char, KeyState*>	m_mapKeyState;
	std::unordered_map<std::string, BindKey*>		m_mapBindKey;

public:
	bool Init();
	void Update(float DeltaTime);

private:
	KeyState* FindKeyState(unsigned char Key);
	BindKey* FindBindKey(const std::string& Name);


public:
	bool AddBindKey(const std::string& Name, unsigned char Key);

	DECLARE_SINGLE(CInput)

};

