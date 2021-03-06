#include <bits/stdc++.h>

using namespace std;

/********************************MACROS********************************/

#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define vt vector
#define pb push_back
#define F first
#define S second
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue

/*******************************DEBUGGER*******************************/

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/******************************ALGORITHMS******************************/

int __pow(int x, int y, int M) {int res = 1;while(y>0){if(y&1) res = (res*x)%M; y>>=1; x = (x*x)%M;}return res%M;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}

/******************************MAIN**CODE******************************/

const int N = 1e6+10, inf = 1e18, M = 1e9+7;
int vis[N];
vt<int> tree[N];
int test, n, m, k, x, query;
void test_case(){
    cin>>n;
    vt<int> a(n);
    for(auto &x:a) cin>>x;
    vt<int> grp;
    grp.pb(0);
    for(int i=0; i<n; i++){
        if(a[i]==1) continue;
        int j=i;
        for(; a[i+1]==0 && i<n-1; i++);
        grp.pb(i-j+1);
    }
    sort(rall(grp));
    debug()<<deb(grp);
    if(grp.size()==1){
        cout<<"No"<<endl;
        return;
    }
    if(grp.size()==2){
        if(grp[0]%2==0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return;
    }
    if(grp[0]==grp[1]){
        cout<<"No"<<endl;
        return;
    }
    if(grp[0]%2==1){
        if((grp[1])>(grp[0])/2){
            cout<<"No"<<endl;
        }
        else cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
    /*
    else{
        if((grp[1]-1)>=grp[0]/2){
            cout<<"No\n";
        }
        else cout<<"Yes\n";
    }*/
}
int32_t main(){
    test = 1;
    cin>>test;
    while(test--)
        test_case();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
