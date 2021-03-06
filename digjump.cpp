#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
#include<queue>
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
typedef  pair<int,int>  ii;
typedef vector< ii > vii;

int main() {
	// your code goes here
	string s;
	cin>>s;
	vector< vector<int> > AdjList(10);
	vector<int> vis(s.size(),0);
	vector< vector<int> > ind(10);
	for(int i=0;i<s.size();i++)
		AdjList[s[i]-'0'].push_back(i);
	//BFS
	vector<int> d(s.size(),INF); d[0]=0;
	queue<int> q; q.push(0);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int j=0;j<AdjList[s[u]-'0'].size();j++){
			int v=AdjList[s[u]-'0'][j];
			if(d[v]==INF){
				d[v]=d[u]+1;
				q.push(v);
			}
			//cout<<v.first<<' '<<d[v.first]<<endl;
		}
		AdjList[s[u]-'0'].clear();
		if(u-1>=0 && d[u-1]==INF){
			d[u-1]=d[u]+1;
			q.push(u-1);
		}
		if(u+1<s.size() && d[u+1]==INF){
			d[u+1]=d[u]+1;
			q.push(u+1);
		}
	}
	int ans=d[s.size()-1];
	cout<<((s.size()-1)?ans:0)<<endl;
	return 0;
}
