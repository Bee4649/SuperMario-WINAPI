#pragma once
#include "Scene.h"
class CMainScene :
    public CScene
{
	friend class CSceneManager;


public:
	CMainScene();
	virtual ~CMainScene();

public:
	bool Init();
	
private:
	void CreateAnimationSequence();

};

