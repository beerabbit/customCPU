#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t in_a[16],in_b[16], outs[16], res[2], carry1, carry2, sum1;

/* 관상용
void do_halfaddr(uint8_t a, uint8_t b){
carry = a & b;
sum = a ^ b;
}*/

void do_fulladdr(uint8_t a, uint8_t b, uint8_t c){
carry1 = a&b;
sum1 = a^b;
carry2 = sum1&c;
sum1 = sum1^c;
carry2 = carry1 | carry2;
res[0] = sum1;
res[1] = carry2;
printf("a : %d b : %d c : %d sum : %d carry : %d\n", a,b,c,res[0],res[1]);
}

//거꾸로 들어간다는점 주의
uint16_t do_add16(uint8_t* a, uint8_t* b){
uint8_t carrybuf;
for (int i=0; i<16; i++){
    if (i==0){
        do_fulladdr(a[15], b[15], 0);
        outs[15] = res[0];
        carrybuf = res[1];
    }
    else{
        do_fulladdr(a[15-i], b[15-i], carrybuf);
        outs[15-i] = res[0];
        carrybuf = res[1];
    }
}
}

//2진수 보기 힘드러요 오류 있어서 수정해야함
/*
int convert(uint8_t* res){
    int dec = 0, rem = 1, j=0;
    for(int i=0; i<16; i++){
        j = 15-i;
        if (i == 15){
            dec += res[15];
        }
        while(j!=0){
            rem = rem * 2;
            j--;
        }
        dec += res[i] * rem;
        rem = 1;
    }
    return dec;
}*/

int main(int argc, char* argv[]){
//ascii로 변환되니까 48 빼주자
    for (int i=0; i<16; i++){
    in_a[i] = (argv[1][i])-48;
    }
    for (int i=0; i<16; i++){
        in_b[i] = (argv[2][i])-48;
    }
    do_add16(in_a,in_b);
    for (int i=0; i<16; i++){
    printf("%d",outs[i]);
    }
    printf("\n");
    //printf("\n%d\n", convert(outs));

}