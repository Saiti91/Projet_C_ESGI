#include "Party.h"
#include <SDL_ttf.h>

void showPartySelectionScreen(SDL_Renderer* renderer, Party party, TTF_Font* font, SDL_Color textColor) {
    // Affichage du nom du donjon sélectionné en haut
    // ...

    // Affichage de la liste des personnages et de leurs stats
    for (int i = 0; i < party.numMembers; i++) {
        // Afficher les informations du personnage (nom, stats, etc.)
        // Vous pouvez utiliser TTF_RenderText_Solid et SDL_CreateTextureFromSurface pour créer des textures de texte
        // ...

        // Afficher les boutons de sélection pour chaque personnage
        // ...

    }

    // Afficher un bouton pour valider la sélection
    // ...
}

// Vous pouvez appeler cette fonction dans main.c lors de l'affichage de l'écran de sélection de la party