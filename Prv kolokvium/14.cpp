/*
Потребно е да се имплементираат класи File (датотека) и Folder (директориум) за работа со едноставен податочен систем.

Во класата File треба да се чуваат следниве податоци:

Име на датотеката (динамички алоцирана низа од знаци)
Екстензија на датотеката (енумерација со можни вредности: txt, pdf, exe)
Име на сопственикот на датотеката (динамички алоцирана низа од знаци)
Големина на датотеката (цел број на мегабајти)
Дополнително, во класата потребно е да се напишат и:

Конструктор без параметри
Конструктор со параметри
Конструктор за копирање
Деструктор
Преоптоварување на операторот =
Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) - print()
Метод за проверка на еднаквост помеѓу две датотеки со потпис bool equals(const File & that) кој ќе враќа true ако датотеките имаат исто име, екстензија и сопственик
Метод за споредба на типот помеѓу две датотеки со потпис bool equalsType(const File & that) кој ќе враќа true ако датотеките се од ист тип, т.е. имаат исто име и екстензија
Во класата Folder треба да се чуваат следниве податоци:

Име на директориумот (динамички алоцирана низа од знаци)
Број на датотеки во него (на почеток директориумот е празен)
Динамички алоцирана низа од датотеки, објекти од класата File
Дополнително, во класата потребно е да се напишат и:

Конструктор со потпис Folder(const char* name)
Деструктор
Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на печатење) - print()
Метод за бришење на датотека од директориумот со потпис void remove(const File & file) кој ќе ја избрише првата датотека од директориумот која е еднаква според equals методот
Метод за додавање на датотека во директориумот со потпис void add(const File & file) кој ќе додава датотеката во директориумот
Не го менувајте почетниот код.
*/
#include<iostream>
#include<cstring>
using namespace std;
enum Extension {pdf, txt, exe};
class File{
  private:
  char *fileName;
  char *fileOwner;
  int fileSize;
  Extension ext;
  public:
  File()
  {
        this->fileName=new char[0];
        strcpy(this->fileName,"");
        this->fileOwner=new char[0];
        strcpy(this->fileOwner,"");
        this->fileSize=0;
        this->ext=(Extension)0;
  }
  File(char *fileName,char *fileOwner, int fileSize, Extension ext)
  {
        this->fileName=new char[strlen(fileName)+1];
        strcpy(this->fileName,fileName);
        this->fileOwner=new char[strlen(fileOwner)+1];
        strcpy(this->fileOwner,fileOwner);
        this->fileSize=fileSize;
        this->ext=ext;
  }
    File(const File &f)
  {
        this->fileName=new char[strlen(f.fileName)+1];
        strcpy(this->fileName,f.fileName);
        this->fileOwner=new char[strlen(f.fileOwner)+1];
        strcpy(this->fileOwner,f.fileOwner);
        this->fileSize=f.fileSize;
        this->ext=f.ext;
  }
      File &operator=(const File &f)
  {
      if(this!=&f)
      {
        this->fileName=new char[strlen(f.fileName)+1];
        strcpy(this->fileName,f.fileName);
        this->fileOwner=new char[strlen(f.fileOwner)+1];
        strcpy(this->fileOwner,f.fileOwner);
        this->fileSize=f.fileSize;
        this->ext=f.ext;
      }
      return *this;
  }
  ~File()
  {
      delete[] fileName;
      delete[] fileOwner;
  }
void ekst(Extension ext)
{
    if (ext==0)
    {
        cout<<".pdf"<<endl;
    }
    else if(ext==1)
    {
        cout<<".txt"<<endl;
    }
    else if(ext==2)
    {
        cout<<".exe"<<endl;
    }
}
void print()
{
    cout<<"File name: "<<fileName;
    ekst(ext);
    cout<<"File owner: "<<fileOwner<<endl;
    cout<<"File size: "<<fileSize<<endl;
}
bool equals(const File & that)
{
    if (strcmp(this->fileName,that.fileName)==0 && ext==that.ext && strcmp(this->fileOwner,that.fileOwner)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool equalsType(const File & that)
{
     if (strcmp(this->fileName,that.fileName)==0 && ext==that.ext )
    {
        return true;
    }
    else
    {
        return false;
    }
}
};
class Folder
{
  private:
  char *name;
  int brojach;
  File *file;
  public:
  Folder()
  {
      this->name=new char[0];
      strcpy(this->name,"");
      this->brojach=0;
      this->file=new File[brojach];
;
  }
    Folder(char *name, int brojach, File *file)
  {
      this->name=new char[strlen(name)+1];
      strcpy(this->name,name);
      this->brojach=brojach;
      this->file=new File[brojach];
      for(int i=0;i<brojach;i++)
      {
      this->file[i]=file[i];
      }
  }
      Folder(char *name)
  {
      this->name=new char[strlen(name)+1];
      strcpy(this->name,name);
      this->brojach=0;
      this->file=new File[brojach];
  }
      Folder(const Folder &ff)
  {
      this->name=new char[strlen(ff.name)+1];
      strcpy(this->name,ff.name);
      this->brojach=ff.brojach;
      this->file=new File[ff.brojach];
      for(int i=0;i<ff.brojach;i++)
      {
      this->file[i]=ff.file[i];
      }
  }
        Folder &operator=(const Folder &ff)
  {
      if(this!=&ff)
      {
      this->name=new char[strlen(ff.name)+1];
      strcpy(this->name,ff.name);
      this->brojach=ff.brojach;
      this->file=new File[ff.brojach];
      for(int i=0;i<ff.brojach;i++)
      {
      this->file[i]=ff.file[i];
      }
      }
      return *this;
  }
  ~Folder()
  {
      delete[]name;
      delete[]file;
  }
  void print()
  {
      cout<<"Folder name: "<<name<<endl;
      for(int i=0;i<brojach;i++)
      {
          this->file[i].print();
      }
  }
  void remove(const File & files)
  {
      int br=0;
        File *temp=new File[brojach-1];
        for(int i=0;i<brojach;i++)
        {
            if(file[i].equals(files) == 1)
            {
                continue;
            }
            else
            {
                temp[br++]=file[i];
            }
        }
        delete[]file;
        file=temp;
        brojach-=1;
  }
  void add(const File & files)
  {
       File *temp=new File[brojach+1];
        for(int i=0;i<brojach;i++)
        {
            temp[i]=file[i];
        }
        temp[brojach++]=files;
        delete[]file;
        file=temp;
  }
};
int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
