#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
int a[2*maxn],pos[maxn];
int sum[2*maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
    for(int i=x;i<=n+maxn;i+=lowbit(i))
        sum[i]+=y;
}
int query(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=sum[i];
    return ans;
}
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(sum,0,sizeof(sum));
        for(int i=1e5+1,j=1;i<=n+1e5;i++,j++)
        {
            add(i,1); 
            pos[j]=i; 
        }
        int p=1e5+1; 
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            if(i!=1) printf(" ");
            printf("%d",query(pos[x])-1); 
            p--; 
            add(pos[x],-1); 
            pos[x]=p; 
            add(p,1);
        }
        printf("\n");
    }
    return 0;
}