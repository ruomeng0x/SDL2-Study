#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL2 could not be initialized: " << SDL_GetError();
    }

    SDL_Window *window = SDL_CreateWindow(
            "Load Image",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            800,
            600,
            SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int flags = IMG_INIT_PNG;
    int initStatus = IMG_Init(flags);
    if ((initStatus & flags) != flags) {
        std::cerr << "SDL2 Image format not available" << std::endl;
        return 2;
    }

    SDL_Surface* image = IMG_Load("./images/mario.png");
    if (!image) {
        std::cerr << "Image not loaded..." << std::endl;
        return 3;
    }

    SDL_Texture *png = SDL_CreateTextureFromSurface(renderer, image);

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, png, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(image);
    SDL_DestroyTexture(png);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}