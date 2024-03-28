/*Да се креира класа за опишување на еден сервис за мобилни уреди. За секој мобилен телефон се чуваат податоци за модел (низа од 100 знаци), тип на уред (смартфон или компјутер), потребни часови за основна проверка (децимален број), година на производство (цел број). (5 поени)

Сите уреди имаат исто времетраење за основна проверка и истата изнесува 1 час. Оваа вредност може да се смени со одлука на сервисот. Дополнително, уредите кои се понови од 2015 година имаат потреба од дополнителени 1.5 часа за проверка. При проверка, лаптопите имаат потреба од дополнителни 2 часа за софтверска дијагностика (5 поени).

За оваа класа да се имплементира оператор << за печатење на уред во формат:

[modelnauredotl]
[tipnaured] [casovizaproverka]

Каде часовите за проверка се оние од основната проверка+ дополнителни 2 часа доколку уредот е понов од 2015 + 2 часа доколу уредот е лаптоп (5 поени)

Да се креира класа MobileServis во која се чува адреса (низа од 100 знаци), низа од уреди (динамички алоцирана низа) и број на уреди.(5 поени)

За класата да се обезбедат:

operatoror+= за додавање на нов уред во сервисот.(5 поени) Не смее да се дозволи годината на производство на уредот да биде поголема од 2019 или помала од 2000. Ако се направи обид за додавање на уред со невалидна година, треба да се генерира исклучок InvalidProductionDate. (10 поени)

Функција pecatiUredi со која се печатат сите уреди со времето потребно за нивната проверка во сервисот (5 поени).

Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата. (5 поени)*/

#include <iostream>
#include <cstring>

using namespace std;
#include<iostream>
#include<cstring>
using namespace std;
enum tip{smartphone, kompjuter};
class InvalidProductionDate
{
    public:
    char poraka[100];
    InvalidProductionDate (char *poraka)
    {
        strcpy(this->poraka,poraka);
    }
    void pecati()
    {
        cout<<poraka<<endl;
    }
};
class Device
{
    protected:
    char ime[100];
    tip Tip;
    static double chasovi;
    int godina;
    public:
    Device()
    {
        strcpy(this->ime,"");
        this->Tip=(tip)0;
        this->godina=0;
    }
    Device( char *ime,tip Tip,int godina)
    {
        strcpy(this->ime,ime);
        this->Tip=Tip;
        this->godina=godina;
    }
    Device(const Device &d)
    {
        strcpy(this->ime,d.ime);
        this->Tip=d.Tip;
        this->godina=d.godina;
    }
    Device &operator=(const Device &d)
    {
        if(this!=&d)
        {
        strcpy(this->ime,d.ime);
        this->Tip=d.Tip;
        this->godina=d.godina;
        }
        return *this;
    }
    ~Device()
    {

    }
    friend ostream &operator<<(ostream &out,Device &d)
    {
        out<<d.ime<<endl;
        if(d.Tip==0 && d.godina<=2015)
        {
            out<<"Mobilen "<<chasovi<<endl;
        }
         else if(d.Tip==0 && d.godina>2015)
        {
            out<<"Mobilen "<<chasovi+2<<endl;
        }
         else if(d.Tip==1 && d.godina<2015)
        {
            out<<"Laptop "<<chasovi+2<<endl;
        }
       else  if(d.Tip==1 && d.godina>2015)
        {
            out<<"Laptop "<<chasovi+4<<endl;
        }
        return out;
    }
    int getGodina()
    {
        return godina;
    }
    char *getIme()
    {
        return ime;
    }
    static double setPocetniCasovi(double num)
    {
        chasovi=num;
    }
};
class MobileServis
{
    private:
    char adresa[100];
    Device *ured;
    int n;
    public:
    MobileServis()
    {
        strcpy(this->adresa,"");
        this->n=0;
        this->ured=new Device[0];
    }
    MobileServis(char *adresa, Device *ured, int n)
    {
        strcpy(this->adresa,adresa);
        this->n=n;
        this->ured=new Device[n];
        for(int i=0;i<n;i++)
        {
            this->ured[i]=ured[i];
        }
    }
    MobileServis(char *adresa)
    {
        strcpy(this->adresa,adresa);
        this->n=0;
        this->ured=new Device[0];

    }
    MobileServis(const MobileServis &m)
    {
        strcpy(this->adresa,m.adresa);
        this->n=m.n;
        this->ured=new Device[m.n];
        for(int i=0;i<m.n;i++)
        {
            this->ured[i]=m.ured[i];
        }
    }
    MobileServis &operator=(const MobileServis &m)
    {
        if(this!=&m)
        {
        strcpy(this->adresa,m.adresa);
        this->n=m.n;
        this->ured=new Device[m.n];
        for(int i=0;i<m.n;i++)
        {
            this->ured[i]=m.ured[i];
        }
        }
        return *this;
    }
    ~MobileServis()
    {
        delete[]ured;
    }
    MobileServis &operator+=(Device &d)
    {
        if(d.getGodina()>2019 || d.getGodina()<2000)
        {
            throw  InvalidProductionDate("Невалидна година на производство");
        }
        Device *temp=new Device[n+1];
        for(int i=0;i<n;i++)
        {
            temp[i]=ured[i];
        }
        temp[n++]=d;
        delete[]ured;
        ured=temp;
        return *this;
    }
    void  pecatiCasovi()
    {
        cout<<"Ime: "<<adresa<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<ured[i];
        }
    }
};
double Device::chasovi=1;
int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try
            {
            t+=tmp;
            }
            catch(InvalidProductionDate ip)
            {
                ip.pecati();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
              try
            {
            t+=tmp;
            }
            catch(InvalidProductionDate ip)
            {
                ip.pecati();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		 cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
              try
            {
            t+=tmp;
            }
            catch(InvalidProductionDate ip)
            {
                ip.pecati();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

              try
            {
            t+=tmp;
            }
            catch(InvalidProductionDate ip)
            {
                ip.pecati();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
              try
            {
            t+=tmp;
            }
            catch(InvalidProductionDate ip)
            {
                ip.pecati();
            }
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}

	return 0;

}
