#include <iostream>
#include <cmath>
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
		int operator-(Laikas* obj2)
		{
			if(this->s-obj2->s>=86400)
			{
				return abs((this->s-obj2->s-86400));
			}
			else if(this->s-obj2->s<0)
			{
				return this->s-obj2->s+86400;
			}
			else return abs(this->s-obj2->s);
		}
};
void outTime(int val)
		{
			int temp;
			if(val/3600<10)
			{
				cout<<"0";
			}
			cout<<val/3600<<":";
			temp=val/3600;
			val=val-temp*3600;
			if(val/60<10)
			{
				cout<<"0";
			}
			cout<<val/60<<":";
			temp=val/60;
			val=val-temp*60;
			if(val<10)
			{
				cout<<"0";
			}
			cout<<val;
		}
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
	int min=86400;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(laikas[i]->operator-(laikas[j])<min)
			{
				min=laikas[i]->operator-(laikas[j]);
			}
			if(laikas[j]->operator-(laikas[i])<min)
			{
				min=laikas[j]->operator-(laikas[i]);
			}
		}
	}
	outTime(min);
}
