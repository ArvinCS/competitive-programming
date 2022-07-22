#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

bool customSort(tuple<int, int, string> a, tuple<int, int, string> b){
	if(get<0>(a) < get<0>(b)) return true;
	else if(get<0>(a) < get<0>(b)) return get<1>(a) < get<1>(b);
	else return false;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	vector<tuple<int, int, string>> data;
	while(n--){
		string tmp;
		cin >> tmp;
		
		int col = 0, startRow = 0;
		bool first = (tmp[0] == 'R');
		for(int x=1;x<tmp.length();x++){
			if(tmp[x] == 'C' && (tmp[x+1] >= '0' && tmp[x+1] <= '9')){
				startRow = x+1;
				break;
			}
			
			col *= 10;
			if(first)col += tmp[x] - 'A';
			else col += tmp[x] - '0';
		}
	
		int row = 0;
		for(int x=startRow;x<tmp.length();x++){
			row *= 10;
			row += tmp[x] - '0';	
		}
		
		data.push_back(make_tuple(row, col, tmp));
	}
	
	sort(data.begin(), data.end(), customSort);
	
	for(ui x=0;x<data.size();x++){
		cout << get<2>(data[x]) << "\n";
	}
    return 0;
}

