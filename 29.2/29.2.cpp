#include <iostream>
using namespace std;
class Zuikis
{
	private:
		int pa,ra,d;
		int efektyvumas;
	public:
		void getData(int a,int b,int c)
		{
			pa=a;
			ra=b;
			d=c;
		}
		void outData()
		{
			cout<<" zuikis paslepe "<<pa<<", buvo rasti "<<ra<<" ir "<<d<<" duzo iskart."<<endl;
		}
		void eOut()
		{
			cout<<" zuikio efektyvumas yra "<<efektyvumas<<"."<<endl;
		}
		void operator!()
		{
			efektyvumas=pa-d;
		}
};
class Counter
{
	private:
		unsigned int count;
	public:
		Counter():count(3){}
		~Counter(){}
		unsigned int getCount()
		{
			return count;	
		}
		void operator--()
		{
			--count;
		}
};
int main()
{
	int n=3;
	Zuikis** zuikis=new Zuikis*[n];
	Counter* counter=new Counter();
	int i=0;
	while(counter->getCount()>1)
	{
		int a,b,c;
		cin>>a>>b>>c;
		zuikis[i]=new Zuikis();
		zuikis[i]->getData(a,b,c);
		i++;
		--counter;
	}
	counter=new Counter();
	i=0;
	while(counter->getCount()>0)
	{
		cout<<i+1;
		zuikis[i]->outData();
		i++;
		--counter;
	}
	counter=new Counter();
	i=0;
	while(counter->getCount()>0)
	{
		cout<<i+1;
		zuikis[i]->operator!();
		zuikis[i]->eOut();
		i++;
		--counter;
	}
}
