#pragma once
#ifndef STRIKE_THROUGH_PARSER_HPP
#define STRIKE_THROUGH_PARSER_HPP

// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "lineparser.hpp"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * StrikeThroughParser
 *
 * @class
 */
class StrikeThroughParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text ~~text~~`
   *
   * To HTML: `text <s>text</s>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::regex re(
      R"((?!.*`.*|.*<code>.*)\~\~(?!.*`.*|.*<\/code>.*)([^\~]*)\~\~(?!.*`.*|.*<\/code>.*))"
    );
    static std::string replacement = "<s>$1</s>";

    line = std::regex_replace(line, re, replacement);
  }
}; // class StrikeThroughParser

// -----------------------------------------------------------------------------

} // namespace maddy

#endif // STRIKE_THROUGH_PARSER_HPP