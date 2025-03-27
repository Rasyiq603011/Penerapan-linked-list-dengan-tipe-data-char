#include "logic.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    CityData cities[MAXCITIES];
    int cityCount = 0;
    int choice;
    
    // Initialize the array
    InitArray(cities, MAXCITIES);
    
    // Load initial data
    loadInitialData(cities, &cityCount);
    
    printf("Program telah dimuat dengan data awal.\n");
    waitForEnter(); // Menunggu Enter sebelum menampilkan menu pertama
    
    do {
    	system("cls");
        displayMainMenu();
        choice = getMenuChoice();
        
        switch (choice) {
            case 1: // Add a City
                handleAddCity(cities, &cityCount);
                break;
                
            case 2: // Add a Name to a City
                handleAddName(cities, cityCount);
                break;
                
            case 3: // Delete a City
                handleDeleteCity(cities, &cityCount);
                break;
                
            case 4: // Delete a Name from a City
                handleDeleteName(cities, cityCount);
                break;
                
            case 5: // Display All Data
                handleDisplayAllData(cities, cityCount);
                waitForEnter(); // Menunggu Enter setelah menampilkan data
                break;
                
            case 6: // Display Data for a Specific City
                handleDisplayCityData(cities, cityCount);
                waitForEnter(); // Menunggu Enter setelah menampilkan data
                break;
                
            case 7: // Count Names
                handleCountNames(cities, cityCount);
                break;
                
            case 8: // Exit
                displayExitMessage();
                printf("\nTekan Enter untuk keluar...");
                getch(); // Menunggu satu kali tekan tombol sebelum keluar
                break;
                
            default:
                displayInvalidChoiceMessage();
        }
    } while (choice != 8);
    
    // Clean up memory before exiting
    cleanupMemory(cities, cityCount);
    
    return 0;
}
