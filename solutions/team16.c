
//objdump -D -b binary -M intel  -m i386:x86-64  team0


#define COMPUTING_HEAP_START 0x40000000
#define OUTPUT_AREA 0x50000000

unsigned long main();
unsigned long start(){
    return (unsigned long) main();
}

int fun(int a){
    return a*327;
}

unsigned long main(){
    unsigned char* bb = (unsigned char*)COMPUTING_HEAP_START;
    bb[4] = 5;
    int cc = fun(7);
    unsigned char* ooo = (unsigned char*)OUTPUT_AREA;
    for(int i=0; i<100000000; i++){
        ooo[i] = 0x37;
    }
    asm volatile(
        "int $3\n"
    );
    return cc;
}


