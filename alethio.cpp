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

int comp(string a,string b){
	if(a.size()!=b.size())
		return a.size()<b.size();
	else
		return a<b;
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	string m="",x="";
	int f=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			if(x.size())
				x=x+s[i];
			else if(s[i]-'0')
				x=x+s[i];
		}
		if('A'<=s[i] && s[i]<='Z'){
			if(f){
				if(comp(m,x))m=x;
				i-=x.size();
				f=0;
				x="";
			}else{
				x=x+'9';
				f=1;
			}
		}
	}
	if(comp(m,x))m=x;
	cout<<m<<endl;
	return 0;
}
