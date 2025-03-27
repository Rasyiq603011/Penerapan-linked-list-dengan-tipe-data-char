/*  File name     : CaseCity.h
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 27 March 2025
*/
#ifndef CASECITY_H
#define CASECITY_H
#include "linked.h"

extern int i; // Variabel Perulangan

typedef struct {
    char* kt;          
    address p;         
} CityData;

/* ===== CITY ARRAY OPERATIONS ===== */

// Initialize the city array
void InitArray(CityData* A, int size);

// Add a new city to the array
int AddCity(CityData* A, int *size, int maxSize, char* cityName);

// Find a city in the array
int FindCity(CityData* A, int size, char* cityName);

// Add a name to a specific city
void AddName(CityData* A, int cityIndex, char* nama);

// Delete a city and all its names
void DeleteCity(CityData* A, int *size, int cityIndex);

// Delete a name from a specific city
void DeleteNameFromCity(CityData* A, int cityIndex, char* nama);

// Print all cities and their names
void PrintAllData(CityData* A, int size);

// Print all names in a specific city
void PrintCityData(CityData* A, int cityIndex);

// Count total number of names across all cities
int CountTotalNames(CityData* A, int size);

#endif /* CASECITY_H */
