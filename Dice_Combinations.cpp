#include <bits/stdc++.h>
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define cyes cout<<"Yes"<<endl;
#define cno cout<<"No"<<endl;
#define all(x) x.begin(), x.end()
#define choto(x) sort((x).begin(), (x).end())
#define boro(x) sort((x).rbegin(), (x).rend())
#define nl cout<<endl;
#define endl '\n'
#define love int main()
#define vtr vector
#define pii pair<int,int>
#define out(x) cout << x << '\n';
#define out2(x,y) cout << x << " " << y << '\n';
#define vii vector<int> 
#define vll vector<ll>
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define vsum(x) accumulate((x).begin(), (x).end(), 0LL)
#define fix(n, val) fixed << setprecision(n) << val
#define Alamgir ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

// Constants
const long double pi = 3.141592653589793238;
const ll MOD = 1e9+7;
const int N = 1e6+5; // Increased to avoid runtime errors

// Utility functions
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b){ return (a / gcd(a, b)) * b; }
bool isPrime(ll n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

// Iterative DP version (no recursion, no stack overflow)
ll find_way(ll n) {
    if (n == 0) return 0;
    vector<ll> dp(n + 1, 0);

    dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    if (n >= 3) dp[3] = 4;
    if (n >= 4) dp[4] = 8;
    if (n >= 5) dp[5] = 16;
    if (n >= 6) dp[6] = 32;

    for (int i = 7; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % MOD;
    }

    return dp[n];
}

void solve() {
    ll n; 
    cin >> n;
    cout << find_way(n) << endl;
}

love {
    Alamgir
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
