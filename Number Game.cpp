bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
 
bool isPowerOfTwo(LL x){
    return (x & (x - 1)) == 0;
}
 
void game(LL n){
    if(n!=2 &&(isPowerOfTwo(n) || (n%2 == 0 && isPrime(n/2)) || n==1))
        cout << "FastestFinger" << endl;
    else cout << "Ashishgup" << endl;
}
 
void solve(){
    LL n;
    cin >> n;
    game(n);
}
