//
// Created by Ariq Heritsa on 17/05/22.
//

#ifndef STD_1305213031_MOD5_JURNAL_ARN_SLL_H
#define STD_1305213031_MOD5_JURNAL_ARN_SLL_H

#include <iostream>

using namespace std;

#define NIL NULL
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first

typedef struct pegawai infotype;
typedef struct elmtPeg *address;

struct pegawai {
  string nama, NIP;
  int gaji;
};

struct elmtPeg {
  infotype info;
  address next;
};

struct List {
  address first;
};

void create_list(List &L);

void insert_last(List &L, address P);

void delete_first(List &L, address &P);

void delete_last(List &L, address &P);

void delete_after(List &L, address Prec, address &P);

void new_element(infotype peg, address &P);

void add_N_data(List &L);

void show_all_data(List &L);

address search_by_NIP(List L, string NIP);

void delete_data(List &L, string NIP);

int jumlah_pegawai(List L);

int total_salary(List L);

address max_gaji(List L);

#endif //STD_1305213031_MOD5_JURNAL_ARN_SLL_H
