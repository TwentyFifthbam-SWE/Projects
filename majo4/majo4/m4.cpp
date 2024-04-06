#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>









void processFlight() {
	FILE *ftptr;
	


}



int main() {
	FILE* ftptr = fopen("C:\\Users\\Redme\\OneDrive\\Documents\\flights.txt","r");
	char buffer[255];
	
	

	errno_t err = fopen_s(&ftptr, "C:\\Users\\Redme\\OneDrive\\Documents\\flights.txt", "r");
	
	if (ftptr == NULL) {
		printf("Error file does not exist please try  again!");

		return 1;
	}
   
	

   



}