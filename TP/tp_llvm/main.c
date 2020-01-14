#include<stdint.h>
#include<stdio.h>
uint32_t myUnsignedAddition (uint32_t a, uint32_t b) ;
int32_t mySignedAddition (int32_t a, int32_t b) ;
uint32_t multiplicationUnsigned (uint32_t a, uint32_t b) ;
int32_t  multiplicationSigned (int32_t a, int32_t b) ;

int main(){
uint32_t res = myUnsignedAddition (1,2) ;
int32_t res1 = mySignedAddition(-1, -8) ;
uint32_t res2 = multiplicationUnsigned(2,3);
int32_t res3 = multiplicationSigned(2,-3);
printf("%d\n",res3);
}