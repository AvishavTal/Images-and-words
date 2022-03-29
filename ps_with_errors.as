
    ;illegal comma
, .entry LIST
.entry , LIST
.entry LIST,
,.extern LIST
.extern, LIST
.extern LIST,
.string ,"some correct string"
SYMBOL:   .string ,"some correct string"
,.data 6,5
.data , 1,2
.data 1,,2
.data      3 , 7 ,
A: ,mov r1,r2
B: mov , r1,r2
C: mov r1,,r2
D: mov  r1,r2
E: mov r1,r2,,

    ; illegal string
.string "some error string
.string some error string"
.string some error string

    ; Missing comma
.data 6 5

    ; not int
L: .data 6,a
.data ^
.data 5.9
mov #3.2, r2

    ; Invalid register for index.
mov L[r9],r3

    ;Invalid register name
mov L[1],r2
mov L[r16],r4
mov L[[r18]],r2

    ;illegal addressing
mov r2, #-1
add 2,#3
sub r8 , #-9
lea #-1,r3
lea r3,r4
lea A,#2
clr #1
not #1
inc #1
dec #1
jmp #1
jmp r3
bne #1
bne r3
jsr #1
jsr r3
red #1

    ;too many operand
mov a1,a2,a3
cmp r1,r2,r3
add r1,r2,r3
sub r1,r2,r3
lea r1,r2,r3
clr r1,r2
not r1,r2
inc r1,r2
dec r1,r2
jmp r1,r2
bne r1,r2
jsr r1,r2
red r1,r2
prn r1,r2
rts r1
stop r1

    ; Too few operands.
mov a1
cmp r1
add r1
sub r1
lea r1
clr
not
inc
dec
jmp
bne
jsr
red
prn

    ;UNDEFINED_OPERATOR
movv r2,r3

    ;ILLEGAL_SYMBOL_NAME
illegal_name: .data 5
illegal:name: .data 5

    ; NOT_IN_RANGE_IMMEDIATE
mov #49586878597247297439623460,r2

    ; DOUBLE_DEFINITION_OF_SYMBOL
SAME: mov r1,r2
SAME: add r1,r2

