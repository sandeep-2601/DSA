#include<bits/stdc++.h>
using namespace std;

int fibanocci(int n) {
    if(n == 0 || n == 1) return n;
    return fibanocci(n-1) + fibanocci(n-2);
}

void subsequences(int arr[],int i,int n,vector<int> &res) {
    if(i == n) {
        for(int i:res)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    res.push_back(arr[i]);
    ++i;
    subsequences(arr,i,n,res);
    res.pop_back();
    subsequences(arr,i,n,res);
}

//prints subsequences with sum k
void subsequenceSumK(int arr[],int i,int n,vector<int> &res,int target,int sum) {
    if(sum > target) return;
    if(i == n) {
        if(sum == target) {
            for(int i:res) 
                cout<<i<<" ";
            cout<<endl;
        }
        return;
    }
    res.push_back(arr[i]);
    subsequenceSumK(arr,i+1,n,res,target,sum+arr[i]);
    res.pop_back();
    subsequenceSumK(arr,i+1,n,res,target,sum);
}

//finds whether any subsequence has sum k
bool hasSubsequenceSumK(int arr[],int i,int n,vector<int> &res,int target,int sum) {
    if(sum > target) return false;
    if(i == n) {
        if(sum == target) 
            return true;
        return false;
    }
    res.push_back(arr[i]);
    if(hasSubsequenceSumK(arr,i+1,n,res,target,sum+arr[i]) == true) return true;
    res.pop_back();
    if(hasSubsequenceSumK(arr,i+1,n,res,target,sum) == true) return true;
    return false;
}

//returns the number of subsequences with sum k
int noOfSubsequenceSumK(int i,int target,int sum,int arr[],int n) {
    if(i == n) {
        if(target == sum) {
            return 1;
        }
       else return 0;
    }
    int left = noOfSubsequenceSumK(i+1,target,sum+arr[i],arr,n);
    int right = noOfSubsequenceSumK(i+1,target,sum,arr,n);
    return left + right;
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int target = 3;

    vector<int> res;

    cout<<noOfSubsequenceSumK(0,target,0,arr,n);
    return 0;
}