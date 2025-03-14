#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_GRASSPIERCER, MOVE_EFFECT_GRASSPIERCER) == TRUE);
}

SINGLE_BATTLE_TEST("Grasspiercer can inflict poison, paralysis or sleep")
{
    u8 statusAnim;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; }
    PASSES_RANDOMLY(1, 3, RNG_GRASSPIERCER);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSPIERCER); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSPIERCER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            STATUS_ICON(opponent, paralysis: TRUE);
        } else if (statusAnim == B_ANIM_STATUS_SLP) {
            STATUS_ICON(opponent, sleep: TRUE);
        } else if (statusAnim == B_ANIM_STATUS_PSN) {
            STATUS_ICON(opponent, badPoison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Grasspiercer cannot poison/paralyze poison/electric types respectively")
{
    u8 statusAnim;
    u16 species;
    u32 rng;
    #if B_PARALYZE_ELECTRIC >= GEN_6
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; }
    #endif // B_PARALYZE_ELECTRIC
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_TOXIC; species = SPECIES_ARBOK; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSPIERCER, WITH_RNG(RNG_GRASSPIERCER, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSPIERCER, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PSN) {
                STATUS_ICON(opponent, badPoison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Grasspiercer cannot poison/paralyze/cause to fall asleep pokemon with abilities preventing respective statuses")
{
    u8 statusAnim;
    u16 species, ability;
    u32 rng;
    if (B_REDIRECT_ABILITY_IMMUNITY >= GEN_5)
        PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_JOLTEON; ability = ABILITY_VOLT_ABSORB; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_ELECTIVIRE; ability = ABILITY_MOTOR_DRIVE; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_TOXIC; species = SPECIES_ZANGOOSE; ability = ABILITY_IMMUNITY; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = MOVE_EFFECT_SLEEP; species = SPECIES_VIGOROTH; ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = MOVE_EFFECT_SLEEP; species = SPECIES_HYPNO; ability = ABILITY_INSOMNIA; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSPIERCER, WITH_RNG(RNG_GRASSPIERCER, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSPIERCER, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_SLP) {
                STATUS_ICON(opponent, sleep: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PSN) {
                STATUS_ICON(opponent, badPoison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Grasspiercer cannot poison/paralyze/cause to fall asleep a mon which is already statused")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_TOXIC; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = MOVE_EFFECT_SLEEP; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSPIERCER, WITH_RNG(RNG_GRASSPIERCER, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSPIERCER, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_SLP) {
                STATUS_ICON(opponent, sleep: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PSN) {
                STATUS_ICON(opponent, badPoison: TRUE);
            }
        }
    }
}
