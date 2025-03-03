NewMap1_MapScripts::
	.byte 0


NewMap_BrockBattle::
# 6 "data//maps/NewMap1/scripts.pory"
	trainerbattle_single TRAINER_BROCK, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
# 7 "data//maps/NewMap1/scripts.pory"
	msgbox NewMap_BrockBattle_Text_3, MSGBOX_DEFAULT
# 8 "data//maps/NewMap1/scripts.pory"
	release
	end


NewMap_BrockBattle_Text_0:
# 6 "data//maps/NewMap1/scripts.pory"
	.string "Intro!$"

NewMap_BrockBattle_Text_1:
# 6 "data//maps/NewMap1/scripts.pory"
	.string "Defeat!$"

NewMap_BrockBattle_Text_2:
# 6 "data//maps/NewMap1/scripts.pory"
	.string "Post-textbox defeat!$"

NewMap_BrockBattle_Text_3:
# 7 "data//maps/NewMap1/scripts.pory"
	.string "OW textbox!$"
