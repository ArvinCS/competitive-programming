#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k, d;
	cin >> n >> k >> d;
	
	string s;
	cin >> s;
	
	int left[k], right[k];
	fill(left, left+k, -1);
	fill(right, right+k, -1);
	
	int pos = 0, cnt = 0;
	while(pos < n && cnt < k){
		if(s[pos] == 'x'){
			pos++;
			continue;
		}
		
		left[cnt++] = pos;
		pos += d+1;
	}
	
	pos = n-1, cnt = k-1;
	while(pos >= 0 && cnt >= 0){
		if(s[pos] == 'x'){
			pos--;
			continue;
		}
		
		right[cnt--] = pos;
		pos -= d+1;
	}
	
	vector<int> ans;
	for(int x=0;x<k;x++){
		if(left[x] != -1 && left[x] == right[x]){
			ans.push_back(left[x]);
		}
	}
	
	if(ans.empty()){
		cout << "-1\n";
		return 0;
	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	for(int x=0;x<ans.size();x++){
		cout << ans[x]+1 << "\n";
	}
    return 0;
}

