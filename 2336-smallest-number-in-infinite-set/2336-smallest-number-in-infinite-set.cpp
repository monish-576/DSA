class SmallestInfiniteSet {
public:
    set<int>s;
    int i;
    SmallestInfiniteSet() {
        i=1;
    }
    
    int popSmallest() {
        if(s.empty()) 
        return i++;
        else
        {
          int min_val = *s.begin();
          if(min_val==i)
          {
             s.erase(min_val);
             return i++;
          }
          if(min_val<i)
          {
            s.erase(min_val);
            return min_val;
          }
          else
          {
            return i++;
          }
        }
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */