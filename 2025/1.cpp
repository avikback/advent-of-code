#include <string>
#include <fstream>
#include <vector>
#include <iostream>

void LoadCodes(const char* file_path, std::vector<int>& output_vector)
{
    std::ifstream codes(file_path);
    std::string output_string;

    while(std::getline(codes, output_string))
    {
        int sign = output_string[0] == 'R' ? -1 : 1;
        output_vector.push_back((std::stoi(output_string.substr(1)) * sign) % 100);
    }
}

int TurnDial(std::vector<int>& input_vector)
{

    int dial = 50;
    int counter = 0;

    for (int i = 0; i < input_vector.size(); ++i)
    {
        dial = (dial + input_vector[i]);
        
        if (dial > 99)
        {
            dial = (dial % 100);
        }

        if (dial < 0)
        {
            dial = (100 - (-dial));
        }

        std::cout << i + 1 << ": " << dial << std::endl;

        if (dial == 0)
        {
            ++counter;
        }
    }

    return (counter);
}

int main()
{
    std::vector<int> turns;
    LoadCodes("input.txt", turns);
    std::cout << TurnDial(turns) << std::endl;
    return(0);
}