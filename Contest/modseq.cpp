#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mx = 5 * 1e5;

vector<ui> ans;
bool exist[mx+100000];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, k;
	cin >> n >> k;
	
	ui data[n], useMod = 0;
	bool mods[k];
	
	fill(mods, mods+k, false);
	fill(exist, exist+mx+100000, false);
	exist[0] = true;
	
	for(ui x=0;x<n;x++){
		cin >> data[x];
		exist[data[x]] = true;
		if(!mods[data[x] % k]){
			useMod++;
			mods[data[x] % k] = true;
		}
	}
	
	ll sum = 0, i = 0;
	while(i < k-1){
		if(mods[data[i] % k]){
			useMod--;
			mods[data[i] % k] = false;
			sum += data[i];
			ans.push_back(data[i++]);
		} else {
			break;
		}
	}

	for(ui x=0;x<k;x++){
		if(ans.size() == k) break;
		if(!mods[x]) continue;
		
		if(ans.size() < k-1 || (sum+x) % k == 0){
			useMod--;
			ui newNum = x;
			while(exist[newNum]) newNum += k;
			
			if(x == data[i] % k) ans.push_back(data[i++]);
			else ans.push_back(newNum);
			
			exist[ans.back()] = true;
			sum += ans.back();
		}
	}
	
	for(ui x=ans.size();x<k-1;x++){ // masukin slot kosong sampai length k-1
		ans.push_back(data[i++]);
		sum += ans.back();
	}
	
	if(ans.size() == k-1){ // bikin jadi bisa dibagi k
		int next = k - (sum % k);
	
		if(data[i] % k == next % k){
			ans.push_back(data[i++]);
		} else {
			while(exist[next]) next += k;
			ans.push_back(next);
			exist[next] = true;
		}
	}
		
	if(useMod > 0){ // ada mod yang tidak kemasukan ke subarray length k
		cout << "-1\n";
		return 0;
	}
		
	while(i < n){
		int need = ans[ans.size()-k] % k;
		if(need % k == data[i] % k){
			ans.push_back(data[i++]);
		} else {
			while(exist[need]){
				need += k;
			}
			if(need > mx){
				cout << "-1\n";
				return 0;
			}
			exist[need] = true;
			ans.push_back(need);
		}
		if(ans.size() > mx) break;
	}
	
	if(ans.size() <= mx && i == n){
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	} else {
		cout << "-1\n";
	}
	
    return 0;
}

