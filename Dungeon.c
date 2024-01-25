#include "Dungeon.h"
#include "string.h"

Dungeon createAngelsSwamp() {
    Dungeon angelsSwamp;
    strcpy(angelsSwamp.name, "Angel’s Swamp");

    /*Création d'Instances Uniques :

    Chaque appel à une fonction comme createGoblin() ou createToad() crée une nouvelle instance unique du monstre correspondant, allouée dynamiquement.
            Si j'appelle  createGoblin() deux fois, j'obtiens deux instances distinctes de Goblin en mémoire.*/

    // Niveau 1
    angelsSwamp.monstersByLevel[0][0] = createToad();// Je crée une instance de Toad dans la Heap.
    angelsSwamp.monstersByLevel[0][1] = createToad();//Une instance différente ici
    angelsSwamp.monstersByLevel[0][2] = NULL;
    angelsSwamp.monstersByLevel[0][3] = NULL;

    // Niveau 2
    angelsSwamp.monstersByLevel[1][0] = createAngel();
    angelsSwamp.monstersByLevel[1][1] = createToad();
    angelsSwamp.monstersByLevel[1][2] = NULL;

    angelsSwamp.monstersByLevel[1][3] = NULL;

    // Niveau 3
    angelsSwamp.monstersByLevel[2][0] = createAngel;
    angelsSwamp.monstersByLevel[2][1] = createToad();
    angelsSwamp.monstersByLevel[2][2] = createToad();
    angelsSwamp.monstersByLevel[2][3] = NULL;

    // Niveau 4
    angelsSwamp.monstersByLevel[3][0] = createToad();
    angelsSwamp.monstersByLevel[3][1] = createToad();
    angelsSwamp.monstersByLevel[3][2] = createAngel();
    angelsSwamp.monstersByLevel[3][3] = createAngel();

    return angelsSwamp;
}

Dungeon createAbysse() {
    Dungeon abysse;
    strcpy(abysse.name, "Abysse");


    // Niveau 1
    abysse.monstersByLevel[0][0] = createGhoul();
    abysse.monstersByLevel[0][1] = createGhoul();
    abysse.monstersByLevel[0][2] = NULL;
    abysse.monstersByLevel[0][3] = NULL;

    // Niveau 2
    abysse.monstersByLevel[1][0] = createPirate();
    abysse.monstersByLevel[1][1] = createGhoul();
    abysse.monstersByLevel[1][2] = NULL;
    abysse.monstersByLevel[1][3] = NULL;

    // Niveau 3
    abysse.monstersByLevel[2][0] = createPirate();
    abysse.monstersByLevel[2][1] = createGhoul();
    abysse.monstersByLevel[2][2] = createGhoul();
    abysse.monstersByLevel[2][3] = NULL;

    // Niveau 4
    abysse.monstersByLevel[3][0] = createGhoul();
    abysse.monstersByLevel[3][1] = createGhoul();
    abysse.monstersByLevel[3][2] = createPirate();
    abysse.monstersByLevel[3][3] = createPirate();

    return abysse;
}

Dungeon createDarkForest() {
    Dungeon darkForest;
    strcpy(darkForest.name, "Dark Forest");

    Monster* goblin = createGoblin();
    Monster* angel = createAngel();
    Monster* pirate = createPirate();
    Monster* toad = createToad();

    // Niveau 1
    darkForest.monstersByLevel[0][0] = goblin;
    darkForest.monstersByLevel[0][1] = goblin;
    darkForest.monstersByLevel[0][2] = NULL;
    darkForest.monstersByLevel[0][3] = NULL;

    // Niveau 2
    darkForest.monstersByLevel[1][0] = pirate;
    darkForest.monstersByLevel[1][1] = goblin;
    darkForest.monstersByLevel[1][2] = NULL;
    darkForest.monstersByLevel[1][3] = NULL;

    // Niveau 3
    darkForest.monstersByLevel[2][0] = angel;
    darkForest.monstersByLevel[2][1] = goblin;
    darkForest.monstersByLevel[2][2] = goblin;
    darkForest.monstersByLevel[2][3] = NULL;

    // Niveau 4
    darkForest.monstersByLevel[3][0] = goblin;
    darkForest.monstersByLevel[3][1] = angel;
    darkForest.monstersByLevel[3][2] = pirate;
    darkForest.monstersByLevel[3][3] = toad;

    return darkForest;
}