    ;DOUBLE_DEFINITION_OF_SYMBOL
sameSymbolLabel: add r1,r2
sameSymbolLabel: mov r1,r2

    ;DOUBLE_DEFINITION_OF_SYMBOL
sameLabel: add r1,r2
.entry sameLabel
.extern sameLabel

; UNDEFINED_SYMBOL
.entry M
.entry O
mov A, r2