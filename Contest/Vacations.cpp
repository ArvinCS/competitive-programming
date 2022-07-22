#include <iostream>

using namespace std;

char data[100] = {'0'};

int solve(int n){
	int table[n][3];
	fill(&table[0][0], &table[0][0] + n*3, 1001);
	// kiri untuk menunjukkan jumlah hari yang telah diambil
	// kanan hari yang telah diambil
	
	table[0][0] = 1;
	if(data[0] == '1' || data[0] == '3') table[0][1] = 0;
	if(data[0] == '2' || data[0] == '3') table[0][2] = 0;
	
	for(int x=1;x<n;x++){
		table[x][0] = min(table[x-1][0], min(table[x-1][1], table[x-1][2])) + 1;
		if(data[x] == '1'){
			table[x][1] = min(table[x-1][0], table[x-1][2]);
		} else if(data[x] == '2'){
			table[x][2] = min(table[x-1][0], table[x-1][1]);
		} else if(data[x] == '3'){
			table[x][1] = min(table[x-1][0], table[x-1][2]);
			table[x][2] = min(table[x-1][0], table[x-1][1]);
		}
	}
	
	return min(table[n-1][0], min(table[n-1][1], table[n-1][2]));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++) cin >> data[x];
	
	cout << solve(n) << "\n";
	
    return 0;
}
