#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ifstream file("Inputs/Input1.txt");
    std::vector<int> list1;
    std::vector<int> list2;
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string item;

            int num1, num2;

            if (ss >> num1)
            {
                list1.emplace_back(num1);
            }

            if (ss >> num2)
            {
                list2.emplace_back(num2);
            }
        }
        file.close();
    }

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int total_abs_difference = 0;
    for (size_t i = 0; i < list1.size(); ++i)
    {
        total_abs_difference += std::abs(list1[i] - list2[i]);
    }

    std::cout << "Total absolute difference: " << total_abs_difference << std::endl;

    return 0;
}