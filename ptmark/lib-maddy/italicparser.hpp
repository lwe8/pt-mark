#pragma once
#ifndef ITALIC_PARSER_HPP
#define ITALIC_PARSER_HPP

// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "lineparser.hpp"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * ItalicParser
 *
 * @class
 */
class ItalicParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text *text*`
   *
   * To HTML: `text <i>text</i>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::regex re(
      R"((?!.*`.*|.*<code>.*)\*(?!.*`.*|.*<\/code>.*)([^\*]*)\*(?!.*`.*|.*<\/code>.*))"
    );
    static std::string replacement = "<i>$1</i>";
    line = std::regex_replace(line, re, replacement);
  }
}; // class ItalicParser

// -----------------------------------------------------------------------------

} // namespace maddy

#endif // ITALIC_PARSER_HPP