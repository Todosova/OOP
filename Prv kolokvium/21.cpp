/*
Да се креира структура Tanc во која се чуваат податоци за името на танцот и земја на потекло (низи од 15 знаци) .

Потоа да се креирa структура Tancer во која се чуваат податоци за име и презиме (низи од максимум 20 знаци), низа од 5 танци
(структура Tanc) кои дадениот танчер може да ги игра. Дополнително, за оваа структура да се обезбеди функција со потпис :

void tancuvanje(Tancer *t, int n, char *zemja)

што ќе ги испечати во посебен ред името и презимето на танчерите што знаат да играат барем по еден танц од земјата која е
проследена како аргумент на функцијата, како и името на танцот во формат: Име Презиме, Име на танц
*/

#include<iostream>
#include<cstring>
using namespace std;
struct Tanc
{
    char ime[15];
    char zemja[15];
};
struct Tancer
{
  char ime[20];
  char prezime[20];
  Tanc niza[5];
};
void tancuvanje (Tancer *tanceri, int n, char *zemja)
  {
      int i,j;
       for(i = 0; i < n; i++){
           for(j = 0; j < 3; j++){
               if(strcmp(zemja,tanceri[i].niza[j].zemja)==0)
               {
                   printf("%s %s, %s\n", tanceri[i].ime, tanceri[i].prezime, tanceri[i].niza[j].ime);

               break;
               }
           }
       }
  }


int main()
{
    int i, j, n;
    char zemja[15];
	Tancer tanceri[5];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tanceri[i].ime;
        cin >> tanceri[i].prezime;
        for(j = 0; j < 3; j++){
        	cin >> tanceri[i].niza[j].ime;
            cin >> tanceri[i].niza[j].zemja;
        }
    }
    cin >> zemja;
    tancuvanje(tanceri, n, zemja);
	return 0;
}
