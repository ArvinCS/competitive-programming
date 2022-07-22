#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int lst[26];
	fill(lst, lst+26, -1);
	
	auto op1 = [&](int idx) -> int {
		cout << "? 1 " << idx+1 << endl;
		
		char c;
		cin >> c;
		
		return (c - 'a'); 
	};
	
	auto op2 = [&](int l, int r) -> int {
		cout << "? 2 " << l+1 << " " << r+1 << endl;
		
		int res;
		cin >> res;
		
		return res;
	};
	
	char ans[n];
	
	int cnt = 1;
	
	{
		int tmp = op1(0);
		lst[tmp] = 0;
		ans[0] = ('a' + tmp);
	}
	
	// op1 : O(26)
	// op2 : O(Nlog26) -> ~4000
	for(int x=1;x<n;x++){
		int cur = op2(0, x);
		assert(cnt <= cur);
		
		if(cur == cnt){
			vector<pair<int, int>> v;
			for(int x=0;x<26;x++){
				if(lst[x] != -1){
					v.push_back({lst[x], x});
				}
			}
			
			sort(v.begin(), v.end());
			
			int pos = v.size();
			int left = 0, right = v.size()-1;
			while(left <= right){ // O(log(26))
				int mid = (left+right) >> 1;
				
				if(op2(v[mid].first, x) == v.size()-mid+1){
					pos = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			int tmp = v[pos-1].second;
			lst[tmp] = x;
			ans[x] = ('a' + tmp);
		} else {
			int tmp = op1(x);
			
			lst[tmp] = x;
			ans[x] = ('a' + tmp);
			cnt++;
		}
	}
	
	cout << "! ";
	for(int x=0;x<n;x++){
		cout << ans[x];
	}
	cout << endl;
    return 0;
}

