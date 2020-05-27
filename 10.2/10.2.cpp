#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Trikampis
{
	protected:
		int a,b,c;
	public:
		Trikampis()
		{
		}
		void setData(int a1,int b1,int c1)
		{
			a=a1;
			b=b1;
			c=c1;
		}
		double S()
		{
			double p;
    		p=(double)(a+b+c)/2;
    		return (double)sqrt(p*(p-a)*(p-b)*(p-c));
		}
		int P()
		{
			return a+b+c;
		}
		
};
class Apskritimas:public Trikampis
{
	public:
		double aS()
		{
			double pi=355./113.;
			return (double)pi*(c/2)*(c/2);
		}
		double aP()
		{
			double pi=355./113.;
			return (double)c*pi;
		}
};
int main()
{
	int n;
	cin>>n;
	int maxTP=0;
	double maxTS=0;
	double maxAP=0;
	double maxAS=0;
	int maxr=0;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		Trikampis t;
		t.setData(a,b,c);
		if(t.P()>maxTP)
		{
			maxTP=t.P();
			maxTS=t.S();
		}
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		Apskritimas aps;
		aps.setData(a,b,c);
		if(c>maxr)
		{
			maxr=c;
			maxAP=aps.aP();
			maxAS=aps.aS();
		}
	}
	if(maxTP>maxAP)
	{
		cout<<fixed<<setprecision(2)<<maxTS;
	}
	else cout<<fixed<<setprecision(2)<<maxAS;
}
