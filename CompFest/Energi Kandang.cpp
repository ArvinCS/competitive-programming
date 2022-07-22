#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ll n, k, l, r, data[1000005];

float solve(ll i, priority_queue<float, vector<float>, greater<float>> minHeap){
	if(i == n && minHeap.size() == k){
		return minHeap.top();	
	}
	
	float ans = 1e19;
	for(ll x=l;x<=r;x++){
		if(i + x > n) break;
		
		float luas = 0;
		for(ll y=0;y<x;y++){
			luas += data[i+y];
		}
		luas /= ((float)x);

		priority_queue<float, vector<float>, greater<float>> tmpMin = minHeap;
		tmpMin.push(luas);
		if(tmpMin.size() > k){
			tmpMin.pop();
		}
		
		float tmp = solve(i+x, tmpMin);
//		cout << ans << " " << tmpMin.top() << " " << tmp << "\n";
		ans = fmin(ans, tmp);
	}	
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> k >> l >> r;
	
	for(ll x=0;x<n;x++) cin >> data[x];
	
	priority_queue<float, vector<float>, greater<float>> minHeap;
	cout << fixed << solve(0, minHeap) << "\n";
	
    return 0;
}

