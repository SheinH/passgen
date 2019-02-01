#include <stdio.h>
#include "sodium.h"

char output[3][7];

int main() {
	if (sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}
	char myInt;

	char randInt = randombytes_uniform(10) + '0';
	char randCapital = randombytes_uniform(26) + 'A';

	int randNum = randombytes_uniform(18);
	output[randNum / 6][randNum % 6] = randInt;

	int nextRand = randombytes_uniform(18);
	while(nextRand == randNum){
		nextRand = randombytes_uniform(18);
	}
	output[nextRand / 6][nextRand % 6] = randCapital;

	for(int i = 0; i < 3; i++){
		for(int i2 = 0; i2 < 6; i2++){
			if(output[i][i2] == 0)
				output[i][i2] = randombytes_uniform(26) + 'a';
		}
	}
	printf("%s-%s-%s\n",output[0],output[1],output[2]);
}
