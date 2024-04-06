#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define Max_length 100













struct Flight_Info {
	int Fl_Info_Array[Max_length];
	
};





void processFlight() {
	struct Flight_Info flightinfo;
	FILE *ftptr;
	char buffer[255];
	


	ftptr = fopen("C:\\Users\\Redme\\OneDrive\\Documents\\flights.txt","r");
	
	if (ftptr == NULL) {
		printf("Error Opening file");
		return;
		}

	fgets(buffer, sizeof(buffer), ftptr);
	for(int i = 0; i < Max_length; i++){
		flightinfo.Fl_Info_Array[i] = i * 2;
	}

	fclose(ftptr);
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