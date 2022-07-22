#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	ui data[n], idxOne = 0;
	bool visited[n];
	for(us x=0;x<n;x++){
		cin >> data[x];
		visited[x] = false;
		if(data[x] == 1) idxOne = x;
	}
	
	string ways;
	if(n > 1){
		int tmp = n, currentIndex = 0;
		bool right = false;
		while(tmp > 0){
			if(right){
				currentIndex += 2;
				currentIndex %= n;
				ways += 'R';
				ways += 'R';
				right = false;
			} else {
				currentIndex--;
				if(currentIndex < 0) currentIndex = n-1;
				ways += 'L';
				right = true;
			}
			if(!visited[currentIndex]){
				ways += 'G';
				tmp--;
				visited[currentIndex] = true;
			}
		}
	}
	
	if(ways.length() <= 101){
		cout << ways.length() << "\n";
		if(ways.length() > 0) cout << ways << "\n";
	} else {
		cout << "-1\n";
	}
	
    return 0;
}

