#pragma once
#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "Font.h"



class TelaInicio : public Game {
private:
	Sprite * background = nullptr;
	Font   * text = nullptr;
	bool dw = false;
	int fm = 0;
	int mfm = 30;
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};