	AREA QUESTION1, CODE, READONLY 			;Naming Code
	ENTRY
										
											;first loop to add for first sum
Start1		ADR		r0, UPC					;point r0 to UPC code
			MOV 	r1, #12					;start loop counter in r1 as length of array
			MOV 	r2, #0					;clear sum of r2 for running total
Loop1		LDR		r3, [r0]				;load r3 with what r0 is pointing at
			ADD		r0,r0,#4				;add 4 bytes to move 1 place in UPC code
			ADD		r2,r2,r3				;add r2 and r3 to have running total of first sum
			SUBS	r1,r1,#2				;increment r1 to move places along array every 2 spaces for even places
			BNE		Loop1					
Endless 	B		Endless											
											;second sum loop to add
Start2		ADR		r0, UPC					;point r0 to UPC code
			MOV 	r1, #11					;start loop counter in r1 as length of array start at 11 rather then 12 for odd placements
			MOV 	r3, #0					;clear sum of r2 for running total
Loop2		LDR		r4, [r0]				;load r3 with what r0 is pointing at
			ADD		r0,r0,#4				;add 4 bytes to move 1 place in UPC code
			ADD		r3,r3,r4				;add r2 and r3 to have running total of first sum
			SUBS	r1,r1,#2				;increment r1 to move places along array every 2 spaces for odd placements
			BNE		Loop2				
Endless2 	B		Endless2				

			ADD		r2,r2,r2,LSL #1			;multiply first sum by 3		
			ADD		r2,r2,r3				;adding the two sums together
			SUBS	r2,r2,#1				;subtracting 1 from the sum
			
mod			TEQ		r2,#10					;compare if sum is less then 10 for mod
			SUBS	r2,r2,#10				;repeteadly subtract 10
			BNE		mod
			
check0		CMP		r2,#Check_Digit			;compare sum with check digit to see if valid UPC or not
			MOVEQ	r0,#1					;set r0 to 1 if the UPC is valid
			BNE		check0
check1		CMPNE	r2, #Check_Digit		;check to see if upc code is not equal to check digit
			MOVEQ	r0,#0					;set r0 to 0 if the UPC is invalid
			BNE		check1
			
UPC 		DCB 0,1,3,8,0,0,1,5,0,7,3,8 	;UPC string
Check_Digit EQU 8							;Check digit definition
	
	END
	