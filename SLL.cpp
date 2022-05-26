//
// Created by Ariq Heritsa on 17/05/22.
//

#include "SLL.h"

// 1305213031 • Ariq Heritsa Maalik
void create_list(List &L) {
  first(L) = NIL;
}

// 1305213031 • Ariq Heritsa Maalik
void insert_last(List &L, address P) {
  if (first(L) == NIL) {
    first(L) = P;
  } else {
    address addressBerjalan = first(L);
    while (next(addressBerjalan) != NIL) {
      addressBerjalan = next(addressBerjalan);
    }
    next(addressBerjalan) = P;
  }
}

// 1305213031 • Ariq Heritsa Maalik
void delete_first(List &L, address &P) {
  P = first(L);
  if (next(first(L)) == NIL) {
    first(L) = NIL;
  } else {
    first(L) = next(first(L));
  }
  next(P) = NIL;
}


// 1305213031 • Ariq Heritsa Maalik
void delete_after(List &L, address Prec, address &P) {
  P = next(Prec);
  next(Prec) = next(P);
  next(P) = NIL;
}

// 1305213031 • Ariq Heritsa Maalik
void delete_last(List &L, address &P) {
  address q = first(L);
  while (next(next(q)) != NIL) {
    q = next(q);
  }
  P = next(q);
  next(q) = NIL;
}

// 1305213031 • Ariq Heritsa Maalik
void new_element(infotype peg, address &P) {
  P = new elmtPeg;

  info(P) = peg;
  next(P) = NIL;
}

// 1305213031 • Ariq Heritsa Maalik
void add_N_data(List &L) {
  int N;
  infotype pegawai;
  address P;

  cout << "Masukkan jumlah pegawai: ";
  cin >> N;

  for (int i = 0; i < N; i++) {
    cout << "Masukkan nama: ";
    cin >> pegawai.nama;

    cout << "Masukkan NIP : ";
    cin >> pegawai.NIP;

    cout << "Masukkan gaji: ";
    cin >> pegawai.gaji;

    cout << endl;

    new_element(pegawai, P);
    insert_last(L, P);
  }
}

// 1305213031 • Ariq Heritsa Maalik
void show_all_data(List &L) {
  if (first(L) == NIL) {
    cout << "List kosong!" << endl;
  } else {
    address P = first(L);

    while (P != NIL) {
      cout << "Nama: " << info(P).nama << endl;
      cout << "NIP : " << info(P).NIP << endl;
      cout << "Gaji: Rp" << info(P).gaji << endl;
      cout << endl;

      P = next(P);
    }
  }
}

// 1305213031 • Ariq Heritsa Maalik
address search_by_NIP(List L, string NIP) {
  address P = first(L);

  while (P != NIL && info(P).NIP != NIP) {
    P = next(P);
  }

  if (P == NIL) {
    cout << "Pegawai dengan NIP tersebut tidak ditemukan!" << endl;
    cout << endl;
  }

  return P;
}

// 1305213031 • Ariq Heritsa Maalik
void delete_data(List &L, string NIP) {
  address P = search_by_NIP(L, NIP);
  address Q;

  if (P == NIL) {
    return;
  }

  if (first(L) == P) {
    delete_first(L, P);
  } else if (next(P) == NIL) {
    delete_last(L, P);
  } else {
    Q = first(L);

    while (info(next(Q)).NIP != NIP) {
      Q = next(Q);
    }

    delete_after(L, Q, P);
  }

  cout << "Pegawai berhasil dihapus!" << endl;
}

// 1305213031 • Ariq Heritsa Maalik
int jumlah_pegawai(List L) {
  address P = first(L);
  int jumlah = 0;

  while (P != NIL) {
    jumlah += 1;
    P = next(P);
  }

  return jumlah;
}

// 1305213031 • Ariq Heritsa Maalik
int total_salary(List L) {
  address P = first(L);
  int total_gaji = 0;

  while (P != NIL) {
    total_gaji += info(P).gaji;
    P = next(P);
  }

  return total_gaji;
}

// 1305213031 • Ariq Heritsa Maalik
address max_gaji(List L) {
  address P = first(L);
  address PMax = first(L);
  int max = info(P).gaji;

  while (P != NIL) {
    if (info(P).gaji > max) {
      max = info(P).gaji;
      PMax = P;
    }

    P = next(P);
  }

  return PMax;
}
