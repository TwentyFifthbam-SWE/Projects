/*
* FILE : m4.cpp
* PROJECT : Seng1000 - Major #4
* PROGRAMMER : Joshua Harvey
* FIRST VERSION : 2024/04/
* DESCRIPTION :
* The functions in this file are used to check flight info from a txt file and the shoot back the most affordable fare
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_FLIGHTS 100
#define MAX_AIRLINES 10
#define MAX_CITY_LENGTH 50

// Global variable for the file path
const char* source = "C:\\Users\\Josh\\Downloads\\Air Canada";
const char* mode = "r";

// Structure to hold flight information
struct FlightEntry {
	char airline[MAX_CITY_LENGTH];
	char source[MAX_CITY_LENGTH];
	char Destination[MAX_CITY_LENGTH];
	int Fare;
};

// Structure to hold flight information with the lowest fare
struct LowestFare {
	char airline[MAX_CITY_LENGTH];
	char source[MAX_CITY_LENGTH];
	char Destination[MAX_CITY_LENGTH];
	int Fare;
};

// Structure to represent a pair of flights
struct Flightpair {
	struct FlightEntry; // Not sure about this line, seems incomplete
	int isfilled; // Indicates whether the flight pair is filled
};

// Function prototypes
void displayLeastFareDetails(struct FlightEntry flights[], int numflights);
int parseline(char* source, char* destination, int* fare, char* read);
int processFlight(const char* filename, struct FlightEntry flights[], int* totalCount);

int main() {
	// Array to store flight entries
	struct FlightEntry flights[MAX_FLIGHTS];
	// Total count of flights read
	int totalCount = 0;
	// Process the flight data and display the least fare details
	processFlight("C:\\Users\\Josh\\Downloads\\Air Canada", flights, &totalCount);
	displayLeastFareDetails(flights, totalCount);
	return 0;
}

// Function to parse a line from the flight data file
int parseline(char* source, char* destination, int* fare, char* read) {
	// Parse the source, destination, and fare from the line
	if (sscanf_s(read, "%[^ -] - % [^, ], % d", source, (unsigned)sizeof(source), destination, (unsigned)sizeof(destination), fare) == 3) {
		return 1; // Parsing successful
	}
	else {
		return 0; // Parsing failed
	}
}

// Function to process the flight data from a file
int processFlight(const char* filename, struct FlightEntry flights[], int* totalCount) {
	FILE* source;
	// Attempt to open the file for reading
	errno_t err = fopen_s(&source, filename, "r");
	if (err != 0 || source == NULL) {
		printf("Error opening file %s. Error code: %d\n", filename, err);
		return 0;
	}
	char line[255];
	// Read lines from the file and parse flight data
	while (fgets(line, sizeof(line), source) != NULL && *totalCount < MAX_FLIGHTS) {
		if (sscanf_s(line, "%[^ -] - %[^, ], % d", flights[*totalCount].airline,
			(unsigned)sizeof(flights[*totalCount].airline),
			flights[*totalCount].source,
			(unsigned)sizeof(flights[*totalCount].source),
			flights[*totalCount].Destination,
			(unsigned)sizeof(flights[*totalCount].Destination),
			&flights[*totalCount].Fare) != 4) {
			printf("Error parsing line from file %s.\n", filename);
			fclose(source);
			return 0; // Return 0 to indicate failure
		}
		(*totalCount)++;
	}
	// Close the file
	fclose(source);
	return 1; // Processing successful
}

// Function to display the flight with the least fare for each source-destination pair
void displayLeastFareDetails(struct FlightEntry flights[], int numflights) {
	// Array to store the flight with the least fare for each source-destination pair
	struct FlightEntry leastfare[MAX_AIRLINES];
	// Initialize the fare of each flight to a high value
	for (int i = 0; i < MAX_AIRLINES; i++) {
		leastfare[i].Fare = 0;
	}
	// Find the flight with the least fare for each source-destination pair
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
	// Display the flight details for each source-destination pair with the least fare
	for (int i = 0; i < MAX_AIRLINES; i++) {
		if (leastfare[i].Fare != 0) {
			printf("%s: %s - %s, Fare $%d\n", leastfare[i].airline, leastfare[i].source, leastfare[i].Destination, leastfare[i].Fare);
		}
	}
}
