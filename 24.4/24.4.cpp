#include <iostream>
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
		void getData(int a,int b,int c,unsigned int d)
		{
			aviliai=a;
			bites=b;
			statines=c;
			count=d;
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
			if(count==0)
			{
				pelnas=statines*2;
			}
			else pelnas=statines*2-(bites-count*1000)*0.03;
		}
		double operator-=(double val)
		{
			val-=666;
			return val;
		}
		double operator+(double a)
		{
			return pelnas+a;
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
		medved[i]=new Bitininkas;
		medved[i]->getData(a,b,c,0);
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
		cout<<i+1<<" bitininko pilnu aviiu kiekis: "<<medved[i]->outCount()<<endl;
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" bitininko pelnas: "<<medved[i]->outPelnas()<<endl;
	}
	if(medved[n-1]->operator-=(medved[n-1]->outPelnas())>0)
	{
		cout<<"Bauda paskutinio bitininko negasdina"<<endl;
	}
	else cout<<"Po baudos paskutinis bitininkas bankrutuos."<<endl;
	cout<<"Paskutinis kartu su primu uzdirbtu: "<<medved[0]->operator+(medved[n-1]->operator-=(medved[n-1]->outPelnas()));
}
