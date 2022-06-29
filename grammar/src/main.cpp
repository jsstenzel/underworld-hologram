#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "grammar.c"

/*
 Format a vector of strings as a single string.
 */
std::string vector_print(const std::vector<std::string>& vec) {
  std::string str = "[";
  for(auto v : vec) {
    str += v;
    str += ",";
  }
  if (str.size() > 1) { str.pop_back(); }
  str += "]";
  return str;
}

/*
 Structure representing a single game action.
 */
struct sCommand{
  std::string object = "";
  std::string action = "";
  std::string target = "";
  std::vector<std::string> object_adjectives;
  std::vector<std::string> target_adjectives;

  void print() {
    std::cout << "Action: " << action << std::endl
              << "Object: " << vector_print(object_adjectives) << " " << object << std::endl
              << "Target: " << vector_print(target_adjectives) << " " << target << std::endl;
  }
};

/*
 Read a line from the console & parse it into a command object.
 */
bool get_command(sCommand& command) {
  // Print prompt
  std::cout << std::endl << ">";

  // Initialize global buffer for holding parsed expression
  clear_expression();

  // Set up parser context
  yycontext yy;
  memset(&yy, 0, sizeof(yy));

  // Read stdin into global struct using PEG-generated parser function
  bool success = yyparse(&yy);
  yyrelease(&yy);
  if (!success) {
    return false;
  }

  // Unpack global struct into a more convenient form
  if (!g_expression.flagEmpty) {
    if (g_expression.flagKeyword) {
      command.action = std::string(g_expression.action);
    }
    else {
      command.action = std::string(g_expression.action);
      std::string token_str;

      std::string objects_str(g_expression.objects);
      if (!objects_str.empty()) {
        std::stringstream objects_ss(objects_str);
        while(std::getline(objects_ss, token_str, ';')) {
          command.object_adjectives.push_back(token_str);
        }
        command.object = command.object_adjectives.back();
        command.object_adjectives.pop_back();
      }
      
      std::string targets_str(g_expression.targets);
      if (!targets_str.empty()) {
        std::stringstream targets_ss(targets_str);
        while(std::getline(targets_ss, token_str, ';')) {
          command.target_adjectives.push_back(token_str);
        }
        command.target = command.target_adjectives.back();
        command.target_adjectives.pop_back();
      }
    }
  }
  return true;
}

int main() {
  while(true) {
    sCommand command;
    if (!get_command(command)) {
      std::cout << "Parser error!" << std::endl;
    }
    else {
      command.print();
    }
  }
  free_expression();
  return 0;
}