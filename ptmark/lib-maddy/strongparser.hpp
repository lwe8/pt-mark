#pragma once
#ifndef STRONG_PARSER_HPP
#define STRONG_PARSER_HPP
// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "lineparser.hpp"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * StrongParser
 *
 * Has to be used before the `EmphasizedParser`.
 *
 * @class
 */
class StrongParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text **text** __text__`
   *
   * To HTML: `text <strong>text</strong> <strong>text</strong>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::vector<std::regex> res{
      std::regex{
        R"((?!.*`.*|.*<code>.*)\*\*(?!.*`.*|.*<\/code>.*)([^\*\*]*)\*\*(?!.*`.*|.*<\/code>.*))"
      },
      std::regex{
        R"((?!.*`.*|.*<code>.*)__(?!.*`.*|.*<\/code>.*)([^__]*)__(?!.*`.*|.*<\/code>.*))"
      }
    };
    static std::string replacement = "<strong>$1</strong>";
    for (const auto& re : res)
    {
      line = std::regex_replace(line, re, replacement);
    }
  }
}; // class StrongParser

// -----------------------------------------------------------------------------

} // namespace maddy

#endif // STRONG_PARSER_HPP