/*	
	File name 	: ui.c
	Made by		: Muhammad Nabil Syauqi Rasyiq and Claude AI
	Date		: 3 April 2025
	Description : Implementation of ui.h for city management system
*/

#include "ui.h"

// Main menu functions
void displayMainMenu() {
    system("cls"); // Clear screen
    drawbox(60, 5);
    gotoxy(20, 2);
    printf("CITY MANAGEMENT SYSTEM");
    gotoxy(10, 5);
    printf("1. Add a new city");
    gotoxy(10, 6);
    printf("2. Add a person to a city");
    gotoxy(10, 7);
    printf("3. Delete a city");
    gotoxy(10, 8);
    printf("4. Delete a person from a city");
    gotoxy(10, 9);
    printf("5. Display all data");
    gotoxy(10, 10);
    printf("6. Display city data");
    gotoxy(10, 11);
    printf("7. Count all names");
    gotoxy(10, 12);
    printf("8. Count names in a city");
    gotoxy(10, 13);
    printf("9. Exit");
    gotoxy(10, 15);
    printf("Enter your choice: ");
}

int getMenuChoice() {
    int choice;
    scanf("%d", &choice);
    fflush(stdin); 
    return choice;
}

void displayExitMessage() {
    system("cls");
    drawbox(50, 7);
    gotoxy(10, 2);
    printf("Thank you for using the program!");
    gotoxy(15, 4);
    printf("Have a nice day!");
    gotoxy(0, 8);
}

void displayInvalidChoiceMessage() {
    gotoxy(10, 16);
    printf("Invalid choice! Please try again.");
    waitForEnter();
}

void readCityName(char **CityName) {
    char temp[100];
    
    // Baca input dari pengguna
    printf("Masukkan nama kota: ");
    scanf(" %99[^\n]", temp); 
    fflush(stdin); // Membersihkan temp input
    
    // Hitung panjang string
    size_t len = strlen(temp);
    
    // Alokasi memori untuk nama dengan ukuran yang tepat
    *CityName = (char *)malloc((len + 1) * sizeof(char));
    if (*CityName == NULL) {
        displayMemoryErrorMessage();
        return;
    }
    
    // Salin buffer ke pointer nama
    strcpy(*CityName, temp);
}

// Fix buffer safety in readPersonName function
void readPersonName(char** personName) {
    char temp[100];
    
    // Baca input dari pengguna
    printf("Masukkan Nama: ");
    scanf(" %99[^\n]", temp); 
    fflush(stdin); // Membersihkan temp input
    
    // Hitung panjang string
    size_t len = strlen(temp);
    
    // Alokasi memori untuk nama dengan ukuran yang tepat
    *personName = (char *)malloc((len + 1) * sizeof(char));
    if (*personName == NULL) {
        displayMemoryErrorMessage();
        return;
    }
    
    // Salin buffer ke pointer nama
    strcpy(*personName, temp);
}

// Output message functions
void displayCityAddedMessage(char* cityName) {
    printf("\nCity '%s' has been added successfully!\n", cityName);
}

void displayCityExistsMessage(char* cityName) {
    printf("\nCity '%s' already exists in the database!\n", cityName);
}

void displayMemoryErrorMessage() {
    printf("\nError: Memory allocation failed!\n");
}

void displayNameAddedMessage(char* personName, char* cityName) {
    printf("\nPerson '%s' has been added to city '%s' successfully!\n", personName, cityName);
}

void displayCityNotFoundMessage(char* cityName) {
    printf("\nCity '%s' not found in the database!\n", cityName);
}

void displayCityDeletedMessage(char* cityName) {
    printf("\nCity '%s' has been deleted successfully!\n", cityName);
}

void displayNameDeletedMessage(char* personName, char* cityName) {
    printf("\nPerson '%s' has been deleted from city '%s' successfully!\n", personName, cityName);
}

void displayCityNameCountMessage(char* cityName, int count) {
    printf("\nThe city '%s' has %d registered person(s).\n", cityName, count);
}

void displayTotalNamesMessage(int cityCount, int totalNames) {
    printf("\nThere are %d cities with a total of %d registered person(s).\n", cityCount, totalNames);
}

void waitForEnter() {
    printf("\nPress Enter to continue...");
    getch();
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawbox(int width, int height) {
    int i, j;
    
    // Draw top border
    gotoxy(0, 0);
    printf("%c", 201); // Top-left corner
    for(i = 0; i < width - 2; i++) {
        printf("%c", 205); // Horizontal line
    }
    printf("%c", 187); // Top-right corner
    
    // Draw sides
    for(i = 1; i < height - 1; i++) {
        gotoxy(0, i);
        printf("%c", 186); // Vertical line
        gotoxy(width - 1, i);
        printf("%c", 186); // Vertical line
    }
    
    // Draw bottom border
    gotoxy(0, height - 1);
    printf("%c", 200); // Bottom-left corner
    for(i = 0; i < width - 2; i++) {
        printf("%c", 205); // Horizontal line
    }
    printf("%c", 188); // Bottom-right corner
}
