/*  
	File name     : controller.c
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 3 April 2025
    Description   : Implementation of controller.h for city management system
*/

#include "controller.h"

void loadInitialData(ListCity *cities) {
    // Nama Kota
    char* initialCities[] = {"Palembang", "Bandung", "Jakarta"};
    
    // Data Nama kota Palembang
    char* PalembangPeople[] = {"Mercy", "Shin", "Doley"};
    
    // Data Nama kota Bandung
    char* BandungPeople[] = {"Asep", "Rudi", "Popi"};
    
    // Data Nama kota Jakarta
    char* JakartaPeople[] = {"Roufiel Hado", "Udin", "Ucup"};
    
    int i, j;
    // Inisialisasi data ke List
    for (i = 0; i < 3; i++) {
        Pcity newCity = Constructor(initialCities[i]);
        if (newCity == NULL) {
            displayMemoryErrorMessage();
            return;
        }
        
        if (i == 0) { // Palembang
            for (j = 0; j < 3; j++) {
                InsertLastV(&(First(ListName(newCity))), PalembangPeople[j]);
            }
        } else if (i == 1) { // Bandung 
            for (j = 0; j < 2; j++) {
                InsertLastV(&(First(ListName(newCity))), BandungPeople[j]);
            }
        } else if (i == 2) { // Jakarta
            for (j = 0; j < 2; j++) {
                InsertLastV(&(First(ListName(newCity))), JakartaPeople[j]);
            }
        }
       
        InsertAkhir(&(Head(*cities)), newCity);
    }
    
}

// Insert Kota Baru
void handleAddCity(ListCity *cities) {
    char *cityName = NULL;
    
    if (cities == NULL) {
        displayMemoryErrorMessage();
        waitForEnter();
        return;
    }
    
    system("cls");
    drawbox(50, 7);
    gotoxy(10, 2);
    printf("Add New City");
    gotoxy(5, 4);
    readCityName(&cityName);
    
    if (cityName == NULL) {
        gotoxy(5, 6);
        printf("Failed to read city name.");
        waitForEnter();
        return;
    }
    
    // Mengecek apakah kota sudah ada?
    Pcity existingCity = FindCity(*cities, cityName);
    if (existingCity != NULL) {
        gotoxy(5, 6);
        displayCityExistsMessage(cityName);
        free(cityName);
        waitForEnter();
        return;
    }
    
    // Membuat node untuk kota
    Pcity newCity = Constructor(cityName);
    if (newCity == NULL) {
        gotoxy(5, 6);
        displayMemoryErrorMessage();
        free(cityName); 
        waitForEnter();
        return;
    }
    
    // Masukan kota ke ListCity
    InsertAkhir(&(Head(*cities)), newCity);
    
    gotoxy(5, 6);
    displayCityAddedMessage(cityName);
    
    free(cityName);
    
    waitForEnter();
}

// Memasukan data nama ke suatu kota
void handleAddName(ListCity *cities) {
    char *cityName = NULL;
    char *personName = NULL;
    
    system("cls");
    drawbox(50, 9);
    gotoxy(10, 2);
    printf("Add Person to City");
    
    gotoxy(5, 4);
    readCityName(&cityName);
    

    Pcity city = FindCity(*cities, cityName);
    if (city == NULL) {
        gotoxy(5, 6);
        displayCityNotFoundMessage(cityName);
        waitForEnter();
        return;
    }
    
    gotoxy(5, 6);
    readPersonName(&personName);
    
    // If this is the first person, initialize the list
    if (ListEmpty(ListName(city))) {
        List nameList;
        CreateList(&nameList, TYPE_STRING);
        ListName(city) = nameList;
    }

    InsertLastV(&(First(ListName(city))), personName);
    
    gotoxy(5, 8);
    displayNameAddedMessage(personName, cityName);
    waitForEnter();
}

// Menghapus sebuah kota
void handleDeleteCity(ListCity *cities) {
    char *cityName = NULL;
    
    system("cls");
    drawbox(50, 7);
    gotoxy(10, 2);
    printf("Delete City");
    
    gotoxy(5, 4);
    readCityName(&cityName);
    
    // Find city
    Pcity city = FindCity(*cities, cityName);
    if (city == NULL) {
        gotoxy(5, 6);
        displayCityNotFoundMessage(cityName);
        waitForEnter();
        return;
    }
    
    DeleteByName(&(*cities), cityName);
    
    gotoxy(5, 6);
    displayCityDeletedMessage(cityName);
    waitForEnter();
}

// Menghapus nama dari suatu kota
void handleDeleteName(ListCity *cities) {
    char *cityName = NULL;
    char *personName = NULL;
    
    system("cls");
    drawbox(50, 9);
    gotoxy(10, 2);
    printf("Delete Person from City");
    
    gotoxy(5, 4);
    readCityName(&cityName);
    
    Pcity city = FindCity(*cities, cityName);
    if (city == NULL) {
        gotoxy(5, 6);
        displayCityNotFoundMessage(cityName);
        free(cityName); 
        waitForEnter();
        return;
    }
    
    gotoxy(5, 6);
    readPersonName(&personName);
    
    if (ListEmpty(ListName(city))) {
        gotoxy(5, 8);
        printf("No people registered in city '%s'!", cityName);
        free(cityName);  
        free(personName); 
        waitForEnter();
        return;
    }
    
    address person = SearchByValue(ListName(city), personName);
    if (person == NULL) {
        gotoxy(5, 8);
        printf("Person '%s' not found in city '%s'!", personName, cityName);
        free(cityName);
        free(personName);
        waitForEnter();
        return;
    }
    
    DeleteByValue(&(ListName(city)), personName);
    
    gotoxy(5, 8);
    displayNameDeletedMessage(personName, cityName);
    
    free(cityName);
    free(personName);
    
    waitForEnter();
}

// Menampilkan seluruh data
void handleDisplayAllData(ListCity cities) {
    system("cls");
    drawbox(60, 5);
    gotoxy(25, 2);
    printf("All City Data");
    
    if (ListCityEmpty(cities)) {
        gotoxy(5, 5);
        printf("No cities in the database!");
        gotoxy(5, 23);
        waitForEnter();
        return;
    }
    
    Pcity temp = Head(cities);
    
    gotoxy(5, 5);
    
    PrintAllCityData(cities);
    
    gotoxy(5, 23);
    waitForEnter();
}

// Menampilkan data suatu kota
void handleDisplayCityData(ListCity cities) {
    char *cityName = NULL;
    
    system("cls");
    drawbox(50, 7);
    gotoxy(10, 2);
    printf("Display City Data");
    
    gotoxy(5, 4);
    readCityName(&cityName);
    
    Pcity city = FindCity(cities, cityName);
    if (city == NULL) {
        gotoxy(5, 6);
        displayCityNotFoundMessage(cityName);
        waitForEnter();
        return;
    }
    
    system("cls");
    drawbox(60, 5);
    gotoxy(25, 2);
    printf("City: %s", cityName);
    
    if (ListEmpty(ListName(city))) {
        gotoxy(5, 5);
        printf("No people registered in this city.");
    } else {
        gotoxy(0, 5);
        
        PrintCityData(city);
    }
    
    gotoxy(5, 18);
    waitForEnter();
}

// Menghitung seluruh nama dan seluruh kota
void handleCountAllNames(ListCity cities) {
    system("cls");
    drawbox(60, 5);
    gotoxy(25, 2);
    printf("Count All Names");
    
    if (ListCityEmpty(cities)) {
        gotoxy(5, 5);
        printf("No cities in the database!");
        waitForEnter();
        return;
    }
    
    int cityCount = countCity(cities);

    int totalNames = CountTotalNames(Head(cities));
    
    gotoxy(5, 5);
    displayTotalNamesMessage(cityCount, totalNames);
    waitForEnter();
}

// Menghitung nama disuatu kota
void handleCountNamesOfCity(ListCity cities) {
    char *cityName = NULL;
    
    system("cls");
    drawbox(50, 7);
    gotoxy(10, 2);
    printf("Count Names in City");
    
    gotoxy(5, 4);
    readCityName(&cityName);
    
    Pcity city = FindCity(cities, cityName);
    if (city == NULL) {
        gotoxy(5, 6);
        displayCityNotFoundMessage(cityName);
        waitForEnter();
        return;
    }
    
    int count = countNameInCity(city);
    
    gotoxy(5, 6);
    displayCityNameCountMessage(cityName, count);
    waitForEnter();
}

// Menghapus seluruh listCity
void cleanupMemory(ListCity *cities) {
    ClearListCity(&(*cities));
}
