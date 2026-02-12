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
    SDL_Rect player1 = {30, 250, 20, 100};
    SDL_Rect player2 = {750, 250, 20, 100};
    SDL_Rect ball = {400 - 10, 300 - 10, 20 , 20};

    int speed = 5;

    /* ---------- Main Loop ---------- */
    while (running) {

        /* --- Handle quit event only --- */
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        /* --- Keyboard state (continuous movement) --- */
        const Uint8 *keys = SDL_GetKeyboardState(NULL);

        /* Player 1: W / S */
        if (keys[SDL_SCANCODE_W]) {
            player1.y -= speed;
        }
        if (keys[SDL_SCANCODE_S]) {
            player1.y += speed;
        }

        /* Player 2: Up / Down arrows */
        if (keys[SDL_SCANCODE_UP]) {
            player2.y -= speed;
        }
        if (keys[SDL_SCANCODE_DOWN]) {
            player2.y += speed;
        }

        /* --- Clamp Player 1 --- */
        if (player1.y < 0)
            player1.y = 0;

        if (player1.y + player1.h > 600)
            player1.y = 600 - player1.h;

        /* --- Clamp Player 2 --- */
        if (player2.y < 0)
            player2.y = 0;

        if (player2.y + player2.h > 600)
            player2.y = 600 - player2.h;

        /* --- Draw --- */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player1);
        SDL_RenderFillRect(renderer, &player2);
        SDL_RenderFillRect(renderer, &ball);

        SDL_RenderPresent(renderer);

        /* --- Slow down loop (~60 FPS) --- */
        SDL_Delay(16);
    }

    /* ---------- Cleanup ---------- */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
