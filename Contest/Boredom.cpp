#include <iostream>

using namespace std;

long long data[100001] = { 0 };

long long solve(){
	long long table[100001] = { 0 };
	table[1] = data[1];
	table[2] = max(data[1], data[2] * 2);
	
	//cout << "1-> " << table[1] << "\n";
	//cout << "2-> " << table[2] << "\n";
	for(int x=3;x<=100000;x++){
		table[x] = max(table[x-1], table[x-2] + (data[x] * x));
		//cout << x << "-> " << table[x] << "\n";
	}
	
	return table[100000];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	long long tmp;
	for(int x=0;x<n;x++){
		cin >> tmp;
		data[tmp]++;
	}
	
	cout << solve() << "\n";
    return 0;
}
