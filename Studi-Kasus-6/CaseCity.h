/*  
	File name     : CaseCity.h
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 1 April 2025
    Description   : Header file for linked list City as requirement for study case
*/
#ifndef CASECITY_H
#define CASECITY_H
#include "linked.h"
#include "boolean.h"
#define Head(L) ((L).Head)
#define next(P) ((P)->next) // akses alamat CityData next untuk Pcity
#define kota(P) ((P)->kt) // aksed kt untuk Pcity
#define ListName(P) ((P)->L) // Akses L untuk Pcity

extern int i; // Variabel Perulangan

typedef struct kota *Pcity;
typedef struct kota{
	Pcity next;
    char* kt;          
    List L;         
} CityData;

typedef struct {
    Pcity Head;
} ListCity;

/*========================================================*/
/*==================== MAIN FUNCTIONS ====================*/
/*========================================================*/

// IS : program tidak tahu apakah ListCity kosong atau tidak
// FS : mereturn true jika List kosong 
boolean ListCityEmpty(ListCity C);

// IS : variabel bertipe Pcity baru di deklarasikan sebagai kamus data
// FS : Pcity dipastikan siap dipakai dengan membuat Pcity menunjuk ke Nil
void CreatePcity(Pcity *A);

// IS : variabel bertipe listcity baru di deklarasikan sebagai kamus data
// FS : memastikan listcity siap dipakai dengan membuat ListCity.first menunjuk ke Nil
void CreateCityList(ListCity *C);

// IS : Program membutuhkan sebuah alamat node Pcity yang sudah memiliki nilai sesuai dengan kebutuhan 
// FS : mereturn alamat node Pcity yang sudah di malloc dan diatur nilainya sesuai dengan parameter
// Catatan: Function ini melakukan deep copy dari string menggunakan strdup, jadi parameter string bisa dibebaskan
Pcity Constructor(char* cityName);

// IS : alamat Node untuk sudah tidak terpakai dan belum di dealloc
// FS : alamat Node dan memori string di dalamnya berhasil di dealloc
void Destructor(Pcity A);

/*=======================================================*/
/*================= INSERTION FUNCTIONS =================*/
/*=======================================================*/

// IS : Pcity *P Sudah di Create
// FS : Pcity newNode sudah dimasukan kedalam ListCity dengan posisi First
void InsertAwal(Pcity *A, Pcity newNode);

// IS : Pcity *P Sudah di Create
// FS : Pcity newNode sudah dimasukan kedalam ListCity dengan posisi Last
void InsertAkhir(Pcity *A, Pcity newNode);

// IS : Pcity *P Sudah di Create
// FS : Pcity newNode sudah dimasukan kedalam ListCity dengan setelah *pBef
void InsertSetelah(Pcity *pBef, Pcity PNew);

// IS : Pcity *P Sudah di Create
// FS : Pcity newNode sudah dimasukan kedalam ListCity dengan sebelum *pAft
void InsertSebelum(Pcity *pAft, Pcity *p, Pcity PNew);

// IS : P mungkin Kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi First dengan nilai info bertipe int jika alokasi berhasil
void InsertAwalV(Pcity *P, char *kota);

// IS : P mungkin Kosong
// FS : melakukan alokasi sebuah elemen dan menambahkan elemen di posisi First dengan nilai info bertipe int jika alokasi berhasil
void InsertAkhirV(Pcity *P, char *kota);

/*========================================================*/
/*================== DELETION FUNCTIONS ==================*/
/*========================================================*/

// IS : A mungkin kosong dan nama kota bisa jadi tidak ditemukan
// FS : Data nama pada kota sudah terhapus semua, lalu node data kota didelete
void DeleteAwal(ListCity *C);

// IS : A mungkin kosong dan nama kota bisa jadi tidak ditemukan
// FS : Data nama pada kota sudah terhapus semua, lalu node data kota didelete
void DeleteAkhir(ListCity *C);
	
// IS : C tidak kosong
// FS : mencari node dengan nilai info dan mendealokasikannya jika ada
void DeleteByName(ListCity *C, char* cityName);

// IS : C tidak kosong
// FS : mendealokasi/menghapus seluruh isi list 
// Catatan: Jika list berisi string, seluruh memori untuk string tersebut juga akan dibebaskan
void ClearListCity(ListCity *C);

/*================================================================*/
/*===================== ADDITIONAL FUNCTIONS =====================*/
/*================================================================*/

// IS : A munkin kosong
// FS : Mereturn Pcity jika cityName ditemukan
Pcity FindCity(ListCity C, char* cityName);

// IS : A mungkin kosong
// FS : Menampilkan data nama dari seluruh kota yang ada dalam list
void PrintAllCityData(ListCity C);

// IS : A mungkin kosong
// FS : Menampilkan data nama suatu kota
void PrintCityData(Pcity cityNode);

int countCity(ListCity C);

// IS : A Mungkin kosong
// FS : Mereturn Jumlah Nama Yang ada di Namakota
int countNameInCity(Pcity cityNode);

// IS : A bisa kosong
// FS : Mereturn Jumlah Nama Yang ada diseluruh kota
int CountTotalNames(Pcity A);

// IS : C mungkin kosong
// FS : isi dari C1 akan dicopy ke C2
void CopyListCity(ListCity C1, ListCity *C2);

#endif /* CASECITY_H */





