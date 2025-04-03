/*	
	File name 	: ui.h
	Made by		: Muhammad Nabil Syauqi Rasyiq
	Date		: 1 April 2025
	Description : Header file for handle ui study case
*/

#ifndef UI_H
#define UI_H
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h> // Untuk getch()

// Main menu functions
void displayMainMenu(); // Menampilkan main menu

int getMenuChoice(); // mengambil input pilihan menu

void displayExitMessage(); // menampilkan Pesan sebelum keluar program

void displayInvalidChoiceMessage(); // menampilkan pesan saat input yang dimasukan salah

// Input functions
void readCityName(char** cityName); // meminta input nama kota yang disimpan sebagai string literal

void readPersonName(char** personName); // meminta input nama yang disimpan sebagai string literal

// Output message functions
void displayCityAddedMessage(char* cityName); // Pesan ketika add kota berhasil

void displayCityExistsMessage(char* cityName); // pesan ketika kota yang ingin di add sudah ada

void displayMemoryErrorMessage(); // pesan ketika gagal alokasi memory

void displayNameAddedMessage(char* personName, char* cityName); // Pesan ketika add nama berhasil

void displayCityNotFoundMessage(char* cityName); // pesan ketika kota yang dicari tidak ditemukan

void displayCityDeletedMessage(char* cityName); // pesan ketika delete kota berhasil

void displayNameDeletedMessage(char* personName, char* cityName); // pesan ketika delete nama berhasil

void displayCityNameCountMessage(char* cityName, int count); // Menampilkan jumlah nama suatu kota

void displayTotalNamesMessage(int cityCount, int totalNames); // menampilkan jumlah nama seluruh kota

void waitForEnter(); // menunggu enter sebelum clear screen

// UI function
 
void gotoxy(int x, int y); // mengatur posisi dari output di terminal (menggunakan handle dari windows.h)

void drawbox(int x, int y); // membuat box untuk output prgram

#endif /* UI_H */
