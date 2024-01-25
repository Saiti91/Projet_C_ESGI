#ifndef DONJON_DUNGEON_H
#define DONJON_DUNGEON_H

#include "Monster.h"

#define MAX_LEVELS 4
#define MAX_MONSTERS_PER_LEVEL 4

typedef struct {
    char name[50];
    Monster* monstersByLevel[MAX_LEVELS][MAX_MONSTERS_PER_LEVEL]; // Tableau de pointeurs vers des monstres, organisé par niveaux
} Dungeon;


Dungeon createAngelsSwamp();
Dungeon createAbyss();
Dungeon createDarkForest();

#endif // DONJON_DUNGEON_H

