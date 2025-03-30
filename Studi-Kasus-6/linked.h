/* File name   : linked.h
   Made by      : Muhammad Nabil Syauqi Rasyiq
   Date         : 30 March 2025
   Description  : Header file for linked list implementation supporting both int and char* types
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef enum {
    TYPE_INT,
    TYPE_STRING
} DataType;

typedef char* string;
typedef struct tElmtList *address;
typedef struct tElmtList {
    union {
        int intInfo;    // Renamed for clarity
        string strInfo; // Renamed for clarity
    };
    address next;      
} ElmtList;

typedef struct {
    DataType type;
    address First;
} List;

// Macros to access the correct union field based on List type
#define Nil NULL
#define First(L) ((L).First)
#define next(P) ((P)->next)
#define infoInt(P) ((P)->intInfo)
#define infoStr(P) ((P)->strInfo)

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

// I.S : program tidak tahu apakah node kosong atau tidak
// F.S : mereturn true jika node kosong
// Alur : return hasil cek P == Nil?
boolean isEmpty(address P);

// I.S : program tidak tahu apakah List kosong atau tidak
// F.S : mereturn true jika List kosong 
// Alur : return hasil cek L.First == Nil?
boolean ListEmpty(List L);

// I.S : variabel bertipe Address baru di deklarasikan sebagai kamus data
// F.S : Address dipastikan siap dipakai dengan membuat address menunjuk ke Nil
void CreateAddress(address *P);

// I.S : variabel bertipe list baru di deklarasikan sebagai kamus data
// F.S : menentukan tipe list dan memastikan list siap dipakai dengan membuat List.first menunjuk ke Nil
void CreateList(List *L, DataType type);

// I.S : Program membutuhkan sebuah alamat node struct bertipe integer yang sudah memiliki nilai sesuai dengan kebutuhan 
// F.S : mereturn alamat node struct bertipe integer yang sudah di malloc dan diatur nilainya sesuai dengan parameter
address AlokasiInt(int X);

// I.S : Program membutuhkan sebuah alamat node struct bertipe char* yang sudah memiliki nilai sesuai dengan kebutuhan 
// F.S : mereturn alamat node struct bertipe char* yang sudah di malloc dan diatur nilainya sesuai dengan parameter
// Catatan: Function ini melakukan deep copy dari string menggunakan strdup, jadi parameter string bisa dibebaskan
address AlokasiCharS(string nama);

// I.S : alamat Node untuk tipe int sudah tidak terpakai dan belum di dealloc
// F.S : alamat Node berhasil di dealloc
void DeAlokasiInt(address P);

// I.S : alamat Node untuk tipe string sudah tidak terpakai dan belum di dealloc
// F.S : alamat Node dan memori string di dalamnya berhasil di dealloc
void DeAlokasiCharS(address P);

// I.S : alamat Node sudah tidak terpakai dan belum di dealloc
// F.S : alamat Node berhasil di dealloc
// Catatan: Fungsi ini tidak aman untuk string, gunakan DeAlokasiCharS untuk node string
void DeAlokasi(address P);

#define DeAlokasi(address P) _Generic((P), \
    int*: DeAlokasiInt, \
    char*: DeAlokasiCharS \
)(P)

/*=======================================================*/
/*================= INSERTION FUNCTIONS =================*/
/*=======================================================*/

// I.S : address *P Sudah di Create
// F.S : address newNode sudah dimasukan kedalam List dengan posisi First
void InsertFirst(address *P, address newNode);

// I.S : address *P Sudah di Create
// F.S : address newNode sudah dimasukan kedalam List dengan posisi Last
void InsertLast(address *P, address newNode);

// I.S : address *P Sudah di Create
// F.S : address newNode sudah dimasukan kedalam List dengan setelah *pBef
void InsertAfter(address *pBef, address PNew);

// I.S : address *P Sudah di Create
// F.S : address newNode sudah dimasukan kedalam List dengan sebelum *pAft
void InsertBefore(address *pAft, address *p, address PNew);

// IS : P mungkin Kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi First dengan nilai info bertipe int jika alokasi berhasil
void InsertFVInt(address *P, int info);

// IS : P mungkin Kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi First dengan nilai info bertipe char* jika alokasi berhasil
// Catatan: Function ini melakukan deep copy dari string parameter
void InsertFVCharS(address *P, string info);

#define InsertFirstV(a, b) _Generic((b), \
    int: InsertFVInt, \
    char*: InsertFVCharS \
)(a, b)

// IS : P mungkin Kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi Last dengan nilai info bertipe int jika alokasi berhasil
void InsertLVInt(address *P, int info);

// IS : P mungkin Kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi Last dengan nilai info bertipe char* jika alokasi berhasil
// Catatan: Function ini melakukan deep copy dari string parameter
void InsertLVCharS(address *P, string info);

#define InsertLastV(a, b) _Generic((b), \
    int: InsertLVInt, \
    char*: InsertLVCharS \
)(a, b)

// IS : P tidak kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi setelah posisi Before dengan nilai info bertipe int jika alokasi berhasil
void InsertAVInt(address *P, int Before, int info);

// IS : P tidak kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi setelah posisi Before dengan nilai info bertipe char* jika alokasi berhasil
// Catatan: Function ini melakukan deep copy dari string parameter
void InsertAVCharS(address *P, string Before, string info);

#define InsertAfterV(a, b, c) _Generic((b), \
    int: InsertAVInt, \
    char*: InsertAVCharS \
)(a, b, c) 

// IS : P tidak kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi setelah posisi After dengan nilai info bertipe int jika alokasi berhasil
void InsertBVInt(address *P, int After, int info);

// IS : P tidak kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi setelah posisi After dengan nilai info bertipe char* jika alokasi berhasil
// Catatan: Function ini melakukan deep copy dari string parameter
void InsertBVCharS(address *P, string After, string info);

#define InsertBeforeV(a, b, c) _Generic((b), \
    int: InsertBVInt, \
    char*: InsertBVCharS \
)(a, b, c)

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

// IS : l tidak kosong
// FS : Mengeluarkan node yang berada di posisi First, mengambil nilai infonya dan disimpan di parameter info yang passing by address, dan mendealokasi node
void DeleteFirstInt(List *L, int *info);

// IS : l tidak kosong
// FS : Mengeluarkan node yang berada di posisi First, mengambil nilai infonya dan disimpan di parameter info yang passing by address, dan mendealokasi node
// Catatan: String yang dikembalikan di *info akan menjadi tanggung jawab pemanggil untuk membebaskan memorinya
void DeleteFirstCharS(List *L, string *info);

#define DeleteFirst(a, b) _Generic((b), \
    int*: DeleteFirstInt, \
    char**: DeleteFirstCharS \
)(a, b)

// IS : l tidak kosong
// FS : Mengeluarkan node yang berada di posisi Last, mengambil nilai infonya dan disimpan di parameter info yang passing by address, dan mendealokasi node
void DeleteLastInt(List *L, int *info);

// IS : l tidak kosong
// FS : Mengeluarkan node yang berada di posisi Last, mengambil nilai infonya dan disimpan di parameter info yang passing by address, dan mendealokasi node
// Catatan: String yang dikembalikan di *info akan menjadi tanggung jawab pemanggil untuk membebaskan memorinya
void DeleteLastCharS(List *L, string *info);

#define DeleteLast(a, b) _Generic((b), \
    int*: DeleteLastInt, \
    char**: DeleteLastCharS \
)(a, b)

// IS : l tidak kosong
// FS : mencari node dengan nilai info dan mendealokasikannya jika ada
void DeleteByVInt(List *L, int info);

// IS : l tidak kosong
// FS : mencari node dengan nilai info dan mendealokasikannya jika ada
void DeleteByVCharS(List *L, string info);

#define DeleteByV(a, b) _Generic((b), \
    int: DeleteByVInt, \
    char*: DeleteByVCharS \
)(a, b)

// IS : l tidak kosong
// FS : mendealokasi/menghapus seluruh isi list 
// Catatan: Jika list berisi string, seluruh memori untuk string tersebut juga akan dibebaskan
void ClearList(List *L);

/*=======================================================*/
/*================== DISPLAY FUNCTIONS ==================*/
/*=======================================================*/

// IS : l bisa jadi kosong dan L harus sudah memiliki nilai type
// FS : Menampilkan isi list bertipe Integer dengan format angka1, angka2, ....., angkaTerakhir jika l tidak kosong jika kosong maka "List Kosong"
void printInfoInt(List L);

// IS : l bisa jadi kosong dan L harus sudah memiliki nilai type
// FS : Menampilkan isi list bertipe String dengan format string1, string2, ....., stringTerakhir jika l tidak kosong jika kosong maka "List Kosong"
void printInfoCharS(List L);

#define PrintList(L) ((L).type == TYPE_INT ? printInfoInt(L) : printInfoCharS(L))

/*================================================================*/
/*================== COUNT AND SEARCH FUNCTIONS ==================*/
/*================================================================*/

// IS : L mungkin kosong
// FS : menghitung jumlah elemen dari sebuah list
int CountList(List L);

// IS : L mungkin kosong, program ingin mengetahui address node sebelum address node dengan nilai info
// FS : function akan mencari tahu apakah ada node dengan nilai info?, jika ada maka function akan mereturn address node sebelumnya, jika tidak ada return Nil
address SearchPrec(List L, int info);

// IS : L mungkin kosong, program ingin mengetahui address node dengan nilai info
// FS : jika ada maka akan return address node tersebut, jika tidak ada maka akan return Nil
address SearchByVInt(List L, int info);

// IS : L mungkin kosong, program ingin mengetahui address node dengan nilai info
// FS : jika ada maka akan return address node tersebut, jika tidak ada maka akan return Nil
address SearchByVCharS(List L, char* info);

#define SearchByV(a, b) _Generic((b), \
    int: SearchByVInt, \
    char*: SearchByVCharS \
)(a, b)

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

// IS : L mungkin kosong
// FS : jika L tidak kosong maka function akan mengalokasikan address untuk menampung hasil dari mereverse List, lalu mereturnnya
address getReverseList(List L);

// IS : L mungkin kosong
// FS : jika L tidak kosong maka function akan membalik isi dari List 
void ReverseList(List *L);

// IS : L mungkin kosong
// FS : isi dari L1 akan dicopy ke L2
// Catatan: Untuk list string, semua string akan di-deep copy
void CopyList(List L1, List *L2);

// IS : L mungkin kosong
// FS : Function akan mengembalikan nilai Front dari list bertipe INT
int GetFrontValueInt(List L);

// IS : L mungkin kosong
// FS : Function akan mengembalikan nilai Front dari list bertipe STRING
// Catatan: Fungsi ini mengembalikan pointer ke string dalam list, tidak melakukan copy
string GetFrontValueCharS(List L);

#define GetFrontValue(L) ((L).type == TYPE_INT ? GetFrontValueInt(L) : GetFrontValueCharS(L))

// IS : L mungkin kosong
// FS : Function akan mengembalikan nilai Tail dari list bertipe INT
int GetTailValueInt(List L);

// IS : L mungkin kosong
// FS : Function akan mengembalikan nilai Tail dari list bertipe STRING
// Catatan: Fungsi ini mengembalikan pointer ke string dalam list, tidak melakukan copy
string GetTailValueCharS(List L);

#define GetTailValue(L) ((L).type == TYPE_INT ? GetTailValueInt(L) : GetTailValueCharS(L))

#endif /* LINKED_H */
