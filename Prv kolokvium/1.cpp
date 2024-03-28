/*Да се дефинира класата Pesna во која се чуваат информации за (5 поени):

име на песна (динамички алоцирано поле од знаци)
времетраење на песната во минути
тип на песна кој може да биде: поп, рап или рок (енумерација tip)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (10 поени)

Дополнително за оваа класа да се дефинира методот:

pecati() - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на песната со постфикс min. (5 поени)
Да се креира класата CD во која се чуваат информации за (5 поени):

низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna )
број на песни снимени на CD-то
максимално времетраење на песните на CD-то (во минути)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (5 поени)

Дополнително за оваа класа да се дефинираат методите:

dodadiPesna (Pesna p) - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни на CD-то. (10 поени)
pecatiPesniPoTip(tip t) – со кој се печатат информациите за сите песни од тип t (поп, рап или рок). (10 поени)
Комплетна функционалност (5 поени).

*/

#include <iostream>
#include <cstring>
using namespace std;
enum tip{pop,rap,rok};
class Pesna
{
    private:
    char *ime;
    int vremetraenje;
    tip kojtip;
    public:
    Pesna()
    {
        this->ime=new char[0];
        strcpy(this->ime,"");
        this->vremetraenje=0;
        this->kojtip=(tip)0;
    }
    Pesna(char *ime,int vremetraenje,tip kojtip)
    {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->vremetraenje=vremetraenje;
        this->kojtip=kojtip;
    }
     Pesna(const Pesna &p)
    {
        this->ime=new char[strlen(p.ime)+1];
        strcpy(this->ime,p.ime);
        this->vremetraenje=p.vremetraenje;
        this->kojtip=p.kojtip;
    }
    Pesna &operator=(const Pesna &p)
    {
        if(this!=&p)
        {
        this->ime=new char[strlen(p.ime)+1];
        strcpy(this->ime,p.ime);
        this->vremetraenje=p.vremetraenje;
        this->kojtip=p.kojtip;
        }
        return *this;
    }
    ~Pesna()
    {
        delete[]ime;
    }
    void pecati()
    {
      cout<<"\""<<ime<<"\""<<"-"<<vremetraenje<<"min"<<endl;
    }
    friend class CD;
};
class CD
{
  private:
  Pesna niza[10];
  int n;
  int maksVremetraenje;
  public:
  CD(int maksVremetraenje)
  {
    this->n=0;
    this->maksVremetraenje=maksVremetraenje;
  }
   void pecatiPesniPoTip(tip t)
    {
        int i;
        for(i = 0; i < n; i++)
        {
            if(t == niza[i].kojtip)
            {
                niza[i].pecati();
            }
        }
    }
     void dodadiPesna (Pesna p)
    {
        if(n < 10)
        {
            if(maksVremetraenje >= p.vremetraenje)
            {
                this->niza[n++] = p;
                maksVremetraenje -= p.vremetraenje;
            }
        }
        else return;
    }
    Pesna getPesna(int i)
{
    return niza[i];
}
int getBroj()
{
    return n;
}
};
int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

return 0;
}
