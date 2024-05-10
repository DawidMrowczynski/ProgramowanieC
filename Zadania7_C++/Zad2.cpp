#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Result  
{
    bool poss;
    int power;
};

Result is_possible(std::string line, int b, int g, int r, int n);

int main()
{
    // maksymalne liczby danych kolorow dla problemu 1
    int b_number = 14;
    int g_number = 13;
    int r_number = 12;

    int sum_power = 0;
    int possible = 0; // do sumy identyfikatorow
    int counter = 1; // numer gry: zaczynamy od 1 gry

    std::ifstream file("input2.txt");

    if (!file.is_open()) 
    {
        std::cerr << "Can't read file!" << std::endl;
        return 1; 
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        Result answer = is_possible(line, b_number, g_number, r_number, counter);
        if (answer.poss)
        {
            possible += counter;
        }
        std::cout << "Game " << counter << ": " << (answer.poss ? "Possible" : "Not Possible") << std::endl; 
        counter++;
        sum_power += answer.power;
    }
    std::cout << "Sum of Identifiers: " << possible << std::endl;
    std::cout << "Sum of Power: " << sum_power << std::endl;

    file.close();

    return 0;
}

Result is_possible(std::string line, int b, int g, int r, int n)
{
    Result answers;
    answers.poss = true;
    int max_blue = 0;
    int max_green = 0;
    int max_red = 0;
    int count = 0, count_max = 0;
    std::string splited, splited_inner;

    // sprawdzam ile cyfr ma numer gry aby go odpowienio odciac (numer gry - np. Game 100:) 
    int len = std::to_string(n).length();
    std::string new_line = line.substr(7 + len, line.length());

    std::stringstream ss(new_line);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(ss, token, ';')) // dziele string po sredniku
    {
        tokens.push_back(token);
    } 
    std::string results[20], inner_results[50];

    for (const auto& t : tokens)
    {
        results[count] = t;
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        std::stringstream ss2(results[i]);
        std::vector<std::string> tokens2;
        std::string token2;
        while (std::getline(ss2, token2, ' ')) // dziele dalej ale po spacji
        {
            tokens2.push_back(token2);
        } 
        for (const auto& t2 : tokens2)
        {
            if (!t2.length() < 1)
            {
                inner_results[count_max] = t2;
                count_max++;
            }
        }
    }
    for (int i = 0; i < count_max; i += 2) // wyszukuje maksymalne wartosci
    {
        if (i + 1 < count_max)
        {
            if (((inner_results[i + 1] == "blue") || (inner_results[i + 1] == "blue,") || (inner_results[i + 1] == "blue\n")) && (std::stoi(inner_results[i]) > max_blue))
            {
                max_blue = std::stoi(inner_results[i]);
            }
            if (((inner_results[i + 1] == "green") || (inner_results[i + 1] == "green,") || (inner_results[i + 1] == "green\n")) && (std::stoi(inner_results[i]) > max_green))
            {
                max_green = std::stoi(inner_results[i]);
            }
            if (((inner_results[i + 1] == "red") || (inner_results[i + 1] == "red,") || (inner_results[i + 1] == "red\n")) && (std::stoi(inner_results[i]) > max_red))
            {
                max_red = std::stoi(inner_results[i]);
            }
        }
    }
    if (b < max_blue) // warunki do sprawdzenia pierwszej czesci zadania
    {
        answers.poss = false;
    }
    if (g < max_green)
    {
        answers.poss = false;
    }
    if (r < max_red)
    {
        answers.poss = false;
    }

    answers.power = max_blue * max_green * max_red;
    return answers;
}