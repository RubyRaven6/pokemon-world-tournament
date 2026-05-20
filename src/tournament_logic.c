#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "event_scripts.h"
#include "tournament_logic.h"
#include "constants/flags.h"
#include "constants/opponents.h"

static const u32 sKantoGymLeaderRoster[] = {
    TRAINER_LEADER_BROCK,
    TRAINER_LEADER_MISTY,
    TRAINER_LEADER_LT_SURGE,
    TRAINER_LEADER_ERIKA,
    TRAINER_LEADER_SABRINA,
    TRAINER_LEADER_KOGA_AND_JANINE,
    TRAINER_LEADER_BLAINE,
    TRAINER_LEADER_GIOVANNI,
};

static const u32 sJohtoGymLeaderRoster[] = {
    TRAINER_LEADER_FALKNER,
    TRAINER_LEADER_BUGSY,
    TRAINER_LEADER_WHITNEY,
    TRAINER_LEADER_MORTY,
    TRAINER_LEADER_CHUCK,
    TRAINER_LEADER_JASMINE,
    TRAINER_LEADER_PRYCE,
    TRAINER_LEADER_CLAIR,
};

static const u32 sHoennGymLeaderRoster[] = {
    TRAINER_LEADER_ROXANNE,
    TRAINER_LEADER_BRAWLY,
    TRAINER_LEADER_WATTSON,
    TRAINER_LEADER_FLANNERY,
    TRAINER_LEADER_NORMAN,
    TRAINER_LEADER_WINONA,
    TRAINER_LEADER_TATE_AND_LIZA,
    TRAINER_LEADER_JUAN,
};

static const struct RosterStruct {
  const u32 *roster;
  u32 rosterCount;
} sGymLeaderRosters[] = {
    [1] = { sKantoGymLeaderRoster, ARRAY_COUNT(sKantoGymLeaderRoster) },
    [2] = { sJohtoGymLeaderRoster, ARRAY_COUNT(sJohtoGymLeaderRoster) },
    [3] = { sHoennGymLeaderRoster, ARRAY_COUNT(sHoennGymLeaderRoster) }
};

static const u8 *sPWTBattleScripts[] =
{
    [TRAINER_LEADER_BROCK]           = EventScript_PWTBattleBrock,
    [TRAINER_LEADER_MISTY]           = EventScript_PWTBattleMisty,
    [TRAINER_LEADER_LT_SURGE]        = EventScript_PWTBattleLtSurge,
    [TRAINER_LEADER_ERIKA]           = EventScript_PWTBattleErika,
    [TRAINER_LEADER_KOGA_AND_JANINE] = EventScript_PWTBattleKogaJanine,
    [TRAINER_LEADER_SABRINA]         = EventScript_PWTBattleSabrina,
    [TRAINER_LEADER_BLAINE]          = EventScript_PWTBattleBlaine,
    [TRAINER_LEADER_GIOVANNI]        = EventScript_PWTBattleGiovanni,
};

void ChooseRandomGymLeader(void) {
    u32 countUndefeated = 0;
    u32 gen = VarGet(VAR_GENERATION_CTL);
    u32 leader1 = 0;
    u32 leader2 = 0;
    u32 leader3 = 0;

    for (u32 i = 0; i < sGymLeaderRosters[gen].rosterCount; i++)
    {
        if(!FlagGet(sGymLeaderRosters[gen].roster[i] + TRAINER_FLAGS_START))
            countUndefeated++;
    }
    
    u32 n = RandomUniform(RNG_NONE, 0, countUndefeated - 1);

    for (u32 i = 0; i < sGymLeaderRosters[gen].rosterCount; i++)
    {
        if (!FlagGet(sGymLeaderRosters[gen].roster[i] + TRAINER_FLAGS_START))
        {
            if (n == 0)
            {
                leader3 = i;
                break;
            }
            n--;
        }
    }
    
    do { leader1 = RandomUniform(RNG_NONE, 0, sGymLeaderRosters[gen].roster[leader1] - 1); } while (leader1 == leader3);

    do { leader2 = RandomUniform(RNG_NONE, 0, sGymLeaderRosters[gen].roster[leader2] - 1); } while (leader2 == leader3 || leader2 == leader1);

    VarSet(VAR_GYM_LEADER_1, sGymLeaderRosters[gen].roster[leader1]);
    VarSet(VAR_GYM_LEADER_2, sGymLeaderRosters[gen].roster[leader2]);
    VarSet(VAR_GYM_LEADER_3, sGymLeaderRosters[gen].roster[leader3]);
};

void Script_goto_pwt_battle_script(struct ScriptContext *ctx)
{
    u16 trainerId = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    ScriptJump(ctx, sPWTBattleScripts[trainerId]);
}