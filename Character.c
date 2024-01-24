// Character.c
#include "Character.h"
#include <stdio.h>

Character createSamurai() {
    return (Character){"Samurai", 100, 50}; // Exemple d'implémentation
}

Character createMainCharacter() {
    return (Character){"Joker", 120, 60}; // Exemple d'implémentation
}

void showCharacterStats(SDL_Renderer* renderer, Character character) {
    // Affichage des stats dans la console pour l'instant
    printf("Nom: %s\n", character.name);
    printf("Santé: %d\n", character.health);
    printf("SP: %d\n", character.sp);
    // Pour un affichage SDL, utiliser SDL_ttf pour créer une texture à partir de ce texte
}
