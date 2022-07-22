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

int ask(int left, int right){
	cout << "? " << (right-left+1);
	for(int x=left;x<=right;x++){
		cout << " " << x;
	}
	cout << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

int ask2(vector<int> v){
	cout << "? " << v.size();
	for(auto val : v){
		cout << " " << val;
	}
	cout << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int parrent[n+1];
		fill(parrent, parrent+n+1, -1);
		
		// Observations:
		// There is at least 1 element with maximum value, call it mx.
		// Mx element only can be picked by 1 subset only, which means that all subset (except who picked mx element) will have this mx element as answer.
		// Now we only considering the subset that picked this mx element.
		// Just check/query this subset, what is the value? that is, replace it.
		// All done.
		// Note: there is case where this element is not picked by any subset, so all subset will have this mx as answer.
		
		for(int x=0;x<k;x++){
			int m;
			cin >> m;
			
			for(int y=0;y<m;y++){
				int tmp;
				cin >> tmp;
				
				parrent[tmp] = x;
			}
		}
		
		queue<pair<int, int>> q;
		int l = ask(1, n/2), r = ask(n/2+1, n);
		int mx = max(l, r);
		
		if(l >= r){
			q.push({1, n/2});
		} else {
			q.push({n/2+1, n});
		}
		
		int pos = -1;
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(p.first == p.second){
				pos = p.first;
				break;
			}
			
			int l = ask(p.first, (p.first+p.second)/2);
			
			if(l == mx){
				q.push({p.first, (p.first+p.second)/2});
			} else {
				q.push({(p.first+p.second)/2+1, p.second});
			}
		}
				
		int ans[k];
		for(int x=0;x<k;x++){
			ans[x] = mx;
		}
		
		if(parrent[pos] >= 0){ // picked or not
			vector<int> v;
			for(int x=1;x<=n;x++){
				if(parrent[x] != parrent[pos]){
					v.push_back(x);
				}
			}
			
			int remain = ask2(v);
			if(remain != mx){
				ans[parrent[pos]] = remain;
			}
		}
		
		cout << "!";
		for(int x=0;x<k;x++){
			cout << " " << ans[x];
		}
		cout << endl;
		
		string res;
		cin >> res;
	}

    return 0;
}

