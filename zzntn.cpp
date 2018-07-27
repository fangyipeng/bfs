#include <iostream>
#include <queue>
using namespace std;
struct Q
{
	long long x;
	long long n;
};
bool G[10005];
int main()
{
	long long gs;
	cin>>gs;
	for(long long fg=0; fg<gs; fg++)
	{
		for(long long i=0; i<10005; i++)G[i]=true;
		queue<Q> open;
		long long r,h;
		cin>>r>>h;
		Q first;
		first.n=0;
		first.x=r;
		open.push(first);
		G[r]=0;
		while(!open.empty())
		{

			Q tis=open.front();
			open.pop();
			if(tis.x==h)
			{
				cout<<tis.n<<endl;
				break;
			}
			tis.n++;
			Q xz;
			if(G[tis.x+1]&&tis.x+1<10005)
			{
				xz.x=tis.x+1;
				xz.n=tis.n;
				open.push(xz);

				G[tis.x+1]=0;
			}
			if(G[tis.x-1]&&tis.x-1>=0)
			{
				xz.x=tis.x-1;
				xz.n=tis.n;
				open.push(xz);

				G[tis.x-1]=0;
			}
			if(G[tis.x*2]&&tis.x*2<10000)
			{
				xz.x=tis.x*2;
				xz.n=tis.n;
				G[tis.x*2]=0;
				open.push(xz);
			}
		}
	}

	return 0;
}

