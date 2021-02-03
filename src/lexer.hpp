#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string integers = "1234567890";
std::string specialCharacters = "ei";
std::string operation = "+-*/%^"

class Lexer {
  private:
  std::string context;
  int index = 0;
  std::vector<char> contextArray;

  private:
    std::vector<char> convertToArray(std::string context) {
      std::vector<char> arr = {};
        for (int i = 0; i < context.size(); i++) {
          arr.push_back(context[i]);
        }

      return arr;
    }

    bool isInteger(char character) {
      std::string ch(1, character);
      
      if (integers.find(ch) == -1) return false;
      
      return true;
    }
    
    bool isSpecialCharacter(char character) {
    	std::string ch(1, character);
    	
    	if(specialCharacters.find(ch)) return false;
    	
    	return true;
    }
    
  public:
    Lexer(std::string input) {
      context = input;
      contextArray = convertToArray(input);
    }
};