#pragma once
#include <vector>
#include <unordered_set>
#include <string>

class SpellingBeeSolverCore 
{
private:

	char m_CenterLetter;

	std::unordered_set<char> m_OuterLetters;

	std::vector<std::string> m_Dictionary;

	void ReadInDictionaryFromFile(void);

	void ToLowerCaseInPlace(std::string& value);

public:
	SpellingBeeSolverCore(const char& CenterLetter, const std::vector<char> OuterLetters);

	const char& getCenterLetter(void);

	const std::unordered_set<char> getOuterLetters(void);

	void SolveWords(void);

};