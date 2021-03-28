// Using a stack defined by nested class templates
#include "Stack.h"
#include <iostream>
#include <string>
#include <array>              // for std::size()

int main()
{
    std::string words[]{"The", "quick", "brown", "fox", "jumps"};
    Stack<std::string> wordStack;

    for (size_t i = 0; i < std::size(words); i++)
    {
        wordStack.push(words[i]);
    }

    Stack<std::string> newStack{wordStack};

    while (!newStack.isEmpty())
    {
        std::cout<<newStack.pop()<<" ";
    }

    std::cout << std::endl;

    while (!wordStack.isEmpty())
    {
        newStack.push(wordStack.pop());
    }
    
    // Display the words in original order
    while(!newStack.isEmpty())
    std::cout << newStack.pop() << " ";
    std::cout << std::endl;

    std::cout<<std::endl<<"Enter a line of text:" << std::endl;
    std::string text;
    std::getline(std::cin,text);// Read a line into the string object
    
    Stack<const char> characters;

    for (size_t i = 0; i < text.length(); i++)
    {
        characters.push(text[i]);
    }

    std::cout << std::endl;
    while(!characters.isEmpty())
        std::cout << characters.pop();          // Pop the characters off the stack

    std::cout << std::endl; 
}