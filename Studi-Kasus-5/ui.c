/*	File name 	: ui.c
	Made by		: Muhammad Nabil Syauqi Rasyiq
	Date		: 27 March 2025
*/

#include "ui.h"

// Main menu functions
void displayMainMenu() {
    printf("\n===== CITY AND NAME MANAGEMENT =====\n");
    printf("1. Add a City\n");
    printf("2. Add a Name to a City\n");
    printf("3. Delete a City\n");
    printf("4. Delete a Name from a City\n");
    printf("5. Display All Data\n");
    printf("6. Display Data for a Specific City\n");
    printf("7. Count Names\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int getMenuChoice() {
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline
    return choice;
}

void displayExitMessage() {
    printf("Exiting program...\n");
}

void displayInvalidChoiceMessage() {
    printf("Invalid choice. Please try again.\n");
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

// Input functions
void readCityName(char* cityName) {
    printf("Enter city name: ");
    fgets(cityName, MAX_CITY_LENGTH, stdin);
    cityName[strcspn(cityName, "\n")] = 0; // Remove newline
}

void readPersonName(char* personName) {
    printf("Enter person name: ");
    fgets(personName, MAX_NAME_LENGTH, stdin);
    personName[strcspn(personName, "\n")] = 0; // Remove newline
}

int readCountChoice() {
    printf("1. Count names in a specific city\n");
    printf("2. Count total names in all cities\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline
    return choice;
}

// Output message functions
void displayCityAddedMessage(char* cityName) {
    printf("City '%s' added successfully.\n", cityName);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayCityExistsMessage(char* cityName) {
    printf("City '%s' already exists.\n", cityName);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayCityLimitMessage() {
    printf("Cannot add more cities. Maximum limit reached.\n");
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayMemoryErrorMessage() {
    printf("Failed to add city due to memory allocation failure.\n");
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayNameAddedMessage(char* personName, char* cityName) {
    printf("Name '%s' added to city '%s'.\n", personName, cityName);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayCityNotFoundMessage(char* cityName) {
    printf("City '%s' not found.\n", cityName);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayCityDeletedMessage(char* cityName) {
    printf("City '%s' and all its names deleted successfully.\n", cityName);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayNameDeletedMessage(char* personName, char* cityName) {
    printf("Name '%s' deleted from city '%s'.\n", personName, cityName);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayCityNameCountMessage(char* cityName, int count) {
    printf("City '%s' has %d names.\n", cityName, count);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

void displayTotalNamesMessage(int cityCount, int totalNames) {
    printf("Total names across all %d cities: %d\n", cityCount, totalNames);
    waitForEnter(); // Menunggu Enter sebelum kembali ke menu
}

// Implementasi fungsi waitForEnter
void waitForEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
    
    int ch;
    // Loop sampai tombol Enter (kode ASCII 13) ditekan
    while ((ch = getch()) != 13);
    
    // Bersihkan layar setelah Enter ditekan (opsional)
    system("cls");
}
