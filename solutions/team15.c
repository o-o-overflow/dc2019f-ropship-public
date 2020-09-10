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
*rop_ptr = chain_table[0x59c300]; //pop rcx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000000L;
rop_ptr++;
*rop_ptr = chain_table[0x5ec300]; //pop rsi; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x40000008L;
rop_ptr++;
*rop_ptr = chain_table[0x5bc300]; //pop rbx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x0L;
rop_ptr++;
*rop_ptr = chain_table[0x8a1ec3]; //mov bl,  byte ptr [rsi]; ret
rop_ptr++;
*rop_ptr = chain_table[0xffc6c3]; //inc esi; ret
rop_ptr++;
*rop_ptr = chain_table[0x8a3ec3]; //mov bh,  byte ptr [rsi]; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0xd1e3c3]; //shl ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x58c300]; //pop rax; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x30000100L;
rop_ptr++;
*rop_ptr = chain_table[0x1d8c3]; //add eax, ebx; ret
rop_ptr++;
*rop_ptr = chain_table[0x89c4c3]; //mov esp, eax; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50000f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50001f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50002f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50003f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50004f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50005f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50006f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50007f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50008f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50009f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5000ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50010f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50011f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50012f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50013f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50014f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50015f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50016f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50017f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50018f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50019f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5001ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50020f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50021f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50022f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50023f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50024f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50025f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50026f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50027f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50028f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50029f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5002ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50030f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50031f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50032f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50033f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50034f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50035f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50036f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50037f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50038f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50039f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5003ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50040f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50041f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50042f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50043f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50044f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50045f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50046f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50047f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50048f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50049f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5004ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50050f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50051f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50052f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50053f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50054f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50055f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50056f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50057f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50058f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50059f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5005ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50060f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50061f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50062f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50063f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50064f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50065f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50066f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50067f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50068f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50069f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006a900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006aa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ab00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ac00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ad00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ae00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006af00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006b900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ba00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006bb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006bc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006bd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006be00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006bf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006c900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ca00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006cb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006cc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006cd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ce00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006cf00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006d900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006da00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006db00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006dc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006dd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x72L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006de00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006df00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x64L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006e900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ea00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006eb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ec00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ed00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ee00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ef00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006f900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006fa00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006fb00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006fc00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x75L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006fd00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006fe00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x5006ff00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070500L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070600L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070700L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070800L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070900L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070a00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070b00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070c00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070d00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070e00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50070f00L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50071000L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50071100L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50071200L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x6cL;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50071300L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x61L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
rop_ptr++;
rop_ptr = (unsigned long**)0x50071400L;
*rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
rop_ptr++;
*rop_ptr = (unsigned long*)0x73L;
rop_ptr++;
*rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
rop_ptr++;
*rop_ptr = chain_table[0xebfec3]; //jmp 0; ret
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
cp team1.c team3.c; cp team1.c team4.c; cp team1.c team5.c; cp team1.c team6.c; cp team1.c team7.c; cp team1.c team8.c; cp team1.c team9.c; cp team1.c team10.c; cp team1.c team11.c; cp team1.c team12.c; cp team1.c team13.c; cp team1.c team14.c; cp team1.c team15.c
*/