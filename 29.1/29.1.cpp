#include <iostream>
using namespace std;
class Zuikis
{
	private:
		unsigned int a,b,c;
	public:
		Zuikis(unsigned int a,unsigned int b,unsigned int c)
		{
			this->a=a;
			this->b=b;
			this->c=c;
		}
		unsigned int aO()
		{
			return a;
		}
		unsigned int bO()
		{
			return b;
		}
		unsigned int cO()
		{
			return c;
		}
};
int main()
{
	short k=0;
	short n=3;
	Zuikis** zuikis=new Zuikis*[n];
	for(int i=3;i>0;i--)
	{
		unsigned int a,b,c;
		cin>>a>>b>>c;
		zuikis[k]=new Zuikis(a,b,c);
		k++;
	}
	k=0;
	for(int i=3;i>0;i--)
	{
		cout<<k+1<<" zuikis paslepe "<<zuikis[k]->aO()<<", buvo rasti "<<zuikis[k]->bO()<<" ir "<<zuikis[k]->cO()<<" duzo iskart"<<endl;
		k++;
	}
}
