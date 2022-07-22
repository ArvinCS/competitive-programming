#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
	int id;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct CHT : public multiset<Line> { 
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m - x->m);
    }
    void insertLine(ll m, ll b, int id) {
        auto y = insert({ m, b, id});
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        while (y != begin() && bad(prev(y))) erase(prev(y));
        if(y != begin()) prev(y)->succ = [=] { return &*y; };
    }
    pair<ll, ll> eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query});
        return {l.m * x + l.b, l.id};
    }
    void merge(CHT &other){
        for(auto &l:other) insertLine(l.m,l.b,l.id);
    }
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	
	ll sum = 0;
	ll w[n];
	for(int x=0;x<n;x++){
		cin >> w[x];
		sum += w[x];
	}
	
	CHT cht;
	cht.insertLine(2ll*h[0], -(sum-w[0]+h[0]*h[0]), 0);
	
	for(int x=1;x<n-1;x++){
		cht.insertLine(2ll*h[x], -(-cht.eval(h[x]).first-w[x]+2*(h[x]*h[x])), x);
	}
	
	cout << -cht.eval(h[n-1]).first-w[n-1]+h[n-1]*h[n-1] << "\n";
    return 0;
}

