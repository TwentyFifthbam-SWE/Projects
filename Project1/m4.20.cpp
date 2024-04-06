#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_FLIGHTS 100
#define MAX_AIRLINES 10
#define MAX_CITY_LENGTH 50

const char* source = "C:\\Users\Josh\Downloads\teams.txt";
const char* source2 = "C:\\Users\Josh\Downloads\Westjet.txt";
const char* source3 = "C:\\Users\Josh\Downloads\Air Canada.txt";
const char* mode = "r";

struct FlightEntry {
    char airline[MAX_AIRLINES];
    char source[MAX_CITY_LENGTH];
    char Destination[MAX_CITY_LENGTH];
    int Fare;
};
struct LowestFare {
        char airline[MAX_AIRLINES];
        char source[MAX_CITY_LENGTH];
        char Destination[MAX_CITY_LENGTH];
        int Fare;
    };
struct Flightpair {
        struct FlightEntry;
        int isfilled;
        
    
    };



void displayLeastFareDetails(struct FlightEntry flights[], int numflights) {
    FILE* WESTJET;
    FILE* Aircanada;
    struct FlightEntry leastfare[MAX_AIRLINES];
    for (int i = 0; i < MAX_AIRLINES; i++); {

    }

    


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


int parseline(char* source,char* destination,int* fare,char* read) {
    if (sscanf_s(read, "%[^,],%[^,],%d", source, destination, fare) == 3) {
        return 1;// parsing passed

    }
    else
    {
        return 0;// parsing failed
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
