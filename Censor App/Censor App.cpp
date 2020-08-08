// Censor App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main()
{   
    std::vector<std::string> bad_words;

    bad_words.push_back("hell");
    bad_words.push_back("shit");
    bad_words.push_back("fuck");
    bad_words.push_back("damn");
    bad_words.push_back("dick");

    std::string phrase;
    std::cout << "Type a phrase: " << std::endl;
    getline(std::cin, phrase);
    std::stringstream word_stream(phrase);
    do 
    {
        std::string word;
        word_stream >> word;
        bool is_true = std::find(bad_words.begin(), bad_words.end(), word) != bad_words.end();
        if (is_true)
        {
            phrase.replace(phrase.find(word), word.length(), "****");
        }
    } while (word_stream);
    std::cout << phrase << std::endl;
}
