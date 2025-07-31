section .data
con_ms dd 0.2778 ; 1 km/h -> 0.2778 m/s 

section .text
bits 64
default rel

global acc
extern printf

acc:
; acc(float* data, int* results, int rows)
; acc(RCX, RDX, R8)

    push rbp
    mov rbp, rsp

    xor r9, r9              ; set index to 0

loop:
    cmp r9, r8            ;loop condition: r9 <= rows
    jge done

    
    mov eax, r9d                      ; load current row index
    imul eax, 12                      ; 12 = 3 floats per row (vi, vf, t)* 4 bytes
    mov r10d, eax                     ; byte offset for current row

    ; load initial velocity (vi), final velocity (vf), time (t)
    movss xmm0, dword [rcx + r10 + 0] ; vi (in KM/H)
    movss xmm1, dword [rcx + r10 + 4] ; vf (in KM/H)
    movss xmm2, dword [rcx + r10 + 8] ; t

    ; convert vi and vf from KM/H to m/s:
    movss xmm3, xmm0
    movss xmm4, xmm1
    movss xmm5, dword [con_ms]     
    mulss xmm3, xmm5        ; vi in m/s
    mulss xmm4, xmm5        ; vf in m/s

    ; compute acceleration: 
    subss xmm4, xmm3        ; (vf - vi)
    divss xmm4, xmm2        ; / t

    ; convert to int (RTN-TE)
    cvtss2si eax, xmm4
    mov [rdx + r9*4], eax   ;

    inc r9
    jmp loop

done:
    pop rbp
    ret
