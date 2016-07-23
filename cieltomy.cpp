#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
using namespace std;
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")//print new line
#define REP(i,n) for(int i=0;i<(n);i++)//repeat n times
#define FOR(i,a,b) for(int i=(a);i<(b);i++)//end not included
#define FORR(i,n) for(int i=(n);i>=0;i--)//reverse for
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";//debugging
#define CL(a,b) memset(a,b,sizeof(a))
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
//}
int a[12][12],C,L=1000000,vis[12];

void go(int k, int len,int N){
	if(len>L){
	}else if(k==N){
		if(L>len){
			L=len;
			C=1;
		}else if(L==len)
			C++;
	}else{
		vis[k]=1;
		for(int j=1;j<=N;j++)
			if(!vis[j] && a[k][j]>0)
				go(j,len+a[k][j],N);
		vis[k]=0;
	}
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n,m;
		si(n);si(m);
		C=0;L=1000000;
		for(int i=0;i<12;i++)
			for(int j=0;j<12;j++)
				a[i][j]=-1;
		for(int i=0;i<12;i++)vis[i]=0;
		for(int i=0;i<m;i++){
			int x,y,l;
			si(x);si(y);si(l);
			a[x][y]=a[y][x]=l;
		}
		go(1,0,n);
		cout<<C<<endl;
	}
	return 0;
}
