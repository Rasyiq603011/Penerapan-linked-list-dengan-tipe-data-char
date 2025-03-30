/*  File name     : logic.h
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 27 March 2025
*/

#ifndef LOGIC_H
#define LOGIC_H

#include "CaseCity.h"
#include "ui.h"
// Constants for city array
#define MAXCITIES 10

// Functions for handling menu actions
void loadInitialData(CityData* cities, int* cityCount);

void handleAddCity(CityData* cities, int* cityCount);

void handleAddName(CityData* cities, int cityCount);

void handleDeleteCity(CityData* cities, int* cityCount);

void handleDeleteName(CityData* cities, int cityCount);

void handleDisplayAllData(CityData* cities, int cityCount);

void handleDisplayCityData(CityData* cities, int cityCount);

void handleCountNames(CityData* cities, int cityCount);

void cleanupMemory(CityData* cities, int cityCount);

#endif /* LOGIC_H */
