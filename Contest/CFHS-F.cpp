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

const int maxA = 3e5 + 5;

ll sum[maxA], cnt[maxA];

void updateSum(int pos, ll val){
	pos++;
	
	while(pos < maxA){
		sum[pos] += val;
		
		pos += pos&(-pos);
	}
}

ll querySum(int pos){
	pos++;
	
	ll ans = 0;
	while(pos > 0){
		ans += sum[pos];
		
		pos -= pos&(-pos);
	}
	return ans;
}

void updateCnt(int pos, ll val){
	pos++;
	
	while(pos < maxA){
		cnt[pos] += val;
		
		pos += pos&(-pos);
	}
}

ll queryCnt(int pos){
	pos++;
	
	ll ans = 0;
	while(pos > 0){
		ans += cnt[pos];
		
		pos -= pos&(-pos);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	fill(sum, sum+maxA, 0);
	fill(cnt, cnt+maxA, 0);
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll ans = 0, sum = 0;
	for(int x=0;x<n;x++){
		ans += sum+a[x]*x+querySum(a[x]); // ax mod ai (i < x)
		
		for(int y=a[x];y<maxA;y+=a[x]){
			updateSum(y, -a[x]);
			ans -= (queryCnt(maxA-3) - queryCnt(y-1)) * a[x]; // ai mod ax (i < x)
		}
		updateCnt(a[x], 1);
		
		sum += a[x];
		
		if(x > 0) cout << " ";
		cout << ans;
	}
	cout << "\n";
    return 0;
}

