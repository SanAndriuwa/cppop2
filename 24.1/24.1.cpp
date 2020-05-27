#include <iostream>
using namespace std;
class Bitininkas
{
	private:
		int aviliai;
		int bites;
		int statines;
		unsigned int count;
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
		void operator++()
		{
			++count;
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
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" bitininko pilnu aviiu kiekis: "<<medved[i]->outCount()<<endl;
	}
}
