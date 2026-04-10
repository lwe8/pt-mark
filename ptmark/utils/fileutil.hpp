#pragma once
#ifndef FILE_UTILS__HPP
#define FILE_UTILS__HPP

#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace fspp = std::filesystem;

namespace ptmark
{
    namespace fs
    {

        std::string readFile(const std::string &path)
        {
            std::ifstream file(path, std::ios::binary);
            if (!file.is_open())
                return "";

            file.seekg(0, std::ios::end);
            std::streamsize size = file.tellg();
            if (size < 0)
                return "";

            file.seekg(0, std::ios::beg);
            std::string content(static_cast<size_t>(size), '\0');
            if (size > 0)
            {
                if (!file.read(content.data(), size))
                    return "";
            }

            return content;
        }
        void writeFile(const std::string &path, const std::string &content)
        {
            fspp::path p = path;
            fspp::path dirname = p.parent_path();

            try
            {
                if (!dirname.empty() && !fspp::exists(dirname))
                {
                    fspp::create_directories(dirname);
                }

                std::ofstream outFile(path, std::ios::binary);
                if (outFile.is_open())
                {
                    outFile << content;
                    outFile.close(); // Optional, but good practice
                }
                else
                {
                    std::cerr << "Failed to open file for writing: " << path << '\n';
                }
            }
            catch (const fspp::filesystem_error &e)
            {
                std::cerr << e.what() << '\n';
            }
        }

    } // namespace fs

} // namespace ptmark

#endif // FILE_UTILS__HPP