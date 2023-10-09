#include <cstdlib>
#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

typedef struct node Node;

struct node
{
	char nrtal;
	char kolor;
	char figura;
	int wartosc;
	int prior;
	Node *next;
	Node *prev;
};

class Lista
{

public:

	Node *head;
	Node *tail;
	Node *current;

public:

	Lista(Node*h = NULL, Node*t = NULL, Node*c = NULL)
	{
		head = h;
		tail = t;
		current = c;
	}



	Node *createzero()
	{
		Node *nev;
		nev = new (Node);
		nev->figura = '0';
		nev->kolor = '0';
		nev->nrtal = '0';
		nev->wartosc = 0;
		nev->prior = 0;
		nev->next = NULL;
		nev->prev = NULL;

		return nev;
	}



	void addlastzero()
	{
		Node *tmp = createzero();

		if (head == NULL)
			head = tmp;
		else {
			Node *pom = head;
			while (pom->next != NULL)
				pom = pom->next;
			pom->next = tmp;
			tmp->prev = pom;
		}

		tail = tmp;
	}



	void deletecurrent()
	{
		if (current == head) {
			head = (current->next);
			(current->next)->prev = NULL;
		}
		else {
			(current->next)->prev = (current->prev);
			(current->prev)->next = (current->next);
		}

		delete current;
	}



	void deletehead()
	{
		Node *pom = head;

		head = (pom->next);
		(pom->next)->prev = NULL;

		delete pom;
	}



	void changefirst()
	{

		if (current == tail)
		{
			(current->prev)->next = NULL;
			tail = (current->prev);

			(current->next) = head;
			(current->prev) = NULL;

			(head->prev) = current;
			head = current;
		}

		else
		{
			(current->next)->prev = (current->prev);
			(current->prev)->next = (current->next);

			(current->next) = head;
			(current->prev) = NULL;

			(head->prev) = current;
			head = current;
		}
	}



	void moveleft()
	{
		current = current->prev;
	}



	void moveright()
	{
		current = current->next;
	}


	void deleteall()
	{
		if (head == NULL)
			cout << "empty!";
		else
		{
			Node *pom = head;
			Node *tmp;
			while (pom->next != NULL)
			{
				tmp = pom;
				pom = (pom->next);
				delete tmp;
			}
			delete pom;
			head = NULL;
			tail = NULL;
			current = NULL;
		}
	}



	void showall()
	{
		if (head == NULL)
			cout << "empty!";
		else
		{
			Node *pom = head;
			while (pom->next != NULL)
			{
				cout << pom->nrtal;
				cout << pom->kolor;
				if (pom->figura == '1') cout << "10";
				else cout << pom->figura;
				cout << " ";
				pom = pom->next;
			}
			cout << pom->nrtal;
			cout << pom->kolor;
			if (pom->figura == '1') cout << "10";
			else cout << pom->figura;
		}
	}


	void showfirst()
	{
		if (head == NULL)
			cout << "empty!";
		else
		{
			cout << head->nrtal;
			cout << head->kolor;
			if (head->figura == '1') cout << "10";
			else cout << head->figura;
			cout << " ";
			cout << "???";
		}
	}



	int countall()
	{
		int i;
		if (head == NULL)
			i = 0;
		else
		{
			Node *pom = head;
			i = 1;
			while (pom->next != NULL)
			{
				i++;
				pom = pom->next;
			}
		}
		return i;
	}



	void bubblesort()
	{
		int size = countall();

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				Node *pom1 = head;
				int k = j;
				while (k > 0)
				{
					pom1 = pom1->next;
					k--;
				}
				Node *pom2 = pom1->next;

				if ((pom1->prior) > (pom2->prior))
				{
					char nrtalpom = pom1->nrtal;
					char kolorpom = pom1->kolor;
					char figurapom = pom1->figura;
					int wartoscpom = pom1->wartosc;
					int priorpom = pom1->prior;

					pom1->nrtal = pom2->nrtal;
					pom1->kolor = pom2->kolor;
					pom1->figura = pom2->figura;
					pom1->wartosc = pom2->wartosc;
					pom1->prior = pom2->prior;

					pom2->nrtal = nrtalpom;
					pom2->kolor = kolorpom;
					pom2->figura = figurapom;
					pom2->wartosc = wartoscpom;
					pom2->prior = priorpom;
				}
			}
		}
	}



	~Lista()
	{
		deleteall();
	}

};



class Talia : public Lista
{
public:

	void wczytaj_karte(char x, char y, char z, int w, int p)
	{
		addlastzero();
		tail->nrtal = x;
		tail->kolor = y;
		tail->figura = z;
		tail->wartosc = w;
		tail->prior = p;
	}

	void wczytaj_talie()
	{
		char tab1[2] = { '1','2' };
		char tab2[4] = { 'W','Z','S','D' };
		char tab3[13] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
		int tab4[13] = { 2,3,4,5,6,7,8,9,10,11,11,11,11 };
		int tab5[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

		int i, j, k;
		for (i = 0, j = 0, k = 0; i < 104; i++)
		{
			if ((i % 13) == 0 && i != 0) j++;
			if (i == 51) k++;
			wczytaj_karte(tab1[k], tab2[(j%4)], tab3[(i % 13)], tab4[(i % 13)], tab5[(i % 13)]);
		}
	}

	void tasowanie()
	{
		srand(time(NULL));
		current = head;
		int licznik;
		for (licznik = 0; licznik < 208; licznik++)
		{
			int n = (rand() % 104);
			if (n == 0);
			else
			{
				while (n > 0)
				{
					moveright();
					n--;
				}
				changefirst();
			}
		}
	}
};




class Gracz
{
public:

	Talia *stos;
	Lista reka;
	int punkty;
	int akcja;

	Gracz(Talia *s, int p = 0, int a = 0)
	{
		stos = s;
		punkty = p;
		akcja = a;
	}


	void dobierz_karte()
	{
		reka.addlastzero();
		reka.tail->nrtal = (*stos).head->nrtal;
		reka.tail->kolor = (*stos).head->kolor;
		reka.tail->figura = (*stos).head->figura;
		reka.tail->wartosc = (*stos).head->wartosc;
		reka.tail->prior = (*stos).head->prior;
		(*stos).deletehead();
	}

	void dobierz_losowo()
	{
		srand(time(NULL));
		int decyzja = (rand() % 2);
		licz_punkty();
		while (decyzja == 1 && punkty < 21)
		{
			reka.addlastzero();
			reka.tail->nrtal = (*stos).head->nrtal;
			reka.tail->kolor = (*stos).head->kolor;
			reka.tail->figura = (*stos).head->figura;
			reka.tail->wartosc = (*stos).head->wartosc;
			reka.tail->prior = (*stos).head->prior;
			(*stos).deletehead();

			decyzja = (rand() % 2);
			licz_punkty();
		}
	}

	void losuj_dwie()
	{
		dobierz_karte();
		dobierz_karte();
	}

	void sortuj_reke()
	{
		reka.bubblesort();
	}

	void pokaz_reke()
	{
		reka.showall();
	}

	void pokaz_pierwsza()
	{
		reka.showfirst();
	}

	void zeruj_reke()
	{
		reka.deleteall();
	}

	void licz_punkty()
	{
		int asy = 0;
		punkty = 0;

		reka.current = reka.head;
		while (reka.current != NULL)
		{
			punkty = punkty + (reka.current->wartosc);
			if (reka.current->figura == 'A') asy++;
			reka.moveright();
		}

		if (asy == 0);
		else if (punkty <= 21);
		else
		{
			while (asy > 0 && punkty > 21)
			{
				punkty = punkty - 10;
				asy--;
			}
		}

		//cout << punkty;
	}

	void co_dalej()
	{
		cout << "What's next?";
	}

};

int sterowanie(Gracz *g, Gracz *k, Talia *t);

int menu(Gracz *g, Gracz *k, int op, Talia *t)
{
	system("cls");

	cout << "BLACKJACK" << endl << endl;

	cout << "your cards:\t"; (*g).pokaz_reke(); (*g).licz_punkty();
	cout << endl << "your points:\t" << (*g).punkty << endl;

	if ((*g).punkty == 0)
	{
		cout << "Card dealer:\t"; (*k).pokaz_pierwsza();
		cout << endl << "Dealer points:\t" << "???" << endl << endl;

		cout << "1 play again" << endl;
		cout << "0 game over" << endl;
		cout << "What you want to do ?" << endl << endl;
	}
	else if ((*g).punkty > 0 && (*g).punkty < 21 && op != 3)
	{
		cout << "Card dealer:\t"; (*k).pokaz_pierwsza();
		cout << endl << "Dealer points:\t" << "???" << endl << endl;

		cout << "1 play again" << endl;
		cout << "2 draw a card" << endl;
		cout << "3 wait" << endl;
		cout << "0 game over" << endl;
		cout << "What you want to do ?" << endl << endl;
	}
	else if ((*g).punkty > 21)
	{
		cout << "Card dealer:\t"; (*k).pokaz_pierwsza();
		cout << endl << "Dealer points:\t" << "???" << endl << endl;

		(*g).punkty = 0;
		cout << "1 play again" << endl;
		cout << "0 game over" << endl;
		cout << "YOU LOST!!! What you want to do ?" << endl << endl;
	}
	else if ((*g).punkty == 21 || ((*g).punkty > 0 && (*g).punkty < 21 && op == 3))
	{
		cout << "Card dealer:\t"; (*k).pokaz_reke(); (*k).licz_punkty();
		cout << endl << "Dealer points:\t" << (*k).punkty << endl << endl;

		if ((*k).punkty > 21)
		{
			cout << "1 play again" << endl;
			cout << "0 game over" << endl;
			cout << "YOU WON!!! What you want to do ?" << endl << endl;
		}
		else if ((*g).punkty > (*k).punkty)
		{
			cout << "1 play again" << endl;
			cout << "0 game over" << endl;
			cout << "YOU WON!!! What you want to do ?" << endl << endl;
		}
		else if ((*g).punkty == (*k).punkty)
		{
			cout << "1 play again" << endl;
			cout << "0 game over" << endl;
			cout << "DRAW!!! What you want to do ?" << endl << endl;
		}
		else if ((*g).punkty < (*k).punkty)
		{
			cout << "1 play again" << endl;
			cout << "0 game over" << endl;
			cout << "YOU LOST!!! What you want to do ?" << endl << endl;
		}
	}
	op = sterowanie(g, k, t);
	return op;
}

int sterowanie(Gracz *g, Gracz *k, Talia *t)
{
	int op = 0;
	cin >> op;
	if (op == 0);
	else if (op == 1)
	{
		(*t).wczytaj_talie();
		(*t).tasowanie();

		(*g).punkty == 0;
		(*g).zeruj_reke();
		(*g).losuj_dwie();
		(*g).sortuj_reke();

		(*k).punkty == 0;
		(*k).zeruj_reke();
		(*k).losuj_dwie();
	}
	else if (op == 2)
	{
		(*g).dobierz_karte();
		(*g).sortuj_reke();
	}
	else if (op == 3)
	{
		(*k).dobierz_losowo();
	}
	return op;
}


int main()
{
	Talia t;
	t.wczytaj_talie();
	t.tasowanie();

	Gracz g(&t);
	Gracz k(&t);

	int op = 100;
	while (op != 0)
	{
		op = menu(&g, &k, op, &t);
	}
	system("pause");
	return 0;
}




