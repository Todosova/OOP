/*
Во програмскиот јазик C да се креира структура Vozenje за опишување на адреналински возења во забавен парк. Структурата треба да содржи: (5 поени)

Име на возењето ( низа од 100 знаци)
Времетраење во минути (цел број)
Цена (децимален број)
Дали има студентски попуст (1-да, 0-не)
Да се креира структура ZabavenPark, што содржи: (10 поени)

Име на забавниот парк (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од адреналински возења во паркот (низа од максимум 100 елементи од структурата Vozenje)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите возења во забавниот парк во формат: (10 поени)

[Ime na parkot] [Lokacija]
[Ime1] [Vremetraenje1] [Cena1]
[Ime2] [Vremetraenje2] [Cena2]
[Ime3] [Vremetraenje3] [Cena3]
...
Да се креира функција najdobar_park, што прима низа од променливи од типот ZabavenPark и го печати името и локацијата на паркот кој е најефтин за посета од страна на студенти. Најефтин парк е оној што содржи најголем број возења со студентски попуст. Ако повеќе паркови ги делат овие карактеристики, да се испечати паркот со најголемото времетраење од сите возења.* (20 поени)*

Да се дополни функцијата main (5 поени).
*/

#include<stdio.h>
typedef struct Vozenje
{
    char ime_vozenje[100];
    int min;
    float cena;
    int popust;
} Vozenje;
typedef struct ZabavenPark
{
    char ime_zab_park[100];
    char lokacija[100];
    Vozenje vozenja[100];
    int n;
}ZabavenPark;
void print(ZabavenPark *a,int n){
    int i,j;
    for(i=0;i<n;i++)
    {
    printf("%s %s\n",a[i].ime_zab_park,a[i].lokacija);
    for(j=0;j<a[i].n;j++)
        {
    printf("%s %d %.2f\n", a[i].vozenja[j].ime_vozenje, a[i].vozenja[j].min, a[i].vozenja[j].cena);
        }
    }
}
void najdobar_park(ZabavenPark *a,int n)
{
    int i,j,brojach=0,suma=0,maxvozenja=-99999,pozicija,maxsuma;
    for(i=0;i<n;i++)
    {
        brojach=0;
        suma=0;
        for(j=0;j<a[i].n;j++)
        {
            if(a[i].vozenja[j].popust==1)
            {
            brojach++;

            }
            suma+=a[i].vozenja[j].min;
        }
        if(brojach>maxvozenja)
        {
            maxvozenja=brojach;
            pozicija=i;
            maxsuma=suma;
        }
        else if(brojach==maxvozenja && suma>maxsuma)
        {
            pozicija=i;
            maxsuma=suma;
        }
    }
    printf("Najdobar park: %s %s", a[pozicija].ime_zab_park,a[pozicija].lokacija);
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	ZabavenPark ff[100];
    for (i = 0; i < n; i++)
    {
        scanf("%s",&ff[i].ime_zab_park);
        scanf("%s",&ff[i].lokacija);
        scanf("%d",&ff[i].n);
		for (j = 0; j < ff[i].n; j++)
		{
		    scanf("%s",&ff[i].vozenja[j].ime_vozenje);
		    scanf("%d",&ff[i].vozenja[j].min);
		    scanf("%f",&ff[i].vozenja[j].cena);
		    scanf("%d",&ff[i].vozenja[j].popust);
		}
    }
    print(ff,n);
    najdobar_park(ff,n);
	return 0;
}

