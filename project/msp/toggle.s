	.arch msp430g2553
	.p2align 1,0

	.data
state:
	.word 0

	.text
jt:
	.word state1
	.word state2
	.word state3
	.word state4

	.gloabl toggle
toggle:
	CMP #3, r12
	Jlo end

	mov &state, r12
	add r12, r12
	mov jt(r12), r0

	;;
state1:
	mov.b	#0, &red_on
	mov.b	#0, &green_on
	mov.b	#1, &state
	jmp 	end

state2:
	mov.b	#1, &red_on
	mov.b	#0, &green_on
	mov.b	#2, &state
	jmp	end

state3:
	mov.b	#0, &red_on
	mov.b	#1, &green_on
	mov.b	#3, &state
	jmp	end

state4:
	mov.b	#1, &red_on
	mov.b	#1, &green_on
	mov.b	#0, &state
	jmp	end

end:
	pop r0	
