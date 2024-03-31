#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Password Generator.h"



char LA[] =  "abcdefghijklmnopqrstuvwxyz";
char UA[] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Num[] =  "1234567890";



char Combine_All_characters() {
	const int  totallength = sizeof(LA) + sizeof(UA) + sizeof(Num);
	char characters[totallength];
	int index = 0;
	for (int i = 0; LA[i] != '\O'; i++) {
		characters[index++] = LA[i];

	}

	return 0;
}





int main() {
	


	return 0;
	

}