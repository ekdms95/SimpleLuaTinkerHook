// LuaPrint.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

/*
Original function :
141668f60[4] : 48 8b 41 10                   mov rax, qword ptr[rcx + 0x10]
141668f64[4] : 48 2b 41 18                   sub rax, qword ptr[rcx + 0x18]
141668f68[4] : 48 c1 f8 04                   sar rax, 4
141668f6c[1] : c3                            ret
141668f6d[1] : cc                            int3
141668f6e[1] : cc                            int3
141668f6f[1] : cc                            int3
141668f70[4] : 48 83 ec 28                   sub rsp, 0x28
141668f74[3] : 4d 63 d0                      movsxd r10, r8d
141668f77[3] : 4c 8b d9                      mov r11, rcx
141668f7a[5] : e8 a1 f9 ff ff                call 0x141668920 -> 141668920
141668f7f[4] : 83 78 08 06                   cmp dword ptr[rax + 8], 6
141668f83[2]: 75 76                         jne 0x141668ffb -> 141668ffb
141668f85[3] : 48 8b 10                      mov rdx, qword ptr[rax]
141668f88[4] : 80 7a 0a 00                   cmp byte ptr[rdx + 0xa], 0
141668f8c[2] : 74 2a                         je 0x141668fb8 -> 141668fb8
141668f8e[4] : 41 83 fa 01                   cmp r10d, 1
141668f92[2] : 7c 67                         jl 0x141668ffb -> 141668ffb
141668f94[4] : 0f b6 42 0b                   movzx eax, byte ptr[rdx + 0xb]
141668f98[3]: 44 3b d0                      cmp r10d, eax
141668f9b[2] : 7f 5e                         jg 0x141668ffb -> 141668ffb
141668f9d[4] : 41 8d 42 ff                   lea eax, [r10 - 1]
141668fa1[3] : 48 63 c8                      movsxd rcx, eax
141668fa4[4] : 4c 8d 42 28                   lea r8, [rdx + 0x28]
141668fa8[4] : 48 c1 e1 04                   shl rcx, 4
141668fac[7] : 48 8d 05 7d 1b 32 01          lea rax, [rip + 0x1321b7d] -> 14298ab30
141668fb3[3] : 4c 03 c1                      add r8, rcx
141668fb6[2] : eb 28                         jmp 0x141668fe0 -> 141668fe0
141668fb8[4] : 4c 8b 4a 20                   mov r9, qword ptr[rdx + 0x20]
141668fbc[4] : 41 83 fa 01                   cmp r10d, 1
141668fc0[2] : 7c 39                         jl 0x141668ffb -> 141668ffb

Prologue to overwrite :
141668f60[4] : 48 8b 41 10                   mov rax, qword ptr[rcx + 0x10]
141668f64[4] : 48 2b 41 18                   sub rax, qword ptr[rcx + 0x18]
141668f68[4] : 48 c1 f8 04                   sar rax, 4

Jmp To Prol :
67922bc[6] : ff 25 46 00 00 00             jmp[6792308] ->141668f6c
6792308[8] : 6c 8f 66 41 01 00 00 00       dest holder

Trampoline :
67922b0[4] : 48 8b 41 10                   mov rax, qword ptr[rcx + 0x10]
67922b4[4] : 48 2b 41 18                   sub rax, qword ptr[rcx + 0x18]
67922b8[4] : 48 c1 f8 04                   sar rax, 4
67922bc[6] : ff 25 46 00 00 00             jmp qword ptr[rip + 0x46] -> 6792308
67922c2[2] : 00 00                         add byte ptr[rax], al
67922c4[2] : 00 00                         add byte ptr[rax], al
67922c6[2] : 00 00                         add byte ptr[rax], al
67922c8[2] : 00 00                         add byte ptr[rax], al
67922ca[2] : 00 00                         add byte ptr[rax], al
67922cc[2] : 00 00                         add byte ptr[rax], al
67922ce[2] : 00 00                         add byte ptr[rax], al
67922d0[2] : 00 00                         add byte ptr[rax], al
67922d2[2] : 00 00                         add byte ptr[rax], al
67922d4[2] : 00 00                         add byte ptr[rax], al
67922d6[2] : 00 00                         add byte ptr[rax], al
67922d8[2] : 00 00                         add byte ptr[rax], al
67922da[2] : 00 00                         add byte ptr[rax], al
67922dc[2] : 00 00                         add byte ptr[rax], al
67922de[2] : 00 00                         add byte ptr[rax], al
67922e0[2] : 00 00                         add byte ptr[rax], al
67922e2[2] : 00 00                         add byte ptr[rax], al
67922e4[2] : 00 00                         add byte ptr[rax], al
67922e6[2] : 00 00                         add byte ptr[rax], al
67922e8[2] : 00 00                         add byte ptr[rax], al
67922ea[2] : 00 00                         add byte ptr[rax], al
67922ec[2] : 00 00                         add byte ptr[rax], al
67922ee[2] : 00 00                         add byte ptr[rax], al
67922f0[2] : 00 00                         add byte ptr[rax], al
67922f2[2] : 00 00                         add byte ptr[rax], al
67922f4[2] : 00 00                         add byte ptr[rax], al
67922f6[2] : 00 00                         add byte ptr[rax], al
67922f8[2] : 00 00                         add byte ptr[rax], al
67922fa[2] : 00 00                         add byte ptr[rax], al
67922fc[2] : 00 00                         add byte ptr[rax], al
67922fe[2] : 00 00                         add byte ptr[rax], al
6792300[2] : 00 00                         add byte ptr[rax], al
6792302[2] : 00 00                         add byte ptr[rax], al
6792304[2] : 00 00                         add byte ptr[rax], al
6792306[2] : 00 00                         add byte ptr[rax], al
6792308[1] : 6c                            insb byte ptr[rdi], dx


hooked*/