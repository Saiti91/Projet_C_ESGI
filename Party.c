#include "Party.h"

void showPartyStats(SDL_Renderer* renderer, Party party) {
    for (int i = 0; i < party.numMembers; i++) {
        showCharacterStats(renderer, party.members[i]);
    }
}
