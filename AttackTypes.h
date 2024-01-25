#ifndef DONJON_ATTACKTYPES_H
#define DONJON_ATTACKTYPES_H

// Définitions des types d'attaques et des constantes
typedef enum {
    PHYSICAL,
    CURSE,
    BLESSING,
    ELECTRICITY,
    FIRE,
    WATER,
    AIR,
    HEAL
} AttackType;

#define MAX_ATTACK_STAT 20

#endif // DONJON_ATTACKTYPES_H
