#include <SDL.h>
#include <SDL_image.h>


#include <stdio.h>
#include <stdbool.h>

// Taille de la fenêtre
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Initialisation de SDL et création de la fenêtre
bool init(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Votre RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!*window) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!*renderer) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Initialisation de SDL_image pour les formats d'images
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

// Chargement de l'image du titre
SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (!loadedSurface) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (!newTexture) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!init(&window, &renderer)) {
        printf("Failed to initialize!\n");
    } else {
        // Chargement de l'image du titre
        SDL_Texture* titleTexture = loadTexture("/Users/davidvucong/CLionProjects/donjon/images/start_screen.png", renderer);

        if (!titleTexture) {
            printf("Failed to load title texture!\n");
        } else {
            bool quit = false;
            SDL_Event e;

            while (!quit) {
                // Gestion des événements
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    } else if (e.type == SDL_KEYDOWN) {
                        quit = true; // Sortir de la boucle si une touche est pressée
                    }
                }

                // Effacer l'écran
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                // Rendu de l'image du titre
                SDL_RenderCopy(renderer, titleTexture, NULL, NULL);

                // Mettre à jour l'écran
                SDL_RenderPresent(renderer);
            }

            // Libérer les ressources et fermer SDL
            SDL_DestroyTexture(titleTexture);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
