#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "tournament_logic.h"
#include "constants/flags.h"
#include "constants/opponents.h"

/* 

- Chooses three gym leaders from an array
- The third gym leader chosen has to be definitively be one that has not been defeated yet

*/

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

static const u32 *const sGymLeaderRosters[] = {
    sKantoGymLeaderRoster,
    sJohtoGymLeaderRoster,
    sHoennGymLeaderRoster
};

static const u32 sGymLeaderArrayCounts[] = {
    ARRAY_COUNT(sKantoGymLeaderRoster),
    ARRAY_COUNT(sJohtoGymLeaderRoster),
    ARRAY_COUNT(sHoennGymLeaderRoster)
};

void ChooseRandomGymLeader(void) {
    u32 countUndefeated = 0;
    u32 gen = VarGet(VAR_GENERATION_CTL);
    u32 leader1 = 0;
    u32 leader2 = 0;
    u32 leader3 = 0;

    for (u32 i = 0; i < sGymLeaderArrayCounts[gen]; i++)
    {
        if(!FlagGet(sGymLeaderRosters[gen][i] + TRAINER_FLAGS_START))
            countUndefeated++;
    }
    
    u32 n = RandomUniform(RNG_NONE, 0, countUndefeated - 1);

    for (u32 i = 0; i < sGymLeaderArrayCounts[gen]; i++)
    {
        if (!FlagGet(sGymLeaderRosters[gen][i] + TRAINER_FLAGS_START))
        {
            if (n == 0)
            {
                leader3 = i;
                break;
            }
            n--;
        }
    }
    
    do { leader1 = RandomUniform(RNG_NONE, 0, sGymLeaderArrayCounts[gen] - 1); } while (leader1 == leader3);

    do { leader2 = RandomUniform(RNG_NONE, 0, sGymLeaderArrayCounts[gen] - 1); } while (leader2 == leader3 || leader2 == leader1);

    VarSet(VAR_GYM_LEADER_1, sGymLeaderRosters[gen][leader1]);
    VarSet(VAR_GYM_LEADER_2, sGymLeaderRosters[gen][leader2]);
    VarSet(VAR_GYM_LEADER_3, sGymLeaderRosters[gen][leader3]);
};