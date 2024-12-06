#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

int main() 
{
    std::ifstream file("Inputs/Input6.txt");
    std::string line;
    std::vector<std::vector<char>> matrix;

    if(file.is_open())
    {
        while (std::getline(file, line))
        {
            std::vector<char> row;
            for (char c : line)
            {
                row.push_back(c);
            }
            matrix.push_back(row);
        }
        file.close();
    }

    bool found;
    do
    {
        found = false;
        for (size_t row = 0; row < matrix.size(); ++row)
        {
            for (size_t col = 0; col < matrix[row].size(); ++col)
            {
                if (matrix[row][col] == '^')
                {
                    matrix[row][col] = 'X';
                    if (row > 0)
                    {
                        if(matrix[row - 1][col] != '#')
                        {
                            row--;
                            matrix[row][col] = '^';
                        }
                        else
                        {
                            matrix[row][col] = '>';
                        }
                    } 

                    found = true;
                    break;
                }
                else if (matrix[row][col] == '>')
                {
                    matrix[row][col] = 'X';
                    if (col < matrix[row].size() - 1)
                    {
                        if(matrix[row][col + 1] != '#')
                        {
                            col++;
                            matrix[row][col] = '>';
                        }
                        else
                        {
                            matrix[row][col] = 'v';
                        }
                    } 

                    found = true;
                    break;
                }
                else if (matrix[row][col] == 'v')
                {
                    matrix[row][col] = 'X';
                    if (row < matrix.size() - 1)
                    {
                        if(matrix[row + 1][col] != '#')
                        {
                            row++;
                            matrix[row][col] = 'v';
                        }
                        else
                        {
                            matrix[row][col] = '<';
                        }
                    } 

                    found = true;
                    break;
                }
                else if (matrix[row][col] == '<')
                {
                    matrix[row][col] = 'X';
                    if (col > 0)
                    {
                        if(matrix[row][col - 1] != '#')
                        {
                            col--;
                            matrix[row][col] = '<';
                        }
                        else
                        {
                            matrix[row][col] = '^';
                        }
                    } 

                    found = true;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    } while (found);

    int countX = 0;
    for (const auto& row : matrix)
    {
        for (char c : row)
        {
            if (c == 'X')
            {
                countX++;
            }
        }
    }

    std::cout << countX << std::endl;

    return 0;
}