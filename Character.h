#ifndef DONJON_CHARACTER_H
#define DONJON_CHARACTER_H
#include <SDL.h>

// Character.h
typedef struct {
    char name[50];
    int health;
    int sp;
    // Autres stats
} Character;

Character createSamurai();
Character createMainCharacter();

void showCharacterStats(SDL_Renderer* renderer, Character character);
#endif //DONJON_CHARACTER_H
