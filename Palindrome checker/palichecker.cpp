#include <stdio.h>


void get_input() {
	char palindrome[10];
	

	for (int i = 0; i < 10; i++) {
		printf("please enter in the word or Phrase You'd like to check:");
		scanf_s("%s", &palindrome, sizeof(palindrome));
	}
}


int main() {

	get_input();
	return 0;
}


