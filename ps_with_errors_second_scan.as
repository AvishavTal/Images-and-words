    ;UNDEFINED_SYMBOL
label:
add label,r2
    ;UNDEFINED_SYMBOL
.entry A
.entry 82
mov A, r2

    ;UNDEFINED_SYMBOL
label: .extern M
add label,r1

    ;BOTH_ENTRY_AND_EXTERN_FOR_SAME_SYMBOL
.extern symbol
.entry symbol

;.entry
;.data
;.extern
;.string