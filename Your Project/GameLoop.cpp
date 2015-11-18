#include "GameLoop.h"
#include "time.h"
#include <iostream>
using namespace std;
void Ball(int &ball, int deltaTime, int moved)
{
	ball -= moved *deltaTime;
}
int RorySucks = 0;
int up;
int down;
int up2;
int by = 400;
int down2;
int ball = 250;
int speed = 10;
float currentTime = clock();
float previousTime = currentTime;
int deltaTime = 0;
float ay = 300;
float ay2 = 300;
int moved = 10;
int ax;
bool p1w = false;
bool p1d = false;
int P1score = -1;
int P2score = 0;
float x = 50;
float y = 450;
float b = 450;
float a = 1550;
bool stop = false;
bool go = false;
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

		/*Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 173,155,34,255 });
		Graphics::DrawRect({ 100,100 }, { 500,500 }, { 740,131,189,58 });*/
		
		/*Graphics::DrawLine({ 1400,0 }, { 300,800 }, { 225,225,225,225 });*/
		//Verticle Stuff
		Graphics::DrawLine({ 100,0 }, { 1500,600 }, { 740,131,189,68 });
		for (float x = 100; x <= 1500; x = x + 100)
		{
			Graphics::DrawLine({ x, 0 }, { x, 1000 }, { 740,131,189,68 });
		}
	
		//Horizontal Stuff
		Graphics::DrawLine({ 100, 600 }, { 1500,600 }, { 225,225,225,225 });
		for (float y = 0; y <= 1500; y = y + 100)
		{
			Graphics::DrawLine({ 100, y }, { 1500, y }, { 225,225,225,225 });
		}
			Graphics::DrawRect({ 0, ay }, { 50, 200 }, { 164,0,96,161 });
			Graphics::DrawRect({ 1550,ay2 }, { 50, 200 }, { 164,0,96,161 });
			Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

			
			/*Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });*/
			Graphics::DrawCircle({ ball,by}, 10, 100, { 173,155,34,225 });
			

			Graphics::Flip(); // Required to update the window with all the newly drawn content

			if (up == 1)
			{
				if (ay <= 0)
				{
					ay = 0;
				}
				ay -= 20;
			}
			if (down == 1)
			{
				if (ay >= 700)
				{
					ay = 700;
				}
				ay += 20;
			}
			if (up2 == 1)
			{
				if (ay2 <= 0)
				{
					ay2 = 0;
				}
				ay2 -= 20;
			}
			if (down2 == 1)
			{
				if (ay2 >= 700)
				{
					ay2 = 700;
				}
				ay2 += 20;
			}
		}
	}

/*int ex = 200;*/
void GameLoop::Update()
{
	currentTime = clock();
	deltaTime = (currentTime - previousTime) / 10;
	std::cout << deltaTime << endl;

	previousTime = currentTime;

	if (stop)
	{
		by += 10;
	}
	if (go)
	{
		by -= 10;
	}
	if (by >= 890)
	{
		stop = false;
		go = true;
	}
	if (by <= 10)
	{
		stop = true;
		go = false;
	}
	if (((ball == x - 20) && (by >= y - 10 && by <= y + 100)))
	{
		if (by > y + 40)
		{
			go = false;
			stop = true;
		}
		else if (by < y + 40)
		{
			stop = false;
			go = true;
		}
		else
		{
			stop = false;
			go = false;
		}
		moved = -10;
	}
	if (((ball - 20 == a) && (by >= b - 10 && by <= b + 100)))
	{
		if (by > b + 40)
		{
			go = false;
			stop = true;
		}
		else if (by < b + 40)
		{
			stop = false;
			go = true;
		}
		else
		{
			stop = false;
			go = false;
		}
		moved = 10;
	}
	if ((ball < 1610 && ball > -10))
	{
		Ball(ball, deltaTime, moved);
	}
	else if (ball >= 1610) { ball = 800; by = 500; stop = false; go = false; }
	else if (ball <= -10) { ball = 800; by = 500; stop = false; go = false; }

	if (p1w) { if (y > 0) { y -= 10 * deltaTime; } }
	if (p1d) { if (y < 800) y += 10 * deltaTime; }

}
void GameLoop::LateUpdate()
{
	/*key = KMOD_NONE;*/
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
	case SDLK_UP: up2 = 1; break;
	case SDLK_DOWN: down2 = 1; break;
	case SDLK_w: up = 1; break;
	case SDLK_s: down = 1; break;
	
		
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
	case SDLK_UP: up2 = 0; break;
	case SDLK_DOWN: down2 = 0; break;
	case SDLK_w: up = 0; break;
	case SDLK_s: down = 0; break;

	case SDLK_ESCAPE: m_bRunning = false; break;

	default:
		key = ac_sdlSym;
		printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
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