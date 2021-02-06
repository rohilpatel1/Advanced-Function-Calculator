#include <iostream>
#include <unordered_map>
#include <vector>
#include "src/lexer.hpp"

int main() {
  Lexer lexer("i^2");
  
  std::vector<Token> tokens = lexer.tokenize();
  
  for (int i = 0; i < tokens.size(); i++) {
  	std::cout << "Type: " << tokens[i].type << ", Value: " <<  tokens[i].value << std::endl;
  }
  return 0;
}