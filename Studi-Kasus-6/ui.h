/*	File name 	: ui.h
	Made by		: Muhammad Nabil Syauqi Rasyiq
	Date		: 27 March 2025
*/

#ifndef UI_H
#define UI_H
#include <stdio.h>
#include <string.h>
#include <conio.h> // Untuk getch()

// Constants for input sizes
#define MAX_NAME_LENGTH 1024
#define MAX_CITY_LENGTH 1024

// Main menu functions
void displayMainMenu();
int getMenuChoice();
void displayExitMessage();
void displayInvalidChoiceMessage();

// Input functions
void readCityName(char* cityName);
void readPersonName(char* personName);
int readCountChoice();

// Output message functions
void displayCityAddedMessage(char* cityName);
void displayCityExistsMessage(char* cityName);
void displayCityLimitMessage();
void displayMemoryErrorMessage();
void displayNameAddedMessage(char* personName, char* cityName);
void displayCityNotFoundMessage(char* cityName);
void displayCityDeletedMessage(char* cityName);
void displayNameDeletedMessage(char* personName, char* cityName);
void displayCityNameCountMessage(char* cityName, int count);
void displayTotalNamesMessage(int cityCount, int totalNames);

// Fungsi tambahan untuk menunggu Enter
void waitForEnter();

#endif /* UI_H */
