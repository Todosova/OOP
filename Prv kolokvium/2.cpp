/*Да се имплементира класа List во којашто ќе се чуваат информации за:

броеви што се дел од листата (динамички алоцирана низа од цели броеви)
бројот на броеви што се дел од листата
За класата да се дефинираат следните методи:

конструктор (со аргументи), copy-конструктор, деструктор, оператор =
void pecati()метод што ќе ги печати информациите за листата во форматот: [број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]
int sum() метод што ја враќа сумата на елементите во листата
double average() метод што ќе го враќа просекот на броевите во листата
Дополнително, креирајте класата ListContainer, во која што ќе се чуваат информации за:

низа од листи (динамички алоцирана низа од објекти од класата List)
број на елементи во низата од листи (цел број)
број на обиди за додавање на листа во контејнерот (цел број првично поставен на нула)
За класата потребно е да ги дефинирате следните методи:

конструктор (default), copy-конструктор, деструктор, оператор =
void pecati() метод што ќе ги печати информациите за контејнерот во форматот: List number: [реден број на листата] List info: [испечатени информации за листата со методот List::pecati()] \n sum: [сума] average: [просек]
доколку контејнерот е празен се печати само порака The list is empty.
void addNewList(List l) метод со којшто се додава листа во контејнерот
Напомена: една листа се додава во контејнерот ако и само ако има различна сума од сите листи што се веќе додадени во контејнерот
int sum() метод што ја враќа сумата на сите елементи во сите листи
double average() метод што го враќа просекот на сите елементи во сите листи во контејнерот*/

#include<iostream>
#include<cstring>
using namespace std;
class List{
    private:
    int *niza;
    int n;
    public:
    List()
    {
        this->niza=new int[n];
        this->n=0;
    }
    List (int *niza,int n)
    {
        this->niza=new int[n];
        this->n=n;
        for(int i=0;i<n;i++)
        {
            this->niza[i]=niza[i];
        }
    }
    List (const List &l)
    {
        this->niza=new int[l.n];
        this->n=l.n;
        for(int i=0;i<l.n;i++)
        {
            this->niza[i]=l.niza[i];
        }
    }
        List &operator= (const List &l)
    {
        if(this!=&l)
        {
        this->niza=new int[l.n];
        this->n=l.n;
        for(int i=0;i<l.n;i++)
        {
            this->niza[i]=l.niza[i];
        }
        } return *this;
    }
    ~List ()
    {
        delete [] niza;
    }
    int sum()
    {
        int suma=0;
        for(int i=0;i<n;i++)
        {
            suma=suma+niza[i];
        }
        return suma;
    }
    double average()
    {
        float prosek=0;
        for(int i=0;i<n;i++)
        {
            prosek=(float) sum()/n;
        }
        return prosek;
    }
       void pecati()
        {
               cout<<n<<":";
            for(int i=0;i<n;i++)
            {
                cout<<" ";
            cout<<niza[i];
            }
            cout<<" sum: "<<sum()<<" average: "<<average()<<endl;
        }
        int getn()
        {
            return n;
        }
};
class ListContainer
{
  private:
  List *lc;
  int N;
  int brobidi;
  public:
  ListContainer()
  {
      this->lc=new List[N];
      this->N=0;
      this->brobidi=0;
  }
  ListContainer( List *lc, int N,int brobidi)
  {
      this->lc=new List [N];
      this->N=N;
      this->brobidi=brobidi;
      for(int i=0;i<N;i++)
      {
          this->lc[i]=lc[i];
      }
  }
    ListContainer( const ListContainer &lcc )
  {
      this->lc=new List [N];
      this->N=lcc.N;
      this->brobidi=lcc.brobidi;
      for(int i=0;i<lcc.N;i++)
      {
          this->lc[i]=lcc.lc[i];
      }
  }
      ListContainer &operator =( const ListContainer &lcc )
  {
      if(this!=&lcc)
      {
      this->lc=new List [lcc.N];
      this->N=lcc.N;
      this->brobidi=lcc.brobidi;
      for(int i=0;i<lcc.N;i++)
      {
          this->lc[i]=lcc.lc[i];
      }
      }
      return *this;
  }
  ~ListContainer()
  {
      delete [] lc;
  }
 int sum()
        {
            int suma=0;
            for(int i=0;i<N;i++)
            {
                suma=suma+lc[i].sum();
            }
            return suma;
        }
        double average()
        {
            float prosek=0;
            int zbir=0;
            for(int i=0;i<N;i++)
            {
                zbir=zbir+lc[i].getn();
            }
            prosek=(float)sum()/zbir;
            return prosek;
        }
           void addNewList(List list)
    {
    	brobidi++;
    	for(int i=0;i<N;i++)
        {
        if(list.sum()==lc[i].sum()){
        	return;
			}
        }
        List *temp=new List[N+1];
        for(int i=0;i<N;i++)
        {
            temp[i]=lc[i];
        }
        temp[N++]=list;
        delete [] lc;
        lc=temp;
    }
        void print()
    {
            if(brobidi==0)
            {
    		cout<<"The list is empty"<<endl;
    		return;
		    }
		else
		{
            for(int i=0;i<N;i++)
            {
            cout<<"List number: "<<i+1<<" List info: ";
            lc[i].pecati();
            }
        }
        cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
        cout<<"Successful attempts: "<<N <<" Failed attempts: "<<brobidi-N<<endl;
    }
};
int main() {

	ListContainer lc;
	int N;
	cin>>N;

	for (int i=0;i<N;i++) {
		int n;
		int niza[100];

		cin>>n;

		for (int j=0;j<n;j++){
			cin>>niza[j];

		}

		List l=List(niza,n);

		lc.addNewList(l);
	}


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}
