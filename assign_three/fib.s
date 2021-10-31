; Problem: Generating Fibonacci Series.
; Name: Karthik Udupa
; Number of elements to be printed in Fibonacci series: R7.
	
	AREA     appcode, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg
	ENTRY 

__main FUNCTION
		MOV R7, #05 ; Number of elements in the series.
		MOV R1, #01 ; second element.
		MOV R2, #00 ; first element.

loop    CMP R7, #00
		BLE finish        ; Jump if less than or equal to

		MOV R3, R2
		ADD R2, R2, R1
		MOV R5, R2
		
		
		MOV R0, R2
		BL printMsg
		MOV R2, R5
		MOV R1, R3
		SUB R7, #01
		B loop          ; Jump back to loop

finish
	ENDFUNC
	END
