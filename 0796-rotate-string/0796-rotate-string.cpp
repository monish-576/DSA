class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string temp=s;
        temp+=s;
        return (temp.find(goal)!=string::npos)?true:false;
    }
};