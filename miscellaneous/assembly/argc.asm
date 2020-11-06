; https://forum.nasm.us/index.php?topic=889.0
; print number of arguments 
; nasm -f elf argc.asm
; ld -m elf_i386 argc.o
global _start

section .text
_start:

    pop ecx     ; argc in ecx
    add ecx, '0'    ; convert number to character - ASSume one digit :(
    push ecx        ; need it in a buffer - use the stack
    mov ecx, esp    ; address of buffer in ecx, as sys_write wants!
   
    mov edx, 1      ; number of bytes to write
    mov ebx, 1      ; file descriptor - STDOUT
    mov eax, 4      ; __NR_write
    int 80h
   
exit:
    xor ebx, ebx    ; claim "no error"
    mov eax, 1      ; __NR_exit
    int 80h
