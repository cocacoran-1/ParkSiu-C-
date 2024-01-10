#pragma once
struct Vector2Int;
struct Vector2
{
	float x, y;

	Vector2 operator-(const POINT pt);
	Vector2 operator-(const Vector2 other);
	Vector2 operator-(Vector2Int other);
	void operator-=(const Vector2 other);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);
	Vector2 operator*(const float other);
	void operator*=(const float other);
	Vector2 operator/(const float other);
	void operator/=(const float other);
	float LengthSquared();
	float Length();
	Vector2 Normalize();
	//내적으로는 주로 각도 계산할떄 많이쓰인다.
	//A Dot B = A.x * B.x + A.y * B.y
	//A Dot B = |A||B|cos(theta) 
	//  -> A B 둘다 길이가 1이면 cos(theta)가 나온다.
	//  -> cos(theta)는 두벡터가 이루는 각도를 나타낸다.
	//  -> 즉 두벡터가 이루는 각도를 구할때 내적을 사용한다.
	//  Tip1. 
	//   -  cos 그래프는
	//   -  0도 일때 1, 90도 일때 0, 180도 일때 -1 이다.
	//  Tip2. 
	//   - 내적으로 180가 넘는 각도는 존재할 수 없다.
	//  Tip3.
	//   - other 벡터가 내 뒤에 있는지 확인하려면
	//   - 내적이 0보다 작으면 내 뒤에 있다. (90도가 넘어갔음)
	float Dot(Vector2 other);
	// 2D는 외적을 할 수 없다.
	// 외적은 두 Vector 의 수직 Vector를 구할때 사용한다.

	//벡터의 반사
	// 1. 법선벡터와 내적을 구한다.
	// 2. 내적을 구한값에 2를 곱한다.
	// 3. 2에서 구한값을 원래 벡터에서 뺀다.
	/*
	Original Vector
		  ^
		  |
		  /
		 /
		/      Normal
	   /      /
	  +------->
	  \
	   \
		\
		 \  Reflected Vector
		  \
		   V

	*/
	Vector2 Reflect(Vector2 normal);
	float SignedAngle(Vector2 other);


	Vector2(float x, float y);
	Vector2();
	Vector2(Vector2Int vec);

	static Vector2 Zero()
	{
		return Vector2{ 0, 0 };
	}

	static Vector2 Up()
	{
		return Vector2{ 0, -1 };
	}

	static Vector2 Down()
	{
		return Vector2{ 0, 1 };
	}

	static Vector2 Right()
	{
		return Vector2{ 1, 0 };
	}

	static Vector2 Left()
	{
		return Vector2{ -1, 0 };
	}


	static Vector2 Lerp(Vector2 startValue, Vector2 endValue, float t)
	{
		Vector2 rv = startValue + (endValue - startValue) * t;
		return rv;
	}
};