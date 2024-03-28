/*
Да се креира структура Proizvod во која се чуваат податоци за кодот напрозиводот (низа од 20 знаци), единична цена на производ (цел број),
бројот на достапни производи кои ги има во еден магацин (цел број) .

Потоа да се креирa структура Narachka во која се чуваат податоци за името лицето кое ја прави нарачката (низи од 15 знаци),
низа од Proizvodi (максимум 10) кои ги има во нарачката, низа од бројот на нарачани производи за секоја производ посебно (максимум10)
и бројот на производи во нарачката .

Треба да се направи функција со потпис

void pecatiFaktura(Narachka n)

која што ќе ги отпечати една фактура за една нарачка (n) .

Во фактурата во првиот ред се печати: Faktura za XXXXX, каде XXXXX е името на лицето кое ја прави нарачката.

Ако сите производи може да се нарачаат печатат нарачаните производи, подредени по азбучен ред според кодот на производот.
Во следните редови, во секој ред посебно се печати кодот на производот, единична цена на производот,
број на нарачани производи и вкупната цена на производот (сите се одделени со едно празно место) .
Исто така бројот на достапни производи од тој производ да се ажурира (да се намали за бројот на нарачани производи од тој производ).
Во последниот ред да се отпечати: Vkupnata suma na fakturata e XXX, каде XXX е вкупната сума за цените за сите нарачани производи.

Ако постои производ кој не може да биде нарачан затоа што во магацинот не се достапни нарачаниот број производи
тогаш не може да се изготви фактура за нарачката. На екранот да се отпечати: Fakturata ne moze da se izgotvi.
*/

#include <stdio.h>
#include <string.h>

typedef struct Proizvod{
    char kod[20];
    int cena;
    int dostapni;
}Proizvod;
typedef struct Narachka
{
    char ime[15];
    Proizvod niza[10];
    char narachanproizvod[10];
    int n;
}Narachka;
void pecatiFaktura(Narachka n)
{
    printf("Faktura za %s\n", n.ime);
    int i;
    for(i=0;i<n.n;i++)

        if(n.narachanproizvod[i]>n.niza[i].dostapni)
        {
            printf("Fakturata ne moze da se izgotvi\n");
            return;
        }

        int j;
        for(i=0;i<n.n;i++)

        for(j=i+1;j<n.n;j++)
        {
            if(strcmp(n.niza[i].kod,n.niza[j].kod)>0)
            {
                Proizvod temp=n.niza[i];
                n.niza[i]=n.niza[j];
                n.niza[j]=temp;
            }
        }

    int z=0;
    for (i=0;i<n.n;i++)
    {
        z+=n.narachanproizvod[i]*n.niza[i].cena;
        printf("%s %d %d %d\n",n.niza[i].kod,n.niza[i].cena,n.narachanproizvod[i],n.narachanproizvod[i]*n.niza[i].cena);
    }
    printf("Vkupnata suma na fakturata e %d\n",z);

}
int main() {
    Narachka narachka;
    scanf("%s%d", &narachka.ime,&narachka.n);
    int i;
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.n; ++i) {
       scanf("%s%d%d", &narachka.niza[i].kod, &narachka.niza[i].cena,&narachka.niza[i].dostapni);
    }
    //за секој производ се внесува колку такви производи се порачани во нарачката
    int j;
    for (j = 0; j < narachka.n; ++j) {
        scanf("%d" , &narachka.narachanproizvod[j]);
    }


  pecatiFaktura(narachka);




    return 0;
}
