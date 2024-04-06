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
    
    
    
    for (int i = 0; i < MAX_AIRLINES; i++) {
        leastfare[i].Fare = INT_MAX;
   }
    for (int i = 0; i < numflights; i++) {
        struct FlightEntry currentFlight = flights[i];
        int j = 0;
        while(j < MAX_FLIGHTS){
            if (strcmp(leastfare[j].source, currentFlight.source) == 0 &&
                strcmp(leastfare[i].Destination, currentFlight.source) == 0)
            {
                 if (currentFlight.Fare < leastfare[j].Fare) {
                    leastfare[j] = currentFlight;
               }
                break;
            }
            j++;
    
    }

    }
    for (int i = 0; i < MAX_FLIGHTS; i++)
    {
        if (leastfare[i].Fare != INT_MAX) {
            printf("%s: %s to %s, Fare $%d\n", leastfare[i].airline, leastfare[i].source, leastfare[i].Destination, leastfare[i].Fare);
        }
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

void processFlight(const char* filename,struct FlightEntry flights[], int* totalCount) {
  
    FILE* source;

    errno_t err = fopen_s(&source, filename, "r");
    if (err != 0 || source == NULL) {
        printf("error opening file %s.\n", filename);
        return;
    }
    char line[100];
    while (fgets(line,sizeof(line),source) != NULL && *totalCount <MAX_FLIGHTS)
    {
        sscanf(line, "%[^,],%[^,],%[^,],%d", flights[*totalCount].airline,
            flights[*totalCount].source, flights[*totalCount].Destination,
            &flights[*totalCount].Fare);
        (*totalCount)++;
    }
    fclose(source);
}



int main() {
  
    struct FlightEntry flights[MAX_FLIGHTS];
    
    int totalCount = 0;
   
    processFlight("Air Canada.txt", flights, &totalCount);
    processFlight("Westjest.txt", flights, &totalCount);

}
