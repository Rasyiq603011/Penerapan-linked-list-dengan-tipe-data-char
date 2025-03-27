/* File name   : linked.h
   Made by      : Muhammad Nabil Syauqi Rasyiq
   Date         : 27 March 2025
   Description  : Header file for linked list implementation supporting both int and char* types
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Nil NULL
#define boolean bool
#define true 1
#define false 0

#define First(L) ((L).First)
#define next(P) ((P)->next)
#define info(P) ((P)->X)

typedef int infotype;

typedef struct tElmtList *address;
typedef struct tElmtList {
    union {
        infotype X;    
        char* info;     
    };
    address next;      
} ElmtList;

typedef struct {
    address First;
} List;


// Check if pointer is empty
boolean isEmpty(address P);

// Check if list is empty
boolean ListEmpty(List L);

// Create an empty list
void CreateList(List *L);

// Allocate a node with integer value
address Alokasi(int X);

// Allocate a node with character string value
address AlokasiC(char* nama);

// Deallocate memory for a node
void DeAlokasi(address P);

/* ===== INSERTION FUNCTIONS ===== */

// Insert a new node at the beginning of a list
void InsertFirst(address *P, address newNode);

// Insert a new node at the end of a list
void InsertLast(address *P, address newNode);

// Insert a new node after a specific node
void InsertAfter(address *pBef, address PNew);

// Insert a new node before a specific node
void InsertBefore(address *pAft, address *p, address PNew);

/* ===== DELETION FUNCTIONS ===== */

// Delete the first node from a list
void DeleteAwal(List *L, infotype *X);

// Delete the first node from a pointer
void DeleteFirst(address *P, address *firstNode);

// Delete the last node from a list
void DeleteAkhir(List *L, infotype *X);

// Delete a specific node by name (for char* type)
address Delete(address *P, char* nama);

// Delete all nodes in a list
void DeleteAll(address *P);

// Clear all nodes from a list
void ClearList(List *L);

/* ===== DISPLAY FUNCTIONS ===== */

// Print all elements in a list (for char* type)
void PrintInfoListC(address P);

/* ===== COUNTING AND SEARCHING FUNCTIONS ===== */

// Count elements in a list
int CountList(List L);

// Count elements from a specific starting point
int CountElmt(address P);

// Search for a node in a list
boolean FSearch(List L, address P);

// Search for a value and return the previous node
address SearchPrec(List L, int X);

// Search for a name in a list (for char* type)
address Search(address P, char* nama);

/* ===== ADDITIONAL FUNCTIONS ===== */

// Reverse a list
address BalikList(List L);

// Get the value of the first element
infotype GetFrontValue(List L);

// Get the value of the last element
infotype GetTailValue(List L);

#endif /* LINKED_H */
