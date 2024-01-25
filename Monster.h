#ifndef DONJON_MONSTER_H
#define DONJON_MONSTER_H

#include "AttackTypes.h"

typedef enum {
    FREQUENT = 70, // 70% de chances d'utiliser l'attaque
    OCCASIONAL = 30 // 30% de chances d'utiliser l'attaque
} AttackFrequency;

typedef struct {
    char name[30];
    int power;
    AttackType type;
    AttackFrequency frequency;
} MonsterAttack;

typedef struct {
    char name[50];
    int health;
    MonsterAttack attacks[2]; // Supposons que chaque monstre a jusqu'à 2 attaques
    AttackType weakness;
    AttackType criticalWeakness;
    AttackType invincibility;
    AttackType resistance;
} Monster;

// fonctions renvoient des pointeurs vers Monster
Monster* createToad();
Monster* createGoblin();
Monster* createPirate();
Monster* createAngel();
Monster* createGhoul();

#endif // DONJON_MONSTER_H



