NewMap1_MapScripts::
	.byte 0


NewMap_BrockBattle::
	applymovement 0, NewMap_BrockBattle_Movement_0
	trainerbattle_single TRAINER_BROCK, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
	end


NewMap_MistyBattle::
	applymovement 0, NewMap_BrockBattle_Movement_0
	trainerbattle_single TRAINER_MISTY, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
	end


NewMap_SurgeBattle::
	applymovement 0, NewMap_BrockBattle_Movement_0
	trainerbattle_single TRAINER_SURGE, NewMap_BrockBattle_Text_0, NewMap_BrockBattle_Text_1, NewMap_BrockBattle_Text_2
	end


NewMap_BrockBattle_Movement_0:
	face_player
	step_end

NewMap_BrockBattle_Text_0:
	.string "Intro!$"

NewMap_BrockBattle_Text_1:
	.string "Defeat!$"

NewMap_BrockBattle_Text_2:
	.string "Post-textbox defeat!$"
