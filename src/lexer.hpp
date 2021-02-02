#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<char> integers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};


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
      if 
    }

  public:
    Lexer(std::string input) {
      context = input;
      contextArray = convertToArray(input);
    }
};