#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int digit(long n) {
	if ( n < 0 ) {
		n = -n;
	}
	int k = (int)(log(n)/log(2));
	return k+1;
}

char *createBinary(long n) {
	const int maxLength = 65;
	char bin[maxLength + 1 + 1];
	bool minus = false;
	if ( n < 0 ) {
		minus = true;
		n = -n;
	}
	int i;
	for ( i = 0; i < maxLength && n != 0; i++ ) {
		long h = n / 2;
		long m = n - 2 * h;
		n = h;
		bin[i] = m;
	}
	char *ret = malloc(i+1+(minus?1:0));
	char *p = ret;
	if ( minus ) {
		*p++ = '-';
	}
	while ( i > 0 ) {
		*p++ = '0' + bin[--i];
	}
	return ret;
}

int main(int argc,char *argv[]) {
	long val = atol(argv[1]);
	char *bin = createBinary(val);
	printf("%s : %ld\n",bin, val);
	printf("digit = %d\n" ,digit(val));
	free(bin);
	return 0;
}
