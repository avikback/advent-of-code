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

long long FindInvalidIds(std::vector<long long>& ids)
{
    long long value = 0;

    for (auto it: ids)
    {
        std::string id_as_str = std::to_string(it);
        std::string first_half = id_as_str.substr(0, id_as_str.size() / 2);
        std::string second_half = id_as_str.substr(id_as_str.size() / 2);

        if (first_half == second_half)
        {
            value += it;
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

    std::cout << FindInvalidIds(ids) << std::endl;
    auto res = GetRangesFromString(std::string("1000000000000-1000000000000"));
    std::cout << res.first << std::endl;
    std::cout << res.second << std::endl;

    return (0);
}