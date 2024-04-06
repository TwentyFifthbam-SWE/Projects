#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#define Max_length 100
#define MAX_ENTRIES 100



struct lowest_Fare {
	char Source[50];
	char destination[50];
	int fare;
	char airline[50];
};
struct flightentry{
	char Source[50];
	char destination[50];
	int fare;
	char airline[50];
};
struct Flight_Info {
	int Fl_Info_Array[Max_length];
	
};


void displayleastfare() {
	char flights[100];
	int lowest_Fares[100];
	
	struct flightentry flights[MAX_ENTRIES];
	struct lowestFare lowest_Fares[MAX_ENTRIES];
	{

	};


}



void processFlight(ftp) {
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