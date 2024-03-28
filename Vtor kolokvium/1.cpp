/*Издавачката куќа FINKI-Education издава онлајн и печатени книги. За секоја книга се чуваат податоци за ISBN бројот (низа од најмногу 20 знаци), насловот (низа од најмногу 50 знаци), авторот (низа од најмногу 30 знаци) и основната цена изразена во $ (реален број). Класата за опишување на книгите е апстрактна (5 поени).

За секоја онлајн книга дополнително се чуваат податоци за url од каде може да се симне (динамички резервирана низа од знаци) и големината изразена во MB (цел број). За секоја печатена книга дополнително се чуваат податоци за масата изразена во килограми (реален број) и дали ја има на залиха (логичка променлива). (5 поени)

За секој објект од двете изведени класи треба да бидат на располагање следниве методи:

Метод bookPrice, за пресметување на продажната цена на книгата на следниот начин: (10 поени)

За онлајн книга - цената се зголемува за 20% од основната цена ако книгата е поголема од 20MB

За печатена книга - цената се зголемува за 15% од основната цена ако масата на книгата е поголема од 0.7kg

Преоптоварен оператор > за споредба на две книги од каков било вид според нивната цена. (5 поени)

Преоптоварен оператор << за печатење на податоците за книгите во формат: (5 поени)
Да се имплементира функција mostExpensiveBook со потпис:

void mostExpensiveBook (Book** books, int n)

во која се печати вкупниот број на онлајн, односно, печатени книги во проследената низа посебно. (5 поени) Потоа се наоѓа и печати најскапата книга. (5 поени)

Да се обезбедат сите потребни функции за правилно функционирање на програмата. (5 поени)*/

#include <iostream>
#include <cstring>
using namespace std;

class Book{
protected:
    char isbn[20];
    char naslov[50];
    char avtor[30];
    float cena;
public:
    float getCena() const {
        return cena;
    }

    Book(){
        strcpy(this->isbn,"");
        strcpy(this->naslov,"");
        strcpy(this->avtor,"");
        this->cena=0;
    }
    Book(char *isbn, char *naslov, char *avtor, float cena)  {
        strcpy(this->isbn,isbn);
        strcpy(this->naslov,naslov);
        strcpy(this->avtor,avtor);
        this->cena=cena;
    }
    void setISBN(char *isbn){
        strcpy(this->isbn,isbn);
    }

    void setCena(float cena) {
        Book::cena = cena;
    }
    virtual float bookPrice()=0;
    bool operator>(Book &b){
        if (cena>b.cena){
            return true;
        } else return false;
    }
    friend ostream &operator<<(ostream &o,Book &b){
        o<<b.isbn<<": "<<b.naslov<<", "<<b.avtor<<" "<<b.bookPrice()<<endl;
        return o;
    }
};

class OnlineBook:public Book{
protected:
    char *url;
    int n;
public:
    OnlineBook(){
        this->n=0;
        this->url=new char[0];
    }

    OnlineBook(char *isbn, char *naslov, char *avtor, float cena, char *url, int n):Book(isbn,naslov,avtor,cena) {
        this->n=n;
        this->url=new char [strlen(url)+1];
        strcpy(this->url,url);

    }

    OnlineBook(const OnlineBook &o):Book(o) {
        this->n=o.n;
        this->url=new char [strlen(o.url)+1];
        strcpy(this->url,o.url);
    }

    OnlineBook &operator=(const OnlineBook &o) {
        if (this != &o) {
            Book::operator=(o);
            this->n = o.n;
            this->url=new char [strlen(o.url)+1];
            strcpy(this->url,o.url);
        }
        return *this;
    }

    float bookPrice(){
        if (n>20){
            return cena+ cena*0.2;
        }
        return cena;
    }
    ~OnlineBook(){
        delete [] url;
    }

};

class PrintBook:public Book{
protected:
    float masa;
    bool zaliha;
public:
    PrintBook(){
        this->masa=0;
        this->zaliha= false;
    }
    PrintBook(char *isbn, char *naslov, char *avtor, float cena, float masa, bool zaliha):Book(isbn,naslov,avtor,cena)  {
        this->masa=masa;
        this->zaliha=zaliha;
    }


    PrintBook(const PrintBook &p):Book(p)  {
        this->masa=p.masa;
        this->zaliha=p.zaliha;
    }

    PrintBook &operator=(const PrintBook &p) {
        if (this!=&p) {
            Book::operator=(p);
            this->masa = p.masa;
            this->zaliha = p.zaliha;
        }
        return *this;
    }

    float bookPrice(){
        if (masa>0.7){
            return cena+ cena*0.15;
        }
    }

};

void mostExpensiveBook (Book** books, int n){
    int o=0,p=0,max_i=0;
    float max=books[0]->getCena();
    for (int i = 0; i < n; ++i) {
        OnlineBook *onl=dynamic_cast<OnlineBook*>(books[i]);
        if (onl!= nullptr){
            o++;
        }
        PrintBook *print=dynamic_cast<PrintBook*>(books[i]);
        if (print!= nullptr){
            p++;
        }
        if (max<books[i]->getCena()){
            max=books[i]->getCena();
            max_i=i;
        }

    }
    cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<o<<endl;
    cout<<"Total number of print books: "<<p<<endl;
    cout<<"The most expensive book is: "<<endl;
    cout<<*books[max_i];
}


int main(){

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
    delete[] books;
    return 0;
}
