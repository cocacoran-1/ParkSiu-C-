#pragma once
class ResourceBase;
class Texture;
class Sprite;
class Flipbook;
struct FlipbookInfo;
class ResourceManager
{
public:
	DECLARE_SINGLE(ResourceManager);

public:
	void Init();
	void Release();

	Flipbook* GetFlipbook(const string& key);
	Flipbook* CreateFlipbook(const string& key, FlipbookInfo info);

	Sprite* GetSprite(const string& key);
	Sprite* CreateSprite(const string& key, Texture* texture, int x = 0, int y = 0, int cx = 0, int cy = 0);

	Texture* GetTexture(const string& key);
	Texture* LoadTexture(const string& key, const string& path, uint32 transparent = RGB(255, 0, 255));
private:
	string _resourcePath;
	map<string, ResourceBase*> _resources;
};

