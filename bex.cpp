#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sd(n) scanf("%lf",&n)
#define sll(n) scanf("%lld",&n)
#define pnl printf("\n")
#define MOD 1000000007LL
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define ABS(x) ((x<0)?-x:x)
#define LL long long 
#define ULL unsigned long long 
ULL gcd(ULL a,ULL b){if(b==0){return a;}return gcd(b,a%b);}

class book{
	int x,c;
	string s;
	public:
		book(){}
		book(int i,string str){
			x=i;
			s=str;
			c=0;
		}
		void inc(){
			c++;
		}
		string gets(){
			return s;
		}
		int getx(){
			return x;
		}
		int getc(){
			return c;
		}
};

int main(){
	int t;
	si(t);
	vector<book> pile;
	while(t--){
		int x;
		string s;
		si(x);
		if(x>-1){
			cin>>s;
			book b(x,s);
			if(x>0){
				if(pile.empty())
					pile.push_back(b);
				else if(x<=pile.back().getx())
					pile.push_back(b);
				else if(x>pile.back().getx())
					pile.back().inc();
			}
		}else{
			cout<<pile.back().getc()<<' '<<pile.back().gets()<<endl;
			pile.pop_back();
		}
	}
	return 0;
}
