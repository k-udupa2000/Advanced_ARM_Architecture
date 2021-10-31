; Problem: Counting Even Number in array.
; Name: Karthik R Udupa

	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION
	
	  MOV R0,#0x00000000 ; Count of number of even numbers in the array.
	  MOV R3,#0x20000000 ; Base address of the array.
	  MOV R7, #04 ; Number of elements in the array. Currently set to 4.
	  
	  
	  ADD R1,R3, #0x00000004
	  ADD R2, R1, #0x00000004
	  ADD R11, R2, #0x00000004

	  MOV R4, #0x4 ; First element.
	  STR R4, [R3]
	  
	  MOV R5, #0x8 ; Second element.
	  STR R5, [R1]
	  
	  MOV R6, #0xc ; Third element.
	  STR R6, [R2]
	  
	  MOV R12, #0xa ; Fourth element.
	  STR R12, [R11]



loop1
	LDR R10, [R3]
	TST R10, #01
	BNE loop2
	ADD R0, #01
	
loop2
	SUB R7, R7, #01 ; Decrement the iterator of the array.
	ADD R3, R3, #0x4;
	CMP R7, #00
	BNE loop1
	
	BL printMsg
	
stop B stop
      END
