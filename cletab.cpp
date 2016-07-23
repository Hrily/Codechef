#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
#include<queue>
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
#define INF 100000000

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n,m,count=0;
		si(n);si(m);
		vector<int> a(m);
		map<int, queue<int> > nextorder;
		map<int, queue<int> >::iterator it;
		for(int i=0;i<m;i++){;
			si(a[i]);
			nextorder[a[i]].push(i);
		}
		//cout<<"running opt...\n";
		vector<int> table;
		for(int i=0;i<m;i++){
			int f=1;
			for(int j=0;j<table.size();j++){
				if(table[j]==a[i]){
					nextorder[a[i]].pop();
					f=0;
				}
			}		
			if(f){
				if(table.size()<n){
					table.push_back(a[i]);
					nextorder[a[i]].pop();
				}else{
					int max=0,mi=-1;
					for(int j=0;j<n;j++){
						if(nextorder[table[j]].empty()){
							mi=j;
							break;
						}
					}
					if(mi<0){
						for(int j=0;j<n;j++){
							if(max<nextorder[table[j]].front()){
								max=nextorder[table[j]].front();
								mi=j;
							}
						}
					}
					//cout<<"removing "<<table[mi]<<" to add "<<a[i]<<" mi="<<mi<<"...\n";
					table[mi]=a[i];
					nextorder[a[i]].pop();
				}
				count++;
			}
			//for(int j=0;j<table.size();j++)
			//	cout<<table[j]<<' ';
			//cout<<endl;
		}//*/
		cout<<count<<endl;
	}
	return 0;
}
