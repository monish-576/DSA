class Solution {
public:
    int a=0,b=0;
    void help1(string answerKey,int k)
    {
        int i=0,j=0,c=0;
        while(j<answerKey.size())
        {
            if(answerKey[j]=='T') c++;
            while(c>k)
            {
                if(answerKey[i]=='T')c--;
                i++;
            }
            b=max(b,j-i+1);
            j++;
        }
    }
    void help(string answerKey,int k)
    {
        int i=0,j=0,c=0;
        while(j<answerKey.size())
        {
            if(answerKey[j]=='F') c++;
            while(c>k)
            {
                if(answerKey[i]=='F')c--;
                i++;
            }
            a=max(a,j-i+1);
            j++;
        }
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
       help(answerKey,k);
       help1(answerKey,k);
       return max(a,b);
    }
};