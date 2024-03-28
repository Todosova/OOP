/*Во програмскиот јазик C да се креира структура Pacient и истата треба да содржи: (5 поени)

Име и презиме на пациентот ( низа од макс. 100 знаци)
Дали е здраствено осигуран (1-да, 0-не)
Број на прегледи во текот на последниот месец (цел број)
Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

Име на докторот (низа од 100 знаци)
Број на пациенти (цел број)
Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
Цена на преглед (децимален број)
Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број;
и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги
прегледувал приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат иста сума,
тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)

Функционалност (5 поени).

*/

#include<stdio.h>
typedef struct Pacient
{
    char ime[100];
    int zdrastveno;
    int pregledi;
}Pacient;
typedef struct MaticenDoktor
{
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
}MaticenDoktor;
void najuspesen_doktor(MaticenDoktor md[],int n)
{
    float zarabotena_suma=0.0,maxsuma=-999999999;
    int brpregledi=0,maxbrpregledi;
   MaticenDoktor maxdoktor;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<md[i].br_pac;j++)
        {
            brpregledi+=md[i].niza[j].pregledi;
            if (md[i].niza[j].zdrastveno==0)
            {
                zarabotena_suma+=md[i].niza[j].pregledi*md[i].cena;
            }
        }
        if(zarabotena_suma>maxsuma)
        {
            maxsuma=zarabotena_suma;
            maxdoktor=md[i];
            maxbrpregledi=brpregledi;
            zarabotena_suma=0;
            brpregledi=0;
        }
        else if(zarabotena_suma==maxsuma)
        {
            if(brpregledi>maxbrpregledi)
            {
                maxdoktor=md[i];
                maxsuma=zarabotena_suma;
                maxbrpregledi=brpregledi;
                brpregledi=0;
                zarabotena_suma=0;
            }
        }
        else{
            zarabotena_suma=0;
            brpregledi=0;
        }
    }
    printf("%s %.2f %d",maxdoktor.ime, maxsuma,maxbrpregledi);
}
int main()
{
	int i, j, n, broj;
	MaticenDoktor md[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", &md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", &md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}
