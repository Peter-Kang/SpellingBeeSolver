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
	std::ifstream my_file( DICTIONARY_FILENAME );
	if (my_file.is_open()) {
		while (my_file)
		{
			std::string line;
			std::getline(my_file, line);
			ToLowerCaseInPlace(line);
			if (line.size() >= MIN_LETTER_COUNT && line.find(m_CenterLetter) != std::string::npos)
			{//fiters words that do not have center letter
				bool word_is_made_of_outer_layers = true;
				std::string::const_iterator line_iter;
				for (line_iter = line.begin(); line_iter != line.end(); line_iter++) 
				{
					word_is_made_of_outer_layers &= (m_OuterLetters.find(*line_iter) != m_OuterLetters.end());
					if (word_is_made_of_outer_layers == false)
					{
						break;
					}
				}
				if (word_is_made_of_outer_layers)
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
	std::string::iterator value_iter;
	for ( value_iter = value.begin(); value_iter != value.end(); value_iter++ ) 
	{
		*value_iter = tolower(*value_iter);
	}
}

//Solve
void SpellingBeeSolverCore::SolveWords(void)
{
	std::cout << "Words:" << std::endl;
	std::vector<std::string>::const_iterator words_iterator;
	for(words_iterator = m_Dictionary.begin(); words_iterator < m_Dictionary.end(); words_iterator++)
	{
		std::cout << *words_iterator << std::endl;
	}
}