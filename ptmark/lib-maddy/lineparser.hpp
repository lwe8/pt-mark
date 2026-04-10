#pragma once
#ifndef LINE_PARSER_HPP
#define LINE_PARSER_HPP

// -----------------------------------------------------------------------------

#include <string>

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * LineParser
 *
 * @class
 */
class LineParser
{
public:
  /**
   * dtor
   *
   * @method
   */
  virtual ~LineParser() {}

  /**
   * Parse
   *
   * From Markdown to HTML
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  virtual void Parse(std::string& line) = 0;
}; // class LineParser

// -----------------------------------------------------------------------------

} // namespace maddy

#endif // LINE_PARSER_HPP
