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

int a[11][3] = {
	{1,4,5},
	{0,2,6},
	{1,3,7},
	{2,4,8},
	{0,3,9},
	{0,7,8},
	{1,8,9},
	{2,5,9},
	{3,5,6},
	{4,6,7},
};

int main() {
	// your code goes here
	int t;
	si(t);
	char h[]={'A','B','C','D','E','A','B','C','D','E'};
	while(t--){
		string s,r="";
		cin>>s;
		int x=s[0]-'A',f=1;
		r+=(x+'0');
		for(int i=1;i<s.size();i++){
			for(int j=0;j<3;j++){
				if(h[a[x][j]]==s[i]){
					x=a[x][j];
					r+=(x+'0');
					break;
				}
			}
		}
		if(r.size()==s.size()){
			cout<<r<<endl;
			continue;
		}
		f=1;
		x=s[0]-'A'+5;
		r="";
		r+=(x+'0');
		for(int i=1;i<s.size();i++){
			for(int j=0;j<3;j++){
				if(h[a[x][j]]==s[i]){
					x=a[x][j];
					r+=(x+'0');
					break;
				}
			}
		}
		if(r.size()==s.size()){
			cout<<r<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	return 0;
}
