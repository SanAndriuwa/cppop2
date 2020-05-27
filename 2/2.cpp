#include <iostream>
#include <cmath>
using namespace std;
class Skritulys
{
	private:
		long int x,y,d;
	public:
		Skritulys(long int x,long int y,long int d)
		{
			this->x=x;
			this->y=y;
			this->d=d;
		}
		bool arPriklauso()
		{
			double r=(double)d/2;
			double a=(double)sqrt(x*x+y*y);
			if(abs(x)<=r||abs(y)<=r)
			{
				return true;
			}
			else return false;
		}
		
};
class Counter
{
	private:
		unsigned int count;	
	public:
		Counter():count(0){}
		void operator ++()
		{
			++count;
		}	
		unsigned int returnCount()
		{
			return count;
		}
};
int main()
{
	Counter c1;
	int n;
	cin>>n;
	Skritulys** skritulys=new Skritulys*[n];
	while(c1.returnCount()<n)
	{
		long int x,y,d;
		cin>>x>>y>>d;
		skritulys[c1.returnCount()]=new Skritulys(x,y,d);
		++c1;
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(skritulys[i]->arPriklauso())
		{
			k++;
		}
	}
	cout<<k;
}
