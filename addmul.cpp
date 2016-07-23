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
#define MID(a,b) (((a)+(b))/2)
#define left(n) (2*(n))
#define right(n) (2*(n)+1)

int n;
vector<int> a, st, add, mul;

void construct_st(int node, int l, int h){
	//if node
	if(l==h){
		st[node] = a[l];
	}
	else if (l<h){
		int m=MID(l,h),
		    ln=left(node),
		    rn=right(node);
		construct_st(ln, l, m);
		construct_st(rn, m+1, h);
		//update current node
		st[node] = (1LL * st[ln] + st[rn]) %MOD;
	}
}

void updateUtil(int i, int j, int node, int l, int h, int va, int vm){
	//cout<<"At seg ["<<l<<","<<h<<"] node "<<node<<endl;
	//do lazy update
	if(add[node]!=0 || mul[node]!=1){
		st[node] = ((1LL*(h-l+1)*add[node])%MOD+1LL*mul[node]*st[node]%MOD)%MOD;
		//if not a leaf
		if(l!=h){
			//postpone updates for children
			add[left(node)]=(1LL*mul[node]*add[left(node)]+add[node])%MOD;
			mul[left(node)]=(1LL*mul[left(node)]*mul[node])%MOD;
			add[right(node)]=(1LL*mul[node]*add[right(node)]+add[node])%MOD;
			mul[right(node)]=(1LL*mul[right(node)]*mul[node])%MOD;

		}
		//clear current lazinnes
		add[node]=0;
		mul[node]=1;
	}
	//if out of range
	if(h<i || l>j || l>h)
		return;
	//segment completely in range
	if(i<=l && h<=j){
		//update current node
		st[node] = ((1LL*(h-l+1)*va)%MOD+1LL*vm*st[node]%MOD)%MOD;
		//if not a leaf 
		if(l!=h){
			//postpone updates for children
			add[left(node)]=(1LL*vm*add[left(node)]+va)%MOD;
			mul[left(node)]=(1LL*mul[left(node)]*vm)%MOD;
			add[right(node)]=(1LL*vm*add[right(node)]+va)%MOD;
			mul[right(node)]=(1LL*mul[right(node)]*vm)%MOD;
		}
		return;
	}
	//if not completely in range
	int m=MID(l,h),
	    ln=left(node),
	    rn=right(node);
	updateUtil(i,j,ln,l,m,va,vm);
	updateUtil(i,j,rn,m+1,h,va,vm);
	//update current node
	st[node] = (1LL * st[ln] + st[rn]) %MOD;
}

void addRange(int i, int j, int va){
	updateUtil(i,j,1,0,n-1,va,1);
}

void mulRange(int i, int j, int vm){
	updateUtil(i,j,1,0,n-1,0,vm);
}

void setRange(int i,int j, int v){
	updateUtil(i,j,1,0,n-1,v,0);
}

int get_sum_util(int i, int j, int node, int l, int h){
	//cout<<"At seg ["<<l<<","<<h<<"] node "<<node<<endl;
	//do lazy update
	if(add[node]!=0 || mul[node]!=1){
		st[node] = ((1LL*(h-l+1)*add[node])%MOD+1LL*mul[node]*st[node]%MOD)%MOD;
		//if not a leaf
		if(l!=h){
			//postpone updates for children
			add[left(node)]=(1LL*mul[node]*add[left(node)]+add[node])%MOD;
			mul[left(node)]=(1LL*mul[left(node)]*mul[node])%MOD;
			add[right(node)]=(1LL*mul[node]*add[right(node)]+add[node])%MOD;
			mul[right(node)]=(1LL*mul[right(node)]*mul[node])%MOD;
		}
		//clear current lazinnes
		add[node]=0;
		mul[node]=1;
	}
	//if out of range
	if(h<i || l>j || l>h)
		return 0;
	//completely in range
	if(i<=l && h<=j)
		return st[node];
	//not completely in range 
	int m=MID(l,h),
	    ln=left(node),
	    rn=right(node);
	return (get_sum_util(i,j,ln,l,m) +
	       get_sum_util(i,j,rn,m+1,h)) %MOD;
}	

int get_sum(int i, int j){
	return get_sum_util(i,j,1,0,n-1)%MOD;
}

int main() {
	// your code goes here
	int q;
	si(n);si(q);
	a.assign(n,0);
	st.assign(4*n,0);
	add.assign(4*n,0);
	mul.assign(4*n,1);
	for(int i=0;i<n;i++)
		si(a[i]);
	construct_st(1,0,n-1);
	while(q--){
		int c,x,y;
		si(c);si(x);si(y);
		x--;y--;
		if(c==4)
			cout<<get_sum(x,y)<<endl;
		else{
			int v;
			si(v);
			if(c==1)
				addRange(x,y,v);
			else if(c==2)
				mulRange(x,y,v);
			else
				setRange(x,y,v);
		}/*
		for(int j=0;j<st.size();j++)
			cout<<st[j]<<' ';
		cout<<endl;
		for(int j=0;j<add.size();j++)
			cout<<add[j]<<' ';
		cout<<endl;
		for(int j=0;j<mul.size();j++)
			cout<<mul[j]<<' ';
		cout<<endl;*/

	}
	return 0;
}
