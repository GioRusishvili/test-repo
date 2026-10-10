#include <iostream>
#include <cmath>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    int a[200001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }
    unordered_map<int, int> m;
    stack<int> st;
    for(int i = 0; i < n; i++){
        m[a[i]] = i;
    }
    int count = 0;;
    for(int i = n-1; i >= 0; i--){
        if(m[a[i]] == i) {
            st.push(a[i]);
            count++;
        }
    }
    cout << count << endl;
    for(int i = 0; i < st.size(); i++){
        cout << st.top() << " ";
        st.pop();
    }
}