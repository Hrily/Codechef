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
#define pb(x) push_back(x)
#define right(v) (2*(v))
#define left(v)  (2*(v)+1)
#define parent(v) ((int)((v)/2))

//0 black
//1 red

int isrr=0;	//is root red

int get_lca(int x, int y){
	if(x==y) return x;
	vector<int> xr,yr;
	while(x>0){
		xr.pb(x);
		x/=2;
	}
	while(y>0){
		yr.pb(y);
		y/=2;
	}
	int lca=-1;
	reverse(xr.begin(), xr.end());
	reverse(yr.begin(), yr.end());
	for(int i=0; i<xr.size() && i<yr.size(); i++){
		if(xr[i]!=yr[i])
			break;
		lca=xr[i];
	}
	return lca;
}

int get_dist(int n){		//get dist from root
	int dist=0;
	while(n>0){
		n/=2;
		dist++;
	}
	return dist;
}

int count_black(int n){		//count number of black nodes from root
	int dist=get_dist(n);
	if(!isrr) return (dist+1)/2;
	return (dist/2);
}

int count_red(int n){		//count number of red nodes from root
	int dist=get_dist(n);
	if(isrr) return (dist+1)/2;
	return (dist/2);
}

int main() {
	// your code goes here
	int q=0;
	si(q);
	while(q--){
		string s;
		cin>>s;
		if(s[1]=='i')isrr=1-isrr;
		else{
			int x,y;
			cin>>x>>y;
			int lca=get_lca(x,y);
			//cout<<"LCA = "<<lca<<endl;
			int d=get_dist(lca);
			int d1, d2, d3, d4=0;
			if(s[1]=='b'){
				d1=count_black(x),
				d2=count_black(y),
				d3=count_black(lca);
				if((d%2 && !isrr) ||
				   (d%2==0 && isrr)) d4=1;
			}else{
				d1=count_red(x),
				d2=count_red(y),
				d3=count_red(lca);
				if((d%2 && isrr) ||
				   (d%2==0 && !isrr)) d4=1;
			}
			//printf("d1 = %d, d2 = %d, d3 = %d, d4 = %d\n",d1,d2,d3,d4);
			cout<<(d1+d2-(2*d3)+d4)<<endl;
		}
	}
	return 0;
}
