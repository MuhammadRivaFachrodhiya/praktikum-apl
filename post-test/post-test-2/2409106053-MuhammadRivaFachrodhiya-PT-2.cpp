#include <iostream>
#include <iomanip>
#include <string>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
using namespace std;

string akun[2] = {"Ripa", "053"};


const int kapasitas = 7;
string furniture[kapasitas][3] = {
    {"Meja Kayu", "500000", "10"},
    {"Kursi Rotan", "250000", "15"},
    {"Lemari Jati", "1500000", "5"},
    {"Sofa Minimalis", "2000000", "3"},
    {"Rak Buku", "300000", "8"}
};
string kategori[kapasitas] = {"Meja", "Kursi", "Lemari", "Sofa", "Rak"};
string bahan[kapasitas] = {"Kayu", "Rotan", "Jati", "Kain", "Kayu"};
int jumlahFurniture = 5;


bool login() {
    string username, password;
    int attempts = 0;
    while (attempts < 3) {
        cout << "==============================" << endl;
        cout << "            LOGIN" << endl;
        cout << "==============================" << endl;
        cout << "Username: "; cin >> username;
        cout << "Password: "; cin >> password;
        
        if (username == akun[0] && password == akun[1]) {
            cout << "Login berhasil!\n";
            system(CLEAR);
            return true;
        }
        cout << "Login gagal! Coba lagi.\n";
        attempts++;
    }
    cout << "Anda telah salah memasukkan password 3 kali. Program berhenti.\n";
    return false;
}

int main() {
    if (!login()) return 0;
    
    int pilihan;
    do {
        system(CLEAR);
        cout << "============================================" << endl;
        cout << "                MENU UTAMA" << endl;
        cout << "============================================" << endl;
        cout << "1. Tampilkan Furniture\n2. Tambah Furniture\n3. Edit Furniture\n4. Hapus Furniture\n5. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        system(CLEAR);
        switch (pilihan) {
            case 1:
                cout << "===============================================================================" << endl;
                cout << "                                MENU FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "-------------------------------------------------------------------------------\n"; 
                cout << "| No | Nama             | Harga (Rp) | Stok | Kategori  | Bahan     |\n";
                cout << "-------------------------------------------------------------------------------\n";
                for (int i = 0; i < jumlahFurniture; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(15) << furniture[i][0] << " | "
                         << setw(10) << furniture[i][1] << " | " << setw(4) << furniture[i][2] << " | "
                         << setw(9) << kategori[i] << " | " << setw(9) << bahan[i] << " |\n";
                }
                cout << "-------------------------------------------------------------------------------\n";
                cout << "Tekan enter untuk kembali ke menu...";
                cin.ignore(); cin.get();
                break;
            case 2:
                if (jumlahFurniture >= kapasitas) {
                    cout << "Stok penuh! Tidak bisa menambah furniture baru.\n";
                    cout << "Tekan enter untuk kembali ke menu...";
                    cin.ignore(); cin.get();
                    break;
                }
                cout << "===============================================================================" << endl;
                cout << "                                MENU FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "-------------------------------------------------------------------------------\n"; 
                cout << "| No | Nama             | Harga (Rp) | Stok | Kategori  | Bahan     |\n";
                cout << "-------------------------------------------------------------------------------\n";
                for (int i = 0; i < jumlahFurniture; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(15) << furniture[i][0] << " | "
                         << setw(10) << furniture[i][1] << " | " << setw(4) << furniture[i][2] << " | "
                         << setw(9) << kategori[i] << " | " << setw(9) << bahan[i] << " |\n";
                }
                cout << "-------------------------------------------------------------------------------\n";
                cout << "===============================================================================" << endl;
                cout << "                            MENU TAMBAH FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "Nama: "; cin.ignore(); getline(cin, furniture[jumlahFurniture][0]);
                cout << "Harga: "; cin >> furniture[jumlahFurniture][1];
                cout << "Stok: "; cin >> furniture[jumlahFurniture][2];
                cin.ignore();
                cout << "Kategori: "; getline(cin, kategori[jumlahFurniture]);
                cout << "Bahan: "; getline(cin, bahan[jumlahFurniture]);
                jumlahFurniture++;
                cout << "Furniture berhasil ditambahkan!\n";
                break;
            case 3:
                cout << "===============================================================================" << endl;
                cout << "                                MENU FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "-------------------------------------------------------------------------------\n"; 
                cout << "| No | Nama             | Harga (Rp) | Stok | Kategori  | Bahan     |\n";
                cout << "-------------------------------------------------------------------------------\n";
                for (int i = 0; i < jumlahFurniture; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(15) << furniture[i][0] << " | "
                        << setw(10) << furniture[i][1] << " | " << setw(4) << furniture[i][2] << " | "
                        << setw(9) << kategori[i] << " | " << setw(9) << bahan[i] << " |\n";
                }
                cout << "-------------------------------------------------------------------------------\n";
                cout << "===============================================================================" << endl;
                cout << "                             MENU EDIT FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "Pilih nomor furniture yang ingin diedit: ";
                int editIndex;
                cin >> editIndex;
                editIndex--;
                if (editIndex < 0 || editIndex >= jumlahFurniture) {
                    cout << "Nomor tidak valid!\n";
                    break;
                }
                cout << "\nMasukkan data baru:\n";
                cout << "Nama: "; cin.ignore(); getline(cin, furniture[editIndex][0]);
                cout << "Harga: "; cin >> furniture[editIndex][1];
                cout << "Stok: "; cin >> furniture[editIndex][2];
                cin.ignore();
                cout << "Kategori: "; getline(cin, kategori[editIndex]);
                cout << "Bahan: "; getline(cin, bahan[editIndex]);
                cout << "Furniture berhasil diperbarui!\n";
                break;
            case 4:
                cout << "===============================================================================" << endl;
                cout << "                                MENU FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "-------------------------------------------------------------------------------\n"; 
                cout << "| No | Nama             | Harga (Rp) | Stok | Kategori  | Bahan     |\n";
                cout << "-------------------------------------------------------------------------------\n";
                for (int i = 0; i < jumlahFurniture; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(15) << furniture[i][0] << " | "
                        << setw(10) << furniture[i][1] << " | " << setw(4) << furniture[i][2] << " | "
                        << setw(9) << kategori[i] << " | " << setw(9) << bahan[i] << " |\n";
                }
                cout << "-------------------------------------------------------------------------------\n";
                cout << "===============================================================================" << endl;
                cout << "                               MENU HAPUS FURNITURE" << endl;
                cout << "===============================================================================" << endl;
                cout << "Pilih nomor furniture yang ingin dihapus: ";
                int hapusIndex;
                cin >> hapusIndex;
                hapusIndex--;
                if (hapusIndex < 0 || hapusIndex >= jumlahFurniture) {
                    cout << "Nomor tidak valid!\n";
                    break;
                }
                for (int i = hapusIndex; i < jumlahFurniture - 1; i++) {
                    for (int j = 0; j < 3; j++) {
                        furniture[i][j] = furniture[i + 1][j];
                    }
                    kategori[i] = kategori[i + 1];
                    bahan[i] = bahan[i + 1];
                }
                jumlahFurniture--;
                cout << "Furniture berhasil dihapus!\n";
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
