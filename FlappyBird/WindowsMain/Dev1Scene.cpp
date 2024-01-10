#include "stdafx.h"
#include "Dev1Scene.h"
#include "Actor.h"
#include "GdiplusSpriteActor.h"
#include "Player.h"
#include "BoxCollider.h"
#include "ItemBox.h"
#include "TrackingMonster.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CameraComponent.h"
#include "Button.h"
#include "TestPanel.h"
#include "CircleCollider.h"
#include "Wall.h"

void Dev1Scene::Init()
{
	LoadResource();


	Actor* playerActor = nullptr;
	{
		Player* player = new Player();
		player->SetPlayerInfo(Shape::MakeCenterRect(80, 80, 100, 100), 500);
		{
			//컴포넌트 추가
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 50, 60));
			collider->SetCollisionLayer(CollsionLayerType::CLT_OBJECT);
			player->AddComponent(collider);

			CameraComponent* cameraComponent = new CameraComponent();
			player->AddComponent(cameraComponent);
		}
		this->SpawnActor(player);
		playerActor = player;
	}


	SpriteActor* backgroundActor = new SpriteActor();
	backgroundActor->SetLayer(LayerType::BackGround);
	backgroundActor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_Background01"));
	this->SpawnActor(backgroundActor);



	vector<RECT> walls = GET_SINGLE(DataManager)->GetCollisionData();
	for (RECT rc : walls)
	{
		Wall* newWall = new Wall();
		newWall->SetWallInfo(rc);
		this->SpawnActor(newWall);

	}



	Super::Init();
}

void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	char str[250];
	sprintf_s(str, "Dev1Scene");
	TextOutA(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
}

void Dev1Scene::Update()
{
	Super::Update();

	if (Input->GetKeyDown('Z'))
	{
		cout << "Z 누름1" << endl;
	}

	if (Input->GetKeyDown('Z'))
	{
		cout << "Z 누름2" << endl;
	}

	if (Input->GetKey('Z'))
	{
		cout << "Z 누르는중" << endl;
	}

	if (Input->GetKeyUp('Z'))
	{
		cout << "Z Up" << endl;
	}


#ifdef CAMERA_TEMP
	{
		if (GET_SINGLE(KeyManager)->GetKey(VK_DOWN))
		{
			Vector2Int cameraPos = CurrentScene->GetCameraPos();
			cameraPos.y += 1;
			CurrentScene->SetCameraPos(cameraPos);
		}
		if (GET_SINGLE(KeyManager)->GetKey(VK_LEFT))
		{
			Vector2Int cameraPos = CurrentScene->GetCameraPos();
			cameraPos.x -= 1;
			CurrentScene->SetCameraPos(cameraPos);
		}
		if (GET_SINGLE(KeyManager)->GetKey(VK_UP))
		{
			Vector2Int cameraPos = CurrentScene->GetCameraPos();
			cameraPos.y -= 1;
			CurrentScene->SetCameraPos(cameraPos);
		}
		if (GET_SINGLE(KeyManager)->GetKey(VK_RIGHT))
		{
			Vector2Int cameraPos = CurrentScene->GetCameraPos();
			cameraPos.x += 1;
			CurrentScene->SetCameraPos(cameraPos);
		}
	}
#endif

}

void Dev1Scene::Release()
{
	Super::Release();

}

void Dev1Scene::LoadResource()
{

	GET_SINGLE(ResourceManager)->LoadTexture("T_Background01", "background1.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_Background01",
		GET_SINGLE(ResourceManager)->GetTexture("T_Background01"));


	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Down", "Character/PlayerDown.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Up", "Character/PlayerUp.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Right", "Character/PlayerRight.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture("T_Character_Left", "Character/PlayerLeft.bmp", RGB(128, 128, 128));


	//------------------------------------
	//		Move
	//------------------------------------
	//Move Down
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Down", info);
	}

	//Move Up
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Up", info);
	}

	//Move Left
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Left", info);
	}

	//Move Right
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 1;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Move_Right", info);
	}

	//------------------------------------
	//		Idle
	//------------------------------------
	//Idle Down 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Down", info);
	}


	//Idle Up 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Up", info);
	}


	//Idle Left 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Left", info);
	}

	//Idle Right 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 9;
		info.line = 0;
		info.loop = true;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Idle_Right", info);
	}


	//------------------------------------
	//		Attack
	//------------------------------------
	//Down 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 10;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Down", info);
	}


	//Up 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 10;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Up", info);
	}


	//Left 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 10;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Left", info);
	}

	//Right 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 10;
		info.line = 6;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Attack_Right", info);
	}

	//------------------------------------
	//		Hit
	//------------------------------------
	//Down 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 7;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Down", info);
	}


	//Up 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 7;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Up", info);
	}


	//Left 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Left");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 7;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Left", info);
	}

	//Right 
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Character_Right");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 7;
		info.line = 2;
		info.loop = false;
		info.size = { 200, 200 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Character_Hit_Right", info);
	}



	//Start Button
	GET_SINGLE(ResourceManager)->LoadTexture("T_StartButton", "Buttons/Start.bmp", RGB(255,0,210));
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Default",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 0, 0, 200, 200);
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Hover",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 200, 0, 200, 200);
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Pressed",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 400, 0, 200, 200);
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Disabled",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 600, 0, 200, 200);

}

void Dev1Scene::OnClick_ChangeScene()
{
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
}