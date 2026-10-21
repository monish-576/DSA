class NumArray {
public:
    vector<int> arr;
    vector<int> segmentTree;
    int buildTree(int idx, int l, int r) {
        if (l == r) {
            return segmentTree[idx] = arr[l];
        }
        int mid = (l + r) / 2;
        int left = buildTree(2 * idx + 1, l, mid);
        int right = buildTree(2 * idx + 2, mid + 1, r);
        return segmentTree[idx] = left + right;
    }
    void updateTree(int idx, int l, int r, int index, int val) {
        if (l == r) {
            segmentTree[idx] = val;
            arr[index] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            updateTree(2 * idx + 1, l, mid, index, val);
        } else {
            updateTree(2 * idx + 2, mid + 1, r, index, val);
        }

        segmentTree[idx] = segmentTree[2 * idx + 1] + segmentTree[2 * idx + 2];
    }
    int sum(int idx, int l, int r, int L, int R) {
        if (r < L || l > R)
            return 0;

        if (L <= l && r <= R)
            return segmentTree[idx];

        int mid = (l + r) / 2;

        int left = sum(2 * idx + 1, l, mid, L, R);
        int right = sum(2 * idx + 2, mid + 1, r, L, R);

        return left + right;
    }
    NumArray(vector<int>& nums) {
        arr = nums;
        segmentTree.resize(4 * nums.size(), 0);
        buildTree(0, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        updateTree(0, 0, arr.size() - 1, index, val);
    }

    int sumRange(int left, int right) {
        return sum(0, 0, arr.size() - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */