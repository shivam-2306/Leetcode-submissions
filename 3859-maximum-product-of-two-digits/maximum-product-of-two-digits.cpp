class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> q;
        while(n>0){
            q.push(n%10);
            cout<<q.top()<<" ";
            n/=10;
        }
        int a = q.top();
        q.pop();
        return a*q.top();
    }
};