#include <stdio.h>

#include "../SDL/include/SDL.h"

#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL/libx86/SDL2.lib")

using namespace std;

int main(int argc, char* argv[])
{
	bool run = true;
	SDL_Event ev;
	SDL_Window *window;                    // Declare a pointer
	SDL_Surface* screenSurface = NULL;
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
		     	                       

	SDL_Rect Rect;
	Rect.w = 200;
	Rect.h = 200;
	Rect.x = 50;
	Rect.y = 50;
	
	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Moving Square",                          // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		720,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Fill the surface blue
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 255));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	while (run)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				run = false;
			}
		}
	
		//Clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
		SDL_RenderClear(renderer);

		//Render red filled quad
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, &Rect);
		SDL_RenderPresent(renderer);
		Rect.y++;
		Rect.x++;
		SDL_Delay(100);
	}
		 // Close and destroy the window
		SDL_DestroyWindow(window);

		// Clean up
		SDL_Quit();
		return 0;
	}

