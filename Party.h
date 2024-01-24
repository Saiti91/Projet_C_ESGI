#ifndef DONJON_PARTY_H
#define DONJON_PARTY_H
#include <SDL.h>
#include "Character.h"

#define MAX_PARTY_MEMBERS 4

typedef struct {
    Character members[MAX_PARTY_MEMBERS];
    int numMembers;
} Party;

void showPartyStats(SDL_Renderer* renderer, Party party);
#endif //DONJON_PARTY_H
