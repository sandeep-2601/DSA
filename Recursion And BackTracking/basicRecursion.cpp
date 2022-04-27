#include<bits/stdc++.h>
using namespace std;

void print1ToN(int n) {
    if(n == 0) return;
    print1ToN(n-1);
    cout<<n;
}

int factorial(int n) {
    if(n == 1) return 1;
    return n*factorial(n-1);
}

void reverse(int arr[],int i,int n) {
    if(i>=n) return;
    swap(arr[i++],arr[n--]);
    reverse(arr,i,n);
}

bool isPalindrome(string &s,int i,int n) {
    if(i >= n) return true;
    return (s[i++] == s[n--]) && isPalindrome(s,i,n);
}

int main() {
    int n;
    string s;
    cin>>n;
    cin>>s;

    cout<<isPalindrome(s,0,n-1);

}