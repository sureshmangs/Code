#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 	int t;
 	cin >> t;
 	
 	while (t--) {
 		int n;
 		cin >> n;
 		
 		vector <int> v(n);
 		for(int i = 0; i < n; i++) cin >> v[i];
 		
 		int hill = 0, valley = 0;
 		
 		for (int i = 1; i < n - 1; i++) {
 			if(v[i] > v[i - 1] && v[i] > v[i + 1]) hill++;
 			if(v[i] < v[i - 1] && v[i] < v[i + 1]) valley++;
		 }
		 cout << hill + valley << endl;
	 }

    return 0;
}

