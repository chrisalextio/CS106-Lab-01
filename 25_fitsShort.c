#include <stdio.h>

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    // if the upper 17 bits of x is the same, then x can fit into short 

    // first shift x to the right by 15,
    // then shift a different instance of x to the right by 16
    // after which we use XOR to check whether or not the upper 17 bits are all the same
    // if same -> XOR will return 0, but that means it "passes", so we use logical NOT to 
    // return 1, ie. true
    return !((x >> 15) ^ (x >> 16));
}

int test_fitsShort(int x)
{
    short int sx = (short int) x;
    return x == sx;
}

int main(void)
{
    int x = 0;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
}
