#pragma once
#ifndef PTMARK__HPP
#define PTMARK__HPP

#include <iostream>
#include <string>

#include "lib-maddy/parser.hpp"
#include "utils/fileutil.hpp"

using namespace std;
using namespace maddy;

namespace ptmark
{
    namespace parser
    {
        inline string fromContent(const string &mdContent, shared_ptr<ParserConfig> config = nullptr)
        {
            shared_ptr<ParserConfig> _config = config ? config : make_shared<ParserConfig>();
            Parser _parser(_config);
            istringstream mdStream(mdContent);
            return _parser.Parse(mdStream);
        }
        inline string fromFile(const string &filePath, shared_ptr<ParserConfig> config = nullptr)
        {
            string mdContent = ptmark::fs::readFile(filePath);
            return fromContent(mdContent,config);
        }
        inline void fromFileToFile(const string &inputFilePath,const string &outFilePath,shared_ptr<ParserConfig> config = nullptr)
        {
            string content = fromFile(inputFilePath,config);
            ptmark::fs::writeFile(outFilePath,content);
        }

    } // namespace parser

} // namespace ptmark

#endif // PTMARK__HPP