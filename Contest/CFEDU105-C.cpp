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

const int maxN = 2*1e5 + 10;

int prefix[maxN], suffix[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector<int> l, r;
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			if(tmp > 0) r.push_back(tmp);
			else l.push_back(tmp);
		}
		
		vector<int> a, b;
		for(int x=0;x<m;x++){
			int loc;
			cin >> loc;
			
			if(loc < 0){
				a.push_back(loc);
			} else {
				b.push_back(loc);
			}
		}
		
		int p = 0;
		fill(prefix, prefix+n+5, 0);
		
		if(l.size() > 0){
			for(int x=0;x<a.size();x++){
				prefix[x] = (x > 0 ? prefix[x-1] : 0);
				while(p+1 < l.size() && l[p] < a[x]){
					p++;
				}
				if(p < l.size() && a[x] == l[p]){
					prefix[x]++;
					p++;
				}
			}
		}
		
		fill(suffix, suffix+n+5, 0);
		if(r.size() > 0){
			p = r.size()-1;
			for(int x=b.size()-1;x>=0;x--){
				suffix[x] = suffix[x+1];
				while(p-1 >= 0 && r[p] > b[x]){
					p--;
				}
				if(p >= 0 && r[p] == b[x]){
					suffix[x]++;
					p--;
				}
			}
		}
		
		int cnt1 = (a.size() > 0 ? prefix[a.size()-1] : 0), cnt2 = (b.size() > 0 ? suffix[0] : 0);
		if(l.size() > 0){
			for(int x=0;x<a.size();x++){
				auto itbox = lower_bound(l.begin(), l.end(), a[x]);
				int sz = l.size();
				int cntBox = sz-(itbox-l.begin());
				
				auto itloc = lower_bound(a.begin(), a.end(), a[x]+cntBox);
				int cntLoc = (itloc-a.begin())-x;
	//			cout << x << " -> " << (x > 0 ? prefix[x-1] : 0) << " " << (itloc-a.begin())-x << " " << *itloc << " " << cntBox << " " << (itbox-box.begin()) << "\n";
				
				int spot = max(cntLoc, 0);
				
				cnt1 = max(cnt1, spot+(x > 0 ? prefix[x-1] : 0));
			}
		}
		
		if(r.size() > 0){
			for(int x=0;x<b.size();x++){
				auto itbox = lower_bound(r.begin(), r.end(), b[x]+1);
				int cntBox = (itbox-r.begin());
				
				auto itloc = lower_bound(b.begin(), b.end(), b[x]-cntBox+1);
				int cntLoc = x-(itloc-b.begin())+1;
	//				cout << x << " -> " << (x+1 < n ? suffix[x+1] : 0) << " " << (itloc-b.begin()) << " " << (itbox-box.begin()) << " " << cntLoc << " " << cntBox << "\n";
				int spot = max(cntLoc, 0);
				
				cnt2 = max(cnt2, spot+suffix[x+1]);
			}
		}
		
//		cout << cnt1 << " " << cnt2 << "\n";
		cout << cnt1+cnt2 << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

