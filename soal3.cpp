#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode transaksi (8 digit): "; // Meminta input kode transaksi
    cin >> kode;

    // Validasi panjang kode harus 8 digit
    if (kode.length() != 8) {
        cout << "Kode transaksi TIDAK VALID." << endl;
        return 0;
    }

    // Validasi semua karakter harus angka
    for (int i = 0; i < 8; i++) {
        if (kode[i] < '0' || kode[i] > '9') {
            cout << "Kode transaksi TIDAK VALID." << endl;
            return 0;
        }
    }

    string jenis_hari = kode.substr(0, 2);
    string loyalitas = kode.substr(2, 2);
    string jumlah_belanja = kode.substr(4, 4);
    
    // Menentukan jenis hari
    string nama_hari;
    if (jenis_hari == "01") {
        nama_hari = "Hari Kerja";
    }
    else if (jenis_hari == "02") {
        nama_hari = "Akhir Pekan";
    }
    else if (jenis_hari == "03") {
        nama_hari = "Hari Libur Nasional";
    }
    else {
        cout << "Kode transaksi TIDAK VALID." << endl;
        return 0;
    }

    // Menentukan jenis pelanggan (biasa/silver/gold)
    string jenis_pelanggan;
    if (loyalitas == "01") {
        jenis_pelanggan = "Biasa";
    }
    else if (loyalitas == "02") {
        jenis_pelanggan = "Silver";
    }
    else if (loyalitas == "03") {
        jenis_pelanggan = "Gold";
    }
    else {
        cout << "Kode transaksi TIDAK VALID." << endl;
        return 0;
    }

    // Menghitung poin berdasarkan jenis hari dan loyalitas
    int poin_per_100rb = 0;

    if (jenis_hari == "01") { // Hari Kerja
        if (loyalitas == "01") poin_per_100rb = 1;
        else if (loyalitas == "02") poin_per_100rb = 2;
        else if (loyalitas == "03") poin_per_100rb = 3;
    }
    else if (jenis_hari == "02") { // Akhir Pekan
        if (loyalitas == "01") poin_per_100rb = 2;
        else if (loyalitas == "02") poin_per_100rb = 3;
        else if (loyalitas == "03") poin_per_100rb = 5;
    }
    else if (jenis_hari == "03") { // Hari Libur Nasional
        if (loyalitas == "01") poin_per_100rb = 3;
        else if (loyalitas == "02") poin_per_100rb = 5;
        else if (loyalitas == "03") poin_per_100rb = 7;
    }

    // Menghitung jumlah belanja dari 4 digit terakhir
    int jumlah_belanja_ = stoi(kode.substr(4, 4)) * 100000;

    // Menghitung total poin
    int total_poin = poin_per_100rb * (jumlah_belanja_ / 100000);

    // 7. Menampilkan hasil
    cout << "Jenis Hari: " << nama_hari << endl;
    cout << "Jenis Pelanggan: " << jenis_pelanggan << endl;
    cout << "Jumlah Belanja: Rp " << jumlah_belanja_ << endl;
    cout << "Total Poin: " << total_poin << endl;

    return 0;
}

/*
Logika pengerjaan:
1. Program meminta user memasukkan kode transaksi 8 digit.
2. Program mengecek apakah panjang kode tepat 8 digit.
    - Jika tidak, program menampilkan "Kode transaksi TIDAK VALID." lalu berhenti.
3. Program mengecek apakah semua karakter pada kode adalah angka.
    - Jika ada huruf/simbol, program menampilkan "Kode transaksi TIDAK VALID." lalu berhenti.
4. Program mengambil isi kode menjadi 3 bagian:
    - 2 digit pertama  : jenis hari
    - 2 digit berikutnya: jenis pelanggan/loyalitas
    - 4 digit terakhir : jumlah belanja
5. Program mengubah 2 digit pertama menjadi nama hari:
    - 01 = Hari Kerja
    - 02 = Akhir Pekan
    - 03 = Hari Libur Nasional
    Jika tidak sesuai, program menampilkan "Kode transaksi TIDAK VALID." lalu berhenti.
6. Program mengubah 2 digit berikutnya menjadi jenis pelanggan:
    - 01 = Biasa
    - 02 = Silver
    - 03 = Gold
    Jika tidak sesuai, program menampilkan "Kode transaksi TIDAK VALID." lalu berhenti.
7. Program menentukan poin per Rp100.000 berdasarkan kombinasi
    jenis hari dan jenis pelanggan.
8. Program menghitung total belanja:
    jumlah = 4 digit terakhir x Rp100.000
9. Program menghitung total poin:
    total_poin = poin_per_100rb x (jumlah / 100000)
10. Program menampilkan:
    - Jenis Hari
    - Jenis Pelanggan
    - Jumlah Belanja
    - Total Poin
*/