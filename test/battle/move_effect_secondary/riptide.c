#include "global.h"
#include "test/battle.h"

// ASSUMPTIONS
// {
//     ASSUME(MoveHasAdditionalEffectSelf(MOVE_RIPTIDE, MOVE_EFFECT_SPD_PLUS_2));
// }

SINGLE_BATTLE_TEST("Riptide raises user's speed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RIPTIDE); }
    }
}