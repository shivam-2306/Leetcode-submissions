class Solution {
public:
    int countCollisions(string d) {
        stack<char> s;
        int result = 0;
        int i = 0;
        while(i!=d.size() && d[i] == 'L') i++;
        
        for(i;i<d.size();i++){
            if(s.empty()){
                // cout<<"first if"<<endl;
                s.push(d[i]);
                // cout<<result<<endl;
                continue;
            }
            if(d[i] == 'L'){
                // cout<<"Second if where L"<<endl;
                if(s.top() == 'S')
                    result++;
                
                else if(s.top() == 'R'){
                    result += 2;
                    s.pop();
                    while(!s.empty() && s.top() == 'R'){
                        result += 1;
                        s.pop();
                    }
                    s.push('S');
                }
            }
            else if(d[i] == 'S'){
                // cout<<"Third if where S"<<endl;
                while(!s.empty() && s.top() == 'R'){
                    result += 1;
                    s.pop();
                }
                    s.push('S');
            }
            else {
                // cout<<"else where R"<<endl;
                s.push(d[i]);
            }
            // cout<<result<<endl;
        }       
        return result;
    }
};