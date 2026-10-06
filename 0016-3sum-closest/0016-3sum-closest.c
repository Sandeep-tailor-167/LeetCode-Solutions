int threeSumClosest(int* nums, int n, int target) {
    int a = 0, b = 1, c = 2;
    int sum = nums[0] + nums[1] + nums[2];
    int diff = target - sum;
    diff = (diff < 0) ? (-diff) : diff;
    int mindiff = diff;
    int bestsum = sum;
    for (a = 0; a < n - 2; a++) {
        for (b = a + 1; b < n - 1; b++) {
            for (c = b + 1; c < n; c++) {
                sum = nums[a] + nums[b] + nums[c];
                diff = target - sum;
                diff = (diff < 0) ? (-diff) : diff;
                if (mindiff > diff) {
                    mindiff = diff;
                    bestsum = sum;
                }
            }
        }
    }

    return bestsum;
}