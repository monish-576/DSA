class StockSpanner {
public:
    int c=0;
    stack<pair<int,int>>pge;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!pge.empty()&&pge.top().first<=price)
        {
            pge.pop();
        }
        if(pge.empty())
        {
            pge.push({price,c});
            c++;
            return c;
        }
        else
        {
            int x=c-pge.top().second;
            pge.push({price,c});
            c++;
            return x;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */