
#pragma once
#ifndef BREAK_LINE_PARSER_HPP
#define BREAK_LINE_PARSER_HPP

// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "lineparser.hpp"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * BreakLineParser
 *
 * @class
 */
class BreakLineParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text\r\n text`
   *
   * To HTML: `text<br> text`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::regex re(R"((\r\n|\r))");
    static std::string replacement = "<br>";

    line = std::regex_replace(line, re, replacement);
  }
}; // class BreakLineParser

// -----------------------------------------------------------------------------

} // namespace maddy
#endif // BREAK_LINE_PARSER_HPP