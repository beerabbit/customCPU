#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "halfaddr.h"

uint8_t carrybuf;
uint8_t res[2];
void do_fulladdr(uint8_t a,uint8_t b, uint8_t c);