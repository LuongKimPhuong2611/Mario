//#include "Entity.h"
//
//class Camera {
//private:
//	float x, y;
//	Entity* player;
//public:
//	void SetX(float x) { this->x = x; }
//	void SetY(float y) { this->y = y; }
//	void SetTarget(Entity* player) { this->player = player; }
//	Entity* GetPlayer() { return this->player; }
//	void Update();
//	int GetScreenWidth() { return SCREEN_WIDTH; }
//	int GetScreenHeight() { return SCREEN_HEIGHT; }
//};
#pragma once
#include <Windows.h>
#include "define.h"
class Camera
{
	static Camera* instance;
	float camx, camy;

	Camera();
	~Camera();
public:

	static Camera* GetInstance();

	void SetCamPos(float x, float y) { camx = x; camy = y; }
	float GetCamx() { return camx; }
	float GetCamy() { return camy; }
	void GetCenter(int& _x, int& _y);

};

