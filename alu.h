#include <stdio.h>
#include <stdbool.h>
/* control bit (sequence)
zx : 1 => x = 0
nx : 1 => x != x (bit flip)
zy : 1 => y = 0
ny : 1 => y != y (bit flip)
f : 1 => out = x+y else out = x&y
no : 1 => out =! out (defeasance)
*/
/* flag
zr  : out = 1 else 0
ng : out <0 1 else 0

*/
unsigned short x;
unsigned short y;

unsigned short out;

typedef struct alu_set_ {
bool zx;
bool nx;
bool zy;
bool ny;
bool f;
bool no;
} alu_set_t;

typedef struct alu_flags_ {
bool zr;
bool ng;
} alu_flags_t;

alu_flags_t setflag(bool zx, bool nx, bool zy, bool ny, bool f, bool no);