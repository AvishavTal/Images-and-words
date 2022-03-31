    ;UNDEFINED_SYMBOL
.entry M
.entry O
mov A, r2

    ;UNDEFINED_SYMBOL
label: .extern M
add label,r1

    ;SAME_SYMBOL_FOR_ENTRY_AND_EXTERN
.extern mashu
.entry mashu