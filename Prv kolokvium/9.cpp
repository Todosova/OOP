/*
Во програмскиот јазик C++ да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)

Фирма која го произведува ( низа од 100 знаци)
Големина на монитор во инчи (реален број)
Дали е со touch или не (булова променлива)
Цена (цел број)
Да се креира структура ITStore, што содржи: (5 поени)

Име на продавницата (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од достапни лаптопи (низа од максимум 100 елементи од структурата Laptop)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите лаптопи во една продавница во формат: (10 поени)

[Ime na prodavnicata] [Lokacija]
[Marka1] [dim_monitor1] [Cena1]
[Marka2] [dim_monitor2] [Cena2]
[Marka3] [dim_monitor3] [Cena3]
...
Да се креира функција najeftina_ponuda, што прима низа од променливи од типот ITStore и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената.* (15 поени)*

Да се дополни функцијата main (10 поени).

Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери, па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда.*/
#include<iostream>
using namespace std;

struct Laptop {
    char ime_firma[100];
    float inchi;
    bool touch;
    int cena;
};
struct ITStore {
    char ime_prodavnica[100];
    char lokacija[100];
    Laptop niza[100];
    int n;
};
void print (ITStore *s,int n)
{
     int i,j;
    for(i=0;i<n;i++){
   cout<<s[i].ime_prodavnica<<" "<<s[i].lokacija<<endl;
    for(j=0;j<s[i].n;j++)
    {
        cout<<s[i].niza[j].ime_firma<<" "<<s[i].niza[j].inchi<< " "<<s[i].niza[j].cena<<endl;
    }
    }
}
void najeftina_ponuda(ITStore *s, int n)
{
  int i,j,pozicija=0,najeftin=99999999,najeftinp=0;
  for(i=0;i<n;i++)
  {
      for(j=0;j<s[i].n;j++){
      if(s[i].niza[j].touch==1)
      {
          if(s[i].niza[j].cena<najeftin)
          {
          najeftin=s[pozicija].niza[j].cena;
          pozicija=i;
          najeftinp=j;

          }
      }
      }
  }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl;
    cout<<s[pozicija].ime_prodavnica<<" "<<s[pozicija].lokacija<<endl;
   cout<<"Najniskata cena iznesuva: "<<s[pozicija].niza[najeftinp].cena<<endl;

}
int main() {
     ITStore s[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> s[i].ime_prodavnica;
        cin >> s[i].lokacija;
        cin >> s[i].n;
            for(int j = 0; j < s[i].n; j++){
        		cin >> s[i].niza[j].ime_firma;
            	cin >> s[i].niza[j].inchi;
            	cin >> s[i].niza[j].touch;
            	cin >> s[i].niza[j].cena;
        }

    }
    print (s,n);
    najeftina_ponuda(s, n);

    return 0;
}

