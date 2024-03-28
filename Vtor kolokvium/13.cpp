/*Да се креира класа која претставува слика (Image) во рамките на еден компјутер. За секоја датотека се чуваат (5 поени):

име на сликата (дин. алоцирана низа од знаци). Предефинирано поставено на untitled.
име на корисникот кој е сопственик на датотеката (низа од макс. 50 знаци). Предефинирано поставено на unknown.
димензии на сликата (2 цели броеви кои претставуваат ширина и висина во пиксели). Предефинирано поставени на 800.
Од класата Imageда се изведе класата TransparentImage, која претставува слика која содржи поддржува транспарентност. За транспарентна слика дополнително се чува :

дали поддржува нивоа на транспарентност (bool променлива, предефинирано не поддржува транспарентност).
За класите Image и TransparentImage да биде достапна метода (fileSize)за пресметка на големината на сликата (во бајти). Големината се пресметува на сл. начин (5 поени):

за објектите од класата Image, големината на датотеката е еднаква на:висината * ширината * 3.
за TransparentImage, доколку поддржува нивоа на транспарентност, големината на датотеката е еднаква на ширина * висина * 4. Доколку не поддржува транспарентност, големината на сликата се пресметува како ширина * висина + бр._на_пиксели_присутни_во_сликата / 8.
За класите Image и TransparentImage да се преоптоварат следниве оператори (5 поени):

оператор << кој ги печати податоците од датотеката во сл. формат:

ime_fajl avtor golemina_na_fajlot_vo_bajti

оператор > кој ги споредува сликите според нивната големина.

Да се дефинира класа Folder, што репрезентира директориум во кој може да се поставуваат слики. За секој фолдер се чува (5 поени):

име на фолдерот (низа од макс 255 знаци)
име на корисникот кој е сопственик на фолдерот (низа од макс. 50 знаци). Предефинирано поставено на unknown.
низа од покажувачи кон Image објекти (макс. 100 во рамките на еден фолдер).
Да се имплементираат следниве методи (5 поени):

метода за пресметка на големината на фолдерот (folderSize). Големината на фолдерот е сума од големините од сите слики во рамките на фолдерот.

метода за пронаоѓање на наголемата слика во рамките на фолдерот (getMaxFile). Методата враќа покажувач кон најголемата слика во фолдерот
(сметано во бајти).

За класата Folder да се имплементира и оператор += кој додава објекти од типот Image/TransparentImage во рамките на фолдерот (5 поени).

Да се креираат следниве функционалности за класите (5 поени):

operator << - со кој се печатат податоците за фолдерот во формат (5 поени):

ime_folder sopstvenik --

imeslika avtor goleminanafajlotvo_bajti
imeslika avtor goleminanafajlotvobajti -- goleminanafoldervo_bajti
operator [] - кој враќа покажувач кон соодветната слика во фолдерот. Доколку не постои слика на тој индекс, треба да се врати NULL (5 поени).

Да се креира и глобална функција max_folder_size која го прима низа од објекти од типот Folder и го враќа фолдерот кој има зафаќа најмногу простор
(во бајти). (5 поени)

Да се овозможи правилно функционирање на класите (потребни set или get методи/оператори/конструктори/деструктори) според изворниот код кој е веќе
зададен. Сите податочни членови на класите се protected. (5 поени)*/


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
class  Image{
protected:
    char *ime;
    char imekorisnik[50];
    int sirina,visina;
    public:
    	/*
	Image(){
		this->visina=800;
		this->shirina=800;
		this->imeslika=new char[0];
		strcpy(this->imeslika,"untitled");
		strcpy(this->ime,"unknown");
	}
	Image(char *imeslika){
		this->visina=800;
		this->shirina=800;
		this->imeslika=new char[strlen(imeslika)+1];
		strcpy(this->imeslika,imeslika);
		strcpy(this->ime,"unknown");
	}
	Image(char *imeslika,char *ime){
	    this->visina=800;
		this->shirina=800;
		this->imeslika=new char[strlen(imeslika)+1];
		strcpy(this->imeslika,imeslika);
		strcpy(this->ime,ime);
	}
	*/
    Image(char *ime="untitled",char *imekorisnik="unknown",int sirina=800,int visina=800){
        this->ime=new char [strlen(ime)+1];
        strcpy(this->ime,ime);
        strcpy(this->imekorisnik,imekorisnik);
        this->sirina=sirina;
        this->visina=visina;
   }
    Image(const Image &m){
        this->ime=new char [strlen(m.ime)+1];
        strcpy(this->ime,m.ime);
        strcpy(this->imekorisnik,m.imekorisnik);
        this->sirina=m.sirina;
        this->visina=m.visina;

    }
    Image &operator=(const Image &m){
        if(this!=&m){
        this->ime=new char [strlen(m.ime)+1];
        strcpy(this->ime,m.ime);
        strcpy(this->imekorisnik,m.imekorisnik);
        this->sirina=m.sirina;
        this->visina=m.visina;
        }
        return *this;

    }
    virtual int  fileSize(){
        return visina*sirina*3;
    }
    char *getIme(){
    return ime;
    }
    char *getKorisnik(){
    return imekorisnik;
    }
    friend ostream &operator<<(ostream &izlez,Image &m){
        izlez<<m.ime<<" "<<m.imekorisnik<<" "<<m.fileSize()<<endl;
        return izlez;
    }
    bool operator>(Image &m){
        if(fileSize()>m.fileSize()){
        return true;
        }
        return false;
    }

};

class TransparentImage:public Image{
private:
    bool vidliva;
public:

    TransparentImage(char *ime="untitled",char *imekorisnik="unknown",int sirina=800,int visina=800,bool vidliva=true):Image(ime,imekorisnik,sirina,visina){
        this->vidliva=vidliva;
    }
    TransparentImage(const TransparentImage &m):Image(m){
    this->vidliva=m.vidliva;
    }

    int  fileSize(){

      if(vidliva==true){
          return (sirina*visina)*4;

        }
        else{

          return (sirina*visina)+((sirina*visina)/8);
        }
    }
     friend ostream &operator<<(ostream &izlez,TransparentImage &m){
        izlez<<m.ime<<" "<<m.imekorisnik<<" "<<m.fileSize()<<endl;
        return izlez;
    }
      bool operator>(TransparentImage &m){
        if(fileSize()>m.fileSize()){
        return true;
        }
        return false;
    }
};

class Folder{
private:
    char imefolder[255];
    char imekorisnik[50];
    Image **imag;
    int br;
public:
    Folder(char *imefolder="",char *imekorisnik=""){
        strcpy(this->imefolder,imefolder);
        strcpy(this->imekorisnik,imekorisnik);
        this->imag=new Image *[0];
        this->br=0;
    }
    Folder(const Folder &m){
        strcpy(this->imefolder,m.imefolder);
        strcpy(this->imekorisnik,m.imekorisnik);
        this->br=m.br;
        this->imag=new Image *[m.br+1];
        for(int i=0;i<m.br;i++)
        this->imag[i]=m.imag[i];

    }
    Folder &operator =(const Folder&m){
        if(this!=&m){
            strcpy(this->imefolder,m.imefolder);
        strcpy(this->imekorisnik,m.imekorisnik);
        this->br=m.br;
        this->imag=new Image *[m.br+1];
        for(int i=0;i<m.br;i++)
        this->imag[i]=m.imag[i];
        }
        return *this;
    }
    int folderSize(){
        int sum=0;
        for(int i=0;i<br;i++){
            sum+=imag[i]->fileSize();
        }
        return sum;
    }
    Image * getMaxFile(){
    int max=imag[0]->fileSize();
        int poz=0;
        for(int i=0;i<br;i++){
        if(imag[i]->fileSize()>max){
        max=imag[i]->fileSize();
            poz=i;
        }
        }
        return imag[poz];
    }
    Folder &operator+=(Image &m){
    Image **tmp=new Image *[br+1];
        for(int i=0;i<br;i++){
        tmp[i]=imag[i];
        }
        tmp[br]=&m;
        br++;
        delete [] imag;
        imag=tmp;
        return *this;
    }

    friend ostream &operator <<(ostream &izlez,Folder &m){

        izlez<<m.imefolder<<" "<<m.imekorisnik<<endl;
    izlez<<"--"<<endl;
        for(int i=0;i<m.br;i++){
        izlez<<m.imag[i]->getIme()<<" "<<m.imag[i]->getKorisnik()<<" "<<m.imag[i]->fileSize()<<endl;
        }
    izlez<<"--"<<endl;
    izlez<<"Folder size: "<<m.folderSize();
        return izlez;
    }
    Image * &operator[](int index)  {
    return this->imag[index];
   }


};

void max_folder_size(Folder *f,int n){
    int max=f[0].folderSize();
    int index=0;
    for(int i=0;i<n;i++){
        if(f[i].folderSize()>max){
        max=f[i].folderSize();
            index=i;
        }
    }
    cout<<f[index];
}



// TODO...

int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;
    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

     max_folder_size(dir_list, folders_num); //Ovde mora da se izbrise cout
    }
    return 0;
};

