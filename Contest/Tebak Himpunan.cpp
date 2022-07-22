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

vector<int> v;
int n, k, q;

short search(int i, int size, int last, int ans[]){
	if(i >= size){
		cout << size;
		for(int x=0;x<size;x++){
			cout << " " << ans[x];
		}
		cout << endl;
		
		string ans;
		cin >> ans;
		
		if(ans == "ya"){
			return 1;
		} else if(ans == "bisajadi"){
			return 0;
		}
		return -1;
	}
	
	short found = -1;
	for(int x=last+1;x<=n-(size-1-i);x++){
		ans[i] = x;
		
		short res = search(i+1, size, x, ans);
		if(res == -1) break;
		found = max(found, res);
	}
	return found;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string subsoal;
	cin >> subsoal >> subsoal;
	
	cin >> n >> k >> q;
	
	if(k == 1){
		if(n <= q){
			for(int x=1;x<=n;x++){
				string ans;
				cout << "1 " << x << endl;
				cin >> ans;
			
				if(ans == "ya"){
					return 0;
				} else if(ans == "bisajadi"){
					v.push_back(x);
				}
			}
		} else {
			int l = 1, r = n;
			while(l <= r){
				int mid = l+(r-l)/2;
				string ansKiri, ansKanan;
				
				cout << mid;
				for(int x=1;x<=mid;x++){
					cout << " " << x;
				}
				cout << endl;
				
				cin >> ansKiri;
				
				if(ansKiri == "ya") return 0;
				
				if(n-mid > 0){
					cout << n-mid;
					for(int x=mid+1;x<=n;x++){
						cout << " " << x;
					}
					cout << endl;
				
					cin >> ansKanan;
				} else {
					ansKanan = "tidak";
				}
				
				if(ansKiri == "ya" || ansKanan == "ya"){
					return 0;
				} else if(ansKiri == "bisajadi" && ansKanan == "bisajadi"){
					l = mid + 1;
				} else if(ansKiri == "bisajadi" && ansKanan == "tidak"){
					r = mid;
				}
			}
		}
	} else {
		for(int x=1;x<=n;x++){
			bool valid = true;
			for(int y=1;y<=n;y++){
				if(x==y) continue;
				cout << "2 " << min(x,y) << " " << max(x,y) << endl;
				
				string ans;
				cin >> ans;
				
				if(ans == "ya"){
					return 0;
				} else if(ans == "tidak"){
					valid = false;
					break;
				}
			}
			if(valid){
				v.push_back(x);
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size();
	for(int x=0;x<v.size();x++){
		cout << " " << v[x];
	}
	cout << endl;
	
    return 0;
}

