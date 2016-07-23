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

int notbad(int a[], int n, int k, int m){
	int res=1;
	for(int i=0;i+k-1<n;i++){
		int max=0,mc=0;
		for(int j=0;j<k;j++)
			max=MAX(max,a[i+j]);
		for(int j=0;j<k;j++)
			mc+=(max==a[i+j]);
		if(mc>=m){
			res=0;
			break;
		}
	}
	return res;
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n,k,m;
		si(n);si(k);si(m);
		int a[n];
		for(int i=0;i<n;i++)
			si(a[i]);
		int ans=100000;
		for(int mask=0;mask<(1<<n);mask++){
			int b[n],count=0;
			for(int i=0;i<n;i++){
				b[i]=a[i];
				if(mask & (1<<i)){
					b[i]++;
					count++;
				}
			}
			//cout<<mask<<' '<<notbad(b,n,k,m)<<endl;
			if(notbad(b,n,k,m) && ans>count)
				ans=count;
		}
		cout<<((ans<100000)?ans:-1)<<endl;
	}
	return 0;
}
