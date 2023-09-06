#include "SpellingBeeSolverCore.h"
#include <iostream>
#include <fstream>
#include <cctype>

static const std::string DICTIONARY_FILENAME = "dictionary.txt";
static const int MIN_LETTER_COUNT = 4; 

using namespace std;

SpellingBeeSolverCore::SpellingBeeSolverCore(const char& CenterLetter, const std::vector<char> OuterLetters) 
{
	m_CenterLetter = tolower(CenterLetter);
	m_OuterLetters = std::unordered_set<char>();
	m_OuterLetters.insert(m_CenterLetter);
	for ( int i =0; i< OuterLetters.size(); i++)
	{
		m_OuterLetters.insert(tolower(OuterLetters[i]));
	}
	ReadInDictionaryFromFile();
}

//getters
const char& SpellingBeeSolverCore::getCenterLetter(void) 
{
	return m_CenterLetter;
}

const std::unordered_set<char> SpellingBeeSolverCore::getOuterLetters(void)
{
	return m_OuterLetters;
}

//init dictionary
void SpellingBeeSolverCore::ReadInDictionaryFromFile(void)
{
	m_Dictionary = std::vector<std::string>();
	std::ifstream myfile( DICTIONARY_FILENAME );
	if (myfile.is_open()) {
		while (myfile)
		{
			std::string line;
			std::getline(myfile, line);
			ToLowerCaseInPlace(line);
			if (line.find(m_CenterLetter) != std::string::npos)
			{//fiters words that do not have center letter
				bool word_is_made_of_outer_layers = true;
				for (int i = 0; i < line.size(); i++)
				{
					word_is_made_of_outer_layers &= (m_OuterLetters.find(line[i]) != m_OuterLetters.end());
					if (word_is_made_of_outer_layers == false)
					{
						break;
					}
				}
				if (word_is_made_of_outer_layers && line.size() >= MIN_LETTER_COUNT)
				{
					m_Dictionary.push_back(line);
				}
			}
		}
	}
}

//internal tool
void SpellingBeeSolverCore::ToLowerCaseInPlace(std::string& value)
{
	for (int i = 0; i < value.size(); i++)
	{
		value[i] = tolower(value[i]);
	}
}

//Solve
void SpellingBeeSolverCore::SolveWords(void)
{
	std::cout << "Words:" << std::endl;
	for ( int i=0; i < m_Dictionary.size(); i++ ) 
	{
		std::cout << m_Dictionary[i] << std::endl;
	}
}