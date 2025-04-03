/*  
	File name     : controller.h
    Made by       : Muhammad Nabil Syauqi Rasyiq
    Date          : 1 April 2025
    Description	  : Header file for handle study case
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CaseCity.h"
#include "ui.h"

/*===================== ADDITIONAL FUNCTIONS =====================*/

// IS : Data yang ada mungkin kosong
// FS : Menginisialisasi beberapa data untuk keperluan simulasi program
void loadInitialData(ListCity *cities);

// IS : cities ungkin osong
// FS : Menambahkan kota baru ke cities
void handleAddCity(ListCity *cities);

// IS : cities mungkin kosong
// FS : menambahkan data nama ke suatu kota
// Alur : meminta input untuk mendapatkan nama yang ingin ditambahkan dan kota tempat data nama akan disimpan, memvalidasi lalu menambahkan data
void handleAddName(ListCity *cities);

/*===================== ADDITIONAL FUNCTIONS =====================*/

// IS : cities mungkin kosong dan kota mungkin tidak ditemukan
// FS : data kota dan data nama yang ada dikota tersebut didealokasikan
// Alur : meminta input untuk mendapatkan nama kota yang ingin dihapus, validasi lalu dealokasi
void handleDeleteCity(ListCity *cities);

// IS : cities mungkin kosong dan kota mungkin tidak ditemukan
// FS : data nama pada suatu kota didealokasikan
// Alur : meminta input untuk mendapatkan kota tempat data nama yang ingin dihapus disimpan, meminta nama yang ingin dihapus, validasi lalu dealokasi
void handleDeleteName(ListCity *cities);

/*===================== ADDITIONAL FUNCTIONS =====================*/

// IS : cities mungkin kosong
// FS : menampilkan seluruh data kota beserta data nama yang ada didalamnya
void handleDisplayAllData(ListCity cities);

// IS : cities mungkin kosong
// FS : menampilkan data nama suatu kota
// Alur : meminta input nama kota, meminta input nama kota yang ingin dihapus, validasi, tampilkan
void handleDisplayCityData(ListCity cities);

// IS : cities mungkin kosong 
// FS : menghitung seluruh data nama dari seluruh node kota
void handleCountAllNames(ListCity cities);

// IS : cities mungkin kosong 
// FS : menghitung seluruh data nama dari suatu kota
// Alur : meminta input kota yang ingin dihitung namanya, validasi, hitung tampilkan hasil
void handleCountNamesOfCity(ListCity cities);

// IS : cities mungkin kosong
// FS : menghapus seluruh data yang ada mulai dari data nama setiap kota beserta data kotanya
void cleanupMemory(ListCity *cities);


#endif /* CONTROLLER_H */
