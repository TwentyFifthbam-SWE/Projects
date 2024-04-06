#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
const char* source = "C:\\Users\Josh\Downloads\teams.txt";
const char* source2 = "C:\\Users\Josh\Downloads\Westjet.txt";
const char* source3 = "C:\\Users\Josh\Downloads\Air Canada.txt";
const char* mode = "r";

struct FlightEntry {
    char source[50];
    char destination[50];
    int fare;
    char airline[50];
};

struct LowestFare {
    char source[50];
    char destination[50];
    int fare;
    char airline[50];
};




void displayLeastFareDetails() {
    struct lowestFare;
    FILE* WESTJET;
    FILE* Aircanada;
    if (fopen_s(&WESTJET, source2, mode)) {
        printf("failed to open file.\n");

    
        
}
    else
    {
        printf("file  opened succesfully.\n");
    }
 
    if (fopen_s(&Aircanada, source3, mode) != 0) {
        printf("failed to open file.\n");

    }
    else {
        printf("file opened succesfully.\n");
    }


}







int main() {
   
    
    char buffer[255];
    char* flights_txt;
    const char* source = "C:\\Users\Josh\Downloads\teams.txt";
    flights_txt = (char*)malloc(100 * sizeof(char));
   
    if (strcpy_s(flights_txt, sizeof(flights_txt), source) != 0) {
        printf("Copying failed\n");
        return 1;
    }
   
    char* fgets(char* flights_txt,  char* source);
    
    
    return 0;


}
