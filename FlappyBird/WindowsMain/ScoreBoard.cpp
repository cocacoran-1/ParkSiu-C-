#include "stdafx.h"
#include "ScoreBoard.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "ScoreScene.h"
#include "FlappyBirdInGameScene.h"


void ScoreBoard::Init()
{
	Super::Init();


	GET_SINGLE(ResourceManager)->LoadTexture("T_Score", "FlappyBird/image/score.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_Score",
		GET_SINGLE(ResourceManager)->GetTexture("T_Score"));

	SpriteActor* actor = new SpriteActor();
	Sprite* sprite = (GET_SINGLE(ResourceManager)->GetSprite("S_Score"));
	actor->SetLayer(LayerType::BackGround);
	actor->SetBody(CenterRect::FromRect(
		Shape::MakeRect(
			0,
			0,
			1200,
			915
		)));
	actor->SetSprite(sprite);
	_sprites.push_back(actor);


	int score =500;
	_score = score;

	int number = 0;
	while ( score != 0 )
	{
		score /= 10;
		number++;
	}

	score = _score;
	vector<int> digits;
	
	for ( int i = 0; i < number; i++ )
	{
		digits.push_back(score % 10);
		score /= 10;
	}
	if ( number < 4 )
	{
		int count = 4 - number;
		for ( int i = 0; i < count; i++ )
		{
			digits.push_back(0);
		}

	}

	GET_SINGLE(ResourceManager)->LoadTexture("T_number_default", "FlappyBird/image/number.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Zero",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 0, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_One",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 100, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Two",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 200, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Three",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 300, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Four",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 400, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Five",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 500, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Six",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 600, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Seven",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 700, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Eight",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 800, 0, 100, 196);
	GET_SINGLE(ResourceManager)->CreateSprite("S_number_Nine",
		GET_SINGLE(ResourceManager)->GetTexture("T_number_default"), 900, 0, 100, 196);

	for ( int i = 0; i < digits.size(); i++ )
	{
		SpriteActor* actor = new SpriteActor();
		Sprite* sprite =nullptr;
		actor->SetLayer(LayerType::BackGround);
		actor->SetBody(CenterRect::FromRect(
			Shape::MakeRect(
				((WIN_SIZE_WIDTH/2) + 200) - 200 * i, 
				WIN_SIZE_HEIGHT/2,
				100, 
				196
			)));
		switch ( digits[i] )
		{
			case 0:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Zero"));
				break;
			case 1:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_One"));
				break;
			case 2:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Two"));
				break;
			case 3:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Three"));
				break;
			case 4:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Four"));
				break;
			case 5:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Five"));
				break;
			case 6:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Six"));
				break;
			case 7:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Seven"));
				break;
			case 8:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Eight"));
				break;
			case 9:
				actor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_number_Nine"));
				break;
		}


		_sprites.push_back(actor);
	}

}
void ScoreBoard::Render(HDC hdc)
{
	for ( int i = 0; i < _sprites.size(); i++ )
	{
		_sprites[i]->Render(hdc);
	}


	Super::Render(hdc);

}
void ScoreBoard::Update()
{
	static float currentTime = 0;

	currentTime += DeltaTime;
	if ( currentTime >= 3.0f )
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::StartScene);
		currentTime = 0;
	}

	Super::Update();
}
void ScoreBoard::Release()
{
	Super::Release();
}


