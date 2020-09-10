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

    *rop_ptr = chain_table[0x59c300]; //pop rcx; ret
    rop_ptr++;
    *rop_ptr = (unsigned long*)0x40000000L;
    rop_ptr++;
    *rop_ptr = chain_table[0x5ac300]; //pop rdx; ret
    rop_ptr++;
    *rop_ptr = (unsigned long*)0x6cL;
    rop_ptr++;
    *rop_ptr = chain_table[0x8811c3]; //mov byte ptr [rcx], dl; ret
    rop_ptr++;
    *rop_ptr = chain_table[0xebfec3]; //jmp 0; ret

    unsigned long x;
    while(1){
        x++;
    }
    return x;
}


/*
objdump -D -b binary -M intel  -m i386:x86-64  team0
*/