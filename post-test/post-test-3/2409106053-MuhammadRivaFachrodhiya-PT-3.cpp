#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

struct User {
    string username;
    string password;
    string role;
};

struct Kategori {
    string nama;
    string bahan;
};

struct Furniture {
    string nama;
    int harga;
    int stok;
    Kategori kategori;
};

const int MAX_USERS = 5;
const int MAX_FURNITURE = 10;
User users[MAX_USERS] = {
    {"admin", "admin053", "admin"}
};
int jumlahUsers = 1;

Furniture furnitures[MAX_FURNITURE] = {
    {"Meja Kayu", 500000, 10, {"Meja", "Kayu"}},
    {"Kursi Rotan", 250000, 15, {"Kursi", "Rotan"}},
    {"Lemari Jati", 1500000, 5, {"Lemari", "Jati"}},
    {"Sofa Minimalis", 2000000, 3, {"Sofa", "Kain"}},
    {"Rak Buku", 300000, 8, {"Rak", "Kayu"}}
};
int jumlahFurniture = 5;

int main() {
    string username, password, role;
    int pilihan;
    
    do {
        system(CLEAR);
        cout << "============================================" << endl;
        cout << "                 MENU AKUN" << endl;
        cout << "============================================" << endl;
        cout << "1. Login\n2. Registrasi\n3. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        if (pilihan == 2) {
            system(CLEAR);
            if (jumlahUsers >= MAX_USERS) {
                cout << "Pendaftaran penuh! Tidak bisa menambah akun baru.\n";
            } else {
                system(CLEAR);
                cout << "==============================" << endl;
                cout << "           REGISTER" << endl;
                cout << "==============================" << endl;
                cout << "Username: "; cin >> users[jumlahUsers].username;
                cout << "Password: "; cin >> users[jumlahUsers].password;
                users[jumlahUsers].role = "user";
                jumlahUsers++;
                cout << "Registrasi berhasil!\n";
            }
            cout << "Tekan enter untuk kembali ke menu...";
            cin.ignore(); cin.get();
        }
    } while (pilihan == 2);
    
    if (pilihan == 3) return 0;
    
    int attempts = 0;
    bool loggedIn = false;
    while (attempts < 3) {
        system(CLEAR);
        cout << "==============================" << endl;
        cout << "            LOGIN" << endl;
        cout << "==============================" << endl;
        cout << "Username: "; cin >> username;
        cout << "Password: "; cin >> password;
        
        for (int i = 0; i < jumlahUsers; i++) {
            if (username == users[i].username && password == users[i].password) {
                cout << "Login berhasil!\n";
                system(CLEAR);
                loggedIn = true;
                role = users[i].role;
                break;
            }
        }
        if (loggedIn) break;
        cout << "Login gagal! Coba lagi.\n";
        attempts++;
    }
    if (!loggedIn) {
        cout << "Anda telah salah memasukkan password 3 kali. Program berhenti.\n";
        return 0;
    }
    
    do {
        system(CLEAR);
        cout << "============================================" << endl;
        cout << "                MENU UTAMA" << endl;
        cout << "============================================" << endl;
        cout << "1. Tampilkan Furniture" << endl;
        if (role == "admin") {
            cout << "2. Tambah Furniture\n3. Edit Furniture\n4. Hapus Furniture" << endl;
        }
        cout << "5. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        system(CLEAR);
        if (pilihan == 1) {
            cout << "=========================================================================" << endl;
            cout << "| No |      Nama      |    Harga (Rp)    | Stok |  Kategori  | Bahan  |" << endl;
            cout << "=========================================================================" << endl;
            for (int i = 0; i < jumlahFurniture; i++) {
                cout << "| " << setw(2) << i + 1 << " | " << setw(14) << furnitures[i].nama << " | "
                     << setw(16) << furnitures[i].harga << " | " << setw(4) << furnitures[i].stok << " | "
                     << setw(10) << furnitures[i].kategori.nama << " | " << setw(6) << furnitures[i].kategori.bahan << " |" << endl;
            }
            cout << "=========================================================================" << endl;
            cout << "Tekan enter untuk kembali ke menu...";
            cin.ignore(); cin.get();
        } else if (role == "admin" && pilihan == 2) {
            cout << "=======================================================================" << endl;
            cout << "| No |      Nama      |    Harga (Rp)    | Stok |  Kategori  | Bahan  |" << endl;
            cout << "=======================================================================" << endl;
            for (int i = 0; i < jumlahFurniture; i++) {
                cout << "| " << setw(2) << i + 1 << " | " << setw(14) << furnitures[i].nama << " | "
                     << setw(16) << furnitures[i].harga << " | " << setw(4) << furnitures[i].stok << " | "
                     << setw(10) << furnitures[i].kategori.nama << " | " << setw(6) << furnitures[i].kategori.bahan << " |" << endl;
            }
            cout << "=======================================================================" << endl;
            if (jumlahFurniture < MAX_FURNITURE) {
                cout << "Nama\t\t: "; cin.ignore(); getline(cin, furnitures[jumlahFurniture].nama);
                cout << "Harga\t\t: "; cin >> furnitures[jumlahFurniture].harga;
                cout << "Stok\t\t: "; cin >> furnitures[jumlahFurniture].stok;
                cin.ignore();
                cout << "Kategori\t: "; getline(cin, furnitures[jumlahFurniture].kategori.nama);
                cout << "Bahan\t\t: "; getline(cin, furnitures[jumlahFurniture].kategori.bahan);
                jumlahFurniture++;
            } else {
                cout << "Kapasitas penuh!";
            }
        } else if (role == "admin" && pilihan == 3) {
            cout << "=======================================================================" << endl;
            cout << "| No |      Nama      |    Harga (Rp)    | Stok |  Kategori  | Bahan  |" << endl;
            cout << "=======================================================================" << endl;
            for (int i = 0; i < jumlahFurniture; i++) {
                cout << "| " << setw(2) << i + 1 << " | " << setw(14) << furnitures[i].nama << " | "
                     << setw(16) << furnitures[i].harga << " | " << setw(4) << furnitures[i].stok << " | "
                     << setw(10) << furnitures[i].kategori.nama << " | " << setw(6) << furnitures[i].kategori.bahan << " |" << endl;
            }
            cout << "=======================================================================" << endl;
            int index;
            cout << "Masukkan nomor furniture yang ingin diedit: ";
            cin >> index;
            index--;
            if (index >= 0 && index < jumlahFurniture) {
                cout << "Nama: "; cin.ignore(); getline(cin, furnitures[index].nama);
                cout << "Harga: "; cin >> furnitures[index].harga;
                cout << "Stok: "; cin >> furnitures[index].stok;
                cin.ignore();
                cout << "Kategori: "; getline(cin, furnitures[index].kategori.nama);
                cout << "Bahan: "; getline(cin, furnitures[index].kategori.bahan);
            } else {
                cout << "Nomor furniture tidak valid!";
            }
        }   
    } while (pilihan != 5);

    
    return 0;
}
