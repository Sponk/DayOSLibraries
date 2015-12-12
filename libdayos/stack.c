#include <stdio.h>
#include <stdlib.h>

void* __stack_chk_guard = NULL;
 
void setup_stack_chk()
{
	uint32_t* p;
	p = (uint32_t*) &__stack_chk_guard;
 
	*p =  0x00000aff;
}
 
void __attribute__((noreturn)) __stack_chk_fail()
{ 
	printf("Stack overflow/corruption detected!");
	exit(-1);
}
