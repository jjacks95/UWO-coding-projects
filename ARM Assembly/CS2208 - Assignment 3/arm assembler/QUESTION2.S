	AREA QUESTION2, CODE, READONLY
	ENTRY

Start		ADR		r0,STRING					;set r0 to point to string
			MOV		r1, #0x00					;set r1 to loop counter
			MOV		r2, #0						;set r2 to zero to clear		
			MOV		r3, #0						;clear r3 to pop stack into

Loop		STMFA	r0!, {r2}					;push entire string onto a full ascending stack from pointer r0 to r2
			ADD		r0,r0,#4					;move r0 4 bytes
			SUBS	r1,r1,#1					;subtract one from counter
			BNE		Loop						;end loop
			LDMFA	r2!, {r3}					;pop stack from r2 into r3

Endless		B		Endless						;infinite loop
		
compare1	CMPEQ	r3,#STRING					;compare newly reversed string with original 
			MOVEQ	r0,#1						;set r0 to 1 if it is a Palindrome
			BNE		compare1					;end compare
			
compare0	CMPNE	r3,#STRING					;comapre if strings do not match	
			MOVEQ	r0,#0						;set r0 to 0 if it is not a Palindrome
			BNE 	compare0					;end compare
		
STRING		DCB		"He lived as a devil, eh?"	;string
EoS			DCB		0x00						;end of string
	
	END
	
	