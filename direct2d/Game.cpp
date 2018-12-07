#include "Game.h"
#include "SpriteSheet.h"
#include <ctime>


Game::Game(Graphics * gfx):
	gfx(gfx)
{

	//-------------------------
	sprites = new SpriteSheet(L"test.png", gfx, 0.4f);
	bunny = new Bunny(gfx);
	//-------------------------

}

Game::~Game()
{
	
	delete sprites;

}

void Game::Run()
{
	gfx->BeginDraw();
	UpdateModel();
	ComposeFrame();
	gfx->EndDraw();

}
//float a = 0.0f;

void Game::UpdateModel()
{

	if ((std::clock() - clock) / (double)CLOCKS_PER_SEC >= refreshRate)
	{
		if (GetAsyncKeyState(VK_SPACE))
			charge += 0.5;

		if (!GetAsyncKeyState(VK_SPACE) && charge != 0) {
			bunny->jump(charge);
			charge = 0;
		}

		bunny->updateBunny();

		/*
		ySpeed += 1.0f;
		y += ySpeed;
		if (y > 600) {
			y = 600;
			ySpeed = -30.0f;
		}
		if (GetAsyncKeyState(VK_CONTROL) & 1) {
			loading = !loading;
		}
		a += 0.2f;
		if (a >= 0.8f) a = 0;
		*/

		clock = std::clock();
	}
}

void Game::ComposeFrame()
{
	if ((std::clock() - clock) / (double)CLOCKS_PER_SEC >= refreshRate)
	{
		/*if (loading) {
			gfx->ClearScreen(0.0f, 0.0f, 0.5f);
			sprites->Draw(a);
			gfx->DrawCircle(400.0f, y, 50.0f, 255, 255, 0, 0.5);
			gfx->DrawCircle(600.0f, 600 - y, 50.0f, 255, 255, 0, 0.5);
			gfx->DrawCircle(200.0f, 600 - y, 50.0f, 255, 255, 0, 0.5);
		}
		else {
		*/
		//8.333333333333333333333
		//80*4
		gfx->ClearScreen(255, 255, 255);

		bunny->showBunny();
		gfx->DrawLine(0, 435, 800, 435);
	}


	//}
	
}
