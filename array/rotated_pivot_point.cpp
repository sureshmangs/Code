using namespace std;

int findRotate(int a[], int n){
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]>a[i+1]) return (i+1)%n;
    return (i+1)%n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<findRotate(a, n)<<endl;
    }

return 0;
}
