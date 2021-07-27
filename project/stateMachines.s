	.data

current_state:
	.byte 0

delay:
	.byte 1

note_pressed:
	.byte 0
	
octave:
	.byte 0


	.global state_advance	

state_advance:

	cmp.b #3, &current_state
	jge else
	add.b #1, &current_state
	jmp end
else:
	mov.b #0, &current_state
end:
	mov.b &delay, &current_state
	add.b &delay, &delay
	add.b #1, &delay

	mov.b &current_state, &octave

	add.b &octave, &octave
	add.b &octave, &octave
	add.b &octave, &octave
	add.b &octave, &octave
	add.b &octave, &octave
	add.b &octave, &octave
	add.b &octave, &octave
	ret
