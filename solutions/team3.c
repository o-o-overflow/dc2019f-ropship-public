#define ROP_AREA_START 0x00800000
#define COMPUTING_HEAP_START 0x40000000
#define OUTPUT_AREA 0x50000000


unsigned long main();
unsigned long start(){
    return (unsigned long) main();
}


unsigned long main(){
    unsigned long** chain_table = (unsigned long**)COMPUTING_HEAP_START;
    unsigned char* rop = (unsigned char*)ROP_AREA_START;

    //because of the Coupon Collector properties, 400M is sufficient to find all the three bytes combinations
    for(unsigned int i=0; i<400000000; i++){
        unsigned int csequence = rop[i] * (256*256) + rop[i+1]*(256) + rop[i+2];
        chain_table[csequence] = (unsigned long*)(rop+i);
    }

    unsigned long** rop_ptr = (unsigned long**)OUTPUT_AREA;
///
//#ROPCHAINBUILDER_start
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002010L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002040L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002070L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400020a0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400020d0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002100L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002130L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002160L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002190L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400021c0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400021f0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002220L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002250L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002280L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400022b0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400022e0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002310L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002340L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40002370L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5fc300]; //pop rdi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dfc3]; //mov edi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e7c3]; //shl edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000128L;
rop_ptr++;
*rop_ptr = chain_table[0x1f8c3]; //add eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x400023a0L;
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a38c3]; //mov bh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e1c3]; //shl ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a28c3]; //mov ch, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a08c3]; //mov cl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f3c3]; //sub ebx, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x29f9c3]; //sub ecx, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f0c3]; //mov eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c6c3]; //mov esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89f8c3]; //mov eax, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7e8c3]; //imul eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c7c3]; //mov edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x1fec3]; //add esi, edi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x2710L;
rop_ptr++;
*rop_ptr = chain_table[0x29dec3]; //sub esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x1L;
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xf7d6c3]; //not esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c6c3]; //and esi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x1f4c3]; //add esp, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
//#ROPCHAINBUILDER_end
///
asm volatile(
        "hlt\n"
    );
    return 0;
}


/*
objdump -D -b binary -M intel  -m i386:x86-64  team0
*/