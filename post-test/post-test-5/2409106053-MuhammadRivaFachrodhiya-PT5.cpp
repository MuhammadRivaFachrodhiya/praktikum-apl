#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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
const int MAX_FURNITURE = 50;
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

void clear() {
    system(CLEAR);
}

void paus() {
    cout << "Tekan enter untuk kembali ke menu...";
    cin.ignore(); cin.get();
}

void updateHarga(Furniture* furniture, int hargaBaru) {
    if (furniture != nullptr) {
        (*furniture).harga = hargaBaru;  
    }
}


void updateStok(Furniture& furniture, int stokBaru) {
    furniture.stok = stokBaru; 
}

void tampilkanFurniture() {
    cout << "=========================================================================" << endl;
    cout << "| No |      Nama      |    Harga (Rp)    | Stok |  Kategori  | Bahan  |" << endl;
    cout << "=========================================================================" << endl;
    for (int i = 0; i < jumlahFurniture; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(14) << furnitures[i].nama << " | "
             << setw(16) << furnitures[i].harga << " | " << setw(4) << furnitures[i].stok << " | "
             << setw(10) << furnitures[i].kategori.nama << " | " << setw(6) << furnitures[i].kategori.bahan << " |" << endl;
    }
    cout << "=========================================================================" << endl;
}

void tampilkanFurniture(string kategoriFilter) {
    cout << "=========================================================================" << endl;
    cout << "| No |      Nama      |    Harga (Rp)    | Stok |  Kategori  | Bahan  |" << endl;
    cout << "=========================================================================" << endl;
    int nomor = 1;
    for (int i = 0; i < jumlahFurniture; i++) {
        if (furnitures[i].kategori.nama == kategoriFilter) {
            cout << "| " << setw(2) << nomor++ << " | " << setw(14) << furnitures[i].nama << " | "
                 << setw(16) << furnitures[i].harga << " | " << setw(4) << furnitures[i].stok << " | "
                 << setw(10) << furnitures[i].kategori.nama << " | " << setw(6) << furnitures[i].kategori.bahan << " |" << endl;
        }
    }
    if (nomor == 1) {
        cout << "|                          Tidak ada data yang cocok                    |" << endl;
    }
    cout << "=========================================================================" << endl;
}

void tambahFurniture(int& jumlahRef) {
    if (jumlahRef >= MAX_FURNITURE) {
        cout << "Kapasitas penuh!\n";
        return;
    }
    cin.ignore();
    cout << "Nama\t\t: "; getline(cin, furnitures[jumlahRef].nama);
    cout << "Harga\t\t: "; cin >> furnitures[jumlahRef].harga;
    cout << "Stok\t\t: "; cin >> furnitures[jumlahRef].stok;
    cin.ignore();
    cout << "Kategori\t: "; getline(cin, furnitures[jumlahRef].kategori.nama);
    cout << "Bahan\t\t: "; getline(cin, furnitures[jumlahRef].kategori.bahan);
    jumlahRef++;  
    cout << "Furniture berhasil ditambahkan!\n";
}

void editFurniture(Furniture* furnitureArray) {
    tampilkanFurniture();
    int index;
    cout << "Masukkan nomor furniture yang ingin diedit: ";
    cin >> index;
    index--;
    if (index >= 0 && index < jumlahFurniture) {
        cin.ignore();
        cout << "Nama: "; getline(cin, (furnitureArray + index)->nama);  
        cout << "Harga: "; cin >> (*(furnitureArray + index)).harga;    
        cout << "Stok: "; cin >> furnitureArray[index].stok;            
        cin.ignore();
        cout << "Kategori: "; getline(cin, (*(furnitureArray + index)).kategori.nama);
        cout << "Bahan: "; getline(cin, (furnitureArray + index)->kategori.bahan);
        cout << "Data berhasil diperbarui!\n";
    } else {
        cout << "Nomor furniture tidak valid!\n";
    }
}


void hapusFurniture(Furniture* furnitureArray, int* jumlahPtr) {
    tampilkanFurniture();
    int index;
    cout << "Masukkan nomor furniture yang ingin dihapus: ";
    cin >> index;
    index--;

    if (index >= 0 && index < *jumlahPtr) {
        for (int i = index; i < *jumlahPtr - 1; i++) {
            *(furnitureArray + i) = *(furnitureArray + i + 1); 
        }
        (*jumlahPtr)--; 
        cout << "Furniture berhasil dihapus!\n";
    } else {
        cout << "Nomor furniture tidak valid!\n";
    }
}

void cariFurnitureBerdasarkanBahan() {
    cin.ignore();
    string bahan;
    cout << "Masukkan bahan yang ingin dicari: "; getline(cin, bahan);
    bool ditemukan = false;
    cout << "=========================================================================" << endl;
    cout << "| No |      Nama      |    Harga (Rp)    | Stok |  Kategori  | Bahan  |" << endl;
    cout << "=========================================================================" << endl;
    int nomor = 1;
    for (int i = 0; i < jumlahFurniture; i++) {
        if (furnitures[i].kategori.bahan == bahan) {
            ditemukan = true;
            cout << "| " << setw(2) << nomor++ << " | " << setw(14) << furnitures[i].nama << " | "
                 << setw(16) << furnitures[i].harga << " | " << setw(4) << furnitures[i].stok << " | "
                 << setw(10) << furnitures[i].kategori.nama << " | " << setw(6) << furnitures[i].kategori.bahan << " |" << endl;
        }
    }
    if (!ditemukan) {
        cout << "|                          Tidak ada data yang cocok                    |" << endl;
    }
    cout << "=========================================================================" << endl;
}

void urutkanFurnitureBerdasarkanHarga() {
    sort(furnitures, furnitures + jumlahFurniture, [](Furniture a, Furniture b) {
        return a.harga < b.harga;
    });
    cout << "Data berhasil diurutkan berdasarkan harga (termurah ke termahal)!\n";
    tampilkanFurniture();
}

void hitungTotal(int& totalStok, int& totalNilai) {
    totalStok = 0;
    totalNilai = 0;
    for (int i = 0; i < jumlahFurniture; i++) {
        totalStok += furnitures[i].stok;
        totalNilai += furnitures[i].stok * furnitures[i].harga;
    }
    cout << "Total Stok Furniture   : " << totalStok << endl;
    cout << "Total Nilai Persediaan : Rp. " << totalNilai << endl;
}

bool login(int attempts, string& role) {
    if (attempts == 0) {
        cout << "Anda telah salah memasukkan password 3 kali. Program berhenti.\n";
        return false;
    }

    string username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    for (int i = 0; i < jumlahUsers; i++) {
        if (username == users[i].username && password == users[i].password) {
            cout << "Login berhasil!\n";
            role = users[i].role;
            return true;
        }
    }

    cout << "Login gagal! Sisa percobaan: " << attempts - 1 << endl;
    return login(attempts - 1, role);
}

void registrasi(User* userArray, int* jumlahPtr) {
    clear();
    if (*jumlahPtr >= MAX_USERS) {
        cout << "Pendaftaran penuh! Tidak bisa menambah akun baru.\n";
    } else {
        cin.ignore();
        cout << "Username: "; getline(cin, (userArray + *jumlahPtr)->username);
        cout << "Password: "; getline(cin, (userArray + *jumlahPtr)->password);
        (*(userArray + *jumlahPtr)).role = "user";  
        (*jumlahPtr)++; 
        cout << "Registrasi berhasil!\n";
    }
    paus();
}

int main() {
    int pilihan;
    string role;

    while (true) {
        do {
            clear();
            cout << "============================================" << endl;
            cout << "|                 MENU AKUN                |" << endl;
            cout << "============================================" << endl;
            cout << "| 1. Login\t\t\t\t   |\n| 2. Registrasi\t\t\t\t   |\n| 3. Keluar\t\t\t\t   |" << endl;
            cout << "============================================" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;

            if (pilihan == 2) {
                registrasi(users, &jumlahUsers);  
            }
        } while (pilihan == 2);

        if (pilihan == 3) break;

        clear();
        cout << "==============================\n";
        cout << "            LOGIN\n";
        cout << "==============================\n";
        if (!login(3, role)) break;

        bool kembaliKeMenuAwal = false;
        do {
            clear();
            cout << "============================================" << endl;
            cout << "                MENU UTAMA" << endl;
            cout << "============================================" << endl;
            cout << "1. Tampilkan Semua Furniture" << endl;
            if (role == "admin") {
                cout << "2. Tambah Furniture" << endl;
                cout << "3. Edit Furniture" << endl;
                cout << "4. Hapus Furniture" << endl;
                cout << "5. Tampilkan Furniture berdasarkan kategori" << endl;
                cout << "6. Cari Furniture berdasarkan bahan" << endl;
                cout << "7. Urutkan berdasarkan harga" << endl;
                cout << "8. Hitung total" << endl;
                cout << "9. Kembali ke Menu Awal" << endl;
            } else {
                cout << "2. Kembali ke Menu Awal" << endl;
            }
            cout << "============================================" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;

            clear();
            if (pilihan == 1) {
                tampilkanFurniture();
                paus();
            } else if (role == "admin" && pilihan == 2) {
                tambahFurniture(jumlahFurniture);  
                paus();
            } else if (role == "admin" && pilihan == 3) {
                editFurniture(furnitures);  
                paus();
            } else if (role == "admin" && pilihan == 4) {
                hapusFurniture(furnitures, &jumlahFurniture);  
                paus();
            } else if (role == "admin" && pilihan == 5) {
                cin.ignore();
                string kategori;
                cout << "Masukkan kategori: ";
                getline(cin, kategori);
                tampilkanFurniture(kategori);
                paus();
            } else if (role == "admin" && pilihan == 6) {
                cariFurnitureBerdasarkanBahan();
                paus();
            } else if (role == "admin" && pilihan == 7) {
                urutkanFurnitureBerdasarkanHarga();
                paus();
            } else if (role == "admin" && pilihan == 8) {
                int totalStok, totalNilai;
                hitungTotal(totalStok, totalNilai);  
                paus();
            } else if ((role == "admin" && pilihan == 9) || (role != "admin" && pilihan == 2)) {
                kembaliKeMenuAwal = true;
            }
        } while (!kembaliKeMenuAwal);
    }

    cout << "Terima kasih telah menggunakan program ini.\n";
    return 0;
}