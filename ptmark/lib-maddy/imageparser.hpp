#pragma once
#ifndef IMAGE_PARSER_HPP
#define IMAGE_PARSER_HPP
// -----------------------------------------------------------------------------

#include <regex>
#include <string>

#include "lineparser.hpp"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * ImageParser
 *
 * Has to be used before the `LinkParser`.
 *
 * @class
 */
class ImageParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `![text](http://example.com/a.png)`
   *
   * To HTML: `<img src="http://example.com/a.png" alt="text"/>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void Parse(std::string& line) override
  {
    static std::regex re(R"(\!\[([^\]]*)\]\(([^\]]*)\))");
    static std::string replacement = "<img src=\"$2\" alt=\"$1\"/>";

    line = std::regex_replace(line, re, replacement);
  }
}; // class ImageParser

// -----------------------------------------------------------------------------

} // namespace maddy

#endif // IMAGE_PARSER_HPP