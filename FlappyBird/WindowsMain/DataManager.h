#pragma once
#include <sqlite3.h>

struct CenterRect;
class DataManager
{
	DECLARE_SINGLE(DataManager);

private:
	sqlite3* _db;
	vector<RECT> _collisionDats;


public:
	void Init();
	void Release();


public:
	void SaveCollisionData(vector<RECT> rectVec);
	vector<RECT> GetCollisionData();
	void ClearCollisionData();
};

