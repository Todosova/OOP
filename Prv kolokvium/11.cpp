/*
Да се дефинира класа Ucesnik за учесник во маратон за кој ќе се чуваат информации за:

име (динамички алоцирана низа од знаци)
пол (bool)
возраст (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)

Дополнително за оваа класа да се преоптоварат:

оператор за споредување > (споредува двајца учесници според возраста) (5 поени)
операторот за проследување на излезен тек << кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред. (5 поени)
Да се дефинира класа Maraton за кој се чуваат:

локација (низа од максимум 100 знаци)
низа од Ucesnik објекти (динмички алоцирана низа од објекти од класата Ucesnik)
број на учесници (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени) Исто така да се имплементираат следните методи:

оператор += за додавање нов Ucesnik на маратонот Maraton. (10 поени)
prosecnoVozrast() вреќа просечена возраст на учесниците на маратонот (5 поени)
pecatiPomladi(Ucesnik &u) ги печати сите учесници помлади од учесникот проследен како аргумент на методот. (5 поени)
*/
#include <iostream>
#include <cstring>
using namespace std;
class Ucesnik{
	private:
		char *ime;
		bool pol;
		int vozrast;
	public:

	Ucesnik(char *ime="",bool pol=false,int vozrast=0){
		this->ime=new char[strlen(ime)+1];
		strcpy(this->ime,ime);
		this->pol=pol;
		this->vozrast=vozrast;
	}
	Ucesnik(const Ucesnik &u){
		this->ime=new char[strlen(u.ime)+1];
		strcpy(this->ime,u.ime);
		this->pol=u.pol;
		this->vozrast=u.vozrast;
	}
	Ucesnik& operator=(const Ucesnik &u){
		if(this!=&u){
		this->ime=new char[strlen(u.ime)+1];
		strcpy(this->ime,u.ime);
		this->pol=u.pol;
		this->vozrast=u.vozrast;
	}
	return *this;
	}
	~Ucesnik(){
		delete [] ime;
	}
	bool operator>(const Ucesnik &u){
		if(this->vozrast>u.vozrast){
			return true;
		}
		else{
			return false;
		}
	}
	friend ostream &operator<<(ostream &pecati,const Ucesnik &u){
		pecati<<u.ime<<endl;
		if(u.pol==true){
			pecati<<"mashki"<<endl;
		}
		else{
			pecati<<"zhenski"<<endl;
		}
		pecati<<u.vozrast<<endl;
		return pecati;
	}
	int getVozdrast(){
		return vozrast;
	}
};
class Maraton{
	private:
	char lokacija[100];
	Ucesnik *ucenik;
	int broj;
	public:
		Maraton (){
			strcpy(this->lokacija,"");
			this->ucenik=new Ucesnik[0];
			this->broj=0;
		}
		Maraton(char *lokacija){
			strcpy(this->lokacija,lokacija);
			this->ucenik=new Ucesnik[0];
			this->broj=0;
		}
			Maraton(const Maraton &m){
			strcpy(this->lokacija,m.lokacija);
				this->broj=m.broj;
			this->ucenik=new Ucesnik[m.broj];
			for(int i=0;i<m.broj;i++){
				this->ucenik[i]=m.ucenik[i];
			}
		}
			Maraton& operator=(const Maraton &m){
				if(this!=&m){
			strcpy(this->lokacija,m.lokacija);
				this->broj=m.broj;
			this->ucenik=new Ucesnik[m.broj];
			for(int i=0;i<m.broj;i++){
				this->ucenik[i]=m.ucenik[i];
			}
		}
		return *this;
		}
			Maraton& operator+=(const Ucesnik &u){
			Ucesnik *temp=new Ucesnik[broj+1];
			for(int i=0;i<broj;i++){
				temp[i]=ucenik[i];
			}
			temp[broj++]=u;
			delete [] ucenik;
			ucenik=temp;
			return *this;
		}
	float prosecnoVozrast(){
			float zbir=0;
			for(int i=0;i<broj;i++){
				zbir+=ucenik[i].getVozdrast();
			}
			return zbir/broj;
		}
	void pecatiPomladi(Ucesnik &u){
			for(int i=0;i<broj;i++){
				if(ucenik[i].getVozdrast()<u.getVozdrast()){
					cout<<ucenik[i];
				}
			}
	}
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
	return 0;
}
