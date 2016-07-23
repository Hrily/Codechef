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
#define flip(s,i) s[i]=(s[i]=='0')?'1':'0'


/*
void flip(string s,int i){
	if(s[i]=='0')
		s[i]='1';
	else
		s[i]='0';
}*/

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n,k;
		si(n);si(k);
		string s;
		cin>>s;
		int c=1,ans=0;
		if(k==1){
			string r=s;
			int k=0,a1=0;
			for(int i=0;i<n;i++){
				if(r[i]!=k+'0'){
					flip(r,i);
					a1++;
				}
				k=1-k;
			}
			k=1;
			for(int i=0;i<n;i++){
				if(s[i]!=k+'0'){
					flip(s,i);
					ans++;
				}
				k=1-k;
			}
			if(a1<ans)
				cout<<a1<<endl<<r<<endl;
			else
				cout<<ans<<endl<<s<<endl;
			continue;
		}
		char x=s[0];
		for(int i=1;i<n;i++){
			if(s[i]==x)
				c++;
			else{	
				x=s[i];
				c=1;
			}
			if(c>k){
				if(s[i]==s[i+1])flip(s,i);
				else flip(s,i-1);
				ans++;
				c=1;
			}
		}
		cout<<ans<<endl;
		cout<<s<<endl;
	}
	return 0;
}

