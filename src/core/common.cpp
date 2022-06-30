#include "common.hpp"
#include "grammar.c"

std::string vector_serialize(const std::vector<std::string>& vec) {
  std::string str = "[";
  for(auto v : vec) {
    str += v;
    str += ",";
  }
  if (str.size() > 1) { str.pop_back(); }
  str += "]";
  return str;
}

std::string SObjectDesc::serialize() const {
  std::string str = vector_serialize(m_adjectives);
  str += m_name;
  return str;
}

std::string SCommandDesc::serialize() const {
  std::string str = "Action: ";
  str += ("Action" +m_action + "\n");
  str += ("Subject: " + m_subject.serialize() + "\n");
  str += ("Target: " + m_target.serialize());
  return str;
}

/*
 Read a line from the console & parse it into a command object.
 */
bool get_command(SCommandDesc& command) {
  // Print prompt
  std::cout << std::endl << ">";

  // Initialize global buffer for holding parsed expression
  clearExpression();

  // Set up parser context
  yycontext yy;
  memset(&yy, 0, sizeof(yy));

  // Read stdin into global struct using PEG-generated parser function
  bool success = yyparse(&yy);
  yyrelease(&yy);
  if (!success) {
    freeExpression();
    return false;
  }

  // Unpack global struct into a more convenient form
  if (!g_expression.flagEmpty) {
    if (g_expression.flagKeyword) {
      command.m_action = std::string(g_expression.action);
      command.m_flagKeyword = true;
    }
    else {
      command.m_action = std::string(g_expression.action);
      std::string token_str;

      std::string objects_str(g_expression.objects);
      if (!objects_str.empty()) {
        std::stringstream objects_ss(objects_str);
        while(std::getline(objects_ss, token_str, ';')) {
          command.m_subject.m_adjectives.push_back(token_str);
        }
        command.m_subject.m_name = command.m_subject.m_adjectives.back();
        command.m_subject.m_adjectives.pop_back();
      }
      
      std::string targets_str(g_expression.targets);
      if (!targets_str.empty()) {
        std::stringstream targets_ss(targets_str);
        while(std::getline(targets_ss, token_str, ';')) {
          command.m_target.m_adjectives.push_back(token_str);
        }
        command.m_target.m_name = command.m_target.m_adjectives.back();
        command.m_target.m_adjectives.pop_back();
      }
    }
  }
  freeExpression();
  return true;
}