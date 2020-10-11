.code
ourFunc proc
	mov rax,qword ptr ds:[rcx+10]
	sub rax,qword ptr ds:[rcx+18]
	jmp [jmpBackAddy]
ourFunc endp
end