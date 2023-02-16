#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nagłówek.h"

int main()
{
	Kolejka poczekalnia;
	inicjalizacja(&poczekalnia);

	int i = 1; //do ladnego wyswietlania menu 
	while (1)
	{
		switch (menu(i))
		{
		case 1: //dodawanie pacjeta do kolejki

			Entry pacjent;

			printf("Podaj nazwisko pacjeta\n");
			stdin_clear();

			gets_s(pacjent.nazwisko);
			while (pacjent.nazwisko[0] == NULL)
			{
				puts("Podane nazwisko jest puste, wpisz je jeszcze raz.");
				gets_s(pacjent.nazwisko);
			}

			puts("Podaj jego wiek");
			scanf_s("%d", &pacjent.wiek);

			if (dodaj(&poczekalnia, pacjent)) ktory_w_kolejce(&poczekalnia);
			else puts("Nie mozna dodac kolejnej osoby, kolejka jest pelna");
			
			break;

		case 2: //usuwanie pierwszego z kolejki

			if (usun(&poczekalnia, 0));
			else puts("Nie mozna usunac pacjeta, kolejka jest pusta");

			break;

		case 3: //koniec programu

			zwalnianie_pamieci(&poczekalnia);
			puts("Dziekuje za dzisiejsza prace, do zobaczenia");
			exit(0);

			break;


		default:
			puts("Wybrana opcja nie istnieje");
			break;
		}
		i = 0;
	}
	
}
