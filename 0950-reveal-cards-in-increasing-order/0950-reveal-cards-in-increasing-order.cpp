class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
           vector<int>ans(deck.size());
           sort(deck.begin(),deck.end());
           queue<int>q;
           for(int i=0;i<deck.size();i++)
           {
              q.push(i);
           }
           int j=0;
           while(!q.empty())
           {
              int i=q.front();
              q.pop();
              ans[i]=deck[j];
              j++;
              if(q.empty()) break;
              int a=q.front();
              q.pop();
              q.push(a);
           }
            return ans;
    }
};