#pragma once

#define DECLARE_SINGLE(ClassName)		\
private:								\
	ClassName() {}						\
	~ClassName() {}						\
public:									\
	static ClassName* GetInstance()		\
	{									\
		static ClassName _instance;		\
		return &_instance;				\
	}


#define GET_SINGLE(ClassName)	ClassName::GetInstance()

#define DeltaTime	GET_SINGLE(TimeManager)->GetDeltaTime()
#define CurrentScene GET_SINGLE(SceneManager)->GetCurrentScene()
#define Input (GET_SINGLE(KeyManager))

#define Alert(title, message) MessageBox(_hWnd, title, message, NULL)

//부동소수점 오차
#define EPSILON 1e-6f // (0.000001)
#define PI 3.14159265358979f //180도
#define Deg2Rad(deg) (0.0174533 * deg)
#define Rad2Deg(rad) (57.2958 * rad)

