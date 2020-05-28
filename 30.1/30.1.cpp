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
		void operator/(int val)
		{
			int temp;
			val=val/3;
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
			s=s/3;
		}
};
int main()
{
	int n;
	cin>>n;
	Laikas laikas;
	int a,b,c;
	cin>>a>>b>>c;
	laikas.getData(a,b,c);
	laikas.conv();
	for(int i=0;i<n;i++)
	{
		laikas.operator/(laikas.outS());
		if(i!=n-1)
		{
			cout<<endl;
		}
	}
}
