/*
 * =====================================================================================
 *
 *       Filename:  gcd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月14日 21时11分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

int gcd(int x, int y)
{
    if (x == y) {
        return x;
    }
    else if (x>y) {
        if (y == 0) {
            return x;
        }
        else if (x&1 && y&1) {
            return gcd(y, x-y);
        }
        else if (x&1) {
            return gcd(x, y>>1);
        }
        else if (y&1) {
            return gcd(x>>1, y);
        }
        else {
            return gcd(x>>1, y>>1)<<1;
        }
    }
    else {
        return gcd(y, x);
    }
}

void gcd_test(void)
{
    int x, y;
    x = 0;
    y = 3;
    printf("x = %d, y = %d, gcd(x, y) is %d .\n", x, y, gcd(x, y));
    x = 5;
    y = 3;
    printf("x = %d, y = %d, gcd(x, y) is %d .\n", x, y, gcd(x, y));
    x = 121;
    y = 1210;
    printf("x = %d, y = %d, gcd(x, y) is %d .\n", x, y, gcd(x, y));
    x = 17;
    y = 17;
    printf("x = %d, y = %d, gcd(x, y) is %d .\n", x, y, gcd(x, y));

}
