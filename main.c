#include <SDL2/SDL.h>

int main()
{
    /* ---------- Init ---------- */
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "Pong",
        100, 100,
        800, 600,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    int running = 1;
    SDL_Event event;

    /* ---------- Players ---------- */
    SDL_Rect player1;
    player1.x = 30;
    player1.y = 250;
    player1.w = 20;
    player1.h = 100;

    SDL_Rect player2;
    player2.x = 750;
    player2.y = 250;
    player2.w = 20;
    player2.h = 100;

    int speed = 5;

    /* ---------- Main Loop ---------- */
    while (running) {

        /* --- Events --- */
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                running = 0;
            }

            if (event.type == SDL_KEYDOWN) {

                if (event.key.keysym.sym == SDLK_w) {
                    player1.y -= speed;
                }

                if (event.key.keysym.sym == SDLK_s) {
                    player1.y += speed;
                }
            }
        }

        /* --- Clamp player inside window --- */
        if (player1.y < 0) {
            player1.y = 0;
        }
        if (player1.y + player1.h > 600) {
            player1.y = 600 - player1.h;
        }

        /* --- Draw --- */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player1);
        SDL_RenderFillRect(renderer, &player2);

        SDL_RenderPresent(renderer);
    }

    /* ---------- Cleanup ---------- */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
