/*Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра. За играчот се чуваат информации за корисничкото име на играчот (низа од 15 знаци), број на ниво до кој играчот е стигнат (цел број) и број на освоени поени (цел број) (10 поени).

Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за името на играта (низа од 20 знаци), низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи. (10 поени)

Треба да се направи функција со потпис (15 поени)

void najdobarIgrac(KompjuterskaIgra *lista, int n)
Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност (ја играат наjголем број на играчи). Најдобар играч е играчот кој има најголем број на освоени поени. Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.

Печатењето е во форматот: "Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY". (XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)

(Забелешка: секогаш ќе има точно еден најдобар играч)

Функционалност на задачата и дополнување на main функцијата (10 поени)

Забелешка: Задачата да се реши во програмскиот јазик C+

*/

#include<iostream>
using namespace std;
struct Igrac
{
    char ime[15];
    int nivo;
    float poeni;
};
struct KompjuterskaIgra {
    char imeigra[20];
    Igrac igr[30];
    int n;
};
void najdobarIgrac(KompjuterskaIgra *lista, int n)
{
   int i,maxigrachi=0;
   for(i=0;i<n;i++)
   {
       if(lista[i].n>lista[maxigrachi].n)
       {
           maxigrachi=i;
       }
   }

   int maxpozicija=0;
   for(i=0;i<lista[maxigrachi].n;i++)
   {
       if(lista[maxigrachi].igr[i].poeni>lista[maxigrachi].igr[maxpozicija].poeni)
       {
           maxpozicija=i;
       }
       else if(lista[maxigrachi].igr[i].poeni==lista[maxigrachi].igr[maxpozicija].poeni)
       {
           if(lista[maxigrachi].igr[i].nivo==lista[maxigrachi].igr[maxpozicija].nivo)
           maxpozicija=i;
       }
   }
   cout<<"Najdobar igrac e igracot so korisnicko ime ";
    cout<<lista[maxigrachi].igr[maxpozicija].ime;
    cout<<" koj ja igra igrata ";
    cout<<lista[maxigrachi].imeigra;
}
int main() {
    int n,m;
    char ime[20];
    KompjuterskaIgra poleigri[100];
    cin>>n;
    for (int i=0; i<n; i++) {
        KompjuterskaIgra nova;
        cin>>nova.imeigra;
        cin>>nova.n;
        Igrac pole[100];
        for (int j=0; j<nova.n; j++) {
            Igrac nov;
             cin>>nov.ime>>nov.nivo>>nov.poeni;
          nova.igr[j]=nov;
        }
       poleigri[i]=nova;
    }

    najdobarIgrac(poleigri,n);
    return 0;
}
