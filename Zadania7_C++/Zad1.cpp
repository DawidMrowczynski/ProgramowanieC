#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

int MAX_NUMBERS = 20;
int MAX_DIGITS = 10;

int decode(std::string line);
int convert_to_int(std::string number);
int concat_int(int number1, int number2);

int main() 
{
    int sum = 0;

    std::ifstream file("input.txt");

    if (!file.is_open()) 
    {
        std::cerr << "Can't read file!" << std::endl;
        return 1; 
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        int energy = decode(line);
        std::cout << ""<<energy << std::endl;
        sum += energy;
    }
    std::cout << "Sum of energy: " << sum << std::endl;
    file.close();

    return 0;
}

int decode(std::string line)
{
    int count = 0;
    std::string numbers[MAX_NUMBERS]; 

    std::string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number_of_words = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < line.length(); i++) 
    {
        if (std::isdigit(line[i])) 
        {
            numbers[count] = line[i]; 
            count++;
        }
        else 
        {
            for (int j = 0; j < number_of_words; j++) 
            {
                if (line.substr(i, words[j].length()) == words[j]) 
                {
                    numbers[count] = line.substr(i, words[j].length());
                    numbers[count][words[j].length()] = '\0';
                    count++;
                    i++; 
                    break;
                }
            }
        }
    }
    return concat_int(convert_to_int(numbers[0]), convert_to_int(numbers[count - 1]));
}

int convert_to_int(std::string number) // zamiana slownych liczb na int
{
    std::string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number_of_words = sizeof(words) / sizeof(words[0]);
    
    for (int i = 0; i < number_of_words; ++i) 
    {
        if (number == words[i]) 
        {
            return i; 
        }
    }
    
    return std::atoi(number.c_str());
}

int concat_int(int number1, int number2) // konkatenacja dwoch liczb
{
    std::string concatenated_string = std::to_string(number1) + std::to_string(number2);
    int concatenated_number = std::stoi(concatenated_string);
    return concatenated_number;
}