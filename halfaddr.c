#include "halfaddr.h"

/* Truth table
a b sum carry
0 0 0 0
0 1 1 0
1 0 1 0
1 1 0 1
sum은 xor, carry는 and로 구현 가능
*/
void do_halfaddr(uint8_t a, uint8_t b){
carry = a & b;
sum = a ^ b;

}