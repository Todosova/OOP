/*Да се креира класа за опишување на концерти. За еден концерт се чуваат информации за (5 поени):

● назив (низа од најмногу 20 знаци)

● локација (низа од најмногу 20 знаци)

● сезонски попуст (реален број)

● цена на билет во денари (децимален број)

Сите податоци во класата треба да се приватни. Сезонскиот попуст е ист за сите концерти и може да се менува од страна на менаџерите
во зависност од сезоната. За таа цел да се обезбеди функција за менување на сезонскиот попуст. Сезонскиот попуст е изразен во проценти и
почетната вредност е 20 проценти. (5 поени)

Основната цена на еден билет за концерт се пресметува со методот:

● cena() – која ја враќа цената со сезонскиот попуст (5 поени)

За потребите на еден летен фестивал, треба да се обезбедат посебен вид на забавни концерти, електронски концерти. За секој eлектронски концерт
дополнително се чуваат инфромации за името на DJ-от(динамички алоцирана низа од знаци), времетраење на настапот во часови (реален број) и логичка
променлива за дали се работи за дневна или ноќна забава (дневна-true/ноќна-false). (5 поени)

За секој електронски концерт треба да биде на располагање метод за пресметување на цената за билет (5 поени):

● cena() - основната цена се зголемува во зависност од времетраењето на електронскиот концерт. Ако времетраењето на концертот е подолго од 5 часа,
основната цена се зголемува за 150 денари. Ако времетраењето е подолго од 7 часа, цената се зголемува за 360 денари. Доколку се работи за дневна забава,
цената се намалува за 50, а доколку се работи за ноќна забава цената се зголемува за 100 денари.

Да се имплементираат следните функции:

· void najskapKoncert(Koncert ** koncerti, int n) – во која ќе се испечати називот и цената на најскапиот концерт во низата. Дополнително,
да се испечати и колку од концертите се електронски, а колку не во формат:

  [Електронски концерти: X од вкупно Y.] (10 поени)
· bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski) – во која ќе се прабарува концерт кој имаат ист назив како
променливата naziv. Доколку променливата elektronski е true, треба да се пребарува само низ електронските концерти, во спротивно се пребаруваат
сите концерти. Доколку е пронајден концертот, се печати неговиот назив и цена и функцијата враќа true. Доколку не е пронајден концертот,
функцијата враќа false. Можно е да има повеќе концерти со ист назив. (10 поени)*/


#include <iostream>
#include <cstring>
using namespace std;

class Koncert{
private:
    char naziv[20];
    char lokacija[20];
    static float popust;
    float price;
public:
    Koncert(){
        strcpy(this->naziv,"");
        strcpy(this->lokacija,"");
        this->price=0;
    }
    Koncert(char *naziv, char *lokacija, float c){
        strcpy(this->naziv,naziv);
        strcpy(this->lokacija,lokacija);
        this->price=c;
    }

    const char *getNaziv() const {
        return naziv;
    }

    const char *getLokacija() const {
        return lokacija;
    }

    static float getSezonskiPopust() {
        return popust;
    }

    static void setSezonskiPopust(float popust) {
        Koncert::popust = popust;
    }

    float getCena() const {
        return price;
    }

    void setCena(float cena) {
        Koncert::price = cena;
    }

    virtual float cena(){
        return price-price*popust;
    }
};

float Koncert::popust=0.20;

class ElektronskiKoncert:public Koncert{
private:
    char *ime;
    float vremetraenje;
    bool dnevna;
public:
    ElektronskiKoncert(char *naz, char *lok, float price,char *ime=nullptr, float vremetraenje=0, bool dnevna=false): Koncert(naz,lok,price) {
        this->vremetraenje=vremetraenje;
        this->dnevna=dnevna;
        this->ime=new char [strlen(ime)+1];
        strcpy(this->ime,ime);
    }
    float cena(){
        float vkupno=Koncert::cena();
        if (vremetraenje>7.0){
            vkupno+=360;
        } else if (vremetraenje>5.0){
            vkupno+=150;
        }
        if (dnevna== true){
            vkupno-=50.0;
        } else vkupno+=100;
        return vkupno;
    }
    ~ElektronskiKoncert(){
        delete [] ime;
    }
};

void najskapKoncert(Koncert **koncerti, int n){
    int elektronski=0,max_i=0;
    float najskap=koncerti[0]->cena();
    for (int i = 1; i < n; ++i) {
        if (najskap < koncerti[i]->cena()) {
            najskap = koncerti[i]->cena();
            max_i = i;
        }
        if(ElektronskiKoncert *k=dynamic_cast<ElektronskiKoncert*>(koncerti[i])) {
            elektronski++;
        }
    }
    cout<<"Najskap koncert: "<<koncerti[max_i]->getNaziv()<<" "<<koncerti[max_i]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<elektronski<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski){
    if (elektronski== true) {
        for (int i = 0; i < n; ++i) {
            if (ElektronskiKoncert *ek=dynamic_cast<ElektronskiKoncert*>(koncerti[i])) {
                if (strcmp(naziv, koncerti[i]->getNaziv()) == 0) {
                    cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                    return true;
                }
            }
        }

    }
    if (elektronski== false){
        for (int i = 0; i < n; ++i) {
            if (strcmp(naziv,koncerti[i]->getNaziv())==0){
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

    cin>>tip;
    if (tip==1){//Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
    }
    else if (tip==2){//cena - Koncert
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
    }
    else if (tip==3){//ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
    }
    else if (tip==4){//cena - ElektronskiKoncert
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
    }
    else if (tip==5) {//najskapKoncert

    }
    else if (tip==6) {//prebarajKoncert
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        najskapKoncert(koncerti,5);
    }
    else if (tip==7){//prebaraj
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        bool elektronski;
        cin>>elektronski;
        if(prebarajKoncert(koncerti,5, "Area",elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

        if(prebarajKoncert(koncerti,5, "Area",!elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

    }
    else if (tip==8){//smeni cena
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[2] -> setSezonskiPopust(0.9);
        najskapKoncert(koncerti,4);
    }

    return 0;
}
