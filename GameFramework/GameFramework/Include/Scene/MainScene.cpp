#include "MainScene.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{

	CreateObject<CPlayer>("Player");

	CreateObject<CMonster>("Monster");

	return true;
}

