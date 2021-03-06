#pragma once
#include <d3dx9.h>
#include "KeyboardHandler.h"
#include "define.h"
#include "Entity.h"

class Scene
{
protected:
	KeyboardHandler* keyHandler;
	LPCWSTR sceneFilePath;
	LPCWSTR texturesFilePath;
public:
	Scene();

	KeyboardHandler* GetKeyEventHandler() { return keyHandler; }
	virtual void LoadSceneObjects() = 0;
	virtual void Unload() = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
};
typedef Scene* LPSCENE;


class ScenceKeyHandler : public KeyboardHandler
{
protected:
	Scene* scence;

public:
	virtual void KeyState(BYTE* states) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
	ScenceKeyHandler(Scene* s) :KeyboardHandler() { scence = s; }
};