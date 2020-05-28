#include <iostream>
using namespace std;
class Zuikis
{
	private:
		int pa,ra,d;
		int efektyvumas;
	public:
		Zuikis(int a,int b,int c)
		{
			pa=a;
			ra=b;
			d=c;
		}
		void outData()
		{
			cout<<" zuikis paslepe "<<pa<<", buvo rasti "<<ra<<" ir "<<d<<" dužo iškart."<<endl;
		}
		void eOut()
		{
			cout<<" zuikio efektyvumas yra "<<efektyvumas<<"."<<endl;
		}
		void operator!()
		{
			efektyvumas=pa-d;
		}
		bool operator*()
		{
			if(pa*2<ra*2 || pa*2<d*2 || ra*2<d*2)
			{
				return true;
			}
			else return false;
		}
		Zuikis* operator+(Zuikis* obj2)
		{
			return new Zuikis(this->pa+obj2->pa,this->ra+obj2->ra,this->d+obj2->d);
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
		zuikis[i]=new Zuikis(a,b,c);
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
	if(zuikis[2]->operator*())
	{
		cout<<"Ievutei išsiustas šaukimas i teisma."<<endl;
		Zuikis* temp=zuikis[2]->operator+(zuikis[0]);
		if(temp->operator*())
		{
			cout<<"Algelis neišgelbetu Ievutes.";
		}
		else cout<<"Algelio deka Ievute išteisinta.";
	}
	else 
	{
		cout<<"Ievute nesukciavo.";
	}
}
