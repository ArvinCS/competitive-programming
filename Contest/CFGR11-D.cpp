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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int data[n], tmp[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	vector<vector<int>> ans;
	bool ok = true;
	for(int x=1;x<n;x++){
		if(data[x-1]+1 != data[x]){
			ok = false;
			break;
		}
	}
	while(!ok){
		vector<int> v;
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				if(data[a] != data[b]+1){
					continue;
				}
				
				for(int c=a;c<b;c++){
					if(data[c] > data[c+1]){
						if(a > 0) v.push_back(a);
						if(c-a+1 > 0) v.push_back(c-a+1);
						if(b-c > 0) v.push_back(b-c);
						if(n-b-1 > 0) v.push_back(n-b-1);
						break;
					}
				}
				if(v.size() > 0) break;
			}
			if(v.size() > 0) break;
		}
		
		int idx = 0, idx2 = n-1;
		for(auto e : v){
			int pos = idx+e-1;
			while(pos >= idx) tmp[idx2--] = data[pos--];
			idx += e;
		}
		for(int x=0;x<n;x++){
			data[x] = tmp[x];
		}
		
		ans.push_back(v);
		bool sorted = true;
		for(int x=1;x<n;x++){
			if(data[x-1]+1 != data[x]){
				sorted = false;
				break;
			}
		}
		
		if(sorted) break;
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		cout << ans[x].size();
		for(auto a : ans[x]) cout << " " << a;
		cout << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

