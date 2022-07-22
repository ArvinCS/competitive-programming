#include <bits/stdc++.h>

#include <chrono>

#include <random>



using namespace std;



#define ll long long



//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//

//struct Node {

//	ll key;

//	ll val, mx;

//	ll prior;

//	ll lazy;

//	Node *l, *r;

//	

//	Node(ll key) : key(key), val(key), lazy(0), mx(key), prior(rng()), l(nullptr), r(nullptr){

//		

//	}

//};

//

//void push(Node &t){

//	if(t.l != NULL){

//		t.l->val += t.l->key*t.lazy;

//		t.l->lazy += t.lazy;

//	}

//	if(t.r != NULL){

//		t.r->val += t.r->key*t.lazy;

//		t.r->lazy += t.lazy;

//	}

//	

//	t.lazy = 0;

//}

//

//void split(Node t, Node &l, Node &r, int val){

//	push(t);

//	

//	if(t.key <= val){

//		if(t.r != nullptr) split(t.r, t.r, r, val);

//		l = t;

//	}

//	else split(t->l, l, t->l, val), r = t;

//	

//	t->mx = max(t->mx, t->val);

//	if(t->l) t->mx = max(t->mx, t->l->mx);

//	if(t->r) t->mx = max(t->mx, t->r->mx);

//}

//

//void merge(Node &t, Node l, Node r){

//	if(!l || !r){

//		t = (l ? l : r);

//		return;

//	}

//	

//	push(l); push(r);

//	

//	if(l.prior > r.prior) merge(l->r, l->r, r), t = l;

//	else merge(r->l, l, r->l), t = r;

//	

//	t->mx = max(t->mx, t->val);

//	if(t->l) t->mx = max(t->mx, t->l->mx);

//	if(t->r) t->mx = max(t->mx, t->r->mx);

//}



int main(){

	ios_base::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	

	int n;

	cin >> n;

	

	pair<int, int> p[n];

	for(int x=0;x<n;x++){

		cin >> p[x].first >> p[x].second;

	}

	

	vector<pair<ll, int>> v;

	for(int x=0;x<n;x++){

		v.push_back({p[x].second, x});

	}

	

	sort(v.begin(), v.end());

	

	int cnt[n];

	fill(cnt, cnt+n, 0);

	

	ll ans = 0;

	multiset<ll> st;

	for(int x=0;x<v.size();x++){

		ll val = v[x].first*(n-x);

		ll val2 = 0;

		int cnt = st.size();

		for(auto v : st){

			val2 = max(val2, v*cnt);

			cnt--;

		}

		

		ans = max(ans, val+val2);

		st.insert(p[v[x].second].first);

	}

	

	cout << ans << "\n";

}


