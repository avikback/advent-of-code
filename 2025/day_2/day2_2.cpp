#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>

void ParseInput(const char* file_path, std::vector<std::string>& output)
{
    std::ifstream codes(file_path);

    std::string output_string;
    std::getline(codes, output_string);

    char* my_string = const_cast<char*>(output_string.c_str());
    const char* sign = ",";
    char* my_ptr = strtok(my_string, sign);
    while (my_ptr)
    {
        output.push_back(std::string(my_ptr));
        my_ptr = strtok(NULL, sign);
    }
}

std::pair<long long, long long> GetRangesFromString(const std::string& range)
{
        long long range_beginning = std::atoll(range.c_str());
            auto delimiter = range.find("-");
        long long range_end = std::atoll(range.substr(delimiter + 1).c_str());


        return (std::pair(range_beginning, range_end));
}
void PopulateRanges(std::vector<std::string>& input_strings, std::vector<long long>& ids)
{
    for (auto it : input_strings)
    {
        auto ranges = GetRangesFromString(it);
        for (long long i = ranges.first; i <= ranges.second; ++i)
        {
            ids.push_back(i);
        }
    }
}

void SplitStringEvenly(std::string& to_split, std::vector<std::string>& split_strings, int num_of_pieces)   
{
    int begin = 0;
    int step = to_split.length() / num_of_pieces;
    while (begin + step <= to_split.length())
    {
        split_strings.push_back(to_split.substr(begin, step));
        begin += step;
    }
}

bool AreAllSubstringsEqual(std::vector<std::string>& split_strings)
{
    for (auto it = split_strings.begin(); std::next(it) != split_strings.end(); ++it)
    {
        if (*it != *std::next(it))
        {
            return (false);
        }
    }

    return (true);
}

long long FindInvalidIds(std::vector<long long>& ids)
{
    long long value = 0;
    for (auto it: ids)
    {
        std::string num_as_string = std::to_string(it);

        for (int i = num_as_string.length(); i > 1; --i)
        {
            if ((num_as_string.length() % i) == 0)
            {
                std::vector<std::string> split_strings;
                SplitStringEvenly(num_as_string, split_strings, i);
                if (AreAllSubstringsEqual(split_strings))
                {
                    value += it;
                    break;
                }

            }
        }
    }

    return (value);
}

int main()
{ 
    std::vector<std::string> output_strings;
    ParseInput("input.txt", output_strings);
    std::vector<long long> ids;
    PopulateRanges(output_strings, ids);
    auto res = FindInvalidIds(ids);
    std::cout << res << std::endl;

    
    return (0);
}