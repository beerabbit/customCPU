#include "fulladdr.h"

// halfaddr 2개로 구현 가능
void do_fulladdr(uint8_t a, uint8_t b, uint8_t c){

do_halfaddr(a,b);
carrybuf = carry;
do_halfaddr(sum,c);
carry = carrybuf | carry;
res[0] = sum;
res[1] = carry;
}
