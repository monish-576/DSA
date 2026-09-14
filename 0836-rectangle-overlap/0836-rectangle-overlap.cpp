class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0],y1=rec1[1];
        int x3=rec1[2],y3=rec1[3];
        int x2=rec1[2],y2=rec1[0];
        int x4=rec1[0],y4=rec1[3];
        int X1=rec2[0],Y1=rec2[1];
        int X3=rec2[2],Y3=rec2[3];
        int X2=rec2[2],Y2=rec2[0];
        int X4=rec2[0],Y4=rec2[3];
        if(Y1>=y4||X1>=x2||Y4<=y1||X2<=x1) return false;
        return true;
    }
};