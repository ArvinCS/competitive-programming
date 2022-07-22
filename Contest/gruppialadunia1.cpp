#include <iostream>

using namespace std;

bool isPossible(int n, int predict[], int p1, int p2, int score[]){
	//cout << p1 << " VS " << p2 << "\n";
	if(p2 > n-1){
		p1++;
		p2 = p1+1;
	}
	if(p1 == n-1){
		for(int x=0;x<n;x++){
			if(predict[x] != score[x]) return false;
		}
		return true;
	}
	//cout << "AFTER: " << p1 << " VS " << p2 << "\n";
	// Win Lose Draw based on P1
	int tempScore[n];
	copy(score, score+n, tempScore);
	tempScore[p1] += 3; // Jika menang maka skor +3
	bool win_p1 = isPossible(n, predict, p1, p2+1, tempScore);
	tempScore[p1] -= 2; // Karena awal sudah +3, -2 saja agar menjadi +1
	//cout << p2 << " to " << tempScore[p1] << " " << tempScore[p2] << "\n";
	tempScore[p2]++; // Karena seri maka p2 juga +1
	bool draw = isPossible(n, predict, p1, p2+1, tempScore);
	tempScore[p1]--;
	tempScore[p2] += 2;
	bool lose_p1 = isPossible(n, predict, p1, p2+1, tempScore);
	
	return win_p1 || draw || lose_p1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int predict[n];
		
		for(int x=0;x<n;x++){
			cin >> predict[x];
		}
		
		int score[n] = {0};
		if(isPossible(n, predict, 0,1,score)){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
