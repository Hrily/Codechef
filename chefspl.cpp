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

int isds(string s){		//is double string
	int n = s.size();
	if(n==0 || n%2)
		return 0;
	for(int i=0;i<n/2;i++)
		if(s[i]!=s[i+n/2])
			return 0;
	return 1;
}

int isss(string a, string b){	//is substring
	int j=0;
	for(int i=0;i<a.size();i++){
		while(j<b.size() && a[i]!=b[j]) j++;
		if(j==b.size()) return 0;
		j++;
	}
	return 1;
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		string s;
		cin>>s;
		int n=s.size(), flag=0;
		if(n%2==0)
			flag = isds(s);
		else if(n>1){
			flag = isss(s.substr(0,n/2), s.substr(n/2,n/2+1)) ||
			       isss(s.substr(n/2+1,n/2), s.substr(0,n/2+1));
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
