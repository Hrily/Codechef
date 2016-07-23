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

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n;
		si(n);
		vector< pair<char,char> > a(n);
		for(int i=0;i<n;i++)
			cin>>a[i].first>>a[i].second;
		string s,r;
		cin>>s;
		r=s;
		int f=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<s.size();j++)
				if(r[j]==a[i].first)s[j]=a[i].second;
		for(int i=0;i<s.size();i++){
			if(!f && s[i]=='.'){
				f=1;
				break;
			}
		}
		int i=0;
		while(i<s.size() && s[i]=='0')i++;
		int j=s.size()-1;
		if(f)while(j>=0 && s[j]=='0')j--;
		if(s[j]=='.')j--;
		if(i>j || i>=s.size() || j<0)printf("0");
		for(int k=i;k<=j;k++)
			if((s[k]>='0' && s[k]<='9') || s[k]=='.')printf("%c",s[k]);
		pnl;
	}
	return 0;
}
