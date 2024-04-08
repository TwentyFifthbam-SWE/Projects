#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_FLIGHTS 100
#define MAX_AIRLINES 10
#define MAX_CITY_LENGTH 50

const char* source = "\\Downloads\\teams";
const char* source2 = "\\Downloads\\Westjet";
const char* source3 = "\\Downloads\\Air Canada";
const char* mode = "r";

struct FlightEntry {
    char airline[MAX_CITY_LENGTH];
    char source[MAX_CITY_LENGTH];
    char Destination[MAX_CITY_LENGTH];
    int Fare;
};
struct LowestFare {
        char airline[MAX_CITY_LENGTH];
        char source[MAX_CITY_LENGTH];
        char Destination[MAX_CITY_LENGTH];
        int Fare;
    };
struct Flightpair {
        struct FlightEntry;
        int isfilled;
        
    
    };



void displayLeastFareDetails(struct FlightEntry flights[], int numflights) {
    
    
    struct FlightEntry leastfare[MAX_AIRLINES];
    
    
    
    for (int i = 0; i < MAX_AIRLINES; i++) {
        leastfare[i].Fare = INT_MAX;
   }
    for (int i = 0; i < numflights; i++) {
        struct FlightEntry currentFlight = flights[i];
        int j = 0;
        while(j < MAX_FLIGHTS){
            if (strcmp(leastfare[j].source, currentFlight.source) == 0 &&
                strcmp(leastfare[i].Destination, currentFlight.Destination) == 0)
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
    
}
    




int parseline(char* source,char* destination,int* fare,char* read) {
    if (sscanf_s(read, "%[^,],%[^,],%d", source, (unsigned)sizeof(source),destination, (unsigned)sizeof(destination),
        fare) == 3) {
        return 1;// parsing passed

    }
    else
    {
        return 0;// parsing failed
    }
}

int processFlight(const char* filename,struct FlightEntry flights[], int* totalCount) {
  
    FILE* source;

    errno_t err = fopen_s(&source, filename, "r");
    if (err != 0 || source == NULL) {
        printf("error opening file %s.\n", filename);
        return 0;
    }
    char line[100];
    while (fgets(line, sizeof(line), source) != NULL && *totalCount < MAX_FLIGHTS) {
        if (sscanf_s(line, "%[^,],%[^,],%[^,],%d", flights[*totalCount].airline,
            (unsigned)sizeof(flights[*totalCount].airline),
            flights[*totalCount].source,
            (unsigned)sizeof(flights[*totalCount].source),
            flights[*totalCount].Destination,
            (unsigned)sizeof(flights[*totalCount].Destination),
            &flights[*totalCount].Fare) != 4) {
            printf("error parsing line from file %s.\n", filename);
            fclose(source);
            return 0; // Return 0 to indicate failure
        }
        (*totalCount)++;
    }

    fclose(source);
    return 1; // Return 1 to indicate success

}



int main() {
  
    struct FlightEntry flights[MAX_FLIGHTS];
    
    int totalCount = 0;
   
    processFlight("Air Canada.txt", flights, &totalCount);
    processFlight("Westjet.txt", flights, &totalCount);

    displayLeastFareDetails;
}
