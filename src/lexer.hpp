#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string integers = "1234567890";
std::string specialCharacters = "ei";
std::string operations = "+-*/%^()!";

class Token {
	public:
	std::string type;
	std::string value;
	
	Token(std::string typeName, std::string val) {
		type = typeName;
		value = val;
	}
};

class Lexer {
  private:
  std::string context;
  int index = 0;
  char character;
  std::vector <Token> tokens;
    
  public:
    Lexer(std::string input) {
      context = input;
      character = input[0];
    }

    char advance(int amount = 1) {
      index += amount;
      character = context[index];

      return character;
    }

    char peek(int amount = 1) {
      return context[amount + index];
    }

    bool isInteger(char character) {
      std::string str(1, character);

      if (integers.find(str) == -1) return false;

      return true;
    }

    bool isOperator(char character) {
      std::string str(1, character);

      if (operations.find(str) == -1) return false;

      return true;
    }

    bool isWhitespace(char character) {
      if (character == ' ') return true;

      return false;
    }

    bool isSpecialCharacter(char character) {
      std::string str(1, character);

      if (specialCharacters.find(str) == -1) return false;

      return true;
    }

    std::vector <Token> tokenize() {
    	while (character != '\0') {
    		int lastIndex = index;
    		
        if (isInteger(character)) {
          std::string num(1, character);
          
          advance();
        
         while(character != '\0' && isInteger(character)) {
           num += character;
         	
           advance();
         }
         
         if (character == '.') {
           num += character;
           advance();
         	
         	 while (character != '\0' && isInteger(character)) {
         	   num += character;
         	
         	   advance();
           }
         }
         
         tokens.push_back(Token("Number", num));
        }
        
        if (isWhitespace(character)) advance();
        
        if (isOperator(character)) {
        	std::string op(1, character);
        	
        	advance();
        	
        	if (isOperator(character)) {
        		op += character;
        		advance();
        	}
        	
        	tokens.push_back(Token("Operator", op));
        }
        
        if (isSpecialCharacter(character)) {
        	std::string specChar(1, character);
        	tokens.push_back(Token("SpecialCharacter", specChar));
        	
        	advance();
        }
        
        if (lastIndex == index) {
          std::cout << "[ERROR] Character " << character << "is undefined.";
        }
      }
      
      tokens.push_back(Token("End of Statement", "End of Statement"));
      
      return tokens;
    }
};