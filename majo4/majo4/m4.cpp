#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 50
#define MAX_ENTRIES 100

struct FlightEntry {
    char source[50];
    char destination[50];
    int fare;
    char airline[50]; // Include airline information in FlightEntry
};

struct LowestFare {
    char source[50];
    char destination[50];
    int fare;
    char airline[50];
};

void parseLine(char* line, struct FlightEntry* entry) {
    sscanf(line, "%[^-] - %[^,], $%d, %[^\n]", entry->source, entry->destination, &entry->fare, entry->airline);
}

void processFlight(char* filename, struct FlightEntry* entries, int* totalEntries) {
    FILE* flightfile = fopen("C:\\Users\Redme\source\repos\Projects\majo4\majo4\aircanada.txt", "r");
    if (flightfile == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[255];
    while (fgets(buffer, sizeof(buffer), flightfile) != NULL && *totalEntries < MAX_ENTRIES) {
        parseLine(buffer, &entries[*totalEntries]);
        (*totalEntries)++;
    }

    fclose(flightfile);
}

void displayLeastFareDetails(struct FlightEntry* entries, int totalEntries) {
    struct LowestFare lowestFare;
    lowestFare.fare = 999999; // Initialize to a high value

    for (int i = 0; i < totalEntries; i++) {
        if (entries[i].fare < lowestFare.fare) {
            strcpy(lowestFare.source, entries[i].source);
            strcpy(lowestFare.destination, entries[i].destination);
            lowestFare.fare = entries[i].fare;
            strcpy(lowestFare.airline, entries[i].airline);
        }
    }

    printf("%s: %s to %s, Fare $%d\n", lowestFare.airline, lowestFare.source,
        lowestFare.destination, lowestFare.fare);
}

int main() {
    // Open flights.txt to read filenames
    FILE* flightFile = fopen("C:\\Users\\Redme\\source\\repos\\Projects\\majo4\\majo4\\flights.txt", "r");
    if (flightFile == NULL) {
        printf("Error opening file: flights.txt\n");
        return 1;
    }

    char filename[MAX_LENGTH];
    int totalEntries = 0;
    struct FlightEntry entries[MAX_ENTRIES];

    // Read filenames from flights.txt and process each flight data file
    while (fgets(filename, sizeof(filename), flightFile) != NULL && totalEntries < MAX_ENTRIES) {
        filename[strcspn(filename, "\n")] = 0; // Remove newline character if present
        processFlight(filename, entries, &totalEntries);
    }

    // Close flights.txt
    fclose(flightFile);

    // Display least fare details
    displayLeastFareDetails(entries, totalEntries);

    return 0;
}

