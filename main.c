#include <SDL.h>
#include <SDL_image.h>
#include "Character.h"
#include "Party.h"

#include <stdio.h>
#include <stdbool.h>

// Système de Gestion de l'Écran
typedef enum {
    INTRO_SCREEN,
    PARTY_STATS_SCREEN,
    COMBAT_SCREEN,
    // Autres écrans
} GameState;

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
    GameState currentState = INTRO_SCREEN;
    bool statsShown = false; // Ajout d'une variable pour contrôler l'affichage des stats

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!init(&window, &renderer)) {
        printf("Failed to initialize!\n");
        return false;
    }

    SDL_Texture* titleTexture = loadTexture("/Users/davidvucong/CLionProjects/donjon/images/start_screen.png", renderer);
    if (!titleTexture) {
        printf("Failed to load title texture!\n");
    }

    bool quit = false;
    SDL_Event e;

    // Création des personnages
    Character samurai = createSamurai();
    Character mainCharacter = createMainCharacter();
    Party myParty;
    myParty.members[0] = samurai;
    myParty.members[1] = mainCharacter;
    myParty.numMembers = 2;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.scancode == SDL_SCANCODE_RETURN) {
                    if (currentState == INTRO_SCREEN) {
                        currentState = PARTY_STATS_SCREEN;
                        statsShown = false; // Réinitialiser pour permettre l'affichage des stats
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        if (currentState == INTRO_SCREEN) {
            SDL_RenderCopy(renderer, titleTexture, NULL, NULL);
        } else if (currentState == PARTY_STATS_SCREEN && !statsShown) {
            // Afficher les stats des personnages seulement si elles n'ont pas déjà été affichées
            showCharacterStats(renderer, samurai);
            showCharacterStats(renderer, mainCharacter);
            showPartyStats(renderer, myParty);
            statsShown = true; // Marquer les stats comme affichées
            // Ici, ajoutez le code pour afficher les stats avec SDL
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(titleTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}


