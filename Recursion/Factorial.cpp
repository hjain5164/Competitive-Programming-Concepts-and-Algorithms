// Problem - Write a recursive code to calculate the factorial of a number 
#include <iostream>
#define ll long long int
using namespace std;

ll factorial(ll n){
    if(n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    ll n;
    cin>>n;
    cout << factorial(n) << endl;
}
