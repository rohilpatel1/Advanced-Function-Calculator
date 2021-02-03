#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string integers = "1234567890";
std::string specialCharacters = "ei";
std::string operation = "+-*/%^()";

class Lexer {
  private:
  std::string context;
  int index = 0;
  char character;
    
  public:
    Lexer(std::string input) {
      context = input;
      character = input[0];
    }

    char advance(int amount = 1) {
      index += amount;

      return context[index];
    }

    char peek(int amount = 1) {
      return context[amount + index];
    }

    bool isInteger(char character) {
      std::string str(1, character);

      if (integers.find(str) == -1) return false;

      return true;
    }

    isOperator(char character) {
      std::string str(1, character);

      if (operators.find(str) == -1) return false;

      return true;
    }
};