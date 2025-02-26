/*
Да се дефинира класа Vozac во која се чуваат информации за:

име (низа од максимум 100 знаци)
возраст (цел број)
број на трки (цел број)
дали е ветеран (да/не).
Да се преоптоварат:

операторот << за печатење кој ќе ги печати името, возраст, бројот на трки и дали е ветеран (се печати VETERAN)
операторот == за споредување на два возачи според заработувачката по трка.
Од оваа класа да се изведат две нови класи Avtomobilist и Motociklist.

За автомобилистот дополнително се чува:

цена на автомобилот (децимален број).
За мотоциклистот дополнително се чува:

моќност на мотор (цел број).
Заработувачката по трка на возачите се пресметува како:

за автомобилостот заработувачката по трка е $\frac{CENA_{AVTOMOBIL}}{5}$
за мотоциклистот заработувачката по трка е $MOKJNOST_NA_MOTOR * 20$
Секој автомобилист плаќа данок на заработка. Да се напишат соодветни методи за пресметување данок:

за автомобилисти: ако бројот на трки е поголем од 10 стапката на данок е 15% од заработката, инаку 10% од заработката.
за мотоциклисти: ако е ветеран стапката на данок е 25% од заработката, инаку 20% од заработката.
Да се напше надворешна функција soIstaZarabotuvachka која како аргументи прима низа од покажувачи од класата Vocac, нивниот број,
 како и покажувач кон ојбект од возач и враќа како резултат бројот на возачи кои имаат иста заработувачка по трка со проследениот возач.
*/

#include<iostream>
#include<cstring>
using namespace std;
class Vozac
{
    protected:
    char ime[100];
	int vozrast;
	int trki;
	bool vet;
	public:
	Vozac()
	{
	    strcpy(this->ime,"");
	    this->vozrast=0;
	    this->trki=0;
	    this->vet=false;
	}
	Vozac(char *ime,int vozrast,int trki,bool vet)
	{
	    strcpy(this->ime,ime);
	    this->vozrast=vozrast;
	    this->trki=trki;
	    this->vet=vet;
	}
	Vozac(const Vozac &v)
	{
	    strcpy(this->ime,v.ime);
	    this->vozrast=v.vozrast;
	    this->trki=v.trki;
	    this->vet=v.vet;
	}
	Vozac &operator=(const Vozac &v)
	{
	    if(this!=&v)
	    {
	    strcpy(this->ime,v.ime);
	    this->vozrast=v.vozrast;
	    this->trki=v.trki;
	    this->vet=v.vet;
	    }
	    return *this;
	}
	~Vozac()
	{

	}
	friend ostream &operator<<(ostream &out, Vozac &v)
	{
	    out<<v.ime<<endl;
	    out<<v.vozrast<<endl;
	    out<<v.trki<<endl;
	    if(v.vet==true)
	    {
	        out<<"VETERAN"<<endl;
	    }
	    return out;
	}
	virtual double danok()=0;
	virtual double zarabotuvachka()=0;
	int getTrki()
	{
	    return trki;
	}
	bool getVet()
	{
	    return vet;
	}
};
class Avtomobilist: public Vozac
{
    private:
    float cena_avto;
    public:
    Avtomobilist()
    {
        this->cena_avto=0;
    }
    Avtomobilist(char *ime,int vozrast,int trki,bool vet,float cena_avto):Vozac(ime,vozrast,trki,vet)
    {
        this->cena_avto=cena_avto;
    }
    Avtomobilist(const Avtomobilist &a):Vozac(a)
    {
        this->cena_avto=a.cena_avto;
    }
    Avtomobilist &operator=(const Avtomobilist &a)
    {
        if(this!=&a)
        {
             strcpy(this->ime,a.ime);
	    this->vozrast=a.vozrast;
	    this->trki=a.trki;
	    this->vet=a.vet;
        this->cena_avto=a.cena_avto;
        }
        return *this;
    }
    ~Avtomobilist()
    {

    }
    double zarabotuvachka()
    {
        return cena_avto/5;
    }
    double danok()
    {
        if(getTrki()>10)
        {
            return zarabotuvachka()*0.15;
        }
        else
        {
            return zarabotuvachka()*0.10;
        }
    }
    bool operator==(Avtomobilist &a)
    {
        if(zarabotuvachka()==a.zarabotuvachka())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Motociklist: public Vozac
{
    private:
    int mokjnost;
    public:
    Motociklist()
    {
        this->mokjnost=0;
    }
    Motociklist(char *ime,int vozrast,int trki,bool vet,int mokjnost):Vozac(ime,vozrast,trki,vet)
    {
        this->mokjnost=mokjnost;
    }
    Motociklist(const Motociklist &m):Vozac(m)
    {
        this->mokjnost=m.mokjnost;
    }
    Motociklist &operator=(const Motociklist &m)
    {
        if(this!=&m)
        {
             strcpy(this->ime,m.ime);
	    this->vozrast=m.vozrast;
	    this->trki=m.trki;
	    this->vet=m.vet;
        this->mokjnost=m.mokjnost;
        }
        return *this;
    }
    ~Motociklist()
    {

    }
    double zarabotuvachka()
    {
        return mokjnost*20;
    }
    double danok()
    {
        if(getVet()==true)
        {
            return zarabotuvachka()*0.25;
        }
        else
        {
            return zarabotuvachka()*0.20;
        }
    }
    bool operator==(Motociklist &m)
    {
        if(zarabotuvachka()==m.zarabotuvachka())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int soIstaZarabotuvachka (Vozac **v,int n,Vozac *vx)
{
    int br=0;
    for(int i=0;i<n;i++)
    {

        if(v[i]->zarabotuvachka()==vx->zarabotuvachka())
        {
            br++;
        }
    }
    return br;
}
int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}
