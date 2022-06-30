#pragma once
/*
 Common definitions and inclusions across the project.
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

/*
 Format a vector of strings as a single string.
 */
std::string vector_serialize(const std::vector<std::string>& vec);

/*
 Structure representing a single game entity.
 */
struct SObjectDesc {
  std::string m_name = "";
  std::vector<std::string> m_adjectives;

  std::string serialize() const;
};

/*
 Structure representing a single game action.
 */
struct SCommandDesc{
  bool m_flagKeyword = false;
  std::string m_action = "";
  std::string m_subject;
  std::string m_target;

  std::string serialize() const;
};

/*
 Read a line from the console & parse it into a command object.
 */
bool get_command(SCommandDesc& command);