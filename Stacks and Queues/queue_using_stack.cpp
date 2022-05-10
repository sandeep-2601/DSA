#include<bits/stdc++.h>
using namespace std;

stack<int> s1;
stack<int> s2;
int front = -1;

void push(int val) {
    if(front == -1) front = val;
    s1.push(val);
}
int peek () {
    return front;
}
void pop() {
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    
    front = s2.empty() ? -1:s2.top();

    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

int main() {

    push(10);
    push(20);
    push(30);
    pop();
    cout<<peek()<<" ";
    push(40);

    while(!s1.empty()) {
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
    }