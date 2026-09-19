class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int x3 = x2, y3 = y1, x4 = x1, y4 = y2;
        int X1 = xCenter, Y1 = yCenter - (radius), X2 = xCenter + radius,
            Y2 = yCenter, X3 = xCenter, Y3 = yCenter + radius,
            X4 = xCenter - radius, Y4 = yCenter;
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;

        if (dx * dx + dy * dy <= 1LL * radius * radius)
            return true;

        return false;
    }
};