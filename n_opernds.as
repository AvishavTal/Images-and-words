;extra operand

;no operands
rts #8
stop r1

;one register operand
clr r8,r9
not r9,r1
inc r10,r3
dec r11,r15
red r12,r2
prn r13,r0

;tow register operands
mov r2,r1,#8
cmp r0,r3,r1
add r5,r4,8
sub r6,r7,4


;missing operand
;one register operand
clr
not
inc
dec
red
prn

;tow register operands
mov r2
cmp r0
add r5
sub r6

mov
cmp
add
sub
