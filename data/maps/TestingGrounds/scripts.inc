TestingGrounds_MapScripts::
	.byte 0


GenerationSelector::
# 6 "data/maps/TestingGrounds/scripts.pory"
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, GenerationSelector_Text_0, GenerationSelector_Text_1, GenerationSelector_Text_2
# 7 "data/maps/TestingGrounds/scripts.pory"
	switch VAR_RESULT
# 8 "data/maps/TestingGrounds/scripts.pory"
	case 0, GenerationSelector_3
# 12 "data/maps/TestingGrounds/scripts.pory"
	case 1, GenerationSelector_4
# 16 "data/maps/TestingGrounds/scripts.pory"
	case 2, GenerationSelector_5
GenerationSelector_1:
# 21 "data/maps/TestingGrounds/scripts.pory"
	msgbox GenerationSelector_Text_6
	end

GenerationSelector_3:
# 9 "data/maps/TestingGrounds/scripts.pory"
	choosegeneration 1
# 10 "data/maps/TestingGrounds/scripts.pory"
	bufferstring STR_VAR_1, GenerationSelector_Text_3
	goto GenerationSelector_1

GenerationSelector_4:
# 13 "data/maps/TestingGrounds/scripts.pory"
	choosegeneration 2
# 14 "data/maps/TestingGrounds/scripts.pory"
	bufferstring STR_VAR_1, GenerationSelector_Text_4
	goto GenerationSelector_1

GenerationSelector_5:
# 17 "data/maps/TestingGrounds/scripts.pory"
	choosegeneration 3
# 18 "data/maps/TestingGrounds/scripts.pory"
	bufferstring STR_VAR_1, GenerationSelector_Text_5
	goto GenerationSelector_1


PickerEventObject::
# 26 "data/maps/TestingGrounds/scripts.pory"
	callnative ChooseRandomGymLeader
# 27 "data/maps/TestingGrounds/scripts.pory"
	msgbox PickerEventObject_Text_0
	return


PWT_Battler1::
	return


PWT_Battler2::
	return


PWT_Battler3::
	return


GenerationSelector_Text_0:
# 6 "data/maps/TestingGrounds/scripts.pory"
	.string "Gen 1$"

GenerationSelector_Text_1:
# 6 "data/maps/TestingGrounds/scripts.pory"
	.string "Gen 2$"

GenerationSelector_Text_2:
# 6 "data/maps/TestingGrounds/scripts.pory"
	.string "Gen 3$"

GenerationSelector_Text_3:
# 10 "data/maps/TestingGrounds/scripts.pory"
	.string "1$"

GenerationSelector_Text_4:
# 14 "data/maps/TestingGrounds/scripts.pory"
	.string "2$"

GenerationSelector_Text_5:
# 18 "data/maps/TestingGrounds/scripts.pory"
	.string "3$"

GenerationSelector_Text_6:
# 21 "data/maps/TestingGrounds/scripts.pory"
	.string "You've chosen Generation\n"
	.string "{STR_VAR_1}.$"

PickerEventObject_Text_0:
# 27 "data/maps/TestingGrounds/scripts.pory"
	.string "Random gym leaders chosen.$"
