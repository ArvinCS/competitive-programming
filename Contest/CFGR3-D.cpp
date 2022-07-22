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

bool customSort(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<1>(a) < get<1>(b);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	tuple<int, int, int> p[n];
	for(int x=0;x<n;x++){
		int a, b;
		cin >> a >> b;
		
		p[x] = make_tuple(a, b, x+1);
	}
	
	sort(p, p+n, customSort);
	
	int cnt1 = 0, cnt2 = 0;
	int last1 = 0, last2 = inf_int;
	vector<int> a, b;
	for(int x=0;x<n;x++){
		if(get<0>(p[x]) <= get<1>(p[x])) continue;
		if(last1 < get<0>(p[x])){
			cnt1++;
			last1 = get<1>(p[x]);
			a.push_back(get<2>(p[x]));
		}
	}
	
	reverse(p, p+n);
	for(int x=0;x<n;x++){
		if(get<0>(p[x]) >= get<1>(p[x])) continue;
		if(last2 > get<0>(p[x])){
			cnt2++;
			last2 = get<1>(p[x]);
			b.push_back(get<2>(p[x]));
		}
	}
	
	if(a.size() >= b.size()){
		cout << a.size() << "\n";
		for(int x=0;x<a.size();x++){
			if(x > 0) cout << " ";
			cout << a[x];
		}
		cout << "\n";
	} else {
		cout << b.size() << "\n";
		for(int x=0;x<b.size();x++){
			if(x > 0) cout << " ";
			cout << b[x];
		}
		cout << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

