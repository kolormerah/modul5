#include <iostream>
#include "SLL.h"

using namespace std;

// 1305213031 • Ariq Heritsa Maalik
void show_menu(int &menu_choice) {
  cout << "======MENU======" << endl;
  cout << "1. Tambah data pegawai" << endl;
  cout << "2. Tampilkan data pegawai" << endl;
  cout << "3. Cari data pegawai berdasarkan NIP" << endl;
  cout << "4. Hapus data berdasarkan NIP" << endl;
  cout << "5. Jumlah pegawai saat ini" << endl;
  cout << "6. Rata-Rata penghasilan pegawai" << endl;
  cout << "7. Nama Pegawai dengan gaji tertinggi" << endl;
  cout << "0. Selesai" << endl;

  cout << "Masukkan menu: ";
  cin >> menu_choice;

  cout << endl;
}

// 1305213031 • Ariq Heritsa Maalik
int main() {
  List L;
  string back_to_menu, NIP;
  int menu_choice;
  address P;

  create_list(L);
  show_menu(menu_choice);

  while (menu_choice != 0) {
    switch (menu_choice) {
      case 1:
        // 1. Tambah data pegawai
        add_N_data(L);
        break;
      case 2:
        // 2. Tampilkan data pegawai
        show_all_data(L);
        break;
      case 3:
        // 3. Cari data pegawai berdasarkan NIP
        cout << "Cari NIP: ";
        cin >> NIP;

        P = search_by_NIP(L, NIP);

        if (P != NIL) {
          cout << "Nama: " << info(P).nama << endl;
          cout << "NIP : " << info(P).NIP << endl;
          cout << "Gaji: Rp" << info(P).gaji << endl;
          cout << endl;
        }

        break;
      case 4:
        // 4. Hapus data berdasarkan NIP
        cout << "Masukkan NIP: ";
        cin >> NIP;

        delete_data(L, NIP);
        cout << endl;

        break;
      case 5:
        // 5. Jumlah pegawai saat ini
        cout << "Jumlah pegawai saat ini: " << jumlah_pegawai(L) << endl;
        cout << endl;
        break;
      case 6:
        // 6. Rata-Rata penghasilan pegawai
        cout << "Rata-rata penghasilan pegawai: Rp" << total_salary(L) / jumlah_pegawai(L) << endl;
        cout << endl;
        break;
      case 7:
        // 7. Nama Pegawai dengan gaji tertinggi
        if (first(L) == NIL) {
          cout << "List kosong!" << endl;
        } else {
          P = max_gaji(L);

          cout << "Nama Pegawai dengan gaji tertinggi: " << endl;
          cout << "Nama: " << info(P).nama << endl;
          cout << "NIP : " << info(P).NIP << endl;
          cout << "Gaji: Rp" << info(P).gaji << endl;
        }

        cout << endl;
        break;
      default:
        cout << "Menu tidak tersedia!\n" << endl;
        cout << endl;
        show_menu(menu_choice);
        continue;
    }

    show_menu(menu_choice);
  }

  cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;

  return 0;
}

