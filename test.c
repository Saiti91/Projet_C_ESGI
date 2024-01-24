

/*
int main() {
    GameState currentState = INTRO_SCREEN;

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

        // Création des personnages après la fin de l'écran d'introduction
        Character samurai = createSamurai();
        Character mainCharacter = createMainCharacter();

        // Afficher les stats des personnages
        showCharacterStats(renderer, samurai);
        showCharacterStats(renderer, mainCharacter);

        Party myParty;
        myParty.members[0] = createSamurai();
        myParty.members[1] = createMainCharacter();
        myParty.numMembers = 2;

        showPartyStats(renderer, myParty);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}*/
