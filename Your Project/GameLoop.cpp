#include "GameLoop.h"
#include <ctime>
using namespace std;
int RorySucks = 0;
int FPS = 255;
int speed = 100;
int ax = 750;
int ay = 400;
SDL_Keycode key;
void GameLoop::Loop()
{
	
	
	while (m_bRunning)
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed


			while (SDL_PollEvent(&sdlEvent))
			{
				// Calls the redefined event function for the EventHandler class
				// Refer to its header file and cpp for more information on what each inherited function is capable of
				// and its syntax
				OnEvent(sdlEvent);
			}
			Update();
			LateUpdate();
			
			Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 173,155,34,255 });
			Graphics::DrawRect({ 100,100 }, { 500,500 }, { 740,131,189,58 });

			Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

			Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
			Graphics::DrawCircle({ ax, ay }, 200, FPS, { 0,255,255, FPS });
			Graphics::DrawCircle({ FPS, 450 }, 50, 253, { 164,0,96,161 });

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}

int ex = 200;
void GameLoop::Update()
{
	RorySucks += 1;
	switch (key)
	{
	case SDLK_UP:
		ay -= speed;
		break;
	case SDLK_DOWN:
		ay += speed;
		break;
	case SDLK_LEFT:
		ax -= speed;
		break;
	case SDLK_RIGHT:
		ax += speed;
		break;
	default:
		break;
	}
	if (RorySucks % 500 == 0)
	{
		FPS = 0;
	}
	else
	{
		FPS = RorySucks % 2000;
	}
	
}
void GameLoop::LateUpdate()
{
	key = KMOD_NONE;
}


void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	
	
		
	
	switch (ac_sdlSym)
	{
	case SDLK_w: ay -= 20; break;
	case SDLK_a: ax -= 20; break;
	case SDLK_s: ay += 20; break;
	case SDLK_d: ax += 20; break;
	case SDLK_z: ex -= 20; break;
	case SDLK_F1: ; break;
	
		
	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default:
		key = ac_sdlSym;
		printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;

		
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{

	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}