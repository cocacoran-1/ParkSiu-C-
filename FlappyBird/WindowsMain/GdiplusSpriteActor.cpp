#include "stdafx.h"
#include "GdiplusSpriteActor.h"
#include "Scene.h"

void GdiplusSpriteActor::Init()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Init();
}
void GdiplusSpriteActor::Render(HDC hdc)
{
	if (_isActive == false) return;

	static Gdiplus::Graphics* g = nullptr;
	static HDC lastHdc = {};

	if (lastHdc != hdc)
	{
		//�̹� Graphics�� �����ϸ�, �����ְ� �ٽø����.
		SAFE_DELETE(g);
		g = new Gdiplus::Graphics(hdc);
		g->SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		lastHdc = hdc;
	}

	if (_sprite)
	{
		//Gdiplus ���� �׸��°� �ǰ� ���ſ���. (PNG, JPG, BMP, GIF)
		//���ſ� �����ӿ�ũ
		// CPU �׸����ִµ�
		//PNG ==> GPU (�׷���ī��) (X)
		// => DirectX (2D)
		
		//�ذ��� :
		// 1. DirectX �� �����Ѵ�. (Gdiplus�� ������� �ʴ´�.)
		// [v]2. 1024*1024 => �츮�� ����ŭ���� ���δ�.
		// [v]3. gdiplus�� ��ü �ӵ��� �ɼ��� Ų��. 
		//  - g.SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		// [v]4. �ڵ���ü ����ȭ (Graphics�� �������� ������ٰ�, ����)
		// 5. �ڡ� ��Ӻ��� BitBlt�� ����� �׸���
		//  ==> ��Ӻ���� PNG�¾ȵſ�. (BMP�ۿ� ���Ұ���) (BMP�� �̹����� ������ �Ұ�����)

		Vector2Int cameraPosition = CurrentScene->GetCameraPos();
		Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

		CenterRect renderRect = _body;
		renderRect.x -= (cameraPosition.x - screenSizeHalf.x);
		renderRect.y -= (cameraPosition.y - screenSizeHalf.x);

		if (false == (abs(_roationRadian) < EPSILON))
		{
			{
				Gdiplus::Matrix matrix;
				matrix.RotateAt(Rad2Deg(_roationRadian), Gdiplus::PointF(renderRect.x, renderRect.y));
				g->SetTransform(&matrix);
			}
			g->DrawImage(_sprite, renderRect.ToGdiRect());
			{
				Gdiplus::Matrix matrix;
				g->SetTransform(&matrix);
			}
		}
		else
		{
			g->DrawImage(_sprite, renderRect.ToGdiRect());
		}

	}

	//�θ�Ŭ���� �⺻���� ó��
	Super::Render(hdc);
}
void GdiplusSpriteActor::Update()
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Update();

}
void GdiplusSpriteActor::Release() 
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Release();

}

void GdiplusSpriteActor::SetSprite(const WCHAR* filePath, CenterRect body)
{
	_sprite = Gdiplus::Image::FromFile(filePath);
	_body = body;
}