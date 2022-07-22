#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxB = (1 << 10);
const int maxT = 50;
const int maxL = 20;
const ll mx = 1e18 + 5;

ll visited[maxT][maxL][maxB];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	fill(*visited[0], *visited[maxT], -1);
	
	{
		int state = 0, len = 0;
		ll cur = m;
		while(cur > 0){
			state |= (1 << (cur%10));
			len++;
			cur /= 10;
		}
		
		visited[0][len][state] = m;
	}
	
	for(int t=0;t+1<maxT;t++){
		for(int l=1;l+1<maxL;l++){
			for(int s=1;s<maxB;s++){
				if(visited[t][l][s] == -1) continue;
				
				for(int c=1;c<10;c++){
					if(s&(1 << c)){
						if(c > ((mx+visited[t][l][s]-1)/visited[t][l][s])){
							break;
						}
						
						ll cur = visited[t][l][s]*1ll*c;
						int len = 0;
						int state = 0;
						
						while(cur > 0){
							len++;
							state |= (1 << (cur%10));
							cur /= 10;
						}
						
						visited[t+1][len][state] = max(visited[t+1][len][state], visited[t][l][s]*1ll*c);
					}
				}
			}
		}
	}
	
	int ans = -1;
	for(int t=0;t<maxT;t++){
		for(int s=1;s<maxB;s++){
			if(visited[t][n][s] != -1){
				ans = t;
				break;
			}
		}
		if(ans != -1) break;
	}
	
	cout << ans << "\n";
    return 0;
}

