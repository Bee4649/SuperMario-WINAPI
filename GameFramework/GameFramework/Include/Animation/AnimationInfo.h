#pragma once

#include "../GameInfo.h"

// Notify : �ִϸ��̼� ������ ������ Ư�� ������ �̺�Ʈ�� �߻��ϵ��� �ϴ� ��.
struct AnimationNotify
{
	int		Frame;
	bool	Call;
	std::function<void()>	Function;

	AnimationNotify() :
		Frame(0),
		Call(false)
	{
		 
	}

};


/*
�ִϸ��̼� �������� �ϳ� ������ �����鼭 �ش� �ִϸ��̼��� �� ���ʿ� ���ļ� �ѹ�
����� �Ұ�����, �� �ִϸ��̼��� ��� �ݺ��ؼ� ����ϴ��� ���� �����صδ� ��ü�̴�.
*/
class CAnimationInfo
{
	friend class CAnimation;


public:
	CAnimationInfo();
	~CAnimationInfo();

private:
	CSharedPtr<class CAnimationSequence>	m_Sequence;
	int		m_Frame;	// ���� �ִϸ��̼��� ���۵Ǵ� ������.
	float	m_Time;		// �ִϸ��̼� �������� ���������ֱ� ���� �ð���.
	float	m_FrmaeTime;	// �� �������� �����ϱ� ���� �ð�.
	float	m_PlayTime;		// ��� �ѹ��� ���۵Ǳ� ���� �ð�.
	float	m_PlayScale;	// ��� �ѹ��� ���۵Ǳ� ���� �ð�.
	bool	m_Loop;			// �ݺ��ؼ� ����ؾ� �ϴ��� ����.
	bool	m_Reverse;		// ����� ����.
	std::function<void()>	m_EndFunction;	// �ִϸ��̼��� ���������� ȣ�� �� �Լ� ���.
	std::vector<AnimationNotify>	m_vecNotify;

public:
	template <typename T>
	void SetEndFunction(int Frame, T* Obj, void(T::* Func)())
	{
		m_EndFunction = std::bind(Func, Obj);
	}




public:
	template <typename T>
	void AddNotify(int Frame, T* Obj, void(T::* Func)())
	{
		AnimationNotify* Notify = new AnimationNotify();

		Notify->Frame = Frame;
		Notify->Function = std::bind(Func, Obj);

		m_vecNotify.push_back(Notify);
	}







};
