// O(n*log(n))

#include <stdio.h>

#ifndef __cplusplus
typedef enum { false, true } bool;
#endif /* __cplusplus */

// the main part 
bool isPrime(int num)
{
    for (int d = 2; (d * d) < (num + 1); ++d)
	{
        if (!(num % d))
		{
            return false;
        }
     }
    return true;
}
 
int main (int argc, char * const argv[])
{
    for (int i = 0; i < 10000; ++i)
	{
        if (isPrime(i))
		{
            printf("%d\t", i);
        }
    }
	
	printf("\n");
}