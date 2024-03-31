#include <stdio.h>
#include <stdlib.h>



const char Upper_case[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
 const char Lower_case[] = { "abcdefghijklmnopqrstuvwxyz" };
 const char  Numbers[] = { "0123456789" };
 const char Sp_chars[] = { "!@#$%^&*()_-+=,." };
 const	char All_Characters = sizeof(Upper_case) + sizeof(Lower_case) + sizeof(Numbers) + sizeof(Sp_chars);
 char Your_Password[20]{ "abcdefghijklmnop" };

void userinput() {
	printf("Please enter in a new password(no special characters):");
	fgets(Your_Password, sizeof(Your_Password), stdin);
	printf("your password is: %s", sizeof(Your_Password), Your_Password);
}

void Errorchecker() {

	if (Your_Password == Sp_chars) {
		printf(" no special characters allowed try again later");
		exit;
		
	}
	else
	{
		printf("password change was successful please save it somewhere safe for future use");
		exit;
	}
}


int main() {
	userinput();
	Errorchecker();


	return 0;
}