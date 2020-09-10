#!/usr/bin/env python

from keystone import *
import struct
import itertools
import math


KS = Ks(KS_ARCH_X86, KS_MODE_64)


ROP_AREA_START = 0x00800000   
COMPUTING_STACK_START = 0x30000000
COMPUTING_HEAP_START = 0x40000000
OUTPUT_AREA = 0x50000000

# memory layout in HEAP_START: move, tick, pad(0x100), state with polar per team


def g(value, ending="ret"):
    valuer = value + "; %s" % ending
    encoding, _ = KS.asm(valuer)
    assert len(encoding)<=3
    penconding = encoding + [0] * (3 - len(encoding))
    vv = penconding[0] * pow(2,16) + penconding[1] * pow(2,8) + penconding[2]
    return "*rop_ptr = chain_table[%s]; //%s\nrop_ptr++;\n" % (hex(vv), valuer)


def d(value):
    return "*rop_ptr = (unsigned long*)%sL;\nrop_ptr++;\n" % hex(value)


def s(value):
    return "rop_ptr = (unsigned long**)%sL;\n" % hex(value)


def save_to_team_solution(tstr, defcon_id):
    with open("solutions/team"+str(defcon_id)+".c", "r") as fp:
        cco = fp.read()
    before, token1, after = cco.partition("//#ROPCHAINBUILDER_start")
    _, token2, after = after.partition("//#ROPCHAINBUILDER_end")
    cc = "\n".join((s.strip() for s in (before, token1, tstr, token2, after)))
    with open("solutions/team"+str(defcon_id)+".c", "w") as fp:
        fp.write(cc)


def save_extra_to_team_solution(tstr, defcon_id):
    with open("solutions/team"+str(defcon_id)+"extra", "wb") as fp:
        fp.write(tstr)


def move_list_to_solution(mlist):
    tstr = ""
    #tstr += g("jmp 0")
    tstr += g("pop rcx")
    tstr += d(COMPUTING_HEAP_START)
    tstr += g("pop rsi")
    tstr += d(COMPUTING_HEAP_START+8)
    tstr += g("pop rbx")
    tstr += d(0x0) #this is the 2-days bug, only needed if registers are not cleared
    tstr += g("mov bl,  byte ptr [rsi]")
    tstr += g("inc esi")
    tstr += g("mov bh,  byte ptr [rsi]")
    tstr += g("shl ebx")
    tstr += g("shl ebx")
    tstr += g("shl ebx")
    tstr += g("shl ebx")
    tstr += g("shl ebx")
    tstr += g("shl ebx")
    tstr += g("shl ebx") 
    tstr += g("shl ebx") #0x100
    tstr += g("pop rax")
    tstr += d(COMPUTING_STACK_START+0x100)
    tstr += g("add eax, ebx")
    tstr += g("mov esp, eax")
    for i, m in enumerate(mlist):
        tstr += s(OUTPUT_AREA+0x100+(0x100*i))
        tstr += g("pop rdx")
        if m == "X":
            tstr += g("pop rcx")
            tstr += d(0x13)
            tstr += g("mov byte ptr [rcx], dl")
        else:
            tstr += d(ord(m))
        tstr += g("mov byte ptr [rcx], dl")
        tstr += g("jmp 0")
    return tstr


def create_move_table(mx=64*2,my=64*2,ma=128,sx=16,sy=16,sa=4,arange=3.8,adistance=110.0):
    def twos_comp(val, bits=11):
        """compute the 2's complement of int value val"""
        if (val & (1 << (bits - 1))) != 0: # if sign bit is set e.g., 8bit: 128-255
            val = val - (1 << bits)        # compute negative value
        return val

    pmtable = [ord(b"s")] * (mx*my*ma)
    for idx, (x, y, a) in enumerate(itertools.product(range(mx), range(my), range(ma))):
        if x == mx-1: # max value
            # who we want to attack is not existing --> s
            # this does not really work, because 0xffff is subtracted to another value, I now check explicitly for NULL ship
            continue
        if x == 0 and y == 0:
            # who we want to attack is ourself --> s
            continue
        rx = twos_comp(x*sx)
        ry = twos_comp(y*sy)
        ra = (a*sa)%360.0
        absangle = (math.atan2(ry, rx) / math.pi * 180.0)%360.0
        dangle = (absangle-ra)%360
        #print(dangle)
        if dangle < arange or dangle > (360.0-arange):
            if math.sqrt(rx*rx+ry*ry) > adistance:
                pmtable[x*my*ma+y*ma+a] = ord(b"u")
            else:
                pmtable[x*my*ma+y*ma+a] = ord(b"a")
        else:
            if dangle <=180.0:
                pmtable[x*my*ma+y*ma+a] = ord(b"l")
            else:
                pmtable[x*my*ma+y*ma+a] = ord(b"r")

    #pmtable = pmtable[:10000]
    tstr = b"\x48\xc7\xc0\x00\x00\x10\x50"
    tstr += b"".join((b"\xc6\x00" + (chr(c)).encode("utf-8") + b"\x48\xff\xc0" for c in pmtable))
    #tstr += "unsigned char table[] = {%s};\n" % ",".join([r"'%s'"%chr(c) for c in pmtable])
    return tstr

'''
tstr = ""
tstr += g("pop rcx")
tstr += d(COMPUTING_HEAP_START)
tstr += g("pop rdx")
tstr += d(ord(b"r"))
tstr += g("mov byte ptr [rcx], dl")
#tstr += g("jmp 0")
'''
mlist = (["l"]*10 + ["s", "a"]) + (["d"]*10 + ["r"]*25 + ["d"]*10 + ["a"] + ["u"]*20 + ["l"]*22 + ["a", "s"] ) * 20
save_to_team_solution(move_list_to_solution(mlist), 15)


mlist = mlist[::-1]
save_to_team_solution(move_list_to_solution(mlist), 1)

'''
tstr = ""
tstr += g("pop rax")
tstr += d(0x10)
tstr += g("inc edx")
tstr += g("sub esp, eax")
save_to_team_solution(tstr, 3)
# avg is > 9M instructions with 0.05, 20M with 0.10
'''


#######################################################################3

tstr = ""
tstr += g("pop rsi")
tstr += d(COMPUTING_HEAP_START+8)
tstr += g("mov bl,  byte ptr [rsi]")
tstr += g("inc esi")
tstr += g("mov bh,  byte ptr [rsi]")
tstr += g("mov esi, ebx") #rsi is the current tick

tstr += g("pop rbx")
tstr += d(0x0)
tstr += g("pop rax") #rdi is team_id
tstr += d(COMPUTING_HEAP_START+16)
tstr += g("mov bl, byte ptr [rax]")
tstr += g("mov edi, ebx")
tstr += (g("shl edi"))*8 #rdi is team_id *0x100

tstr += g("pop rbx")
tstr += d(0x0)

tstr += g("pop rax")
tstr += d(COMPUTING_HEAP_START+0x100+8*5)
tstr += g("add eax, edi") #eax points to .x of our team

# ebx = dword ptr [eax]
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("mov bh, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov bl, byte ptr [rax]")
tstr += (g("shl ebx"))*16
tstr += g("dec eax")
tstr += g("mov bh, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov bl, byte ptr [rax]")

tstr += g("inc eax") * 8 # eax points to .y of our team
# ecx = word ptr [eax]
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("mov ch, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov cl, byte ptr [rax]")
tstr += (g("shl ecx"))*16
tstr += g("dec eax")
tstr += g("mov ch, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov cl, byte ptr [rax]")
#ebx/ecx is our location

tstr += g("inc eax") * 8 # eax points to .a of our team
# ecx = word ptr [eax]
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("mov dh, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov dl, byte ptr [rax]")
tstr += (g("shl edx"))*16
tstr += g("dec eax")
tstr += g("mov dh, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov dl, byte ptr [rax]")
#edx is our angle

#tstr += g("jmp 0")
#rsi (the tick) is used to select the team to attack, based on %128

tstr += (g("shr esi"))*7
tstr += g("pop rax")
tstr += d(0x000000000000000f) # modulo 0xf
tstr += g("and esi, eax")
#tstr += (g("inc esi"))*3 #attack team tid 3 at the beginning
tstr += (g("shl esi"))*8

tstr += g("pop rax")
tstr += d(COMPUTING_HEAP_START+0x100+8*4)
tstr += g("add eax, esi") #eax points to .x of the to-attack team

# move our location to esi/edi
tstr += g("mov esi, ebx")
tstr += g("mov edi, ecx")

# check for NULL ship
tstr += g("pop rbx")
tstr += d(0x0)
tstr += g("mov bl, byte ptr [rax]")
tstr += (g("shl ebx"))*6 # 8 gadgets skipped (after the next) if bl = 1 (ship is present)
tstr += g("add esp, ebx")

tstr += g("pop rdx")
tstr += d(ord(b's'))
tstr += g("pop rcx")
tstr += d(COMPUTING_HEAP_START)
tstr += g("mov byte ptr [rcx], dl")
tstr += g("jmp 0")
tstr += g("jmp 0")
tstr += g("jmp 0")

tstr += g("inc eax")*8

# ebx = dword ptr [eax]
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("mov bh, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov bl, byte ptr [rax]")
tstr += (g("shl ebx"))*16
tstr += g("dec eax")
tstr += g("mov bh, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov bl, byte ptr [rax]")
tstr += g("inc eax") * 8 # eax points to .y of the other team
# ecx = word ptr [eax]
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("inc eax")
tstr += g("mov ch, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov cl, byte ptr [rax]")
tstr += (g("shl ecx"))*16
tstr += g("dec eax")
tstr += g("mov ch, byte ptr [rax]")
tstr += g("dec eax")
tstr += g("mov cl, byte ptr [rax]")
#ebx/ecx is the other team location

#subtract locations and scale them
tstr += g("sub ebx, esi")
tstr += g("sub ecx, edi")
tstr += g("mov esi, ebx")
tstr += g("mov edi, ecx")
tstr += g("shr esi") * 4 # 1024 -> 64 (non existing ship distance is 0xff)
tstr += g("shr edi") * 4 # 1024 -> 64
#scale angle
tstr += g("shr edx") * 2


#create table index
tstr += g("pop rax")
tstr += d(0x000000000000007f) #mask: just get 0->64 values with sign
tstr += g("and esi, eax")
tstr += g("shl esi") * 7
tstr += g("and edi, eax")
tstr += g("or esi, edi")
tstr += g("shl esi") * 7
tstr += g("or esi, edx")
# esi is the table index [dx/64, dy/64, my_angle/4]

MOVE_TABLE_OFFSET = 0x100000
MOVE_TABLE_LOCATION = OUTPUT_AREA+MOVE_TABLE_OFFSET
tstr += g("pop rax")
tstr += d(COMPUTING_STACK_START+MOVE_TABLE_OFFSET)
tstr += g("add eax, esi")
tstr += g("pop rbx")
tstr += d(0x0)
tstr += g("mov bl, byte ptr [rax]")
tstr += g("pop rcx")
tstr += d(COMPUTING_HEAP_START)
tstr += g("mov byte ptr [rcx], bl")

#tstr += g("jmp 0")
#tstr += s(MOVE_TABLE_LOCATION)
#tstr += create_move_table()

save_to_team_solution(tstr, 6)
save_extra_to_team_solution(create_move_table(), 6)


#TODO debug on tick > 256


##############################################################

tstr = ""
for i in range(20):
    tstr += g("pop rax") #rdi is team_id
    tstr += d(COMPUTING_HEAP_START+16)
    tstr += g("pop rsi")
    tstr += d(0)
    tstr += g("pop rdi")
    tstr += d(0)
    tstr += g("pop rbx")
    tstr += d(0)
    tstr += g("pop rcx")
    tstr += d(0)
    tstr += g("pop rdx")
    tstr += d(0)
    tstr += g("mov bl, byte ptr [rax]")
    tstr += g("mov edi, ebx")
    tstr += (g("shl edi"))*8 #rdi is team_id *0x100

    tstr += g("pop rbx")
    tstr += d(0x0)

    tstr += g("pop rax")
    tstr += d(COMPUTING_HEAP_START+0x100+8*5)
    tstr += g("add eax, edi") #eax points to .x of our team

    # ebx = dword ptr [eax]
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("mov bh, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov bl, byte ptr [rax]")
    tstr += (g("shl ebx"))*16
    tstr += g("dec eax")
    tstr += g("mov bh, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov bl, byte ptr [rax]")
    tstr += g("inc eax") * 8 # eax points to .y of our team
    # ecx = word ptr [eax]
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("mov ch, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov cl, byte ptr [rax]")
    tstr += (g("shl ecx"))*16
    tstr += g("dec eax")
    tstr += g("mov ch, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov cl, byte ptr [rax]")
    #ebx/ecx is our location

    # move our location to esi/edi
    tstr += g("mov esi, ebx")
    tstr += g("mov edi, ecx")

    tstr += g("pop rax")
    # we do not check if the bullet exists (so there is always a bullet at 0)
    tstr += d(COMPUTING_HEAP_START+0x2000+i*0x30+0x10)
    # ebx = dword ptr [eax]
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("mov bh, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov bl, byte ptr [rax]")
    tstr += (g("shl ebx"))*16
    tstr += g("dec eax")
    tstr += g("mov bh, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov bl, byte ptr [rax]")
    tstr += g("inc eax") * 8 # eax points to .y of the bullet
    # ecx = word ptr [eax]
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("inc eax")
    tstr += g("mov ch, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov cl, byte ptr [rax]")
    tstr += (g("shl ecx"))*16
    tstr += g("dec eax")
    tstr += g("mov ch, byte ptr [rax]")
    tstr += g("dec eax")
    tstr += g("mov cl, byte ptr [rax]")
    #ebx/ecx is the bullet

    #tstr += g("jmp 0")
    tstr += g("sub ebx, esi")
    tstr += g("sub ecx, edi")
    tstr += g("mov esi, ebx")
    tstr += g("mov edi, ecx")
    #esi/edi is the difference

    tstr += g("mov eax, esi")
    tstr += g("imul eax")
    tstr += g("mov esi, eax")
    tstr += g("mov eax, edi")
    tstr += g("imul eax")
    tstr += g("mov edi, eax")

    tstr += g("add esi, edi") #squared distance
    tstr += g("pop rbx")
    tstr += d(pow(100,2))
    tstr += g("sub esi, ebx") # negative if near
    tstr += (g("shr esi"))*31
    tstr += g("pop rax")
    tstr += d(0x1)
    tstr += g("and esi, eax") # esi is 1 if near
    tstr += g("not esi") 
    tstr += g("and esi, eax") # esi is 0 if near
    tstr += (g("shl esi"))*6 # 8 gadgets

    tstr += g("add esp, esi")
    tstr += g("pop rdx")
    tstr += d(ord(b's'))
    tstr += g("pop rcx")
    tstr += d(COMPUTING_HEAP_START)
    tstr += g("mov byte ptr [rcx], dl")
    tstr += g("jmp 0")
    tstr += g("jmp 0")
    tstr += g("jmp 0")

tstr += g("pop rdx")
tstr += d(ord(b'l'))
tstr += g("pop rcx")
tstr += d(COMPUTING_HEAP_START)
tstr += g("mov byte ptr [rcx], dl")

save_to_team_solution(tstr, 3)
