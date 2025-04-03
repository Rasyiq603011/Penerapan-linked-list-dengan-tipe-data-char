/*  
	File name	: CaseCity.c
    Made by		: Muhammad Nabil Syauqi Rasyiq
    Date		: 2 April 2025
    Description	: Implementation of linked list CaseCity.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CaseCity.h"

int i; // Variabel Perulangan

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

boolean ListCityEmpty(ListCity C) {
    return (Head(C) == NULL);
}

void CreatePcity(Pcity *A) {
	*A = NULL;
}

void CreateCityList(ListCity *C) {
    Head(*C) = NULL;
}

Pcity Constructor(char* cityName) {
    Pcity newNode = (Pcity) malloc(sizeof(CityData));
    if (newNode != NULL) {
        next(newNode) = NULL;
        kota(newNode) = strdup(cityName); // Deep copy of string
        
        if (kota(newNode) == NULL) {
            free(newNode);
            return NULL;
        }
        
        CreateList(&(ListName(newNode)), TYPE_STRING);
    }
    return newNode;
}

void Destructor(Pcity A) {
    if (A != NULL) {
        if (A->kt != NULL) {
            free(A->kt);
        }
        if (!ListEmpty(ListName(A))) {
            ClearList(&(ListName(A)));
        }
        free(A);
    }
}

/*=======================================================*/
/*================= INSERTION FUNCTIONS =================*/
/*=======================================================*/

void InsertAwal(Pcity *A, Pcity newNode) {
    if (newNode != NULL) {
        next(newNode) = *A;
        *A = newNode;
    }
}

void InsertAkhir(Pcity *A, Pcity newNode) {
    if (*A == NULL) {
        InsertAwal(&(*A), newNode); 
    } else {
        Pcity temp = *A;
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = newNode;
    }
}

void InsertSetelah(Pcity *pBef, Pcity PNew) {
    if (*pBef != NULL && PNew != NULL) {
        next(PNew) = next(*pBef);
        next(*pBef) = PNew;
    }
}

void InsertSebelum(Pcity *pAft, Pcity *p, Pcity PNew) {
    if (PNew != NULL) {
        if (*p == *pAft) {
            InsertAwal(&(*p), PNew);
        } else {
            Pcity temp = *p;
            while (temp != NULL && next(temp) != *pAft) {
                temp = next(temp);
            }
            if (temp != NULL) {
                InsertSetelah(&temp, PNew);
            }
        }
    }
}

void InsertAwalV(Pcity *P, char *kota) {
    Pcity newNode = Constructor(kota);
    if (newNode != NULL) {
        InsertAwal(&(*P), newNode);
    }
}

void InsertAkhirV(Pcity *P, char *kota) {
    Pcity newNode = Constructor(kota);
    if (newNode != NULL) {
        InsertAkhir(&(*P), newNode);
    }
}

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

void DeleteAwal(ListCity *C) {
    if (!ListCityEmpty(*C)) {
        Pcity temp = Head(*C);
        Head(*C) = next(temp);
        Destructor(temp);
    }
}

void DeleteAkhir(ListCity *C) {
    if (!ListCityEmpty(*C)) {
        if (next(Head(*C)) == NULL) {
            DeleteAwal(C);
        } else {
            Pcity last = Head(*C);
            Pcity prev = NULL;
            
            while (next(last) != NULL) {
                prev = last;
                last = next(last);
            }
            
            next(prev) = NULL;
            Destructor(last);
        }
    }
}

void DeleteByName(ListCity *C, char* cityName) {
    if (!ListCityEmpty(*C)) {
        Pcity temp = Head(*C);
        
        if (strcmp(kota(temp), cityName) == 0) {
            DeleteAwal(C);
        } else {
            Pcity prev = temp;
            temp = next(temp);
            
            while (temp != NULL && strcmp(kota(temp), cityName) != 0) {
                prev = temp;
                temp = next(temp);
            }
            
            if (temp != NULL) {
                next(prev) = next(temp);
                Destructor(temp);
            }
        }
    }
}

void ClearListCity(ListCity *C) {
    while (!ListCityEmpty(*C)) {
        DeleteAwal(C);
    }
}

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

Pcity FindCity(ListCity C, char* cityName) {
    Pcity temp = Head(C);
    while (temp != NULL) {
        if (strcmp(kota(temp), cityName) == 0) {
            return temp;
        }
        temp = next(temp);
    }
    return NULL;
}

void PrintAllCityData(ListCity C) {
    Pcity temp = Head(C);
    printf("List of Cities:\n");
    if (temp == NULL) {
        printf("(Empty List)\n");
    } else {
        while (temp != NULL) {
            PrintCityData(temp);
            temp = next(temp);
        }
    }
}

void PrintCityData(Pcity cityNode) {
    if (cityNode != NULL) {
        printf("City: %s\n", kota(cityNode));
        
        if (!ListEmpty(ListName(cityNode))) {
            printf("Names in %s: ", kota(cityNode));
            PrintList(ListName(cityNode));
            }
        else {
            printf("No names in this city.\n");
        }
    }else {
        printf("City node is NULL.\n");
    }
}

int countCity(ListCity C){
	int cityCount = 0;
    Pcity city = Head(C);
    while (city != NULL) {
        cityCount++;
        city = next(city);
    }
    return cityCount;
}

int countNameInCity(Pcity cityNode) {
    if (cityNode == NULL ||  ListEmpty(ListName(cityNode))) {
        return 0;
    }

    int count = CountList(ListName(cityNode));
    return count;
}

int CountTotalNames(Pcity A) {
    int total = 0; 
    Pcity temp = A;
    
    while (temp != NULL) {
        total += countNameInCity(temp);
        temp = next(temp);
    }
    
    return total;
}

void CopyListCity(ListCity C1, ListCity *C2) {
    CreateCityList(C2);
    Pcity temp = Head(C1);
    while (temp != NULL) {
        
        Pcity newNode = Constructor(kota(temp));
        
        if (!ListEmpty(ListName(temp))) {
            CopyList(ListName(temp), &(ListName(newNode)));
        }
        
        InsertAkhir(&(Head(*C2)), newNode);
        
        temp = next(temp);
    }
}
