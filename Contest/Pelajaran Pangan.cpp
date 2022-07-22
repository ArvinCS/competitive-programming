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

vector<ll> data;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		ll tmp;
		cin >> tmp;
		
		data.push_back(tmp);
	}
	
	sort(data.begin(), data.end());

	ull ans = inf_int, cur = 0;
	for(int x=1;x<data.size();x++){
		int index = x%data.size(), behindIndex = (data.size()+index-1)%data.size();
		if(data[index] >= data[behindIndex]){
			cur += data[index]-data[behindIndex];
		} else {
			cur += m+data[behindIndex]-data[index];
		}
	}
	ans = cur;
	
	for(int x=1;x<data.size();x++){
		int tail = (data.size()+x-1)%data.size();
		int behindTail = (data.size()+tail-1)%data.size();
		
		cur -= data[(tail+1)%data.size()] - data[tail];
		if(data[tail] >= data[behindTail]){
			cur += data[tail]-data[behindTail];
		} else {
			cur += m+data[tail]-data[behindTail];
		}
		
		ans = min(ans, cur);
	}
	
	cout << ans << "\n";
    return 0;
}

