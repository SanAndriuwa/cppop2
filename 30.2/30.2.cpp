#include <iostream>
using namespace std;
class Laikas
{
	private:
		int h,m,s;
	public:
		void getData(int a, int b, int c)
		{
			h=a;
			m=b;
			s=c;
		}	
		void conv()
		{
			s+=m*60+h*60*60;
			h=0;
			m=0;
		}
		int outS()
		{
			return s;	
		}
		void operator+(int val)
		{
			int temp;
			s=s+val;
			if(s/3600<10)
			{
				cout<<"0";
			}
			cout<<s/3600<<":";
			temp=s/3600;
			s=s-temp*3600;
			if(s/60<10)
			{
				cout<<"0";
			}
			cout<<s/60<<":";
			temp=s/60;
			s=s-temp*60;
			if(s<10)
			{
				cout<<"0";
			}
			cout<<s;
		}
};
int main()
{
	int n;
	cin>>n;
	Laikas** laikas=new Laikas*[n];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		laikas[i]=new Laikas();
		laikas[i]->getData(a,b,c);
		laikas[i]->conv();
	}
	int max1;
	int max2;
	int imax1=0;
	int imax2=1;
	max1=laikas[0]->outS();
	max2=laikas[1]->outS();
	if(max1<max2)
	{
		int temp=max2;
		max2=max1;
		max1=temp;
		imax1=imax2;
		imax2=0;
	}
	for(int i=0;i<n;i++)
	{
		if(laikas[i]->outS()>max1 && laikas[i]->outS()>max2)
		{
			max2=max1;
			imax2=imax1;
			max1=laikas[i]->outS();
			imax1=i;
		}
		else if(laikas[i]->outS()<max1 && laikas[i]->outS()>max2)
		{
			max2=laikas[i]->outS();
			imax2=i;
		}
	}
	laikas[imax1]->operator+(laikas[imax2]->outS());
}
