#include "alu.h"


int main(){

 

}
alu_flags_t setflag(bool zx, bool nx, bool zy, bool ny, bool f, bool no){

alu_flags_t flags;

if(zx==true) x = 0;
if(nx==true) x = ~x;
if(zy==true) y = 0;
if(ny==true) y = ~y;
if(f==true) out = x+y;
if(f==false) out = x & y;
if(no==1) out = ~out;
if(out == 0) flags.zr = 1;
if(out < 0 ) flags.ng = 1;

return flags;
}