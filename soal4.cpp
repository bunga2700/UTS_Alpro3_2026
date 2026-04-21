#include <iostream>
#include <string>
#include <cctype> // Untuk fungsi toupper
using namespace std;

int main() {
    int n;
    string s;

    cin >> n; // input jumlah pertandingan
    cin >> s; // input hasil pertandingan (A/B/C)

    // Validasi panjang string harus sama dengan n
    if (s.length() != n) {
        cout << "Input TIDAK VALID." << endl;
        return 0;
    }

    int poin_A = 0, poin_B = 0;
    int streak_A = 0, streak_B = 0;

    // Loop untuk setiap pertandingan
    for (int i = 0; i < n; i++) { 
        char hasil = toupper(s[i]);

        if (hasil == 'A') { // Jika pemain A menang
            poin_A += 3;
            streak_A++;
            streak_B = 0;

            // Bonus jika menang 3 kali berturut-turut
            if (streak_A == 3) {
                poin_A += 2;
                streak_A = 0;
            }
        }
        else if (hasil == 'B') { // jika pemain B menang
            poin_B += 3;
            streak_B++;
            streak_A = 0;

            // Bonus jika menang 3 kali berturut-turut
            if (streak_B == 3) {
                poin_B += 2;
                streak_B = 0;
            }
        }
        else if (hasil == 'C') { // jika pertandingan seri
            poin_A += 1;
            poin_B += 1;
            streak_A = 0;
            streak_B = 0;
        }
        else {
            cout << "Input TIDAK VALID." << endl; // Validasi input
            return 0;
        }
    }

    // Menampilkan poin akhir kedua pemain
    cout << "\nPoin A: " << poin_A << endl; 
    cout << "Poin B: " << poin_B << endl; 

    // Menentukan pemenang
    if (poin_A > poin_B) { // Jika poin A lebih besar dari B
        cout << "Pemenangnya adalah pemain A" << endl;
    }
    else if (poin_B > poin_A) { // Jika poin B lebih besar dari A
        cout << "Pemenangnya adalah pemain B" << endl;
    }
    else {
        cout << "Hasil pertandingan Seri!" << endl; // Jika poin A dan B sama
    }

    return 0;
}

/*
Logika pengerjaan:
1. Program membaca input pertama yaitu jumlah pertandingan (n).
2. Program membaca input kedua yaitu string hasil pertandingan (s) yang berisi A, B, atau C.
3. Program mengecek apakah panjang string s sama dengan n.
    - Jika tidak sama, program menampilkan "Input TIDAK VALID." dan berhenti.
4. Program menyiapkan variabel poin dan streak:
    - poin_A dan poin_B untuk menyimpan poin akhir.
    - streak_A dan streak_B untuk menghitung kemenangan berturut-turut.
5. Program memproses setiap karakter dalam string hasil pertandingan satu per satu.
6. Setiap karakter diubah menjadi huruf kapital dengan toupper agar input kecil tetap terbaca.
7. Jika hasil pertandingan adalah:
    - A: pemain A menang, poin A bertambah 3, streak A naik 1, streak B reset.
    - B: pemain B menang, poin B bertambah 3, streak B naik 1, streak A reset.
    - C: pertandingan seri, poin A dan B masing-masing bertambah 1, kedua streak direset.
8. Jika salah satu pemain menang 3 kali berturut-turut, pemain tersebut mendapat bonus 2 poin.
    Setelah bonus diberikan, streak kembali direset ke 0.
9. Jika karakter selain A, B, atau C ditemukan, program menampilkan "Input TIDAK VALID." dan berhenti.
10. Setelah semua pertandingan diproses, program menampilkan poin akhir pemain A dan B.
11. Program membandingkan poin akhir:
    - Jika poin A lebih besar, pemain A menang.
    - Jika poin B lebih besar, pemain B menang.
    - Jika sama, hasil pertandingan seri.
*/