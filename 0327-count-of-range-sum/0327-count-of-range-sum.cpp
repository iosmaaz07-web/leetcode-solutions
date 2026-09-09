class Solution {
public:
int countRangeSum(vector<int>& nums, int lower, int upper) {

    int n = nums.size();

    vector<long long> pre(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + nums[i];
    }

    return mergeSort(pre, 0, n, lower, upper);
}
int mergeSort(vector<long long>& pre, int left, int right,
              int lower, int upper) {

    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int ans = 0;

    ans += mergeSort(pre, left, mid, lower, upper);
    ans += mergeSort(pre, mid + 1, right, lower, upper);

    int j = mid + 1;
    int k = mid + 1;

   
    for (int i = left; i <= mid; i++) {

        while (j <= right && pre[j] - pre[i] < lower)
            j++;

        while (k <= right && pre[k] - pre[i] <= upper)
            k++;

        ans += k - j;
    }

 
    vector<long long> temp;

    int i = left;
    int p = mid + 1;

    while (i <= mid && p <= right) {

        if (pre[i] <= pre[p]) {
            temp.push_back(pre[i]);
            i++;
        }
        else {
            temp.push_back(pre[p]);
            p++;
        }
    }

    while (i <= mid) {
        temp.push_back(pre[i]);
        i++;
    }

    while (p <= right) {
        temp.push_back(pre[p]);
        p++;
    }

    for (int i = left; i <= right; i++) {
        pre[i] = temp[i - left];
    }

    return ans;
}
};