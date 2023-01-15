#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Xml.h"
namespace yazi
{
    namespace xml
    {
        class Parser
        {
        public:
            Parser();
            bool load_file(const std::string & file);
            bool load_string(const std::string& str);
            Xml parse();
        private:
            void skip_white_space();  //去空格
            bool parse_declaration();
            bool parse_comment();
            Xml parse_element();
            std::string parse_element_name();
            std::string parse_element_text();
            std::string parse_element_attr_key();
            std::string parse_element_attr_val();
        private:
            std::string _str;
            int _index;
        };
    }
}