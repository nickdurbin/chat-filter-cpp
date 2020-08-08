// Censor App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main()
{   
    // We create a our data structure with a flexible vector
    // The type of vector is a string
    // We name the vector bad_words
    std::vector<std::string> bad_words;

    // We push values into our vector
    bad_words.push_back("hell");
    bad_words.push_back("shit");
    bad_words.push_back("fuck");
    bad_words.push_back("damn");
    bad_words.push_back("dick");

    // Create a variable to store a phrase a user can input
    std::string phrase;
    std::cout << "Type a phrase: " << std::endl;
    getline(std::cin, phrase);

    // Use sstream to take the phrase and make is a string stream
    std::stringstream word_stream(phrase);

    // A do/while loop for when we have a phrase created
    do 
    {
        // A variable we will eventually store each word from the
        // String stream and compare if it is in our vector
        std::string word;
        word_stream >> word;

        // A boolean to check if a bad word was typed in the phrase
        // And a check to amke sure we do not hit the end of our vector
        // Because that implicitly returns a value we do not want
        // if both conditions are met, then we hit our if statement
        // The statement will find the word in the phrase
        // evaluate its length and change the value to astreks
        bool is_true = std::find(bad_words.begin(), bad_words.end(), word) != bad_words.end();
        if (is_true)
        {
            phrase.replace(phrase.find(word), word.length(), "****");
        }
    } while (word_stream);
    std::cout << phrase << std::endl;
}
