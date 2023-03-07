#include "MainScene.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"
#include "../GameObject/BackObj.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	CreateObject<CBackObj>("BackObj");

	CPlayer* Player = CreateObject<CPlayer>("Player");

	SetPlayer(Player);

	CreateObject<CMonster>("Monster");

	return true;
}

