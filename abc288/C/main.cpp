#include <iostream>
#include <vector>

using namespace std;

int maxPrizes(vector<int>& prizePositions, int k) {
    int prizeCount = 0;
    int left = 0, right = 0;
    while (right < prizePositions.size()) {
        while (right < prizePositions.size() && prizePositions[right] - prizePositions[left] <= k) {
            right++;
        }
        prizeCount += min(right - left, k);
        left++;
    }
    return prizeCount;
}

int main() {
    vector<int> prizePositions = {1, 2, 3, 6, 7};
    int k = 3;
    cout << maxPrizes(prizePositions, k) << endl;
    return 0;
}