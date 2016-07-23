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
#define x first
#define y second

int isint(pair<int,int> a,pair<int,int> b){
	return (a.x<=b.x && a.y>=b.x && a.y<=b.y)?1:0;
}

void splitnadd(vector< pair<int,int> > &r, pair<int,int> a, pair<int,int> b){
	r.push_back(make_pair(a.x,b.x-1));
	r.push_back(make_pair(b.x,a.y));
	r.push_back(make_pair(a.y+1,b.y));
	cout<<';';
}

int comp(pair<int,int> a, pair<int,int> b){
	return ABS(a.second-a.first)<ABS(b.second-b.first);
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n,k;
		si(n);si(k);
		vector<char> s(n,'-');
		vector< pair<int,int> > r,seg;
		for(int i=0;i<k;i++){
			 int x,y;
			 si(x);si(y);
			 r.push_back(make_pair(x,y));
		}
		for(int i=1;i<r.size();i++){
			for(int j=0;j<i;j++){
				if(isint(r[i],r[j])){
					r.push_back(make_pair(r[i].x,r[j].x-1));
					r.push_back(make_pair(r[j].x,r[i].y));
					r.push_back(make_pair(r[i].y+1,r[j].y));
					r.erase(r.begin()+i);r.erase(r.begin()+j);
					i-=2;
				}else if(isint(r[j],r[i])){
					r.push_back(make_pair(r[j].x,r[i].x-1));
					r.push_back(make_pair(r[i].x,r[j].y));
					r.push_back(make_pair(r[j].y+1,r[i].y));
					r.erase(r.begin()+i);r.erase(r.begin()+j);
					i-=2;
				}
			}
		}
		sort(r.begin(),r.end(),comp);
		//for(int i=0;i<r.size();i++)
			//cout<<r[i].x<<' '<<r[i].y<<endl;
		for(int i=0;i<r.size();i++){
			int low=r[i].x,high=r[i].y;
			while(low<high){
				while(s[low]!='-' && low<=high)
					low++;
				if(s[low]=='-'){
					s[low]='(';
					low++;
				}
				while(s[high]!='-' && low<=high)
					high--;
				if(s[high]=='-'){
					s[high]=')';
					high--;
				}
				//for(int j=0;j<s.size();j++)cout<<s[j];
				//cout<<' '<<low<<' '<<high;
				//cout<<endl;
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='-')s[i]='(';
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
