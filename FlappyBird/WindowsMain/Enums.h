#pragma once

// 그냥 enum과 거의 완전 동일
enum class SceneType
{
	None,
	Dev1Scene,
	Dev2Scene,
	MapToolScene,
	FlappyBirdInGameScene,
	StartScene,
	ScoreScene,
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

enum class LayerType
{
	BackGround,
	Object,


	End
};

enum CollsionLayerType : uint8
{
	CLT_OBJECT,
	CLT_WALL,

	//FLAPPYBIRD
	CLT_BIRD,
	CLT_OBSTACLE,
	CLT_SCORE,
	CLT_LAND
};

enum eCounter
{
	LAYER_MAXCOUNT = static_cast<int>(LayerType::End)
};

enum class ItemBoxType
{
	None,
	HpItemBox,
	MissileItemBox,
};