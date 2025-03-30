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

// Create an empty list
void CreateListCity(ListCity *LC){
	LC->First = Nil;
}

Pcity AlokasiCity(char* kota) {
    Pcity P = (Pcity)malloc(sizeof(CityData));
    if (P != Nil) {
        P->kt = strdup(kota); // Gunakan strdup untuk mengalokasikan memori untuk string
        if (P->kt != Nil) {
            P->next = Nil;
        } else {
            free(P);
            P = Nil;
        }
    }
    return P;
}

/* ===== INSERTION FUNCTIONS ===== */

// Insert a new node at the beginning of a list
void InsertFirstCity(Pcity *P, Pcity newCity){
	if (newCity != Nil){
		newCity->next = *P;
		*P = newCity;
	}
}

// Insert a new node at the end of a list
void InsertLastCity(Pcity *P, Pcity newCity){
    if (newCity != Nil) {
        if (*P == Nil) {
            *P = newCity;
        } else {
            Pcity last = *P;
            while (next(last) != Nil) {
                last = next(last);
            }
            next(last) = newCity;
        }
    }
}

void InsertAfterCity(Pcity *pBef, Pcity PNew) {
    next(PNew) = next(*pBef);
    next(*pBef) = PNew;
}

void InsertBeforeCity(Pcity *pAft, Pcity *p, Pcity PNew) {
    Pcity temp = *p;
    if (!isEmpty(temp)) {
        while(true) {
            if (next(temp) == *pAft ) {
                next(PNew) = *pAft;
                next(temp) = PNew;
                break;      
            } else {
                temp = next(temp);
            }
        }
    }   
}

/* ===== DELETION FUNCTIONS ===== */

// Delete untuk pointer (untuk char*)
void DeleteFirst(Pcity *P, Pcity *firstNode) {
    if (*P != Nil) {
        *firstNode = *P;
        *P = next(*P);
        next(*firstNode) = Nil;
    }
}

void DeleteLast(ListCity *L, infotype *X) {
    // Jika list kosong
    if (ListEmpty(*L)) {
        printf("\nList Kosong Tidak bisa menghapus\n");
        return;
    }
    
    Pcity temp = First(*L);
    
    // Jika list hanya berisi 1 elemen
    if (next(temp) == Nil) {
        *X = info(temp);
        DeAlokasi(temp);
        First(*L) = Nil;
        return;
    }
    
    // Jika list berisi lebih dari 1 elemen
    // Cari node sebelum node terakhir
    while (next(next(temp)) != Nil) {
        temp = next(temp);
    }
    
    // Ambil nilai dari node terakhir
    *X = info(next(temp));
    
    // Dealokasi node terakhir
    DeAlokasi(next(temp));
    
    // Set next dari node sebelum terakhir menjadi Nil
    next(temp) = Nil;
}

void DeleteAll(Pcity *P) {
    Pcity temp;
    while (*P != NULL) {
        DeleteFirst(P, &temp);
        DeAlokasi(temp);
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
        } // City exits indicators
    }
    
    // Add the new city
    A[*index].kt = strdup(cityName); 
    if (A[*index].kt != Nil) {
        A[*index].p = NULL;
        (*index)++;
        return *index - 1;  // Return the index of the new city
    }
    
    return -3;  // Memory allocation failed indicator
}

// Find a city in the array
int FindCity(CityData* A, int size, char* cityName) {
	int i;
    for (i = 0; i < size; i++) {
        if (A[i].kt != Nil && strcmp(A[i].kt, cityName) == 0) {
            return i;
        }
    }
    return -1;  // City not found indicator
}

// Add a name to a specific city
void AddName(CityData* A, int cityIndex, char* nama) {
    Pcity newNode = AlokasiC(nama);
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
        Pcity deletedNode = Delete(&(A[cityIndex].p), nama);
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
