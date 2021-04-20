#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <inttypes.h>

#define cx uint64_t
#define _ }
#define __ {
#define ___ int
#define ____ printf
#define _____ ;
#define ______ scanf
#define fuyuna main()
#define float cx
#define x (
#define xx )
#define y getch()
#define fuee =
#define O0 ,
#define O1 /
#define O2 %

___ fuyuna __
    float num O0 p1000 _____
    ___ p100 O0 p10 O0 p1 _____
    ____ x"Masukkan angka:"xx _____
    ______  x "%ju" O0 &num xx _____
    p1000 fuee x num O1 1000 xx _____ 
    p100 fuee x num O2 1000 xx O1 100 _____
    p10 fuee x num O2 100 xx O1 10 _____
    p1 fuee x num O2 10 xx  _____
    ____ x "%ju\n%ju pecahan 1000\n%d pecahan 100\n%d pecahan 10\n%d satuan" O0 num O0 p1000 O0 p100 O0 p10 O0 p1 xx _____ 
    y _____
_
