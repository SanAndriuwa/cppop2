#include <iostream>
#include <cmath>
using namespace std;
class Sgabalas
{
	protected:
		int a;
		int b;
	public:
		Sgabalas(int a,int b)
		{
			this->a=a;
			this->b=b;
		}
		bool arPavyks(int A,int B)
		{
			int min;
			if(a>b)
			{
				min=b;
			}
			else min=a;
			
			if(min<=(double)sqrt(A*A+B*B))
			{
				return true;
			}
			else return false;
		}	
};
int main()
{
	int A,B;
	cin>>A>>B;
	int n;
	cin>>n;
	Sgabalas** gabalas=new Sgabalas*[n];
	int k=0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		gabalas[i]=new Sgabalas(a,b);
		if(gabalas[i]->arPavyks(A,B))
		{
			k++;
		}
	}
	cout<<k;
}
