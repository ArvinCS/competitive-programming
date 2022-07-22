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

int ask(vector<int> q){
	cout << "?";
	for(int x=0;x<100;x++){
		cout << " " << q[x];
	}	
	cout << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

void answer(int n){
	cout << "! " << n << endl;
}

int getLeftBit(int n){
	int pos = -1;
	for(int x=0;x<=31;x++){
		if(n&(1ll << x)) pos = x;
	}	
	return pos;
}

int getRightBit(int n){
	for(int x=0;x<=31;x++){
		if(n&(1ll << x)) return x;
	}	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	vector<int> q1;
	int cnt = 0;
	for(int x=1;x<=16383;x++){
		q1.push_back(x);
		cnt++;
		if(cnt >= 100) break;
	}
	
	sort(q1.begin(), q1.end());
	
	int r1 = ask(q1);
	
	vector<int> q2;
	int startBit = getLeftBit(q1.back())+1;
	cnt = 1;
	
	q2.push_back(0);
	for(int x=(1ll << startBit);x<=16383;x++){
		if(getRightBit(x) >= startBit){
			q2.push_back(x);
			cnt++;
			if(cnt >= 100) break;
		}
	}
	
	int r2 = ask(q2);
	
	int ans = 0;
	if(getLeftBit(r2) >= startBit){
		for(int x=0;x<startBit;x++){
			if(r2&(1 << x)){
				ans += (1 << x);
			}
		}
	} else {
		ans += r2;
	}
	
	if(getLeftBit(r1) >= startBit){
		for(int x=startBit;x<=15;x++){
			if(r1&(1ll << x)) ans += (1ll << x);
		}
	}
	
	answer(ans);
    return 0;
}

// Santai
// Pikirin dengan benar-benar

