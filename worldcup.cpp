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
#define LIMIT 300

LL ncr[LIMIT+5][LIMIT+5];
void pre(){
	for(int i=0;i<=LIMIT;i++)ncr[i][i]=ncr[i][0]=1;
	for(int i=2;i<=LIMIT;i++)
		for(int j=1;j<i;j++)
			ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
}

LL C(int n,int r){
	if(n<r)return 0LL;
	return ncr[n][r];
}

int main() {
	// your code goes here
	pre();
	int t;
	si(t);
	while(t--){
		LL runs,balls,wkts;
		sll(runs);sll(balls);sll(wkts);
		LL sum=0,sixes,fours;
		if(runs>6*balls){
			printf("0\n");
			continue;
		}
		for(LL i=0;i<=runs/6;i++){
			sixes=i;
			fours=(runs - 6*sixes)/4;
			if(4*fours+6*sixes!=runs)continue;
			for(int w=0;w<=wkts;w++){
				sum=(sum + C(balls,fours) * (( C(balls-fours,sixes) * C(balls-fours-sixes,w) )%MOD) )%MOD;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
