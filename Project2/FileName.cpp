#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_FLIGHTS 100
#define MAX_CITY_LENGTH 50

const char* source = "C:\\Users\\Josh\\Downloads\\Air Canada.txt";

struct FlightEntry {
    char airline[MAX_CITY_LENGTH];
    char source[MAX_CITY_LENGTH];
    char Destination[MAX_CITY_LENGTH];
    int Fare;
};

void displayLeastFareDetails(struct FlightEntry flights[], int numflights);
int parseline(char* source, char* destination, int* fare, char* read);
int processFlight(const char* filename, struct FlightEntry flights[], int* totalCount);

 

int parseline(char* source, char* destination, int* fare, char* read) {
    if (sscanf_s(read, "%[^,-]-%[^,],%d", source, (unsigned)sizeof(source), destination, (unsigned)sizeof(destination), fare) == 3) {
        return 1; // Parsing passed
    }
    else {
        return 0; // Parsing failed
    }
}

int processFlight(const char* filename, struct FlightEntry flights[], int* totalCount) {
    FILE* source;
    errno_t err = fopen_s(&source, filename, "r");
    if (err != 0 || source == NULL) {
        printf("error opening file %s. Error code: %d\n", filename, err);
        return 0;
    }
    char line[255];
    while (fgets(line, sizeof(line), source) != NULL && *totalCount < MAX_FLIGHTS) {
        if (parseline(flights[*totalCount].airline, flights[*totalCount].source, &flights[*totalCount].Fare, line)) {
            (*totalCount)++;
        }
        else {
            printf("error parsing line from file %s.\n", filename);
            fclose(source);
            return 0;
        }
    }
    fclose(source);
    return 1;
}

void displayLeastFareDetails(struct FlightEntry flights[], int numflights) {
    struct FlightEntry leastfare[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        leastfare[i].Fare = INT_MAX;
    }
    for (int i = 0; i < numflights; i++) {
        struct FlightEntry currentFlight = flights[i];
        int j = 0;
        while (j < MAX_FLIGHTS) {
            if (strcmp(leastfare[j].source, currentFlight.source) == 0 &&
                strcmp(leastfare[j].Destination, currentFlight.Destination) == 0) {
                if (currentFlight.Fare < leastfare[j].Fare) {
                    leastfare[j] = currentFlight;
                }
                break;
            }
            j++;
        }
    }
    for (int i = 0; i < numflights; i++) {
        if (leastfare[i].Fare != INT_MAX) {
            printf("%s: %s - %s, Fare $%d\n", leastfare[i].airline, leastfare[i].source, leastfare[i].Destination, leastfare[i].Fare);
        }
    }
}
int main(){
    struct FlightEntry flights[MAX_FLIGHTS];
    int totalCount = 0;
    processFlight("C:\\Users\\Josh\\Downloads\\Air Canada.txt", flights, &totalCount);
    displayLeastFareDetails(flights, totalCount);
    return 0;
}