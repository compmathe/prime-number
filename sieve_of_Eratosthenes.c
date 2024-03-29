#include <stdlib.h>
#include <stdio.h>

#define N 10000
#define size (N/6*2 + (N%6 == 5? 2: (N%6>0)))

int p[size / 32 + 1] = {1};

// the main part
int creat_prime(void)
{
	int i, j;
	int len, stp;
	int c = size + 1;
	for (i = 1; ((i&~1)<<1) * ((i&~1) + (i>>1) + 1) < size; i++)
	{
		if (p[i >> 5] >> (i & 31) & 1) continue;
		
		len = (i & 1)? ((i&~1)<<1) + 3: ((i&~1)<<2) + 1;
		stp = ((i&~1)<<1) + ((i&~1)<<2) + ((i & 1)? 10: 2);
		j = ((i&~1)<<1) * (((i&~1)>>1) + (i&~1) + 1) + ((i & 1)? ((i&~1)<<3) + 8 + len: len);
		
		for (; j < size; j += stp)
		{
			if (p[j >> 5] >> (j & 31) & 1 ^ 1)
				p[j >> 5] |= 1L << (j & 31), --c;
			if (p[(j-len) >> 5] >> ((j-len) & 31) & 1 ^ 1)
				p[(j-len) >> 5] |= 1L << ((j-len) & 31), --c;
		}
		
		if (j - len < size && (p[(j-len) >> 5] >> ((j-len) & 31) & 1 ^ 1))
			p[(j-len) >> 5] |= 1L << ((j-len) & 31), --c;
	}

	return c;
}

int main(int argc, char * const argv[])
{
	printf("%d ", creat_prime());

	return EXIT_SUCCESS;
}