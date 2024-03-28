/*Фирмата FINKI Cloud има потреба од решение за управување со image датотеките од различните оперативни системи кои ги користат при сетирање на нови сервери. За таа цел потребно е да се дефинираат следниве класи:

OperativenSistem
Во класата OperativenSistem треба да се чуваат следниве податоци:

име на оперативниот систем (динамички алоцирана низа од знаци)
верзија (float)
тип (енумерација со можни вредности LINUX, UNIX, WINDOWS)
големина (во GB) (float)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктори со и без параметри
copy constructor
destructor
преоптоварување на операторот =
метод за печатење на информациите - void pecati() (видете го излезот од тест примерите за структурата)
метод за проверка на еднаквост помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија, тип и големина) - bool ednakviSe(const OperativenSistem &os)
метод за споредба на верзии помеѓу два оперативни система - int sporediVerzija(const OperativenSistem &os), кој ќе враќа 0 доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
метод за проверка дали два оперативни системи се од иста фамилија. Два оперативни системи се од иста фамилија доколку имаат исто име и се од ист тип. bool istaFamilija(const OperativenSistem &sporedba)
Repozitorium
Во класата Repozitorium треба да се чуваат следниве податоци:

име на репозиториумот (низа од 20 знака)
динамички алоцирана низа од OperativenSistem
број на оперативни системи кои моментално се наоѓаат во репозиториумот (int)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктор Repozitorium(const char *ime)
деструктор
метод void pecatiOperativniSistemi() кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
метод void izbrishi(const OperativenSistem &operativenSistem) кој ќе го избрише оперативниот систем проследен како аргумент, доколку тој се наоѓа во репозиториумот. Да се користи методот ednakviSe за споредба на два оперативни система.
метод за додавање на оперативен систем (void dodadi(const OperativenSistem &nov)) кој ќе го има следново однесување:
Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од проследениот оперативен систем, тогаш постоечкиот оперативен систем се заменува со новиот.
Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумот.*/

#include<iostream>
#include<cstring>
using namespace std;
enum Tip { LINUX, UNIX, WINDOWS};
class OperativenSistem
{
  private:
  char *ime;
  float verzija;
  Tip tip;
  float golemina;
  public:
  OperativenSistem()
  {
      this->ime=new char[0];
      strcpy(this->ime,"");
      this->verzija=0;
      this->tip=(Tip)0;
      this->golemina=0;
  }
  OperativenSistem(char *ime, float verzija, Tip tip, float golemina)
  {
      this->ime=new char[strlen(ime)+1];
      strcpy(this->ime,ime);
      this->verzija=verzija;
      this->tip=tip;
      this->golemina=golemina;
  }
    OperativenSistem(const OperativenSistem &o)
  {
      this->ime=new char[strlen(o.ime)+1];
      strcpy(this->ime,o.ime);
      this->verzija=o.verzija;
      this->tip=o.tip;
      this->golemina=o.golemina;
  }
      OperativenSistem &operator=(const OperativenSistem &o)
  {
      if(this!=&o)
      {
      this->ime=new char[strlen(o.ime)+1];
      strcpy(this->ime,o.ime);
      this->verzija=o.verzija;
      this->tip=o.tip;
      this->golemina=o.golemina;
      }
      return *this;
  }
  ~OperativenSistem()
  {
      delete[]ime;
  }
  void pecati()
  {
      cout<<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<tip<<" Golemina:"<<golemina<<"GB"<<endl;
  }
   bool ednakviSe(const OperativenSistem &os)
   {
       if(strcmp(ime,os.ime)==0 && verzija==os.verzija && tip==os.tip && golemina==os.golemina)
       {
           return true;
       }
       else
       {
           return false;
       }
   }
   int sporediVerzija(const OperativenSistem &os){
       if(verzija==os.verzija)
       {
           return 0;
       }
       else if(verzija<os.verzija)
       {
           return -1;
       }
       else {
           return 1;
       }
   }
   bool istaFamilija(const OperativenSistem &sporedba)
   {
       if(strcmp(ime,sporedba.ime)==0 && tip==sporedba.tip)
       {
           return true;
       }
       else
       {
           return false;
       }
   }
};
class Repozitorium {
  private:
  char *repoName;
  OperativenSistem *os;
  int brojOperativniSistemi;
  public:
  Repozitorium ()
  {
      this->repoName=new char[0];
      strcpy(this->repoName,"");
      this->brojOperativniSistemi=0;
      this->os=new OperativenSistem[brojOperativniSistemi];
  }
     Repozitorium (char *repoName, OperativenSistem *os,int brojOperativniSistemi)
  {
      this->repoName=new char[strlen(repoName)+1];
      strcpy(this->repoName,repoName);
      this->brojOperativniSistemi=brojOperativniSistemi;
      this->os=new OperativenSistem[brojOperativniSistemi];
      for(int i=0;i<brojOperativniSistemi;i++)
      {
          this->os[i]=os[i];
      }
  }
   Repozitorium (char *repoName)
  {
      this->repoName=new char[strlen(repoName)+1];
      strcpy(this->repoName,repoName);
      this->brojOperativniSistemi=0;
      this->os=new OperativenSistem[brojOperativniSistemi];
  }
    Repozitorium (const Repozitorium &r)
  {
      this->repoName=new char[strlen(r.repoName)+1];
      strcpy(this->repoName,r.repoName);
      this->brojOperativniSistemi=r.brojOperativniSistemi;
      this->os=new OperativenSistem[r.brojOperativniSistemi];
      for(int i=0;i<r.brojOperativniSistemi;i++)
      {
          this->os[i]=r.os[i];
      }
  }
    Repozitorium &operator=(const Repozitorium &r)
  {
      if(this!=&r)
      {
      this->repoName=new char[strlen(r.repoName)+1];
      strcpy(this->repoName,r.repoName);
      this->brojOperativniSistemi=r.brojOperativniSistemi;
      this->os=new OperativenSistem[r.brojOperativniSistemi];
      for(int i=0;i<r.brojOperativniSistemi;i++)
      {
          this->os[i]=r.os[i];
      }
      }
      return *this;
  }
  ~Repozitorium()
  {
      delete[] repoName;
      delete[] os;
  }
   void pecatiOperativniSistemi()
   {
       cout<<"Repozitorium: "<<repoName<<endl;
       for(int i=0;i<brojOperativniSistemi;i++)
       {
           os[i].pecati();
       }
   }
   void izbrishi(const OperativenSistem &operativenSistem)
   {
       int brojach=0;
        OperativenSistem *temp=new OperativenSistem[brojOperativniSistemi];
        for(int i=0;i<brojOperativniSistemi;i++)
        {
            if(os[i].ednakviSe(operativenSistem) == 1)
            {
                continue;
            }
            else
            {
                temp[brojach++]=os[i];
            }
        }
        if(brojach<brojOperativniSistemi)
        {
            delete[]os;
            os=temp;
            brojOperativniSistemi=brojach;
        }
   }
   void dodadi(const OperativenSistem &nov)
   {
       int flag=1;
        OperativenSistem *temp=new OperativenSistem[brojOperativniSistemi+1];
        for(int i=0;i<brojOperativniSistemi;i++)
        {
            temp[i]=os[i];
            if(os[i].istaFamilija(nov) == 1)
            {
                if(os[i].sporediVerzija(nov) == -1)
                {
                    temp[i]=nov;
                    flag=0;
                }
            }
        }
        if(flag==1)
        {
            temp[brojOperativniSistemi++]=nov;
            delete[]os;
            os=temp;
        }
        else
        {
            delete[]os;
            os=temp;
        }
    }

};
int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
     cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}

