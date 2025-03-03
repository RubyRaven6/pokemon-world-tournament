NewMap1_MapScripts::
	.byte 0


NewMap_BrockBattle::
# 6 "data//maps/NewMap1/scripts.pory"
	applymovement 0, NewMap_BrockBattle_Movement_0
# 7 "data//maps/NewMap1/scripts.pory"
	trainerbattle_single TRAINER_BROCK, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
	end


NewMap_MistyBattle::
# 12 "data//maps/NewMap1/scripts.pory"
	applymovement 0, NewMap_BrockBattle_Movement_0
# 13 "data//maps/NewMap1/scripts.pory"
	trainerbattle_single TRAINER_MISTY, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
	end


NewMap_SurgeBattle::
# 18 "data//maps/NewMap1/scripts.pory"
	applymovement 0, NewMap_BrockBattle_Movement_0
# 19 "data//maps/NewMap1/scripts.pory"
	trainerbattle_single TRAINER_SURGE, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
	end


# 6 "data//maps/NewMap1/scripts.pory"
NewMap_BrockBattle_Movement_0:
# 6 "data//maps/NewMap1/scripts.pory"
	face_player
	step_end

NewMap_BrockBattle_Text_0:
# 7 "data//maps/NewMap1/scripts.pory"
	.string "Intro!$"

NewMap_BrockBattle_Text_1:
# 7 "data//maps/NewMap1/scripts.pory"
	.string "Defeat!$"

NewMap_BrockBattle_Text_2:
# 7 "data//maps/NewMap1/scripts.pory"
	.string "Post-textbox defeat!$"
