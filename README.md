# Praktikum SDA - Implementasi Struktur Data Linear

Repository ini berisi implementasi studi kasus struktur data linear menggunakan bahasa C, yang dikembangkan sebagai bagian dari mata kuliah Struktur Data dan Algoritma di Politeknik Negeri Bandung.

## Studi Kasus

### Kasus 5: Manajemen Data Kota dan Nama (Struktur Statis)
Implementasi struktur data yang menggabungkan alokasi statis (array) untuk menyimpan data kota dan alokasi dinamis (linked list) untuk menyimpan nama-nama orang di setiap kota.

#### Fitur:
- Entry data kota dan nama
- Penghapusan kota beserta seluruh nama terkait
- Penghapusan nama spesifik pada suatu kota
- Menampilkan data nama per kota atau seluruh kota

### Kasus 6: Pengembangan Kasus 5 (Struktur Dinamis)
Pengembangan dari studi kasus 5 dengan mengubah struktur penyimpanan kota dari array statis menjadi linked list.

#### Peningkatan:
- ADT linked list yang dioptimalkan untuk tipe data integer dan string
- Manajemen list kota dengan linked list
- UI program yang ditingkatkan dengan menggunakan drawbox dan gotoxy

## Struktur Kode

### Komponen ADT pada Kasus 5:
- Linked.h & Linked.c - Implementasi linked list dasar
- CaseCity.h & CaseCity.c - ADT untuk pengelolaan array kota
- Logic.h & Logic.c - Kontrol logika program
- UI.h & UI.c - Komponen tampilan
- Main.c - Program utama

### Komponen ADT pada Kasus 6:
- Linked.h & Linked.c - Implementasi linked list yang dioptimasi
- CaseCity.h & CaseCity.c - ADT untuk pengelolaan kota dengan linked list
- Controller.h & Controller.c - Pengganti Logic untuk adaptasi struktur baru
- UI.h & UI.c - Komponen tampilan yang ditingkatkan
- Main.c - Program utama

## Pembelajaran Utama
- Implementasi alokasi statis vs dinamis
- Pengelolaan memori di bahasa C
- Penggunaan macro generic untuk fleksibilitas tipe data
- Modularisasi program untuk kemudahan pengembangan
- Teknik handling memory leak pada penggunaan string literal

## Pengembang
Dikembangkan oleh Muhammad Nabil Syauqi Rasyiq (241524018) - Kelas 1A
Jurusan Teknik Komputer dan Informatika, Politeknik Negeri Bandung
