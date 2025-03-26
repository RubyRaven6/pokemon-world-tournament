NewMap1_MapScripts::
	.byte 0


NewMap_BrockBattle::
	applymovement 0, NewMap_BrockBattle_Movement_0
	end


NewMap_MistyBattle::
	applymovement 0, NewMap_BrockBattle_Movement_0
	end


NewMap_SurgeBattle::
	applymovement 0, NewMap_BrockBattle_Movement_0
	end


NewMap_BrockBattle_Movement_0:
	face_player
	step_end
