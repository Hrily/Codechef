#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
#include<map>
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

int a[100009];

int fpm(int n,int p){
	if(p==0)
		return 1;
	int r=fpm(n,p/2)%MOD;
	r=(r*r)%MOD;
	if(p%2)
		 return (n*r)%MOD;
	return r;
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n;
		si(n);
		for(int i=1;i<=n;i++)
			si(a[i]);
		vector<int> c,v(n+1,0);
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			if(!v[i]){
				v[i]=1;
				int count=1,x=a[i];
				while(x!=i){
					v[x]=1;
					x=a[x];
					count++;
				}
				for(int j=2;j*j<=count;j++){
					int p=0;
					while(count%j==0){
						p++;
						count/=j;
					}
					if(p)
						mp[j]=MAX(mp[j],p);
				}
				if(count!=1)
					mp[count]=MAX(mp[count],1);
			}
		}
		int l=1;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
			for(int i=0;i<it->second;i++)
				l=(l*1LL*it->first)%MOD;
		cout<<l<<endl;
	}
	return 0;
}
