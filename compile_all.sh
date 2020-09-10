#!/bin/bash

#set -o xtrace


rm rnd_generator
gcc -O3 rnd_generator.c -o rnd_generator

rm stub_process
gcc -O0  -masm=intel stub_process.c -o stub_process

rm stub_ropping
gcc -O0  -masm=intel stub_ropping.c -o stub_ropping

(
cd solutions
for i in {0..20}
do
    rm "team$i"
    rm "team$i.elf"
    clang -O1 -masm=intel -m64 -fPIC -nostdlib  -ffreestanding "team$i.c" -o "team$i.elf"
    objcopy -O binary --only-section=.text "team$i.elf" "team$i"
    cat "team$i" "team""$i""extra" >> "team""$i""tmp"
    mv "team""$i""tmp" "team$i"
done
)

(
cd solutions
clang -O1 -masm=intel -m64 -fPIC -nostdlib  -ffreestanding "heavyleft.c" -o "heavyleft.elf"
objcopy -O binary --only-section=.text "heavyleft.elf" "heavyleft"
clang -O1 -masm=intel -m64 -fPIC -nostdlib  -ffreestanding "heavyleft_seccomp.c" -o "heavyleft_seccomp.elf"
objcopy -O binary --only-section=.text "heavyleft_seccomp.elf" "heavyleft_seccomp"
clang -O1 -masm=intel -m64 -fPIC -nostdlib  -ffreestanding "heavyleft_seccomprop.c" -o "heavyleft_seccomprop.elf"
objcopy -O binary --only-section=.text "heavyleft_seccomprop.elf" "heavyleft_seccomprop"
clang -O1 -masm=intel -m64 -fPIC -nostdlib  -ffreestanding "heavyright.c" -o "heavyright.elf"
objcopy -O binary --only-section=.text "heavyright.elf" "heavyright"
)

#cp ../../solutions/* solutions/


