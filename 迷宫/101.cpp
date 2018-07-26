#include <iostream>
#include <queue>
#include <windows.h>
#define MAX 10000
using namespace std;
struct Q
{
    int n;
	int x,y;	
};
queue<Q> open; 
char a[MAX][MAX];

int sx,sy;
int main()
{
	bool G[100][100];
	for(int i=0;i<100;i++)for(int j=0;j<100;j++)G[i][j]=true; 
	int n,m,i,j;
	cout<<"请输入矩阵大小(n,m)(空格分开):";
	cin>>n>>m;
	cout<<"请输入地图(#代表墙,.代表路,S表示开始,E表示结束):";
	cout<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	bool flag=false;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(a[i][j]=='S')
    		{
    			sx=i;
    			sy=j;
    			flag=true;
    			break;
			}
		}
		if(flag==true)break;
	}
	if(flag==false)
	{
		Sleep(1);
		cout<<"异常Stop!未含有起点(S)请重试";
		return 0;
	}
	Q first;
	first.x=sx;
	first.y=sy;
	first.n=0;
	open.push(first);
	G[first.x][first.y]=false;
	while(!open.empty())
	{
		Q tis=open.front();
		open.pop();
		if(a[tis.x][tis.y]=='E')
		{
			cout<<"成功找到,需走"<<tis.n<<"步.";
			return 0;
		}
		Q xz;
		tis.n++;
		if(a[tis.x-1][tis.y]!='#'&&G[tis.x-1][tis.y])
		{
			xz.x=tis.x-1;
			xz.y=tis.y;
			xz.n=tis.n;
			G[tis.x-1][tis.y]=false;
			open.push(xz);
		}
		if(a[tis.x+1][tis.y]!='#'&&G[tis.x+1][tis.y])
		{
			xz.x=tis.x+1;
			xz.y=tis.y;xz.n=tis.n;
			G[tis.x+1][tis.y]=false;
			open.push(xz);
		}
		if(a[tis.x][tis.y-1]!='#'&&G[tis.x][tis.y-1])
		{
			xz.x=tis.x;
			xz.y=tis.y-1;xz.n=tis.n;
			G[tis.x][tis.y-1]=false;
			open.push(xz);
		}
		
		if(a[tis.x][tis.y+1]!='#'&&G[tis.x][tis.y+1])
		{
			xz.x=tis.x;
			xz.y=tis.y+1;xz.n=tis.n;
			G[tis.x][tis.y+1]=false;
			open.push(xz);
		}
	}
	cout<<"结果:错误或无法正常到达.";
	system("pause>nul"); 
	return 0;
}
