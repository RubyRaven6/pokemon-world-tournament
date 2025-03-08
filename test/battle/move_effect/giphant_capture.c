#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Giphant Capture disables the target's last used move (player sealed)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_GIPHANT_CAPTURE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIPHANT_CAPTURE, opponent);
        MESSAGE("The opposing Wobbuffet sealed Tackle for your team!");
        NOT HP_BAR(opponent);
        MESSAGE("Wobbuffet's Tackle is disabled!");
    }
}

SINGLE_BATTLE_TEST("Giphant Capture disables the target's last used move (opponent sealed)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_GIPHANT_CAPTURE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIPHANT_CAPTURE, player);
        MESSAGE("Wobbuffet sealed Tackle for the opposing team!");
        NOT HP_BAR(player);
        MESSAGE("The opposing Wobbuffet's Tackle is disabled!");
    }
}

SINGLE_BATTLE_TEST("Giphant Capture fails on Z-Moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, gimmick: GIMMICK_Z_MOVE); MOVE(opponent, MOVE_GIPHANT_CAPTURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GIPHANT_CAPTURE, opponent);
        MESSAGE("But Giphant Capture couldn't seal any move!");
    }
}

SINGLE_BATTLE_TEST("Giphant Capture fails on Max Moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_GIPHANT_CAPTURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GIPHANT_CAPTURE, opponent);
        MESSAGE("But Giphant Capture couldn't seal any move!");
    }
}

DOUBLE_BATTLE_TEST("Giphant Capture disables the move for the entire team")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); MOVE(opponentLeft, MOVE_GIPHANT_CAPTURE, target: playerLeft); MOVE(playerRight, MOVE_TACKLE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIPHANT_CAPTURE, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        MESSAGE("Wynaut's Tackle is disabled!");
    }
}

SINGLE_BATTLE_TEST("Stuff stuff")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CONVERSION); MOVE(opponent, MOVE_CONVERSION_2); }
    }
}
