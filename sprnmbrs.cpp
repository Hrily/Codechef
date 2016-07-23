#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sd(n) scanf("%lf",&n)
#define sll(n) scanf("%lld",&n)
#define pnl printf("\n")
#define MOD 1000000007LL
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define ABS(x) ((x<0)?-x:x)
#define LL long long
#define ULL unsigned long long 
ULL gcd(ULL a,ULL b){if(b==0){return a;}return gcd(b,a%b);}

int  main(){
	int t;
	si(t);
	while(t--){
		LL l,r;
		sll(l);sll(r);
		LL val=2,ans=0;
		while(val<=r){
			LL cur=val;
			while(cur<=r){
				if(l<=cur && cur<=r)
					ans++;
				cur*=3;
			}
			val*=2;
		}
		if(l<=1 && 1<=r)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}
