/*  File name     : logic.c
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 27 March 2025
*/

#include "logic.h"


// Load initial sample data (as per PDF example)
void loadInitialData(CityData* cities, int* cityCount) {
    AddCity(cities, cityCount, MAXCITIES , "Bandung");
    AddName(cities, 0, "Amir");
    AddName(cities, 0, "Wahab");
    AddName(cities, 0, "Yahya");
    
    AddCity(cities, cityCount, MAXCITIES , "Jakarta");
    AddName(cities, 1, "Badu");
    AddName(cities, 1, "Hasan");
    
    // Add a few more cities to meet the minimum requirement of 5 cities
    AddCity(cities, cityCount, MAXCITIES , "Surabaya");
    AddName(cities, 2, "Dodi");
    AddName(cities, 2, "Eko");
    
    AddCity(cities, cityCount, MAXCITIES , "Medan");
    AddName(cities, 3, "Faisal");
    
    AddCity(cities, cityCount, MAXCITIES , "Makassar");
    AddName(cities, 4, "Gani");
    AddName(cities, 4, "Hamid");
}

// Handle adding a new city
void handleAddCity(CityData* cities, int* cityCount) {
    char cityName[MAX_CITY_LENGTH];
    readCityName(cityName);
    
    int cityIndex = AddCity(cities, cityCount, MAXCITIES , cityName); // menggunakan integer sebagai salah eatu bentuk exept
    if (cityIndex >= 0) {
        displayCityAddedMessage(cityName);
    } else if (cityIndex == -1) {
        displayCityLimitMessage();
    } else if (cityIndex == -2) {
        displayCityExistsMessage(cityName);
    } else {
        displayMemoryErrorMessage();
    }
}

// Handle adding a name to a city - FIXED
void handleAddName(CityData* cities, int cityCount) {
    char cityName[MAX_CITY_LENGTH];
    char personName[MAX_NAME_LENGTH];
    
    readCityName(cityName);
    int cityIndex = FindCity(cities, cityCount, cityName); // check is it exits
    
    if (cityIndex >= 0) {
        readPersonName(personName);
        AddName(cities, cityIndex, personName);
        displayNameAddedMessage(personName, cityName);
    } else {
        displayCityNotFoundMessage(cityName);
    }
}

// Handle deleting a city
void handleDeleteCity(CityData* cities, int* cityCount) {
    char cityName[MAX_CITY_LENGTH];
    
    readCityName(cityName);
    
    int cityIndex = FindCity(cities, *cityCount, cityName);
    if (cityIndex >= 0) {
        DeleteCity(cities, cityCount, cityIndex);
        displayCityDeletedMessage(cityName);
    } else {
        displayCityNotFoundMessage(cityName);
    }
}

// Handle deleting a name from a city
void handleDeleteName(CityData* cities, int cityCount) {
    char cityName[MAX_CITY_LENGTH];
    char personName[MAX_NAME_LENGTH];
    
    readCityName(cityName);
    int cityIndex = FindCity(cities, cityCount, cityName);
    
    if (cityIndex >= 0) {
        readPersonName(personName);
        DeleteNameFromCity(cities, cityIndex, personName);
        displayNameDeletedMessage(personName, cityName);
    } else {
        displayCityNotFoundMessage(cityName);
    }
}

// Handle displaying all data
void handleDisplayAllData(CityData* cities, int cityCount) {
    PrintAllData(cities, cityCount);
}

// Handle displaying data for a specific city
void handleDisplayCityData(CityData* cities, int cityCount) {
    char cityName[MAX_CITY_LENGTH];
    
    readCityName(cityName);
    int cityIndex = FindCity(cities, cityCount, cityName);
    
    if (cityIndex >= 0) {
        PrintCityData(cities, cityIndex);
    } else {
        displayCityNotFoundMessage(cityName);
    }
}

// Handle counting names
void handleCountNames(CityData* cities, int cityCount) {
    int countChoice = readCountChoice();
    
    if (countChoice == 1) {
        char cityName[MAX_CITY_LENGTH];
        
        readCityName(cityName);
        int cityIndex = FindCity(cities, cityCount, cityName);
        
        if (cityIndex >= 0) {
            int count = CountElmt(cities[cityIndex].p);
            displayCityNameCountMessage(cityName, count);
        } else {
            displayCityNotFoundMessage(cityName);
        }
    } else if (countChoice == 2) {
        int totalNames = CountTotalNames(cities, cityCount);
        displayTotalNamesMessage(cityCount, totalNames);
    }
}

// Clean up memory before exiting
void cleanupMemory(CityData* cities, int cityCount) {
	int i;
    for ( i = 0; i < cityCount; i++) {
        DeleteAll(&(cities[i].p));
        if (cities[i].kt != NULL) {
            free(cities[i].kt);
        }
    }
}
