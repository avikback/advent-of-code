#include <string>
#include <fstream>
#include <vector>
#include <iostream>

void LoadCodes(const char* file_path, std::vector<std::pair<int, char>>& output_vector)
{
    std::ifstream codes(file_path);
    std::string output_string;

    while(std::getline(codes, output_string))
    {
        output_vector.push_back((std::pair(std::stoi(output_string.substr(1)), output_string[0])));
    }
}

int TurnDial(std::vector<std::pair<int, char>>& input_vector)
{

    int dial = 50;
    int counter = 0;

    for (int i = 0; i < input_vector.size(); ++i)
    {
        int number_of_turns_left = input_vector[i].first;
        while (number_of_turns_left != 0)
        {
            input_vector[i].second == 'L' ? ++dial : --dial;
            --number_of_turns_left;

            switch (dial)
            {
                case 100 :
                    dial = 0;
                    break;
                case -1 :
                    dial = 99;
                    break;
                default:
                    break;
            }

            if (dial == 0) 
            {
                ++counter;
            }
        }
    }

    return (counter);
}

int main()
{
    std::vector<std::pair<int, char>> turns;
    LoadCodes("input.txt", turns);
    std::cout << TurnDial(turns) << std::endl;
    return(0);
}