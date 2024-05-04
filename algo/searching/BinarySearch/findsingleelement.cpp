#include <iostream>
#include <vector>


using namespace std;

int bs(std::vector<int> &nums)
{
    int n = nums.size();

    int l = 0, r = n - 1;
    int mid;

    int ans = -1;

    if (n % 2 == 0) {
        return -1;
    }

    while (l <= r) {
        mid = l + (r - l)/2;
        //std::cout << "mid: " << mid << std::endl;
        if (mid + 1 <= r and nums[mid] == nums[mid + 1]) {
            if ((mid) % 2 == 1) {
                r = mid - 1;
            } 
            if ((r - (mid + 1)) % 2 == 1) {
                l = mid + 2;
            }
           
        } else if (mid > 1 and nums[mid] == nums[mid - 1]) {
            if ((mid - 1) % 2 == 1) {
                r = mid - 2;
            } 
            if ((r - (mid)) % 2 == 1) {
                l = mid + 1;
            }
           
        } else {

            ans = mid;
            break;
        }
    }

    return ans;
}

int main()
{
    //this allows ./a.out < input.txt
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TC;
    std::cin >> TC;

    std::cout << "test cases: " << TC << std::endl;
    std::vector<int> nums;
    int num, n;

    for (int i = 0; i < TC; ++i) {

        nums.clear();

        cin >> n;
        std::cout << "read " << n << std::endl;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            nums.push_back(num);
        }

        int ans = bs(nums);
        std::cout << "index: " << ans << std::endl;
        if (ans != -1) {
            std::cout << "answer: " << nums[ans] << std::endl;
        } else
          std::cout << "not found\n";
    }

    return 0;
}
