#include "guess.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int NA, NB, NC;

void initialize(int NA, int NB, int NC) {
	::NA = NA, ::NB = NB, ::NC = NC;
}

int guess(int K) {
	int leftA = 0, rightA = NA-1;
	int leftB = 0, rightB = NB;
	int leftC = 0, rightC = NC;
	
	int lastMove = 0;
	int last = -1, lastcnt = -1;
	while(leftA <= rightA){
		int midA = (leftA+rightA) >> 1;
		
		int cnt = -1, cnt2 = -1;
		
		int leftTmp1 = leftB, rightTmp1 = rightB;
		while(leftTmp1 <= rightTmp1){
			int midTmp1 = (leftTmp1+rightTmp1) >> 1;
			
			if(ask(midA, midTmp1, NC) == 1){
				cnt = max(cnt, midTmp1);
				leftTmp1 = midTmp1+1;
			} else {
				rightTmp1 = midTmp1-1;
			}
		}
		
		int leftTmp2 = leftC, rightTmp2 = rightC;
		while(leftTmp2 <= rightTmp2){
			int midTmp2 = (leftTmp2+rightTmp2) >> 1;
			
			if(ask(midA, NB, midTmp2) == 2){
				cnt2 = max(cnt2, midTmp2);
				leftTmp2 = midTmp2+1;
			} else {
				rightTmp2 = midTmp2-1;
			}
		}
		
//		cout << "NA " << leftA << " " << midA << " " << rightA << " " << cnt << " " << midA+cnt+1 << "\n";
		if(midA+cnt+1+cnt2+1 == K){
			return midA;
		} else if(midA+cnt+1+cnt2+1 < K){
			if(midA+cnt+1+cnt2+1 > last){
				last = midA+cnt+1+cnt2+1;
				lastcnt = cnt2;
			}
			
			leftA = midA+1;
			leftB = max(leftB, cnt);
			leftC = max(leftC, cnt2);
			lastMove = 0;
		} else {
			rightA = midA-1;
			rightB = min(rightB, cnt);
			rightC = min(rightC, cnt2);
			lastMove = 1;
		}
	}
	
	leftA = max(leftA-1, 0);
	rightA = min(rightA+1, NA);
	while(leftB <= rightB){
		int midB = (leftB+rightB) >> 1;
		
		int cnt = -1, cnt2 = -1;
		
		int leftTmp1 = leftA, rightTmp1 = rightA;
		while(leftTmp1 <= rightTmp1){
			int midTmp1 = (leftTmp1+rightTmp1) >> 1;
			
			if(ask(midTmp1, midB, NC) == 0){
				cnt = max(cnt, midTmp1);
				leftTmp1 = midTmp1+1;
			} else {
				rightTmp1 = midTmp1-1;
			}
		}
		
		int leftTmp2 = leftC, rightTmp2 = rightC;
		while(leftTmp2 <= rightTmp2){
			int midTmp2 = (leftTmp2+rightTmp2) >> 1;
			
			if(ask(NA, midB, midTmp2) == 2){
				cnt2 = max(cnt2, midTmp2);
				leftTmp2 = midTmp2+1;
			} else {
				rightTmp2 = midTmp2-1;
			}
		}
		
//		cout << "NB " << leftB << " " << midB << " " << rightB << " " << cnt << " " << cnt2 << " " << midB+cnt+cnt2+2 << "\n";
		if(midB+cnt+1+cnt2+1 == K){
			return NA+midB;
		} else if(midB+cnt+1+cnt2+1 < K){
			if(midB+cnt+1+cnt2+1 > last){
				last = midB+cnt+1+cnt2+1;
				lastcnt = cnt2;
			}
			
			leftA = max(leftA, cnt);
			leftB = midB+1;
			leftC = max(leftC, cnt2);
		} else {
			rightA = min(rightA, cnt);
			rightB = midB-1;
			rightC = min(rightC, cnt2);
		}
	}
	
	return NA+NB+lastcnt+1+(K-(last+1));
}
