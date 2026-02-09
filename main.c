#include <SDL2/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(
		"My First SDL Window",
		100, 100,
		640, 480,
		0
	);

	int running = 1;

	SDL_Event event;

	while (running){
		while(SDL_PollEvent(&event)){
			if (event.type ==SDL_QUIT){
				running = 0;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
