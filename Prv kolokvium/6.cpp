/*Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++

*/

#include<iostream>
#include <cstring>
using namespace std;
typedef struct voz
{
    char rel[50];
    float km;
    int br_pat;
}Voz;
typedef struct ZeleznickaStanica
{
    char grad[20];
    int vozovi;
    Voz a[100];
}ZeleznickaStanica;
void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
{
    int minp=0,min=9999, pozicija;
    for(int i=0;i<n;i++)
    {
    if(strcmp(zs[i].grad,grad)==0)
    {
        pozicija=i;
        min=zs[pozicija].a[0].km;
        for(int j=0;j<zs[i].vozovi;j++)
        {
            if (zs[pozicija].a[j].km<=min)
            {
            min=zs[pozicija].a[j].km;
            minp=j;
            }

        }
    cout<<"Najkratka relacija: "<<zs[pozicija].a[minp].rel<<" "<<"("<<zs[pozicija].a[minp].km<<" km)"<<endl;
    }
}
}
int main(){

    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
      cin>>zStanica[i].grad;
      cin>>zStanica[i].vozovi;
      for(int j=0;j<zStanica[i].vozovi;j++){
      cin>>zStanica[i].a[j].rel>>zStanica[i].a[j].km>>zStanica[i].a[j].br_pat;
      }
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
    }

    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
