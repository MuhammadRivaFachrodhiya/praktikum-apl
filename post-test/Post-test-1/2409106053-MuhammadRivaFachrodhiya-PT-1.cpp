#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

const string pinATM = "6053";
const int kesempatanMaks = 3;
double saldo = 20000;

void clearScreen() {
    system("cls");
    system("clear");
}

void delay(int detik) {
    this_thread::sleep_for(chrono::seconds(detik));
}

void cekSaldo() {
    cout << fixed << setprecision(0);
    cout << "Saldo Anda saat ini: Rp " << saldo << endl;
}

void setorTunai() {
    double jumlah;
    cout << "Masukkan jumlah setor tunai: Rp ";
    cin >> jumlah;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid! Harus angka.\n";
        return;
    }

    if (jumlah > 0) {
        saldo += jumlah;
        cout << fixed << setprecision(0);
        cout << "Setor tunai berhasil! Saldo Anda sekarang: Rp " << saldo << endl;
    } else {
        cout << "Jumlah tidak valid!" << endl;
    }
}

void tarikTunai() {
    double jumlah;
    cout << "Masukkan jumlah tarik tunai: Rp ";
    cin >> jumlah;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid! Harus angka.\n";
        return;
    }

    if (jumlah > 0 && jumlah <= saldo) {
        saldo -= jumlah;
        cout << fixed << setprecision(0);
        cout << "Tarik tunai berhasil! Saldo Anda sekarang: Rp " << saldo << endl;
    } else {
        cout << "Jumlah tidak valid atau saldo tidak mencukupi!" << endl;
    }
}

int main() {
    string pin;
    int kesempatan = 0;
    bool isAuthenticated = false;

    while (kesempatan < kesempatanMaks) {
        clearScreen();
        cout << "===============";
        cout << "\nMasukkan PIN";
        cout << "\n===============";
        cout << "\nPIN : ";
        cin >> pin;

        if (pin.length() != 4) {
            cout << "PIN harus 4 digit!" << endl;
        } else if (pin == pinATM) {
            isAuthenticated = true;
            break;
        } else {
            cout << "PIN salah! Percobaan ke-" << (kesempatan + 1) << endl;
        }

        delay(1);
        kesempatan++;
    }

    if (!isAuthenticated) {
        cout << "Anda telah 3 kali salah memasukkan PIN. ATM diblokir!" << endl;
        return 0;
    }

    int pilihan;
    do {
        clearScreen();
        cout << "======================================";
        cout << "\n\t       Menu ATM\n";
        cout << "======================================";
        cout << "\n1. Cek Saldo >>\n2. Setor Tunai >>\n3. Tarik Tunai >>\n4. Keluar >>\n";
        cout << "=====================================";
        cout << "\nPilih menu: ";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Harap masukkan angka 1-4.\n";
            delay(2);
            continue; 
        }

        clearScreen();
        
        switch (pilihan) {
            case 1:
                cekSaldo();
                break;
            case 2:
                setorTunai();
                break;
            case 3:
                tarikTunai();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan ATM ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Harap masukkan angka 1-4.\n";
        }

        if (pilihan != 4) {
            cout << "\nTekan Enter untuk kembali ke menu... \n(Jika tekan sekali tidak bisa, maka tekan 2 kali)";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 4);

    return 0;
}
