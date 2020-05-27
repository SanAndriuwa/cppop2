#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Zvejas
{
	protected:
		int A,B,K,L;
	public:
		void getData(int a,int b,int c,int d)
		{
			this->A=a;
			this->B=b;
			this->K=c;
			this->L=d;
		}
		double TS()
		{
			double S;
			S=(double)B/4*sqrt(4*(A*A)-(B*B));
			return S;
		}
		int bauda()
		{
			int k=0;
			double S;
			S=(double)B/4*sqrt(4*(A*A)-(B*B));
			if((K+L)/S>5 || L/S>2)
			{
				cout<<endl;
				cout<<A<<ends<<B<<ends<<K<<ends<<L<<endl;
				k=(K+L)/S;
				return k*666;
			}
			else return 0;
		}
};
class Ukininkas:public Zvejas
{
	public:
		int ubauda()
		{
			int k=0;
			double S=A*B/2;
			double P=sqrt(((A/2)*(A/2))+((B/2)*(B/2)))*4;
			if(S<P && L>K*3)
			{
				k=L+K;
				return k*66;
			}
			return 0;
		}
		double US()
		{
			return (double)A*B/2;
		}
};
int main()
{
	int n,m;
	double max1=0;
	double max2=0;
	short imax1=0,imax2=0;
	int bauda=0;
	cin>>n;
	Zvejas** zvejas=new Zvejas*[n];
	short um=0;
	short zm=0;
	for(int i=0;i<n;i++)
	{
		zvejas[i]=new Zvejas();
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		zvejas[i]->getData(a,b,c,d);
		bauda+=zvejas[i]->bauda();
		if(zvejas[i]->bauda()==0)
		{
			if(max1<(zvejas[i]->TS()))
			{
				max1=zvejas[i]->TS();
				imax1=i;
			}
		}
	}
	cin>>m;
	Ukininkas** ukininkas=new Ukininkas*[m];
	for(int i=0;i<m;i++)
	{
		ukininkas[i]=new Ukininkas();
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		ukininkas[i]->getData(a,b,c,d);
		bauda+=ukininkas[i]->ubauda();
		if(ukininkas[i]->ubauda()==0)
		{
			if(max2<ukininkas[i]->US())
			{
				max2=ukininkas[i]->US();
				imax2=i;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" zvejo tvenkinio plotas "<<fixed<<setprecision(2)<<zvejas[i]->TS()<<endl;
	}
	for(int i=0;i<m;i++)
	{
		cout<<i+1<<" ukininko lauko plotas "<<fixed<<setprecision(2)<<ukininkas[i]->US()<<endl;
	}
	cout<<"Gyventoju gautos baudos suma: "<<bauda<<endl;
	if(max1==0&&max2==0)
	{
		
	}
	else
	{
		if(max1>max2)
		{
			cout<<imax1+1<<" zvejas taps milijonieriumi";
		}
		else cout<<imax2+1<<" ukininkas taps milijonieriumi";
	}
	for(int i=0;i<m;i++)
	{
		cout<<endl;
		
	}
}
