// SpellingBeeSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctype.h>
#include <vector>
#include <cctype>
#include "SpellingBeeSolverCore.h"

int main()
{
    char center=' ';
    while (!isalpha(center) )
    {
        std::string input = "";
        std::cout << "Enter In the Center Letter!\n";
        std::cin >> input;
        if ( !input.empty() && isalpha(input[0]))
        {
            center = tolower(input[0]);
        }
    }
    std::vector<char> list = std::vector<char>();
    while (list.empty())
    {
        std::string input = "";
        std::cout << "Enter In all the letters!\n";
        std::cin >> input;
        for ( int i =0; i<input.size();i++ ) 
        {
            if ( isalpha(input[i]))
            {
                list.push_back(tolower(input[i]));
            }
        }
        //check if input is ok
        std::cout << "Using this: ["<<center<<",";
        for ( int i=0; i<list.size(); i++ ) 
        {
            std::cout << list[i];
            if (i!=list.size()-1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;

        SpellingBeeSolverCore solver = SpellingBeeSolverCore(center, list);
        solver.SolveWords();
        std::cin.ignore();
    }

}
