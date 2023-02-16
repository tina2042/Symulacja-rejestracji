#pragma once
#define SIZE_CHAR 20
#define SIZE_KOLEJKA 10

//-----------------Struktury-------------------

typedef struct pacjent {
	char nazwisko[SIZE_CHAR];
	int wiek;
}Entry;

typedef struct node {
	Entry entry;
	struct node* next;
}Node;

typedef struct kolejka {
	Node* tail;
	Node* head;
	int cnt; //counter
}Kolejka;

//--------------Prototypy funkcji-----------------------

void inicjalizacja(Kolejka* kwsk);

bool czy_pelna(const Kolejka* kwsk);

bool czy_pusta(const Kolejka* kwsk);

int ile_elementow_kolejka(const Kolejka* kwsk);

bool dodaj(Kolejka* kwsk, Entry en);

bool usun(Kolejka* kwsk, int czy_koniec);

int menu(int rodzaj);

void stdin_clear();

void wyswietl_info(const Kolejka* kwsk);

void wyswietl_info_nast(const Kolejka* kwsk);

void ktory_w_kolejce(const Kolejka* kwsk);

void zwalnianie_pamieci(Kolejka* kwsk);