#include <iostream>

using namespace std;

short rasyid[9], rahman[9];

string solve(short n, short m){
	short table[9][9] = {};
	fill(&table[0][0], &table[0][0] + 9 * 9, 0);
	
	for(short x=1;x<=n;x++){
		for(int short y=1;y<=m;y++){
			table[x][y] = rasyid[x] * rahman[y];
		}
	}	
	
	short range = 9;
	
	string ans;
	int remain = 0;
	for(short x=1;x<=range;x++){
		short point = remain, a = x;
		while(a >= 1){
			point += table[a][x-a+1];
			a--;
		}
		
		if(point > 10) remain = point/10;
		else remain = 0;
		
		point %= 10;
		
		ans.insert(0, to_string(point));
	}
	
	return ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n,m;
	cin >> n >> m;
	
	for(int x=1;x<=n;x++) cin >> rasyid[x];
	for(int x=1;x<=m;x++) cin >> rahman[x];
	
	cout << solve(n,m) << "\n";
	
    return 0;
}
