#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> solutions;
    int size = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    if (find(solutions.begin(), solutions.end(), temp) == solutions.end())
                    {
                        solutions.push_back(temp);
                    }
                }
            }
        }
    }

    return solutions;
}

vector<int> genRandomArray(int size)
{

    vector<int> random;

    int a = rand() % 501 - 250;
    int b = rand() % 501 - 250;

    random.push_back(-a);
    random.push_back(-b);
    random.push_back(a+b);

    while (random.size() < size)
    {
        random.push_back(rand() % 501 - 250);
    }

    return random;
}

int main()
{

    srand(time(0));

    vector<int> sizes = {400, 800, 1600, 3200, 4000};

    vector<int> nums;

    for (int i = 0; i < sizes.size(); i++)
    {

        nums = genRandomArray(sizes[i]);

        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = threeSum(nums);
        auto end = chrono::high_resolution_clock::now();
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        cout << "Size: " << sizes[i] << " " << time_ms << " ms"<<endl;
    }
}