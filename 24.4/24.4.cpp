#include <iostream>
#include <iomanip>
using namespace std;
class Bitininkas
{
	private:
		int aviliai;
		int bites;
		int statines;
		unsigned int count;
		double pelnas;
	public:
		Bitininkas(int a,int b,int c, int d,int e)
		{
			aviliai=a;
			bites=b;
			statines=c;
			count=d;
     		pelnas=e;
		}
    int outA()
    {
      return aviliai;
    }
    int outB()
    {
      return bites;
    }
		unsigned int outCount()
		{
			return count;
		}
		double outPelnas()
		{
			return pelnas;
		}
		void operator++()
		{
			++count;
		}
		double operator*()
		{
			if(count==0 || bites-count*1000<1000)
			{
				pelnas=statines*2;
			}
			else pelnas=statines*2-(bites-count*1000)*0.03;
      return 0;
		}
		double operator-=(double val)
		{
			val-=666;
      return val;
		}
    Bitininkas* operator+(Bitininkas* obj2)
		{
			return new Bitininkas(this->aviliai+obj2->aviliai,this->bites+obj2->bites,this->statines+obj2->statines,0,this->pelnas+obj2->pelnas);
		}
		void outData()
    {
      cout<<aviliai<<" "<<bites<<" "<<statines<<" "<<count<<endl;
    }
    double hlpme()
		{
			if(count==0 || bites-count*1000<1000||count==aviliai)
			{
				pelnas=statines*2;
			}
			else pelnas=statines*2-(bites-count*1000)*0.03;
      return 0;
		}
};
int main()
{
	int n;
	cin>>n;
	Bitininkas** medved=new Bitininkas*[n];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		medved[i]=new Bitininkas(a,b,c,0,0);
		while(b>=1000&&a>0)
		{
			b=b-1000;
			a--;
			medved[i]->operator++();
		}
		medved[i]->operator*();
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" bitininko pilnu aviliu kiekis: "<<medved[i]->outCount()<<endl;
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" bitininko pelnas: "<<fixed<<setprecision(2)<<medved[i]->outPelnas()<<"e"<<endl;
	}
  if(medved[n-1]->outPelnas()<0)
  {
    cout<<"Paskutinis taip ar taip jau bankrutaves."<<endl;
  }
	else if(medved[n-1]->operator-=(medved[n-1]->outPelnas())>0)
	{
		cout<<"Bauda paskutinio bitininko negasdina."<<endl;
	}
	else cout<<"Po baudos paskutinis bitininkas bankrutuos."<<endl;
  Bitininkas* temp=medved[0]->operator+(medved[n-1]);
  int a=temp->outA();
  int b=temp->outB();
  while(b>=1000&&a>0)
		{
			b=b-1000;
			a--;
			temp->operator++();
		}
  if(n==2)
  {
    cout<<"Paskutinis kartu su pirmu udirbtu: "<<temp->outPelnas()-666<<"e.";
  }
  else 
  {
	temp->hlpme();
	cout<<"Paskutinis kartu su pirmu udirbtu: "<<temp->outPelnas()-666<<"e.";
  }
  
}
