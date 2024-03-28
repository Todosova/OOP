/*Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број на
корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа (низи од 20 знаци),
низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)
која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои може да се опслужуваат
во еден момент вкупно на сите ски лифтови во центарот). Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови.
Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот. Кога се пресметува капацитет на еден ски центар во
предвид се земаат само ски лифтовите кои се поставени дека се во функција.

*/

#include<stdio.h>
#include<string.h>
typedef struct SkiLift
{
    char ime_skilift[20];
    int br_korisnici;
    int funkcionalnost;
}SkiLift;
typedef struct SkiCenter
{
    char ime_skicentar[20];
    char drzava[20];
    SkiLift niza[20];
    int brlift;
} SkiCenter;
int korisnik (SkiCenter sc)
{
    int i,tmp=0;
       for(i=0;i<sc.brlift;i++)
    {
        if(sc.niza[i].funkcionalnost==1)
        {
           tmp+=sc.niza[i].br_korisnici;
        }

    }
    return tmp;
}
void najgolemKapacitet(SkiCenter *sc, int n)
{
    int i,j,pozicija,vkupno,max;
    pozicija=0;
    max=0;
    for(i=0;i<n;i++)
    {
        vkupno=korisnik(sc[i]);
         if((vkupno>max) || (vkupno==max && sc[i].brlift> sc[pozicija].brlift))
         {
             max=vkupno;
             pozicija=i;

         }
    }

    printf("%s\n%s\n%d", sc[pozicija].ime_skicentar, sc[pozicija].drzava, max);

}
int main()
{
    int n,i,j;
    SkiCenter sc[20];
    scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
	    scanf("%s", &sc[i].ime_skicentar);
	     scanf("%s", &sc[i].drzava);
	      scanf("%d", &sc[i].brlift);

        for (j = 0; j <sc[i].brlift ; j++)
        {
             scanf("%s", &sc[i].niza[j].ime_skilift);
              scanf("%d", &sc[i].niza[j].br_korisnici);
               scanf("%d", &sc[i].niza[j].funkcionalnost);
        }
    }
    najgolemKapacitet(sc, n);
	return 0;
}
