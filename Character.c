// Character.c
#include "Character.h"
#include <stdio.h>

Character createSamurai() {
    Character samurai = {
            "Samurai",
            100, // Santé
            50,// SP

            {
                    {"Katana Slash", ACTION_ATTACK, 14, 0, PHYSICAL},
                    {"Wind Blast", 8, 10, 10,AIR}
                    // Autres actions si nécessaire...
            },

            2,// Nombre d'actions
            FIRE,      // Faiblesse
            BLESSING,     // Faiblesse critique
            CURSE,     // Invincibilité
            PHYSICAL   // Résistance
   };
    return samurai;
}

Character createMainCharacter() {
    Character mainCharacter = {
            "Joker",
            120, // Santé
            60,  // SP
            {{"Thief Slash", 8, 0, PHYSICAL},   // Attaque physique
             {"Blessing Strike", 12, 10, BLESSING}// Attaque élémentaire
            },
            2,
            ELECTRICITY, // Faiblesse
            BLESSING,       // Faiblesse critique
            CURSE,       // Invincibilité
            AIR          // Résistance
    };
    return mainCharacter;
}

Character createMonk() {
    Character monk = {
            "Monk",
            100, // Santé
            50,  // SP
            {
                    {"Fist of Fury", ACTION_ATTACK, 10, 0, PHYSICAL},
                    {"Tranquil Aura", ACTION_HEAL, 15, 15, HEAL}
            },
            2, // Nombre d'actions
            AIR,       // Faiblesse
            CURSE,     // Faiblesse critique
            BLESSING,  // Invincibilité
            ELECTRICITY// Résistance
    };
    return monk;
}

Character createMedic() {
    Character medic = {
            "Medic",
            90,  // Santé
            60,  // SP
            {
                    {"Healing Touch", ACTION_HEAL, 40, 20, HEAL},
                    {"Healing Light", ACTION_HEAL, 15, 7, HEAL}
            },
            2, // Nombre d'actions
            FIRE,      // Faiblesse
            CURSE,     // Faiblesse critique
            BLESSING,  // Invincibilité
            WATER      // Résistance
    };
    return medic;
}

Character createAssassin() {
    Character assassin = {
            "Assassin",
            80,  // Santé
            40,  // SP
            {
                    {"Silent Strike", ACTION_ATTACK, 12, 0, PHYSICAL},
                    {"Shadow Piercer", ACTION_ATTACK, 20, 12, PHYSICAL}
            },
            2, // Nombre d'actions
            BLESSING,  // Faiblesse
            AIR,       // Faiblesse critique
            CURSE,     // Invincibilité
            WATER      // Résistance
    };
    return assassin;
}

Character createDemon() {
    Character demon = {
            "Demon",

            110, // Santé
            70,  // SP
            {
                    {"Abyssal Bolt", ACTION_ATTACK, 14, 0, CURSE},
                    {"Inferno Burst", ACTION_ATTACK, 10, 12, FIRE}
            },
            2, // Nombre d'actions
            CURSE,     // Faiblesse
            WATER,     // Faiblesse critique
            BLESSING,  // Invincibilité
            AIR,// Résistance
            "../char_images/"
    };
    return demon;
}



void showCharacterStats(SDL_Renderer* renderer, Character character) {
    // Affichage des stats dans la console pour l'instant
    printf("Nom: %s\n", character.name);
    printf("Santé: %d\n", character.health);
    printf("SP: %d\n", character.sp);
    // Pour un affichage SDL, utiliser SDL_ttf pour créer une texture à partir de ce texte
}
