/*
Во програмскиот јазик C да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)

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
#include<stdio.h>
typedef struct Laptop
{
    char marka[100];
    float golemina_inci;
    int touch;
    int cena;
} Laptop;
typedef struct ITStore
{
    char ime[100];
    char lokacija[100];
    Laptop dostapni[100];
    int br;
} ITStore;
void print (ITStore *s,int n)
{
    int i,j;
    for(i=0;i<n;i++){
   printf("%s %s\n",s[i].ime,s[i].lokacija);
    for(j=0;j<s[i].br;j++)
    {
        printf("%s %g %d\n",s[i].dostapni[j].marka, s[i].dostapni[j].golemina_inci, s[i].dostapni[j].cena);
    }
    }
}

void najeftina_ponuda(ITStore *s, int n)
{
  int i,j,pozicija=0,najeftin=99999999,najeftinp=0;
  for(i=0;i<n;i++)
  {
      for(j=0;j<s[i].br;j++){
      if(s[i].dostapni[j].touch==1)
      {

          if(s[i].dostapni[j].cena<najeftin)
          {
          najeftin=s[pozicija].dostapni[j].cena;
          pozicija=i;
          najeftinp=j;

          }
      }
      }
  }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s \nNajniskata cena iznesuva: %d\n",s[pozicija].ime,s[pozicija].lokacija, s[pozicija].dostapni[najeftinp].cena);

}
int main() {
    ITStore s[100];
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%s ", &s[i].ime);
     scanf("%s",&s[i].lokacija);
    scanf("%d",&s[i].br);
        for(j=0;j<s[i].br;j++)
            {
        scanf("%s",&s[i].dostapni[j].marka);
        scanf("%f",&s[i].dostapni[j].golemina_inci);
        scanf("%d",&s[i].dostapni[j].touch);
        scanf("%d",&s[i].dostapni[j].cena);
            }
    }
        print (s,n);
    najeftina_ponuda(s, n);


    return 0;
}
