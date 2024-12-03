#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    std::ifstream file("Inputs/Input2.txt");
    std::string line;
    int safeResults = 0;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            int direction = 0;
            std::vector <int> nums;
            int num;

            while (ss >> num)
            {
                nums.push_back(num);
            }
            
            int i = 1;
            for (; i < nums.size(); ++i)
            {
                int difference = nums[i] - nums[i - 1];
                bool inRange = std::abs(difference) > 0 and std::abs(difference) < 4;
                bool sameSign = difference > 0 and direction >= 0 or difference < 0 and direction <= 0;
                direction = difference;
                if (not inRange or not sameSign)
                {
                    break;
                }
            }

            safeResults = i == nums.size() ? safeResults + 1 : safeResults;
        }
        file.close();
    }

    std::cout << safeResults << std::endl;

    return 0;
}