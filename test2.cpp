mov eax,dword ptr [ebp+8]
mov eax,dword ptr [ebp+12]
cmp eax,edx
jbe .L1
mov eax,dword ptr [edx]
jmp .L2
.L1:
mov eax.dword ptr [eax]
