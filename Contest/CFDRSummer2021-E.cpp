#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 1e5 + 5;
const int logN = log2(maxN);

template<typename T> struct SparseTable{
	vector<T> table[logN+1];
	int n, lg;
	function<T(T, T)> cmp;
	
	SparseTable(){}
	SparseTable(int n, function<T(T, T)> cmp, T a[]) : n(n), cmp(cmp) {
		for(int x=0;x<n;x++){
			table[0].push_back(a[x]);
		}
		
		lg = log2(n);
		for(int x=1;x<=lg;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x].push_back(cmp(table[x-1][y], table[x-1][y+length/2]));
			}
		}
	}
	
	public:
	T query(int left, int right){
		int lg = log2(right-left+1);
		return cmp(table[lg][left], table[lg][right-(1<<lg)+1]);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, q;
	cin >> n >> q;
		
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		a[x] = (x-1 >= 0 ? a[x-1] : 0ll) + b[x] - a[x];
	}
	
	auto cmpMx = [&](ll a, ll b) -> ll {
	    return max(a, b);
	};
	auto cmpMn = [&](ll a, ll b) -> ll {
	    return min(a, b);
	};
	
	SparseTable<ll> mx(n, cmpMx, a), mn(n, cmpMn, a);
	
	for(int i=1;i<=q;i++){
		int left, right;
		cin >> left >> right;
		
		left--; right--;
		
		ll tmp = mn.query(left, right), tmp2 = a[right];
		if(left-1 >= 0){
			tmp -= a[left-1];
			tmp2 -= a[left-1];
		}
		
		if(tmp < 0 || tmp2 != 0){
			cout << "-1\n";
			continue;
		}
		
		ll ans = mx.query(left, right);
		if(left-1 >= 0) ans -= a[left-1];
		
		if(ans < 0){
			cout << "-1\n";
			continue;
		}
		
		cout << ans << "\n";
	}
    return 0;
}

