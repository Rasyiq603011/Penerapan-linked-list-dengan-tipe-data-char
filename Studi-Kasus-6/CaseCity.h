/*  File name     : CaseCity.h
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 1 April 2025
*/
#ifndef CASECITY_H
#define CASECITY_H
#include "linked.h"
#define First(L) ((L).First)
#define next(P) ((P)->next)
#define kota(P) ((P)->kt)
#define ListName(P) ((P)->p)

extern int i; // Variabel Perulangan

typedef struct kota *Pcity;
typedef struct kota{
	Pcity next;
    char* kt;          
    address p;         
} CityData;

typedef struct {
    Pcity First;
} ListCity;

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

// I.S : program tidak tahu apakah ListCity kosong atau tidak
// F.S : mereturn true jika List kosong 
boolean ListEmpty(ListCity C);

// IS : variabel bertipe Pcity baru di deklarasikan sebagai kamus data
// FS : Pcity dipastikan siap dipakai dengan membuat Pcity menunjuk ke Nil
void Create CityData(CityData *A);

// I.S : variabel bertipe listcity baru di deklarasikan sebagai kamus data
// F.S : memastikan listcity siap dipakai dengan membuat ListCity.first menunjuk ke Nil
void Create CityList(ListCity *C);

// IS : Program membutuhkan sebuah alamat node Pcity yang sudah memiliki nilai sesuai dengan kebutuhan 
// FS : mereturn alamat node Pcity yang sudah di malloc dan diatur nilainya sesuai dengan parameter
// Catatan: Function ini melakukan deep copy dari string menggunakan strdup, jadi parameter string bisa dibebaskan
Pcity Constructor(char* cityName);

// I.S : alamat Node untuk sudah tidak terpakai dan belum di dealloc
// F.S : alamat Node dan memori string di dalamnya berhasil di dealloc
Destructor(Pcity A);

/*=======================================================*/
/*================= INSERTION FUNCTIONS =================*/
/*=======================================================*/

// I.S : Pcity *P Sudah di Create
// F.S : Pcity newNode sudah dimasukan kedalam List dengan posisi First
void InsertFirst(Pcity *A, Pcity newNode);

// I.S : Pcity *P Sudah di Create
// F.S : Pcity newNode sudah dimasukan kedalam List dengan posisi Last
void InsertLast(Pcity *A, Pcity newNode);

// IS :
// FS :
int AddCity(Pcity A, char* cityName);

// IS : A mungkin kosong dan nama kota bisa jadi tidak ditemukan
// FS : Data nama pada kota sudah terhapus semua, lalu node data kota didelete
void AddName(Pcity A, Pcity CityNode, char* nama);

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

// IS : A mungkin kosong dan nama kota bisa jadi tidak ditemukan
// FS : Data nama pada kota sudah terhapus semua, lalu node data kota didelete
void DeleteFirst(ListCity *C);

// IS : A mungkin kosong dan nama kota bisa jadi tidak ditemukan
// FS : Data nama pada kota sudah terhapus semua, lalu node data kota didelete
void DeleteLast(ListCity *C):

// IS : A mungkin kosong dan nama kota bisa jadi tidak ditemukan
// FS : Data nama pada kota sudah terhapus semua, lalu node data kota didelete
void DeleteCity(ListCity *C, Pcity cityNode);

// IS : A mungkin kosong
// FS : menghapus suatu nama dari suatu kota
void DeleteNameFromCity(ListCity *C, Pcity cityNode, char* nama);

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

// IS : A munkin kosong
// FS : Mereturn Pcity jika cityName ditemukan
Pcity FindCity(Pcity A, char* cityName);

// IS : A mungkin kosong
// FS : Menampilkan data nama dari seluruh kota yang ada dalam list
void PrintAllData(Pcity A);

// IS : A mungkin kosong
// FS : Menampilkan data nama suatu kota
void PrintCityData(Pcity A, Pcity cityNode);

// IS : A Mungkin kosong
// FS : Mereturn Jumlah Nama Yang ada di Namakota
int countNameInCity(Pcity A, Pcity cityNode);

// IS : A bisa kosong
// FS : Mereturn Jumlah Nama Yang ada diseluruh kota
int CountTotalNames(Pcity A);

#endif /* CASECITY_H */





