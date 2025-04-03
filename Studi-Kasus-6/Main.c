/*
    File name   : Main.c
    Made by     : Muhammad Nabil Syauqi Rasyiq
    Date        : 3 April 2025
    Description : Main program for city management system
*/

#include "controller.h"

int main(int argc, char *argv[]) {
    ListCity cities;
    CreateCityList(&cities);
    
    int choice;
    boolean running = true;
    
    // Menginisialisasi sample data
    loadInitialData(&cities);
    
    // Main program loop
    while (running) {
        displayMainMenu();
        choice = getMenuChoice();
        
        switch (choice) {
            case 1: // Add new city
                handleAddCity(&cities);
                break;
                
            case 2: // Add person to city
                handleAddName(&cities);
                break;
                
            case 3: // Delete city
                handleDeleteCity(&cities);
                break;
                
            case 4: // Delete person from city
                handleDeleteName(&cities);
                break;
                
            case 5: // Display all data
                handleDisplayAllData(cities);
                break;
                
            case 6: // Display city data
                handleDisplayCityData(cities);
                break;
                
            case 7: // Count all names
                handleCountAllNames(cities);
                break;
                
            case 8: // Count names in city
                handleCountNamesOfCity(cities);
                break;
                
            case 9: // Exit
                running = false;
                displayExitMessage();
                break;
                
            default: // Invalid choice
                displayInvalidChoiceMessage();
                break;
        }
    }
    // memastikan semua data di dealokasikan terlebih dahulu
    cleanupMemory(&cities);
    
    return 0;
}
