#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

int main()
{
    std::ifstream file("Inputs/Input3.txt");
    std::string line;
    int numberValidPasswords = 0;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string appearances;
            char character;
            std::string password;

            ss >> appearances;
            std::replace(appearances.begin(), appearances.end(), '-', ' ');
            ss >> character;
            ss.ignore();
            ss >> password;
            
            int minAppearances, maxAppearances;
            std::stringstream rangeStream(appearances);
            rangeStream >> minAppearances >> maxAppearances;
        
            int count = std::count(password.begin(), password.end(), character);

            if(count >= minAppearances && count <= maxAppearances)
            {
                numberValidPasswords++;
            }
        }
        file.close();
    }

    std::cout << numberValidPasswords << std::endl;

    return 0;
}