/*
Да се имплементира класа Trud во која се чуваат информации за: (5 поени)

вид на труд (еден знак и тоа C за конференциски труд, J за труд во списание)
година на издавање (цел број).
Да се имплементира класа Student во која се чува: (5 поени)

името на студентот (низа од најмногу 30 карактери)
индекс (цел број)
година на упис (цел број)
листа на оцени од положени предмети (низа од цели броеви)
број на положени предмети (цел број)
За оваа класа да се имплементираат следните методи:

функција rang() што пресметува просек од положените испити на студентот (5 поени)
оператор << за печатење на студентот во формат: (5 поени)

Индекс Име Година на упис ранг

Да се имплементира класа PhDStudent во која покрај основните информации за студентот дополнително се чува: (5 поени)

листа од објавени трудови (динамички резервирана низа од објекти од класата Trud)
бројот на трудови (цел број)
Во оваа класа да се препокрие соодветно функцијата rang() така што на просекот од положените испити ќе се додаде и збирот од поените од објавените трудови на PhD студентот. Во зависност од видот на трудот, секој универзитет има посебен начин на бодување на трудовите. Начинот на бодување е ист за сите PhD студенти. Иницијално да се смета дека конференциски труд се бодува со 1 поен, а труд во списание со 3 поени. Универзитетот има можност да ги менува вредностите на бодовите. (5 поени + 5 поени)

За оваа класа да се обезбеди:

оператор += за додавање нов објект од класата Trud во листата (5 поени). Ако се направи обид да се внесе труд што е издаден порано од годината на упис на студентот да се фрли исклучок (објект од класата Exception). Справувањето со исклучокот треба да се реализира во главната функција main каде што е потребно, но и во конструктор ако е потребно. Ако бил генериран исклучок треба да се отпечати соодветна порака за грешка "Ne moze da se vnese dadeniot trud", а новиот труд нема да се внесе во листата на трудови од студентот. (10 поени)
Напомена: Сите променливи на класите се чуваат како приватни.

Да се обезбедат сите потребни функции за правилно функционирање на програмата. (5 поени)
*/


#include <iostream>
#include <cstring>

using namespace std;

class Exception{
public:
    void message(){
        cout<<"Ne moze da se vnese dadeniot trud"<<endl;
    }
};

class Trud{
protected:
    char znak;
    int godina;
public:
    Trud(){
        this->znak= 'A';
        this->godina=0;
    }
    Trud(char znak, int godina)  {
        this->znak= toupper(znak);
        this->godina=godina;
    }
    Trud(const Trud &t)  {
        this->znak=t.znak;
        this->godina=t.godina;
    }
    Trud &operator=(const Trud &t)  {
        if (this!=&t) {
            this->znak = t.znak;
            this->godina = t.godina;
        }
        return *this;
    }

    friend istream &operator>>(istream &in,Trud &t){
        in>>t.znak;
        in>>t.godina;
        return in;
    }

    char getZnak() {
        return znak;
    }

    int getGodina() const {
        return godina;
    }
};
class Student{
protected:
    char ime[30];
    int indeks;
    int godina_upis;
    int *ocenki;
    int n;
public:
    Student()  {
        strcpy(this->ime,"");
        this->indeks=0;
        this->godina_upis=0;
        this->n=0;
        this->ocenki=new int[n];
    }
    Student(char *ime, int indeks, int godinaUpis, int *ocenki, int n)  {
        strcpy(this->ime,ime);
        this->indeks=indeks;
        this->godina_upis=godinaUpis;
        this->n=n;
        this->ocenki=new int[n];
        for (int i = 0; i < n; ++i) {
            this->ocenki[i]=ocenki[i];
        }
    }
    Student(const Student &s)  {
        strcpy(this->ime,s.ime);
        this->indeks=s.indeks;
        this->godina_upis=s.godina_upis;
        this->n=s.n;
        this->ocenki=new int[s.n];
        for (int i = 0; i < s.n; ++i) {
            this->ocenki[i]=s.ocenki[i];
        }
    }
    Student &operator=(const Student &s)  {
        if (this!=&s) {
            strcpy(this->ime, s.ime);
            this->indeks = s.indeks;
            this->godina_upis = s.godina_upis;
            this->n = s.n;
            this->ocenki = new int[s.n];
            for (int i = 0; i < s.n; ++i) {
                this->ocenki[i] = s.ocenki[i];
            }
        }
        return *this;
    }

    virtual double rang(){
        double prosek=0;
        for (int i = 0; i < n; ++i) {
            prosek+=ocenki[i];
        }
        return prosek/n;
    }

    friend ostream &operator<<(ostream &o,Student &s){
        o<<s.indeks<<" "<<s.ime<<" "<<s.godina_upis<<" "<<s.rang()<<endl;
        return o;
    }
    virtual ~Student(){
        delete[]ocenki;
    }

    const char *getIme() const {
        return ime;
    }

    int getIndeks() const {
        return indeks;
    }

    void setIndeks(int indeks) {
        Student::indeks = indeks;
    }

    int getGodinaUpis() const {
        return godina_upis;
    }

    void setGodinaUpis(int godinaUpis) {
        godina_upis = godinaUpis;
    }

    int *getOcenki() const {
        return ocenki;
    }

    void setOcenki(int *ocenki) {
        Student::ocenki = ocenki;
    }

    int getN() const {
        return n;
    }

    void setN(int n) {
        Student::n = n;
    }
};

class PhDStudent:public Student{
private:
    Trud *trudovi;
    int tn;
    static int coefC;
    static int coefJ;
public:
    static void setC(int coefC) {
        PhDStudent::coefC = coefC;
    }

    static void setJ(int coefJ) {
        PhDStudent::coefJ = coefJ;
    }

    PhDStudent() : Student(){
        this->tn=0;
        this->trudovi=new Trud[tn];

    }
    PhDStudent(char *ime, int indeks, int godinaUpis, int *ocenki, int n, Trud *trudovi, int tn) : Student(ime,indeks,godinaUpis,ocenki,n){
        this->tn=tn;
        this->trudovi=new Trud[tn];
        for (int i = 0; i < tn; ++i) {
            try {
                if (trudovi[i].getGodina()<getGodinaUpis()) throw Exception();
                this->trudovi[i]=trudovi[i];
            }
            catch (Exception &e){
                e.message();
            }
        }
    }
    double rang(){
        double poeni=Student::rang();
        for (int i = 0; i < tn; ++i) {
            if (toupper(trudovi[i].getZnak())=='C'){
                poeni+=coefC;
            } else if (toupper(trudovi[i].getZnak())=='J'){
                poeni+=coefJ;
            }
        }
        return poeni;
    }
    PhDStudent &operator+=(Trud &t){
        if (trudovi->getGodina()>t.getGodina()){
            throw Exception();
        }
        Trud *pom=new Trud[n+1];
        for (int i = 0; i < n; ++i) {
            pom[i]=trudovi[i];
        }
        pom[tn++]=t;
        delete [] trudovi;
        trudovi=pom;
        return *this;
    }


};

int PhDStudent::coefC=1;
int PhDStudent::coefJ=3;

int main(){
    int testCase;
    cin >> testCase;

    int god, indeks, n, god_tr, m, n_tr;
    int izbor; //0 za Student, 1 za PhDStudent
    char ime[30];
    int oceni[50];
    char tip;
    Trud trud[50];

    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        Student s(ime, indeks, god, oceni, n);
        cout << s;

        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++){
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        bool found=false;
        try{
            for (int i = 0; i < m; ++i) {
                if (niza[i]->getIndeks()==indeks && dynamic_cast<PhDStudent*>(niza[i])){
                    *dynamic_cast<PhDStudent*>(niza[i])+=t;
                    found= true;
                }
            }
        }
        catch (Exception &e){
            e.message();
        }
        if (!found){
            cout<<"Ne postoi PhD student so indeks "<<indeks<<endl;
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2
        try{
            for (int i = 0; i < m; ++i) {
                if (niza[i]->getIndeks()==indeks && dynamic_cast<PhDStudent*>(niza[i])){
                    *dynamic_cast<PhDStudent*>(niza[i])+=t;
                }
            }
        }
        catch (Exception &e){
            e.message();
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 4){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++){
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 5){
        cout << "===== Testiranje na isklucoci ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot
        try{
            for (int i = 0; i < m; ++i) {
                if (niza[i]->getIndeks()==indeks && dynamic_cast<PhDStudent*>(niza[i])){
                    *dynamic_cast<PhDStudent*>(niza[i])+=t;
                }
            }
        }
        catch (Exception &e){
            e.message();
        }


        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 6){
        cout << "===== Testiranje na static clenovi ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        int conf, journal;
        cin >> conf;
        cin >> journal;

        //postavete gi soodvetnite vrednosti za statickite promenlivi

        PhDStudent::setC(conf);
        PhDStudent::setJ(journal);

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }

    return 0;
}
