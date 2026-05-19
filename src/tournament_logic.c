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

#define KANTO_LEADERS_COUNT 8

const u32 sKantoGymLeaderRoster[KANTO_LEADERS_COUNT] = {
    TRAINER_GRUNT_AQUA_HIDEOUT_1,
    TRAINER_GRUNT_AQUA_HIDEOUT_2,
    TRAINER_GRUNT_AQUA_HIDEOUT_3,
    TRAINER_GRUNT_AQUA_HIDEOUT_4,
    TRAINER_GRUNT_AQUA_HIDEOUT_5,
    TRAINER_GRUNT_AQUA_HIDEOUT_6,
    TRAINER_GRUNT_AQUA_HIDEOUT_7,
    TRAINER_GRUNT_AQUA_HIDEOUT_8,
};

void ChooseRandomGymLeader(void) {
    u32 countUndefeated = 0;
    u32 i1 = 0;
    u32 i2 = 0;
    u32 i3 = 0;

    for (u32 i = 0; i < ARRAY_COUNT(sKantoGymLeaderRoster); i++)
    {
        if(!FlagGet(sKantoGymLeaderRoster[i] + TRAINER_FLAGS_START))
            countUndefeated++;
    }

    DebugPrintf("countUndefeated: %u", countUndefeated);
    
    u32 n = RandomUniform(RNG_NONE, 0, countUndefeated - 1);

    DebugPrintf("1st n: %u",n);

    for (u32 i = 0; i < ARRAY_COUNT(sKantoGymLeaderRoster); i++)
    {
        if (!FlagGet(sKantoGymLeaderRoster[i] + TRAINER_FLAGS_START))
        {
            if (n == 0)
            {
                i3 = i;
                break;
            }
            n--;
        }
    }
    
    DebugPrintf("after loop n: %u",n);

    do { i1 = RandomUniform(RNG_NONE, 0, ARRAY_COUNT(sKantoGymLeaderRoster) - 1); } while (i1 == i3);

    do { i2 = RandomUniform(RNG_NONE, 0, ARRAY_COUNT(sKantoGymLeaderRoster) - 1); } while (i2 == i3 || i2 == i1);

    DebugPrintf("i1: %u",i1);
    DebugPrintf("i2: %u",i2);
    DebugPrintf("i3: %u",i3);

    VarSet(VAR_GYM_LEADER_1, sKantoGymLeaderRoster[i1]);
    VarSet(VAR_GYM_LEADER_2, sKantoGymLeaderRoster[i2]);
    VarSet(VAR_GYM_LEADER_3, sKantoGymLeaderRoster[i3]);

}