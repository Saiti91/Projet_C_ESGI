#include "Monster.h"
#include <stdlib.h>

Monster* createToad() {
    Monster* toad = malloc(sizeof(Monster));
    *toad = (Monster) {
            "Toad",
            50, // Santé
            {
                    {"Lick", 15, PHYSICAL, FREQUENT},
                    {"Cursed Lick", 10, CURSE, OCCASIONAL}
            },
            FIRE,        // Faiblesse
            AIR,         // Faiblesse critique
            WATER,       // Invincibilité
            ELECTRICITY  // Résistance
    };
    return toad;
}

Monster* createGoblin() { //la fonction createGoblin me renvoit un pointeur
    Monster* goblin = malloc(sizeof(Monster)); //j'alloue dans l'espace mémoire l'espace d'une instance de Monster définit par la struct Monster
    *goblin = (Monster){ //je déreference mon pointeur pour lui donner la valeur de l'instance que je détaille. (liste d'initialisation)
            "Goblin",
            70, // Santé
            {
                    {"Claw Strike", 12, PHYSICAL, FREQUENT},
                    {"Venomous Swipe", 13, WATER, OCCASIONAL}
            },
            AIR,          // Faiblesse
            BLESSING,     // Faiblesse critique
            CURSE,        // Invincibilité
            ELECTRICITY   // Résistance
    };
    return goblin; //ma fonction me renvoit un pointeur vers une instance de Monster allouée dans la Heap, je l'utilise dans mon tableau dungeon.c
}

Monster* createAngel() {
    Monster* angel = malloc(sizeof(Monster));
    *angel = (Monster) {
            "Angel",
            90, // Santé
            {
                    {"Celestial Strike", 14, BLESSING, FREQUENT},
                    {"Radiant Beam", 10, BLESSING, OCCASIONAL} // Assurez-vous que LIGHT est défini
            },
            FIRE,      // Faiblesse
            CURSE,         // Faiblesse critique
            BLESSING,      // Invincibilité
            AIR            // Résistance
    };
    return angel;
}

Monster* createPirate() {
    Monster* pirate = malloc(sizeof(Monster));
    *pirate = (Monster) {
            "Pirate",
            80, // Santé
            {
                    {"Cutlass Slash", 14, PHYSICAL, FREQUENT},
                    {"Blunderbuss Blast", 10, FIRE, OCCASIONAL}
            },
            WATER,         // Faiblesse
            ELECTRICITY,   // Faiblesse critique
            AIR,           // Invincibilité
            CURSE          // Résistance
    };
    return pirate;
}

Monster* createGhoul() {
    Monster* ghoul = malloc(sizeof(Monster));
    *ghoul = (Monster){
            "Ghoul",
            60, // Santé
            {
                    {"Corpse Claw", 12, PHYSICAL, FREQUENT},
                            {"Zombifying Grasp", 8, CURSE, OCCASIONAL}
                    },
                    FIRE,         // Faiblesse
                    BLESSING,   // Faiblesse critique
                    CURSE,           // Invincibilité
                    AIR       // Résistance
            };
            return ghoul;
    }

