#include<bits/stdc++.h>
using namespace std;
 
#define MAX 1000000

void ETF_seive(vector <int> &phi) {
	
	for (int i = 2; i <= MAX; i++) {
		// prime number
		if (i == phi[i]) {
			for (int j = i; j <= MAX; j += i) {
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
}


 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	vector <int> phi(MAX + 1); // for storing phi
	
	for (int i = 1; i <= MAX; i++) phi[i] = i;
	
	ETF_seive(phi); // calculate phi for all numbers till N
	
	while (t--)  {
		int n;
		cin >> n;
		
		cout <<  phi[n] << "\n";
	}
	
    return 0;
}
