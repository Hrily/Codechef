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

void solve(int node,int a[],double p[],int dir[],int n){
	if(2*node>=n)
		p[node]=log(a[node]);
	else{
		solve(2*node,a,p,dir,n);
		solve(2*node+1,a,p,dir,n);
		p[node]=log(a[node])+MAX(p[2*node],p[2*node+1]);
		dir[node]=(p[2*node+1]>p[2*node])?1:0;
	}
}

int get(int node,int dir[],int a[],int n){
	if(2*node>=n)
		return a[node];
	return (a[node]*get(2*node+dir[node],dir,a,n))%MOD;
}

int main() {
	// your code goes here
	int h;
	while(si(h),h!=0){
		int n=(1<<h)-1;
		unsigned long long int a[n+1];
		double long b[n+1];
		for(int i=1;i<=n;i++){
			scanf("%llu",&a[i]);
			b[i]=a[i];
		}
		int i=n;
		while(i>1){
			int l=i-1,r=i,par=i/2; 
			b[par]=(b[par]*((b[l]>b[r])?b[l]:b[r]));
			a[par]=(a[par]*((b[l]>b[r])?a[l]:a[r]))%MOD;
			i-=2;
		}
		printf("%llu\n",a[1]);
	}
	return 0;
}
