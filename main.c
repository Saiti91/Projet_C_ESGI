#include <SDL.h>
#include <SDL_image.h>
#include "Character.h"
#include "Party.h"
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

// Système de Gestion de l'Écran
typedef enum {
    INTRO_SCREEN,
    DUNGEON_SELECTION_SCREEN,
    PARTY_STATS_SCREEN,
    COMBAT_SCREEN,
    // Autres écrans
} GameState;


// Taille de la fenêtre
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Declaration of font variable
TTF_Font *font;

// Initialisation de SDL et création de la fenêtre
bool init(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("The Dungeon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    // Initialisation de SDL_ttf
    if (TTF_Init() == -1) {
        printf("TTF could not initialize! TTF Error: %s\n", TTF_GetError());
        IMG_Quit();
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    // Loading the font
    font = TTF_OpenFont("/Users/davidvucong/CLionProjects/donjon/font/the-wild-breath-of-zelda-font/TheWildBreathOfZelda-15Lv.ttf", 24);
    if (!font) {
        printf("Failed to load font! TTF Error: %s\n", TTF_GetError());
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    SDL_Color textColor = {255, 255, 255, 255}; // Couleur du texte en blanc
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

// Déclaration de la variable globale pour la couleur du texte
SDL_Color textColor = {255, 255, 255, 255};

int main() {
    GameState currentState = INTRO_SCREEN;
    bool dungeonSelected = false;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!init(&window, &renderer)) {
        printf("Failed to initialize!\n");
        return false;
    }

    SDL_Texture *titleTexture = loadTexture("/Users/davidvucong/CLionProjects/donjon/images/start_screen.png",
                                            renderer);
    if (!titleTexture) {
        printf("Failed to load title texture!\n");
    }

    bool quit = false;
    SDL_Event e;

    //écran donjons

    // Ajout de variables pour gérer les donjons
    int selectedDungeonIndex = 0;
    const int totalDungeons = 3;
    SDL_Texture *dungeonTextures[totalDungeons]; // Tableau de textures pour les donjons
    const char *dungeonNames[totalDungeons] = {"Angel’s Swamp", "Abysse", "Dark Forest"};

    // Chargement des textures des donjons (assurez-vous que les chemins sont corrects)
    dungeonTextures[0] = loadTexture("/Users/davidvucong/CLionProjects/donjon/Dungeons_images/angels_swamp.png",
                                     renderer);
    dungeonTextures[1] = loadTexture("/Users/davidvucong/CLionProjects/donjon/Dungeons_images/abysse.png", renderer);
    dungeonTextures[2] = loadTexture("/Users/davidvucong/CLionProjects/donjon/Dungeons_images/dark_forest.png",
                                     renderer);


    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (currentState) {
                    case INTRO_SCREEN:
                        if (e.key.keysym.scancode == SDL_SCANCODE_RETURN) {
                            currentState = DUNGEON_SELECTION_SCREEN;
                        }
                        break;
                    case DUNGEON_SELECTION_SCREEN:
                        if (e.key.keysym.sym == SDLK_LEFT) {
                            selectedDungeonIndex = (selectedDungeonIndex - 1 + totalDungeons) % totalDungeons;
                        } else if (e.key.keysym.sym == SDLK_RIGHT) {
                            selectedDungeonIndex = (selectedDungeonIndex + 1) % totalDungeons;
                        } else if (e.key.keysym.scancode == SDL_SCANCODE_RETURN) {
                            dungeonSelected = true; // Simule la sélection du donjon
                            currentState = PARTY_STATS_SCREEN;
                        }
                        break;
                        // Autres cas...
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        switch (currentState) {
            case INTRO_SCREEN:
                // Rendu de l'écran d'introduction
                SDL_RenderCopy(renderer, titleTexture, NULL, NULL);
                break;
            case DUNGEON_SELECTION_SCREEN:
                // Fond noir pour l'écran
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Noir
                SDL_RenderClear(renderer);

                // Afficher le nom du donjon en haut au centre
                SDL_Surface* textSurface = TTF_RenderText_Solid(font, dungeonNames[selectedDungeonIndex], textColor);
                SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                int textWidth = textSurface->w;
                int textHeight = textSurface->h;
                SDL_FreeSurface(textSurface);

                SDL_Rect textRect = { (SCREEN_WIDTH - textWidth) / 2, 30, textWidth, textHeight }; // Positionnement en haut
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_DestroyTexture(textTexture);

                // Afficher l'image du donjon sous le nom
                SDL_Rect dungeonImageRect = { (SCREEN_WIDTH - 600) / 2, 100, 600, 450 }; // Vous pouvez ajuster ces valeurs
                SDL_RenderCopy(renderer, dungeonTextures[selectedDungeonIndex], NULL, &dungeonImageRect);

                break;
                // Autres cas...
        }

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(titleTexture);
    // Nettoyage SDL_ttf
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}


