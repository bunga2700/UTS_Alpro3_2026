#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode, waktu_keluar;

    cout << "Masukkan kode parkir (10 digit): "; // Meminta input kode parkir
    cin >> kode;

    cout << "Masukkan waktu keluar (HHMM): "; // Meminta input waktu keluar
    cin >> waktu_keluar;

    // Validasi panjang kode harus 10 digit
    if (kode.length() != 10) {
        cout << "Kode parkir TIDAK VALID." << endl;
        return 0;
    }

    // Validasi semua karakter harus angka
    for (int i = 0; i < 10; i++) {
        if (kode[i] < '0' || kode[i] > '9') {
            cout << "Kode parkir TIDAK VALID." << endl;
            return 0;
        }
    }

    string jenis_kode = kode.substr(0, 2);
    string waktu_masuk = kode.substr(2, 4);
    string lokasi = kode.substr(6, 4);

    string jenis;
    int tarif_awal, tarif_berikutnya;

    // Menentukan jenis kendaraan dan tarif
    if (jenis_kode == "10") {
        jenis = "Mobil"; 
        tarif_awal = 5000; 
        tarif_berikutnya = 3000;
    } 
    else if (jenis_kode == "20") {
        jenis = "Motor"; 
        tarif_awal = 3000; 
        tarif_berikutnya = 2000;
    } 
    else if (jenis_kode == "30") {
        jenis = "Bus"; 
        tarif_awal = 10000; 
        tarif_berikutnya = 7000;
    } 
    else {
        cout << "Kode parkir TIDAK VALID." << endl;
        return 0;
    }

    // Ambil jam & menit
    int jm = stoi(waktu_masuk.substr(0, 2));
    int mm = stoi(waktu_masuk.substr(2, 2));
    int jk = stoi(waktu_keluar.substr(0, 2));
    int mk = stoi(waktu_keluar.substr(2, 2));

    // Validasi waktu
    if (jm > 23 || mm > 59 || jk > 23 || mk > 59) {
        cout << "Waktu TIDAK VALID." << endl;
        return 0;
    }

    // konversi ke menit
    int masuk = jm * 60 + mm;
    int keluar = jk * 60 + mk;

    // Validasi waktu keluar harus lebih besar dari masuk 
    if (keluar < masuk) {
        cout << "Waktu TIDAK VALID." << endl;
        return 0;
    }

    // Hitung lama parkir dalam jam (pembulatan ke atas)
    int lama_parkir = (keluar - masuk + 59) / 60;

    // Hitung biaya
    int biaya = 0;
    if (lama_parkir <= 1) {
        biaya = tarif_awal;
    } 
    else {
        biaya = tarif_awal + (lama_parkir - 1) * tarif_berikutnya;
    }

    // Menampilkan ringkasan parkir
    cout << "\n--- Ringkasan Parkir ---" << endl;
    cout << "Jenis kendaraan: " << jenis << endl;
    cout << "Waktu masuk: " << jm << ":" << mm << endl;
    cout << "Waktu keluar: " << jk << ":" << mk << endl;
    cout << "Durasi parkir: " << lama_parkir << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}

/*
Logika pengerjaan:
1. Program meminta input kode parkir dan waktu keluar.
2. Program mengecek apakah kode parkir terdiri dari 10 digit dan berupa angka.
    - Jika tidak, program menampilkan "Kode parkir TIDAK VALID." lalu berhenti.
4. Program memisahkan kode parkir menjadi 3 bagian:
    - 2 digit pertama : jenis kendaraan
    - 4 digit tengah  : waktu masuk
    - 4 digit terakhir : lokasi parkir
5. Program menentukan jenis kendaraan dan tarif:
    - 10 = Mobil
    - 20 = Motor
    - 30 = Bus
    Jika tidak sesuai, program menampilkan "Kode parkir TIDAK VALID." lalu berhenti.
6. Program memisahkan waktu masuk dan waktu keluar menjadi jam dan menit.
7. Program memeriksa validitas waktu:
    - jam harus 0 sampai 23
    - menit harus 0 sampai 59
    Jika tidak valid, program menampilkan "Waktu TIDAK VALID." lalu berhenti.
8. Program mengubah waktu masuk dan waktu keluar ke satuan menit.
9. Program mengecek apakah waktu keluar lebih besar atau sama dengan waktu masuk.
    - Jika waktu keluar lebih kecil, program menampilkan "Waktu TIDAK VALID." lalu berhenti.
10. Program menghitung lama parkir dalam jam, dibulatkan ke atas.
11. Program menghitung biaya parkir:
    - Jika durasi <= 1 jam, biaya = tarif awal
    - Jika durasi > 1 jam, biaya = tarif awal + (jam berikutnya x tarif berikutnya)
12. Program menampilkan ringkasan parkir:
    - jenis kendaraan
    - waktu masuk
    - waktu keluar
    - durasi parkir
    - lokasi
    - total biaya
*/