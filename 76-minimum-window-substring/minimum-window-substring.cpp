class Solution {
public:
    bool checkArr(vector<int>& arr1, vector<int>& arr2){
        for(int i = 0; i < 257; i++){
            if(arr1[i] == 0){
                continue;
            }
            if(arr1[i] > arr2[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || t.size() > s.size()) return "";

        vector<int> frequencyMap(257, 0);
        vector<int> windowMap(257, 0);

        for(auto ch : t){
            frequencyMap[ch]++;
        }

        int i = 0, j = 0;

        while(i < s.length() && frequencyMap[s[i]] == 0){
            i++;
        }

        if(i == s.length()) return "";

        windowMap[s[i]]++;
        j = i;

        queue<int> q;
        q.push(i);

        while(j < s.length() - 1 && !checkArr(frequencyMap, windowMap)){
            j++;

            if(frequencyMap[s[j]]){
                q.push(j);
                windowMap[s[j]]++;
            }
        }
        if(!checkArr(frequencyMap, windowMap)) return "";
        while(!q.empty() &&
              frequencyMap[s[q.front()]] < windowMap[s[q.front()]]) {

            int temp = q.front();
            q.pop();

            windowMap[s[temp]]--;

            if(!q.empty())
                i = q.front();
        }

        int left = i, right = j, shortest = j - i + 1;

        j++;

        while(j < s.length()){
            if(frequencyMap[s[j]]){
                windowMap[s[j]]++;
                q.push(j);
                while(!q.empty() &&
                      frequencyMap[s[q.front()]] < windowMap[s[q.front()]]) {

                    int temp = q.front();
                    q.pop();

                    windowMap[s[temp]]--;

                    if(!q.empty())
                        i = q.front();
                }

                if(j - i + 1 < shortest){
                    left = i;
                    right = j;
                    shortest = j - i + 1;
                }
            }

            j++;
        }

        return s.substr(left, shortest);
    }
};