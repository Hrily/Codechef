#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
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

class city{
	string f,t;
	int cost;
	public:
	city(){}
	void init(string from,string to,string co){
		f=from;
		t=to;
		cost=0;
		for(int i=0;i<co.size()-1;i++)
			cost=cost*10+(co[i]-'0');
	}
	string getf(){
		return f;
	}
	string gett(){
		return t;
	}
	int getc(){
		return cost;
	}
};

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int n;
		si(n);
		map<string,int> find,count;
		vector<city> data(n);
		for(int i=0;i<n-1;i++){
			string from, to, co;
			cin>>from>>to>>co;
			data[i].init(from,to,co);
			find[from]=i;
			count[from]--;
			count[to]++;
		}
		int start=-1;
		map<string,int>::iterator it;
		for(it=count.begin();it!=count.end();it++){
			if(it->second==-1){
				start=find[it->first];
				break;
			}
		}
		int c=0,total=0,ind=start;
		while(c<n-1){
			cout<<data[ind].getf()<<' '<<data[ind].gett()<<' '<<data[ind].getc()<<"$\n";
			total+=data[ind].getc();
			ind=find[data[ind].gett()];
			c++;
		}
		cout<<total<<"$\n";
	}
	return 0;
}
