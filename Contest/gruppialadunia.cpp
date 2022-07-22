#include <iostream>
#include <cmath>

using namespace std;

struct TeamScore {
	int win = 0,draw = 0,lose = 0;
};

bool isPossible(int n, int team[], int i, TeamScore score[], int possibility[]){
	if(i == n){
		int same = 0;
		bool checked[n] = { false };
				
		for(int x=0;x < n;x++){
			int win = score[x].win;
			if(win > 0){
				for(int y=0;y<n && win > 0;y++){
					if(y==x) continue;
					if(score[y].lose < 0){
						score[y].lose++;
						win--;
					}
				}
			}
			score[x].win = win;
			int draw = score[x].draw;
			cout << x << " draw: " << draw << "\n";
			if(draw < 0){
				for(int y=0;y<n && draw < 0;y++){
					if(y==x) continue;
					if(score[y].draw < 0){
						score[y].draw++;
						draw++;
					}
				}
			}
			score[x].draw = draw;
			cout << "after: " << possibility[x] << ":" << score[x].win << "-" << score[x].draw << "-" << score[x].lose << "\n";
		}
		
		cout << "POSSIBILITY: ";
		for(int x=0;x<n;x++){
			cout << possibility[x] << ":" << score[x].win << "-" << score[x].draw << "-" << score[x].lose << " ";
		}
		cout << "\n";
		// 4 0 7 3
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(!checked[y] && possibility[y] == team[x] && score[y].win == 0 && score[y].draw == 0 && score[y].lose == 0){
					//cout << y << " same with " << x << "\n";
					checked[y] = true;
					same++;
					break;
				}
			}
		}
		//cout << "loses: " << loses << "\n";
		return same == n;
	}
	bool run = false;
	//cout << " ------------------------- \n";
	//(loses < 0 ? 0 : loses)
	for(int win=0;win<n-score[i].draw-score[i].lose && !run;win++){
		for(int draw=0;draw < n-win-score[i].lose && !run;draw++){
			TeamScore tmpList[n];
			
			copy(score, score+n, tmpList);
			
			TeamScore ts = tmpList[i];
			ts.win += win;
			ts.lose -= n-1-win-draw;
			ts.draw -= draw;
			cout << i << " : " << win << "-" << ts.draw << "-" << ts.lose << "\n";
			/*int tmpLose[n] = { 0 };
			int tmpTie[n] = { 0 };
			copy(lose, lose+n, tmpLose);
			copy(tie, tie+n, tmpTie);
			
			tmpLose[i] -= n-1-win-draw;
			tmpTie[i] -= draw;
			int count = 0;
			for(int x=0;count < max(win, draw);x++){
				if(i == x) continue;
				if(count < draw) tmpTie[x]++;
				if(count < win) tmpLose[x]++;
				count++;
			}*/
			if(i < 1) cout << "draw of " << i + 1 << " : " << tmpList[i+1].draw << "\n";
			possibility[i] = win * 3 + draw;
			tmpList[i] = ts;
			run = isPossible(n, team, i+1, tmpList, possibility);
		}
	}
	return run;
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
		
		int tim[n];
		bool valid = false;
		for(int x=0;x<n;x++){
			cin >> tim[x];
			if(tim[x] > 0) valid = true;
		}
		
		int possibility[n] = { 0 };
		TeamScore teamScore[n];
		bool possible = isPossible(n, tim, 0, teamScore, possibility);
		if(valid && possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
