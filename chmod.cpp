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

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
LL cum[100009][26];

inline LL bigmod(LL a, LL b, LL m)
{
	if(b == 0) return 1 % m;
	LL x = a, ans = 1;
	while(b)
	{
		if(b&1) ans = (ans * x)%m;
		b >>= 1;
		x = (x*x)%m;
	}
	return ans;
}

int fpm(int x,int p,int m){
	if(p==0)
		return 1;
	int r=fpm(x,p/2,m)%m;
	r=(1LL*r*r)%m;
	if(p%2)
		return (1LL*x*r)%m;
	return r;
}

vector< pair<int,int> > V[101];
void pre(){
	for(int i=2;i<=100;i++){
		int temp=i;
		for(int j=0;j<25;j++){
			int count=0;
			while(temp%prime[j]==0){
				count++;
				temp/=prime[j];
			}
			if(count)
				V[i].push_back(make_pair(j,count));
			if(temp==1)
				break;
		}
	}
}

int main() {
	// your code goes here
	pre();
	LL n,x;
	sll(n);
	for(LL i=1;i<=n;i++){
		sll(x);
		for(int j=0;j<25;j++)
			cum[i][j]=cum[i-1][j];
		for(int j=0;j<V[x].size();j++)
			cum[i][V[x][j].first]+=V[x][j].second;
	}
	int t;
	si(t);
	while(t--){
		LL l,r,m;
		sll(l);sll(r);sll(m);
		LL ans=1%m;
		for(int i=0;i<25;i++){
			ans=(1LL*ans*bigmod(prime[i],cum[r][i]-cum[l-1][i],m))%m;
			if(ans==0)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
