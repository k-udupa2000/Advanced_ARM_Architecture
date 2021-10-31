; Problem: Largest of 3 numbers.
; Name: Karthik R Udupa


	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY


      
__main  FUNCTION
	
	MOV R0,#0x20000000

	ADD R1,R0, #0x00000004  
	ADD R2, R1, #0x00000004


	MOV R4, #0xf ; Number 1
	STR R4, [R0] 
	LDR R7, [R0]
	
	MOV R5, #0x6 ; Number 2
	STR R5, [R1]
	LDR R8, [R1]
	
	MOV R6, #0xa ; Number 3
	STR R6, [R2]
	LDR R9, [R2]

	CMP R7, R8 ; Compare Number 1 and Number 2.
	BGT CHECK1
	MOV R7, R8
	
CHECK1	
	CMP R7, R9 ; Compare with Number 3
	BGT CHECK2
	MOV R7, R9
	
		
CHECK2
	MOV R0, R7
	BL printMsg

stop B stop 
	ENDFUNC
	END
