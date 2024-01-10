#include "stdafx.h"
#include "MapToolScene.h"
#include "MapToolPanel.h"
#include "SpriteActor.h"

void MapToolScene::Init()
{
	Super::Init();
	GET_SINGLE(ResourceManager)->LoadTexture("T_SuperMarioBackground01", "Background/backround_supermario.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_SuperMarioBackground01",
		GET_SINGLE(ResourceManager)->GetTexture("T_SuperMarioBackground01"));

	{
		SpriteActor* background = new SpriteActor();
		background->SetLayer(LayerType::BackGround);
		background->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_SuperMarioBackground01"));
		background->SetBody(CenterRect::FromRect(RECT(0, 0, 2624, 240)));
		this->SpawnActor(background);

	}

	this->SetCameraPos(Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2));


	{
		Panel* panel = new MapToolPanel();
		panel->Init();
		_uis.push_back(panel);
	}

	_state = MapToolState::IDLE;


	vector<RECT> collisions = GET_SINGLE(DataManager)->GetCollisionData();

	for (RECT collision : collisions)
	{
		_wallVec.push_back(collision);
	}

}
void MapToolScene::Render(HDC hdc)
{
	Super::Render(hdc);

	for (RECT rc : _wallVec)
	{
		Draw::Rect(hdc, rc, this->GetCameraPos());
	}

	Draw::Rect(hdc, _currentRect, this->GetCameraPos());



	switch (_state)
	{
	case MapToolState::IDLE:
		RenderIdle(hdc);
		break;
	case MapToolState::WALL_MAKE:
		RenderWallMake(hdc);
		break;
	default:
		break;
	}


	char str[250];
	sprintf_s(str, "MapToolScene");
	TextOutA(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
}
void MapToolScene::Update()
{
	Super::Update();

	UpdateInput();

	switch (_state)
	{
	case MapToolState::IDLE:
		UpdateIdle();
		break;
	case MapToolState::WALL_MAKE:
		UpdateWallMake();
		break;
	default:
		break;
	}
}
void MapToolScene::Release()
{
	Super::Release();


}

void MapToolScene::UpdateInput()
{
	if (GET_SINGLE(KeyManager)->GetKey(VK_LEFT))
	{
		_cameraPosition.x -= 1;
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_RIGHT))
	{
		_cameraPosition.x += 1;
	}
}

void MapToolScene::UpdateIdle()
{
	if (GET_SINGLE(KeyManager)->GetKeyDown('Q'))
	{
		_state = MapToolState::WALL_MAKE;
		_currentRect.left = _mousePos.x + this->GetCameraPos().x - WIN_SIZE_WIDTH / 2;
		_currentRect.top = _mousePos.y + this->GetCameraPos().y - WIN_SIZE_HEIGHT / 2;
	}
}
void MapToolScene::UpdateWallMake()
{
	_currentRect.right = _mousePos.x + this->GetCameraPos().x - WIN_SIZE_WIDTH / 2;
	_currentRect.bottom = _mousePos.y + this->GetCameraPos().y - WIN_SIZE_HEIGHT / 2;

	if (GET_SINGLE(KeyManager)->GetKeyDown('Q'))
	{
		_state = MapToolState::IDLE;

		//_currentRect를 정상값으로 바꾼다.
		Shape::ChangeToNormalValue(_currentRect);

		_wallVec.push_back(_currentRect);
		_currentRect = {};
	}
}


void MapToolScene::RenderIdle(HDC hdc)
{
	char str[250];
	sprintf_s(str, "Q버튼을 눌러서 벽을 생성해주세요.");
	TextOutA(hdc, WIN_SIZE_WIDTH - 300, 0, str, strlen(str));
}
void MapToolScene::RenderWallMake(HDC hdc)
{
	char str[250];
	sprintf_s(str, "Q버튼을 눌러서 벽을 완성해주세요.");
	TextOutA(hdc, WIN_SIZE_WIDTH - 300, 0, str, strlen(str));
}

void MapToolScene::Save()
{
	GET_SINGLE(DataManager)->ClearCollisionData();
	GET_SINGLE(DataManager)->SaveCollisionData(_wallVec);
}

void MapToolScene::Revert()
{
	if (0 < _wallVec.size())
	{
		_wallVec.pop_back();
	}
}

