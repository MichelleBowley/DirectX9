#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	delete dx;
}

bool Game::Initialise(HWND hWindow)
{
	dx = new DirectX;
	dx->InitDx(hWindow, screenWidth, screenHeight, m_fullscreen);
	m_running = true;
	return false;
}

void Game::Run()
{
	Update(0);
	Draw(0);
}

void Game::Draw(float gameTime)
{
	dx->Clear(D3DCOLOR_XRGB(0, 100, 100));
	dx->Begin();
	dx->End();
	dx->PresentBB();
}

void Game::Update(float gameTime)
{
}
