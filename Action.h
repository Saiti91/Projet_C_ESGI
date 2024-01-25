#ifndef DONJON_ACTION_H
#define DONJON_ACTION_H

#include "AttackTypes.h"

typedef enum {
    ACTION_ATTACK,
    ACTION_HEAL,
    // Pas d'autres types d'actions prévues...
} ActionType;

typedef struct {
    char name[30];
    ActionType type;
    int power;   // Utilisé pour les attaques et les soins
    int spCost;  // Coût en points SP
    AttackType elementType; // Type élémentaire, si applicable (les soins ne s'en serviront pas par exemple)
} Action;

#endif // DONJON_ACTION_H

