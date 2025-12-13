class Solution {
public:
    
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 int timeA = stoi(a[1]);
                 int timeB = stoi(b[1]);
                 if (timeA != timeB) {
                     return timeA < timeB;
                 }

                 return a[0] == "OFFLINE" && b[0] == "MESSAGE";
             });

        queue<pair<int, int>> q;
        vector<int> totalMessages(n, 0);
        unordered_set<int> onlineUsers;
        for (int i = 0; i < n; i++) {
            onlineUsers.insert(i);
        }
        for (auto i : events) {

            while (!q.empty() && q.front().second <= stoi(i[1])) {
                onlineUsers.insert(q.front().first);
                q.pop();
            }
            if (i[0] == "MESSAGE") {
                if (i[2] == "ALL") {
                    transform(totalMessages.begin(), totalMessages.end(),
                              totalMessages.begin(),
                              [](int x) { return x + 1; });
                } else if (i[2] == "HERE") {
                    for (int ind : onlineUsers) {
                        totalMessages[ind]++;
                    }
                } else {
                    stringstream ss(i[2]);
                    string token;

                    while (ss >> token) {
                        int startPos = token.find_first_of("0123456789");
                        if (startPos != string::npos) {
                            int id = stoi(token.substr(startPos));
                            totalMessages[id]++;
                        }
                    }
                }
            } else {
                q.push({stoi(i[2]), stoi(i[1]) + 60});
                onlineUsers.erase(stoi(i[2]));
            }
        }
        return totalMessages;
    }
};