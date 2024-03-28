/*Да се креира класа Customer за опишување на купувачи на една книжара. За секој купувач се чуваат податоци за:

името (низа од 50 знаци),
електронска адреса (низа од 50 знаци),
вид на купувач (стандардни, лојални или вип),
основен попуст (цел број изразен во проценти),
дополнителен попуст (цел број изразен во проценти) и
број на купени производи. (5 поени)
Сите лојални купувачи со покажување на клуб картичка имаат право на основниот попуст при купување од книжарата. Основниот попуст
е ист за сите лојални купувачи и изнесува 10%. Оваа вредност може да се смени со одлука на раководството на книжарата.
Дополнителниот попуст е фиксен и може да го користат само вип купувачите и изнесува 20%. Стандардните купувачи немаат право на попуст (5 поени).

За оваа класа да се имплементира оператор << за печатење на купувач во формат:

[ime_na_kupuvac]
[email_na_kupuvac]
[broj_na_proizvodi]
[vid_na_kupuvac] [popust_sto_moze_da_go_koristi]
каде попустот е 0% ако купувачот е стандарден, вредноста на основниот попуст, ако е лојален или збир од основниот и
дополнителниот попуст, ако купувачот е вип. (5 поени)

Да се креира класа за онлајн книжара FINKI-bookstore во која се чува низа од регистрирани купувачи (динамички алоцирана низа) и број на купувачи.
(5 поени) За класата да се обезбедат:
operator+= (10 поени) за додавање купувач во листата од купувачи, но само ако веќе не е дел од неа (ако во листата нема купувач со иста електронска адреса).
Ако во листата постои корисник со иста електронска адреса, треба да се генерира исклучок UserExistsException. Потребно е да се обезбеди справување со
исклучокот во функцијата main на означеното место. Во ваква ситуација се печати порака "The user already exists in the list" (5 поени).
Функција update со која сите стандардни купувачи со купени повеќе од 5 производи стануваат лојални, а сите лојални купувачи со над 10 купени производи,
стануваат вип (5 поени).
Оператор << за печатење на информациите за сите регистрирани купувачи (5 поени).
Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата. (10 поени)*/


#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

/*
class UserExistsException{
public:
    char msg[100];

    UserExistsException(char msg[100]){
    strcpy(this->msg,msg);
    }
    void pecati(){
    cout<<msg<<endl;
    }
};
*/
class UserExistsException{
public:
    char msg[100];

    UserExistsException(){
    strcpy(this->msg,"");
    }
    void pecati(){
    cout<<"The user already exists in the list!"<<endl;
    }
};
enum typeC{standarden=0,lojalen=1,vip=2};
class Customer{
protected:
    char ime[50];
    char email[50];
    typeC kupuvac;
   static int osnovenPopust;
   int dopolnitelenPopust;
    int brojKupeniProizvodi;
public:
	 Customer(){
    strcpy(this->ime,"");
    strcpy(this->email,"");
    this->kupuvac=(typeC)0;
    this->brojKupeniProizvodi=0;
    this->dopolnitelenPopust=20;
    }
    Customer(char *ime,char *email,typeC kupuvac,int brojKupeniProizvodi){
    strcpy(this->ime,ime);
    strcpy(this->email,email);
    this->kupuvac=kupuvac;
    this->brojKupeniProizvodi=brojKupeniProizvodi;
    }
    Customer(const Customer &c){
    strcpy(this->ime,c.ime);
    strcpy(this->email,c.email);
    this->kupuvac=c.kupuvac;
    this->brojKupeniProizvodi=c.brojKupeniProizvodi;
    }
    Customer &operator=(const Customer &c){
        if(this!=&c){
    strcpy(this->ime,c.ime);
    strcpy(this->email,c.email);
    this->kupuvac=c.kupuvac;
    this->brojKupeniProizvodi=c.brojKupeniProizvodi;
    }
    return *this;
    }
    int getBrKupeni(){
    return brojKupeniProizvodi;
    }
    char *getEmail(){
    return email;
    }
    typeC getVid(){
    return kupuvac;
    }
    typeC setVid(typeC kupuvac){
    this->kupuvac=kupuvac;
    }
    static void setDiscount1(int newpopust){
    osnovenPopust=newpopust;
    }
    int popust(){
    	if(kupuvac==standarden)
        return 0;
    if(kupuvac==lojalen)
        return osnovenPopust;
    if(kupuvac==vip)
        return osnovenPopust+dopolnitelenPopust;
    }
    friend ostream &operator<<(ostream &print,Customer &o){
    print<<o.ime<<endl;
    print<<o.email<<endl;
    print<<o.brojKupeniProizvodi<<endl;
    if(o.kupuvac==standarden)
	print<<"standard ";
   if(o.kupuvac==lojalen)
	print<<"loyal ";
    if(o.kupuvac==vip)
	print<<"vip ";
    print<<o.popust()<<endl;
    return print;
    }
};

int Customer::osnovenPopust=10;


class FINKI_bookstore{
private:
    Customer *niza;
    int broj;
public:
	FINKI_bookstore(){
    this->broj=0;
    this->niza=new Customer[broj];
    }
    FINKI_bookstore(Customer *niza,int broj){
    this->broj=broj;
    this->niza=new Customer[broj];
    for(int i=0;i<broj;i++){
        this->niza[i]=niza[i];
    }
    }
    FINKI_bookstore(const FINKI_bookstore &f){
    this->broj=f.broj;
    this->niza=new Customer[f.broj];
    for(int i=0;i<f.broj;i++){
        this->niza[i]=f.niza[i];
    }
    }

    void setCustomers(Customer *niza,int broj){
    this->broj=broj;
    this->niza=new Customer[broj];
    for(int i=0;i<broj;i++){
        this->niza[i]=niza[i];
    }
    }
    FINKI_bookstore &operator+=(Customer &c){
    int flag=0;
    for(int i=0;i<broj;i++){
        if(strcmp(niza[i].getEmail(),c.getEmail())==0){// Ako vo listata postoi korisnik so ista elektronska adresa
              throw UserExistsException();// generiram isklucok od kalsata UserExistsException
    flag=1;
			}
	}
    if(flag==0){// Ako vo listata ne postoi korisnik so ista elektronska adresa
        Customer *temp=new Customer[broj+1];
        for(int i=0;i<broj;i++){
            temp[i]=niza[i];
        }
        temp[broj++]=c;
        delete [] niza;
        niza=temp;
    }
    return *this;
    }
    void update(){
    for(int i=0;i<broj;i++){
        if(niza[i].getBrKupeni()>5 && niza[i].getVid()==standarden){
            niza[i].setVid(lojalen);
        }
        else if(niza[i].getBrKupeni()>10 && niza[i].getVid()==lojalen){
            niza[i].setVid(vip);
        }
    }
    }
    friend ostream &operator<<(ostream &print,FINKI_bookstore &o){
    for(int i=0;i<o.broj;i++)
        print<<o.niza[i];
    return print;
    }
};

int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    try{
    fc+=c;
}
 catch (UserExistsException &ex){
   ex.pecati();
   }
    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
     Customer c(name, email, (typeC) tC, numProducts);
   try{
    fc+=c;
   }
   catch (UserExistsException &ex){
   ex.pecati();
   }
    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;
}
