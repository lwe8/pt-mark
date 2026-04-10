#pragma once
#ifndef INLINE_CODE_PARSER_HPP
#define INLINE_CODE_PARSER_HPP

// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "lineparser.hpp"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * InlineCodeParser
 *
 * @class
 */
class InlineCodeParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text `some code``
   *
   * To HTML: `text <code>some code</code>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::regex re("`([^`]*)`");
    static std::string replacement = "<code>$1</code>";

    line = std::regex_replace(line, re, replacement);
  }
}; // class InlineCodeParser

// -----------------------------------------------------------------------------

} // namespace maddy

#endif // INLINE_CODE_PARSER_HPP