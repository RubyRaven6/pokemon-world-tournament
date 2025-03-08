#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_ROCK_HEART, MOVE_EFFECT_INFATUATED) == TRUE);
}

SINGLE_BATTLE_TEST("Rock Heart can infatuate")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_HEART); }
        TURN {}
    }
}