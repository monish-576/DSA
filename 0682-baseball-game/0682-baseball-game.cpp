class Solution {
public:
    int calPoints(vector<string>& operations) {
         stack<int>st;
         int ans=0;
         for(int i=0;i<operations.size();i++)
         {
            if(operations[i]=="C")
            {
                 st.pop();
            }
            else if(operations[i]=="D")
            {
                 st.push(st.top()*2);
            }
            else if(operations[i]=="+")
            {
                 int s1,s2,c=0;
                 while(!st.empty()&&c<2)
                 {
                    if(c==0)
                    s1=st.top();
                    else
                    s2=st.top();
                    st.pop();
                    c++;
                 }
                 int x=s1+s2;
                 st.push(s2);
                 st.push(s1);
                 st.push(x);
            }
            else
            {
                st.push(stoi(operations[i]));
            }
         }
         while(!st.empty())
         {
            ans+=st.top();
            st.pop();
         }
         return ans;
    }
};