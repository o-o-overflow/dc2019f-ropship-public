#define ROP_AREA_START 0x00800000
#define COMPUTING_HEAP_START 0x40000000
#define OUTPUT_AREA 0x50000000


void main();
void start(){
    return (void) main();
}


void main(){
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
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000008L;
rop_ptr++;
*rop_ptr = chain_table[0x8a1ec3]; //mov bl,  byte ptr [rsi]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc6c3]; //inc esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a3ec3]; //mov bh,  byte ptr [rsi]; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000010L;
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
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a30c3]; //mov dh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a10c3]; //mov dl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e2c3]; //shl edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a30c3]; //mov dh, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc8c3]; //dec eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a10c3]; //mov dl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
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
*rop_ptr = (unsigned long*)0xfL;
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
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000120L;
rop_ptr++;
*rop_ptr = chain_table[0x1f0c3]; //add eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x89dec3]; //mov esi, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89cfc3]; //mov edi, ecx; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
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
*rop_ptr = chain_table[0x1dcc3]; //add esp, ebx; ret
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
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc0c3]; //inc eax; ret
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
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eec3]; //shr esi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1efc3]; //shr edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1efc3]; //shr edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1efc3]; //shr edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1efc3]; //shr edi; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eac3]; //shr edx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1eac3]; //shr edx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x7fL;
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
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x21c7c3]; //and edi, eax; ret
rop_ptr++;
*rop_ptr = chain_table[0x9fec3]; //or esi, edi; ret
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
*rop_ptr = chain_table[0xd1e6c3]; //shl esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x9d6c3]; //or esi, edx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x30100000L;
rop_ptr++;
*rop_ptr = chain_table[0x1f0c3]; //add eax, esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a18c3]; //mov bl, byte ptr [rax]; ret
rop_ptr++;
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x8819c3]; //mov byte ptr [rcx], bl; ret
rop_ptr++;
//#ROPCHAINBUILDER_end
///

asm volatile(
        "call a\na:\npop %rax\naddq $8, %rax\njmpq *%rax\n"
    );

/*
//while(1){;}
asm volatile(
        "hlt\n"
    );
    return 0;

*/

}

/*
objdump -D -b binary -M intel  -m i386:x86-64  team0
cp team1.c team3.c; cp team1.c team4.c; cp team1.c team5.c; cp team1.c team6.c; cp team1.c team7.c; cp team1.c team8.c; cp team1.c team9.c; cp team1.c team10.c; cp team1.c team11.c; cp team1.c team12.c; cp team1.c team13.c; cp team1.c team14.c; cp team1.c team15.c
*/