//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/trainers.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/trainers.h' to remove #line markers.
//

#line 1 "src/data/trainers.party"

#line 76
    [DIFFICULTY_NORMAL][TRAINER_NONE] =
    {
#line 78
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 79
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
#line 81
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 82
        .doubleBattle = FALSE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 135
    [DIFFICULTY_NORMAL][TRAINER_KANTO_BROCK] =
    {
#line 136
        .trainerName = _("MAY"),
#line 137
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
#line 138
        .trainerPic = TRAINER_PIC_RS_MAY,
        .encounterMusic_gender =
#line 139
F_TRAINER_FEMALE | 
#line 140
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 141
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
#line 143
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 145
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 144
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
