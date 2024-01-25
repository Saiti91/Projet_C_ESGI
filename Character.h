#ifndef DONJON_CHARACTER_H
#define DONJON_CHARACTER_H

#include <SDL.h>
#include "Action.h"

#define MAX_ACTIONS 5

typedef struct {
    char name[50];
    int health;
    int sp;
    Action actions[MAX_ACTIONS];//tableau d'actions, qui sont eux-mêmes des tableaux
    int numActions; // Nombre d'actions réellement utilisées
    AttackType weakness;
    AttackType criticalWeakness;
    AttackType invincibility;
    AttackType resistance;
    char imagePath[100];
} Character;

Character createSamurai();
Character createMainCharacter();
Character createMonk();
Character createMedic();
Character createAssassin();
Character createDemon();

void showCharacterStats(SDL_Renderer* renderer, Character character);

#endif //DONJON_CHARACTER_H

