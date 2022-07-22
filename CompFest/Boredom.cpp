#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ui cnt[100001];

ui solve(ui x){
	if(x == 1) return cnt[1];
	if(x == 0) return 0;
	
	return max(solve(x-1), solve(x-2) + cnt[x] * x);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(begin(cnt), end(cnt), 0);
	
	ui n, tmp;
	set<ui> numbers;
	
	cin >> n;
	while(n--){
		cin >> tmp;
		cnt[tmp]++;
		numbers.insert(tmp);
	}
	
	ui ans = 0;
	for(set<ui>::iterator it = numbers.begin(); it != numbers.end(); it++){
		tmp = solve(*it);
		ans = max(ans, tmp);
	}
	
	cout << ans << "\n";
    return 0;
}

