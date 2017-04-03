#pragma comment(linker, "/STACK:102400000,102400000")
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define icc(x) (1<<(x))
#define lcc(x) (1ll<<(x))
#define lowbit(x) (x&-x)
#define debug(x) cout<<#x<<"="<<x<<endl
#define rep(i,s,t) for(int i=s;i<t;++i)
#define per(i,s,t) for(int i=t-1;i>=s;--i)
#define mset(g, x) memset(g, x, sizeof(g))
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> veci;
const int mod=1000000007,inf=0x3fffffff,rx[]={-1,0,1,0},ry[]={0,1,0,-1};
const ll INF=1ll<<60;
const db pi=acos(-1),eps=1e-8;
 
template<class T> void rd(T &res){
    res = 0; int ch,sign=0;
    while( (ch=getchar())!='-' && !(ch>='0'&&ch<='9'));
    if(ch == '-') sign = 1; else res = ch-'0';
    while((ch=getchar())>='0'&&ch<='9') res = (res<<3)+(res<<1)+ch-'0';
    res = sign?-res:res;
}
template<class T>void rec_pt(T x){
    if(!x)return;
    rec_pt(x/10);
    putchar(x%10^48);
}
template<class T>void pt(T x){
    if(x<0) putchar('-'),x=-x;
    if(!x)putchar('0');
    else rec_pt(x);
}
template<class T>inline void ptn(T x){ pt(x),putchar('\n'); }
template<class T>inline void Max(T &a,T b){ if(b>a)a=b; }
template<class T>inline void Min(T &a,T b){ if(b<a)a=b; }
template<class T>inline T mgcd(T b,T d){ return b?mgcd(d%b,b):d; }//gcd模板，传入的参数必须是用一类型
//-------------------------------主代码--------------------------------------//
 
/**************
 快速幂模板
 调用:Quk_Mul(a,b,mod)
 返回:a^b%mod
 复杂度:当mod>10^9，log(mod)*log(b),否则log(b)
 ***************/
long long Mod_Mul(long long a,long long b,long long mod)
{
    long long msum=0;
    while(b)
    {
        if(b&1) msum = (msum+a)%mod;
        b>>=1;
        a = (a+a)%mod;
    }
    return msum;
}
 
long long Quk_Mul(long long a,long long b,long long mod)
{
    bool qmflag=mod>2e9?1:0;
    long long qsum=1;
    while(b)
    {
        if(b&1) qsum = (qmflag==1) ? Mod_Mul(qsum,a,mod) : (qsum*a)%mod;
        b>>=1;
        a = (qmflag==1) ? Mod_Mul(a,a,mod) : (a*a)%mod;
    }
    return qsum;
}
 
#define N 2020
 
map<ll, ll> mmp;
ll g[N];
 
int main()
{
    int T;
    cin>>T;
    while(T--) {
        mmp.clear();
        int n;
        cin>>n;
        rep(i, 0, n) {
            rd(g[i]);
            mmp[g[i]]++;
        }
        sort(g,g+n);
        ll ans = 0;
        rep(i, 0, n) {
            if (i != 0 && g[i] == g[i - 1]) continue;
            rep(j, i + 1, n) {
                if (g[j] == g[j - 1]) continue;
                if (g[i] == g[j]) continue;
                ll other = (-g[i] - g[j]);
                if (other == g[i] || other == g[j] || other <= g[j]) continue;
                if (mmp[other] != 0) {
                    ans = (ans + (g[i] * g[i] + g[j] * g[j] + other * other)%mod)%mod;
                }
            }
        }
        rep(i, 0, n) {
            if(i!=0 && g[i] == g[i-1]) {
                continue;
            }
            ll other = 2 * -g[i];
            if (mmp[g[i]] > 1 && mmp[other] != 0 && other != g[i]) {
                ans = ((ans + 2 * g[i] * g[i]%mod)%mod + other * other)%mod;
            }
             
        }
        cout  << (ans+mod)%mod << endl;
    }
    return 0;
}