#include <SDL2/SDL.h>

int main()
{
    // 1. Start SDL (graphics system)
    SDL_Init(SDL_INIT_VIDEO);

    // 2. Create a window
    SDL_Window *window = SDL_CreateWindow(
        "Pong",
        100, 100,
        800, 600,
        0
    );

    // 3. Create a renderer (this draws pixels)
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    int running = 1;
    SDL_Event event;

    // 4. Define Player 1 as a rectangle
    SDL_Rect player1;
    player1.x = 30;   // distance from left
    player1.y = 250;  // distance from top
    player1.w = 20;   // width
    player1.h = 100;  // height

    SDL_Rect player2;
    player2.x =750;
    player2.y =250;
    player2.w = 20;
    player2.h = 100;

    // 5. Main loop
    while (running) {

        // 6. Handle events (close button)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // 7. Clear screen (background = black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 8. Draw Player 1 (white rectangle)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player1);
        SDL_RenderFillRect(renderer, &player2);

        // 9. Show everything on screen
        SDL_RenderPresent(renderer);
    }

    // 10. Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
