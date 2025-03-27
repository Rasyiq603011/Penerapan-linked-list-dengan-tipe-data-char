/*  File name     : CaseCity.c
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 27 March 2025
*/
#include "CaseCity.h"
int i;
/* ===== CITY ARRAY OPERATIONS ===== */

// Initialize the city array
void InitArray(CityData* A, int size) {
    for (i = 0; i < size; i++) {
        A[i].kt = Nil;
        A[i].p = Nil;
    }
}

// Add a new city to the array
int AddCity(CityData* A, int *index, int maxIndex, char* cityName) {
    // Check if array is full
    if (*index >= maxIndex) {
        return -1;
    }
    
	int i;
    for (i = 0; i < *index; i++) {
        if (A[i].kt != Nil && strcmp(A[i].kt, cityName) == 0) {
            return -2;
        }
    }
    
    // Add the new city
    A[*index].kt = strdup(cityName); // Ganti malloc+strcpy dengan strdup
    if (A[*index].kt != Nil) {
        A[*index].p = NULL;
        (*index)++;
        return *index - 1;  // Return the index of the new city
    }
    
    return -3;  // Memory allocation failed
}

// Find a city in the array
int FindCity(CityData* A, int size, char* cityName) {
	int i;
    for (i = 0; i < size; i++) {
        if (A[i].kt != Nil && strcmp(A[i].kt, cityName) == 0) {
            return i;
        }
    }
    return -1;  // City not found
}

// Add a name to a specific city
void AddName(CityData* A, int cityIndex, char* nama) {
    address newNode = AlokasiC(nama);
    if (newNode != Nil) {
        InsertLast(&(A[cityIndex].p), newNode);
    }
}

// Delete a city and all its names
void DeleteCity(CityData* A, int *size, int cityIndex) {
    if (cityIndex >= 0 && cityIndex < *size) {
        // Delete all names in the city
        DeleteAll(&(A[cityIndex].p));
        
        // Free the city name
        if (A[cityIndex].kt != NULL) {
            free(A[cityIndex].kt);
        }
        
        
		int i; // Shift all cities after the deleted city
        for (i = cityIndex; i < *size - 1; i++) {
            A[i].kt = A[i + 1].kt;
            A[i].p = A[i + 1].p;
        }
        
        // Clear the last position
        A[*size - 1].kt = Nil;
        A[*size - 1].p = Nil;
        
        // Decrease the size
        (*size)--;
    }
}

// Delete a name from a specific city
void DeleteNameFromCity(CityData* A, int cityIndex, char* nama) {
    if (cityIndex >= 0) {
        address deletedNode = Delete(&(A[cityIndex].p), nama);
        if (deletedNode != NULL) {
            DeAlokasi(deletedNode);
        }
    }
}

// Print all cities and their names
void PrintAllData(CityData* A, int size) {
	int i;
    printf("=== All Cities and Names ===\n");
    for (i = 0; i < size; i++) {
        if (A[i].kt != NULL) {
            printf("City %d: %s\n", i + 1, A[i].kt);
            printf("Names: ");
            if (A[i].p != NULL) {
                PrintInfoListC(A[i].p);
            } else {
                printf("(No names)\n");
            }
            printf("\n");
        }
    }
}

// Print all names in a specific city
void PrintCityData(CityData* A, int cityIndex) {
    if (cityIndex >= 0 && A[cityIndex].kt != NULL) {
        printf("City: %s\n", A[cityIndex].kt);
        printf("Names: ");
        if (A[cityIndex].p != NULL) {
            PrintInfoListC(A[cityIndex].p);
        } else {
            printf("(No names)\n");
        }
    }
}

// Count total number of names across all cities
int CountTotalNames(CityData* A, int size) {
    int total = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (A[i].kt != NULL) {
            total += CountElmt(A[i].p);
        }
    }
    return total;
}
