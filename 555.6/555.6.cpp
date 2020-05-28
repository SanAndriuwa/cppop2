#include <iostream>
using namespace std;
class Atlikejas
{
	private:
		int x,y,z,t;
		int balansas;
	public:
		Atlikejas(int a,int b,int c,int d)
		{
			x=a;
			y=b;
			z=c;
			t=d;
		}	
		void operator--()
		{
			balansas=x;
			balansas-=(y+z);
		}
		bool operator*()
		{
			if((double)balansas*0.01>=0.66)
			{
				return true;
			}
			else return false;
		}
		int outB()
		{
			return balansas;
		}
		int outT()
		{
			return t;
		}
		void outData()
		{
			cout<<x<<ends<<y<<ends<<z<<ends<<t;
		}
		Atlikejas* operator+(Atlikejas* obj2)
		{
			return new Atlikejas(this->x+obj2->x,this->y+obj2->y,this->z+obj2->z,this->t+obj2->t);
		}
};
int main()
{
	int n;
	cin>>n;
	Atlikejas** atlikejas=new Atlikejas*[n];
	for(int i=0;i<n;i++)
	{
		int x,y,z,t;
		cin>>x>>y>>z>>t;
		atlikejas[i]=new Atlikejas(x,y,z,t);
	}
	for(int i=0;i<n;i++)
	{
		atlikejas[i]->operator--();
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" atlikejo balanasas yra ";
		if(atlikejas[i]->outB()>0)
		{
			cout<<"+"<<atlikejas[i]->outB()<<endl;
		}
		else cout<<atlikejas[i]->outB()<<endl;
	}
	if(atlikejas[0]->operator*())
	{
		cout<<"Pirmas dalyvis gales megautis kebabu"<<endl;
	}
	else cout<<"Pirmam dalyviui teks apseiti be kebabo"<<endl;
	Atlikejas* temp=atlikejas[1]->operator+(atlikejas[n-1]);
	temp->operator--();
	cout<<"Antro ir paskutinio balansas po pergales butu "; 
	if(temp->outB()+temp->outT()>0)
		{
			cout<<"+"<<temp->outB()+temp->outT()<<endl;
		}
	else cout<<temp->outB()+temp->outT()<<endl;
}
