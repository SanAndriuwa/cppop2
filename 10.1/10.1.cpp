#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Staciakampis
{
	protected:
		int a,b;
	public:
		Staciakampis()
		{
		}
		void setData(int a1,int b1)
		{
			a=a1;
			b=b1;
		}
		int S()
		{
			return a*b;
		}
		
};
class Elipse:public Staciakampis
{
	public:
		double eS()
		{
			double pi=355./113.;
			return (double)a*b*pi;
		}
};
int main()
{
	int n;
	cin>>n;
	int max1=0;
	double max2=0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		Staciakampis s;
		s.setData(a,b);
		if(s.S()>max1)
		{
			max1=s.S();
		}
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		Elipse e;
		e.setData(a,b);
		if(e.eS()>max2)
		{
			max2=e.eS();
		}
	}
	if(max1>max2)
	{
		cout<<"Didziausia figura staciakampis"<<endl<<"Plotas"<<ends<<max1;
	}
	else cout<<"Didziausia figura elipse"<<endl<<"Plotas"<<ends<<max2;
}
