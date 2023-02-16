#include "kolejka.h"
#include <stdio.h>
#include <stdlib.h>

static void kopiuj_do_wezla(Node* nwsk, Entry e);

void inicjalizacja(Kolejka* kwsk)
{	
	kwsk->head = NULL;
	kwsk->tail = NULL;
	kwsk->cnt = 0;
}

bool czy_pelna(const Kolejka* kwsk)
{	if(ile_elementow_kolejka(kwsk) == SIZE_KOLEJKA)
		return true;

	return false;
}

bool czy_pusta(const Kolejka* kwsk)
{
//-----czy head jest null- jeœli tak to kolejka jest pusta----------
	if (kwsk->head == NULL) return true;
	return false; 
}

int ile_elementow_kolejka(const Kolejka* kwsk)
{
	return kwsk->cnt;
}

bool dodaj(Kolejka* kwsk, Entry en)
{
	Node* nwsk;

	//----sprawdzam czy kolejka nie jest pelna-----
	if (czy_pelna(kwsk)) return false;

	//---- utworzenie nowego wezla - malloc-----
	nwsk = (Node*)malloc(sizeof(Node));
	if (nwsk == NULL) { puts("Cos poszlo nie tak"); exit(1); }

	//---skopiowanie pozycji do wezla - kopiuj do wezla ----
	kopiuj_do_wezla(nwsk, en);
	

	// sprawdzanie czy jest pusta
	if (czy_pusta(kwsk)) {

		//jezeli jest pusta to ustawiam head na nowy wskaznik z node
		kwsk->head = nwsk;
	}
	else
	{
	// jezeli nie byla pusta to dodajemy za koncem kolejny element czyli nwsk
		kwsk->tail->next = nwsk;
	}
//Przypisanie wskaŸnikowi tail bie¿¹cego ostatniego wêz³a
	kwsk->tail = nwsk;

//Inkrementacja licznika pozycji
	(kwsk->cnt)++;

//oznaczenie ze nie ma nic za nim 
	nwsk->next = NULL;

	return true; //wszystko sie udalo, wszyscy sa zadowoleni, na swiecie nie ma wojen, glodu i smutku
}

bool usun(Kolejka* kwsk, int czy_koniec)
{
// Jezeli kolejka jest pusta to nie ma co usuwac
	if (czy_pusta(kwsk)) 
		 return false;

//wyswietlanie kogo usuwamy	
	if(czy_koniec != 1)
		wyswietl_info(kwsk);

// zapamietujemy jaki jest kolejny element po head
	Kolejka pom;
	pom.head = kwsk->head->next;

// zwalniamy pamiec z pierwszej pozycji
	free(kwsk->head);
// zmniejszamy licznik bo usunelismy jedna pozycje
	kwsk->cnt--;
// ustawienie nowego poczatku, glowy
	kwsk->head = pom.head; 
// Sprawdzamy i wyswietlamy kto jest nastepny
// jezeli usuwany element byl ostatnim to nie ma kogo wyswietlic
	
	if (czy_pusta(kwsk))
	{
		kwsk->tail = NULL;
		if (czy_koniec != 1)
		puts("Usunieta pozycja byla ostatnia");
	}
	else if(czy_koniec != 1)
		wyswietl_info_nast(kwsk);
	
	return true; //usuwanie przebieglo poprawnie, jupi
}

static void kopiuj_do_wezla(Node* nwsk, Entry e)
{
	nwsk->entry = e; 
}

int menu(int rodzaj)
{
	if(rodzaj) printf("Witaj w zdalnej pracy rejestratora/ki\n\n");

	if (rodzaj) puts("Aby dodac nowego pacjeta wybierz 1");
	else {
		printf("\n");
		puts("Aby dodac kolejnego pacjeta wybierz 1");
	}
	puts("Aby usunac pierwszego w kolejce pacjeta wybierz 2");
	puts("Aby zakonczyc prace wybierz 3");
	
	int wybor;
	scanf_s("%d", &wybor);
	return wybor;
}

void stdin_clear()
{
	int ch;
	while ((ch = getchar()) != '\n') {}
}

void wyswietl_info(const Kolejka* kwsk)
{
	printf("\n");
	puts("Usuwasz pacjeta:");
	printf("Nazwisko: %s\n", kwsk->head->entry.nazwisko);
	printf("Wiek: %d\n", kwsk->head->entry.wiek);
}

void wyswietl_info_nast(const Kolejka* kwsk)
{
	printf("\n");
	puts("Nastepny/a w kolejce jest:");
	printf("Nazwisko: %s\n", kwsk->head->entry.nazwisko);
	printf("Wiek: %d\n", kwsk->head->entry.wiek);
}

void ktory_w_kolejce(const Kolejka* kwsk)
{
	printf("Wpisany pacjent jest %d w kolejce\n", kwsk->cnt);
}

void zwalnianie_pamieci(Kolejka* kwsk)
{	
	while (usun(kwsk, 1))
		;
}
