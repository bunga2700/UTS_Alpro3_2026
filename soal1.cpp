#include <iostream>
using namespace std;

int main() {
    char nomor_kartu[20];
    int panjang = 0;

    cout << "Masukkan nomor kartu digital: "; // Meminta input nomor kartu
    cin >> nomor_kartu;

    //Mencari panjang input
    while (nomor_kartu[panjang] != '\0') {
        panjang++;
    }

    // Cek semua karakter harus angka
    for (int i = 0; i < panjang; i++) {
        if (nomor_kartu[i] < '0' || nomor_kartu[i] > '9') {
            cout << "Nomor kartu TIDAK VALID." << endl;
            return 0;
        }
    }

    // Cek tipe kartu berdasarkan panjang dan awalan
    int digit1 = nomor_kartu[0] - '0';
    int digit2 = nomor_kartu[1] - '0';
    const char* tipe = "";

    if (panjang == 14 && digit1 == 6 && digit2 == 5) {
        tipe = "NUSANTARA";
    }
    else if (panjang == 16 && digit1 == 7 && (digit2 == 7 || digit2 == 8)) {
        tipe = "GARUDA";
    }
    else if (panjang == 15 && digit1 == 9 && digit2 == 1) {
        tipe = "MERDEKA";
    }
    else {
        cout << "Nomor kartu TIDAK VALID." << endl;
        return 0;
    }

    // Validasi menggunakan algoritma Luhn
    int total = 0;
    bool gandakan = false;

    for (int i = panjang - 1; i >= 0; i--) { // Loop dari digit terakhir ke pertama
        int digit = nomor_kartu[i] - '0';

        if (gandakan) {
            digit = digit * 2;
            if (digit > 9) {
                digit = digit - 9;
            }
        }

        total += digit;
        gandakan = !gandakan;
    }

    // Menampilkan tipe kartu
    cout << "Tipe kartu: " << tipe << endl;

    // Menampilkan hasil validasi
    if (total % 10 == 0) {
        cout << "Nomor kartu VALID." << endl;
    } 
    else {
        cout << "Nomor kartu TIDAK VALID." << endl;
    }

    return 0;
}

/*
Logika pengerjaan:
1. Program meminta user memasukkan nomor kartu digital.
2. Program menghitung panjang input secara manual dengan perulangan.
3. Program memeriksa apakah semua karakter pada input adalah angka.
    - Jika ada huruf atau simbol, program menampilkan: "Nomor kartu TIDAK VALID." lalu berhenti.
4. Program memeriksa apakah panjang input minimal 2 digit.
    - Jika kurang dari 2 digit, program menampilkan: "Nomor kartu TIDAK VALID." lalu berhenti.
5. Program mengambil 2 digit awal untuk menentukan tipe kartu.
6. Program menentukan tipe kartu berdasarkan panjang dan awalan:
    - 14 digit dan awalan 65  -> NUSANTARA
    - 16 digit dan awalan 77 atau 78 -> GARUDA
    - 15 digit dan awalan 91  -> MERDEKA
7. Jika panjang dan awalan tidak sesuai, program menampilkan:
    "Nomor kartu TIDAK VALID."
    lalu berhenti.
8. Jika tipe kartu valid, program menjalankan algoritma Luhn:
    - membaca digit dari kanan ke kiri
    - setiap digit ke-2 digandakan
    - jika hasil perkalian lebih dari 9, dikurangi 9
    - semua hasil dijumlahkan
9. Program menampilkan tipe kartu.
10. Program memeriksa hasil akhir algoritma Luhn:
    - jika total habis dibagi 10, nomor kartu VALID
    - jika tidak, nomor kartu TIDAK VALID
*/