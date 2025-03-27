/*  File name     : linked.c
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 27 March 2025
    Description   : Implementation of linked list supporting both int and char* types
*/

#include "linked.h"

/* ===== BASIC LIST FUNCTIONS ===== */

boolean isEmpty(address P){
    return (P == Nil);
}

boolean ListEmpty(List L) {
    return (First(L) == Nil);    
}

void CreateList(List *L) {
    First(*L) = Nil;
}

// Alokasi untuk Tipe Char* - Diperbaiki
address AlokasiC(char* nama) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        P->info = strdup(nama); // Gunakan strdup untuk mengalokasikan memori untuk string
        if (P->info != Nil) {
            P->next = Nil;
            // Jangan free nama karena itu parameter!
        } else {
            free(P);
            P = Nil;
        }
    }
    return P;
}

// Alokasi untuk tipe int
address Alokasi(int X) {
    address P;
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        next(P) = Nil;
    }
    return (P);
} 

void DeAlokasi(address P) {
    if (P != Nil) {
        // Jika sedang digunakan untuk char*
        if (P->info != Nil) {
            free(P->info);
        }
        free(P);
    }
}

/* ===== INSERTION FUNCTIONS ===== */

// Insert untuk pointer (dapat digunakan oleh kedua tipe)
void InsertFirst(address *P, address newNode) {
    if (newNode != NULL) {
        newNode->next = *P;
        *P = newNode;
    }
}

void InsertLast(address *P, address newNode) {
    if (newNode != NULL) {
        if (*P == NULL) {
            *P = newNode;
        } else {
            address last = *P;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        }
    }
}

void InsertAfter(address *pBef, address PNew) {
    next(PNew) = next(*pBef);
    next(*pBef) = PNew;
}

void InsertBefore(address *pAft, address *p, address PNew) {
    address temp = *p;
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

// Delete untuk List (biasanya untuk tipe int)
void DeleteAwal(List *L, infotype *X) {
    if(First(*L) == Nil) {
        printf("\nList Kosong Tidak bisa menghapus\n");
        return;
    }
    
    address temp = First(*L);
    First(*L) = next(First(*L));
    
    *X = info(temp);
    DeAlokasi(temp);
}

// Delete untuk pointer (untuk char*)
void DeleteFirst(address *P, address *firstNode) {
    if (*P != NULL) {
        *firstNode = *P;
        *P = (*P)->next;
        (*firstNode)->next = NULL;
    }
}

void DeleteAkhir(List *L, infotype *X) {
    // Jika list kosong
    if (ListEmpty(*L)) {
        printf("\nList Kosong Tidak bisa menghapus\n");
        return;
    }
    
    address temp = First(*L);
    
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

// Delete untuk char* berdasarkan nama
address Delete(address *P, char* nama) {
    address temp = NULL;
    
    if (*P != NULL) {
        // If the first node matches
        if (strcmp((*P)->info, nama) == 0) {
            DeleteFirst(P, &temp);
            return temp;
        }
        
        // Search for the node in the rest of the list
        address prev = *P;
        address current = (*P)->next;
        
        while (current != NULL && strcmp(current->info, nama) != 0) {
            prev = current;
            current = current->next;
        }
        
        // If found, delete it
        if (current != NULL) {
            prev->next = current->next;
            current->next = NULL;
            return current;
        }
    }
    return NULL;
}

// DeleteAll untuk pointer - harus dimodifikasi agar bekerja untuk char*
void DeleteAll(address *P) {
    address temp;
    while (*P != NULL) {
        DeleteFirst(P, &temp);
        DeAlokasi(temp);
    }
}

// ClearList untuk List (biasanya untuk tipe int)
void ClearList(List *L) {
    if(First(*L) == Nil) {
        printf("List Kosong Tidak bisa menghapus");
        return;
    }
    
    infotype Hapus;
    while (First(*L) != Nil) {
        DeleteAwal(L, &Hapus);
        printf("Node dengan isi %d telah dihapus!\n\n", Hapus);
    }
    printf("\nList Telah Kosong Head menunjuk kembali ke Nil\n");
}

/* ===== DISPLAY FUNCTIONS ===== */

// Print untuk char*
void PrintInfoListC(address P) {
    address current = P;
    while (current != NULL) {
        printf("%s --> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

/* ===== COUNTING AND SEARCHING FUNCTIONS ===== */

int CountList(List L) {
    address temp = First(L);
    return CountElmt(temp);
}

int CountElmt(address P) {
    int count = 0;
    address current = P;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* ===== SEARCHING FUNCTIONS ===== */

// Search untuk pointer
boolean FSearch(List L, address P) {
    boolean found = false;
    address PSearch = First(L);
    
    while ((PSearch != Nil) && (!found)) {
        if (PSearch == P) {
            found = true;
        } else {
            PSearch = next(PSearch);
        }
    }
    return (found);
}

// Search untuk tipe int
address SearchPrec(List L, int X) {
    address Prec, P;
    boolean found = false;

    Prec = Nil;
    P = First(L);
    while ((P != Nil) && (!found)) {
        if (info(P) == X) {
            found = true;
        } else {
            Prec = P;
            P = next(P);
        }
    }
    if (found) {
        return (Prec);
    } else {
        return (Nil);
    }
}

// Search untuk tipe char*
address Search(address P, char* nama) {
    address current = P;
    while (current != NULL) {
        if (strcmp(current->info, nama) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* ===== ADDITIONAL FUNCTIONS ===== */

// Membalik urutan list
address BalikList(List L) {
    address p, temp, reverse;
    
    if (First(L) != Nil) {
        p = First(L);
        temp = next(p);
        reverse = next(next(p));
        next(p) = Nil;
        while(true) {
            next(temp) = p;
            p = temp;
            temp = reverse;
            reverse = next(reverse);
                
            if (isEmpty(next(reverse))) {
                next(temp) = p;
                next(reverse) = temp;
                return reverse;
            }
        }       
    }
    else {
        printf("List Kosong");
        return Nil;
    }       
}

// Mendapatkan nilai depan list
infotype GetFrontValue(List L) {
    if (ListEmpty(L)) {
        printf("List Kosong");
        return -1; // Return default value for error
    }
    else {
        address temp = First(L);
        return (info(temp));
    }
}

// Mendapatkan nilai belakang list
infotype GetTailValue(List L) {
    if (ListEmpty(L)) {
        printf("List Kosong");
        return -1; // Return default value for error
    }
    else {
        address temp = First(L);
        while(!isEmpty(next(temp))) {
            temp = next(temp);
        }
        return (info(temp));
    }
}
