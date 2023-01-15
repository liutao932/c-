#include "Parser.h"
using namespace yazi::xml;
Parser::Parser():_str(""),_index(0)
{

}
bool Parser::load_file(const std::string &file)
{
    std::ifstream in(file);
    if(in.fail())
    {
        return false;
    }
    std::stringstream ss;
    ss << in.rdbuf();
    _str = ss.str();
    _index = 0;
    in.close();
    return true;
}
bool Parser::load_string(const std::string &str)
{
    _str = str;
    _index = 0;
    return true;
}
Xml Parser::parse()
{
    //核心
    skip_white_space();
    //头
    if(_str.compare(_index,5,"<?xml") == 0)
    {
        if(!parse_declaration())
        {
            throw new std::logic_error("parse declaration error");
        }
    }
    skip_white_space();  
    //注释
    while(_str.compare(_index,4,"<!--") == 0)
    {
        if(!parse_comment())
        {
            throw new std::logic_error("parse comment error");
        }
        skip_white_space();
    }
    //解析根
    if(_str[_index] == '<' && (isalpha(_str[_index + 1]) || _str[_index + 1] == '_'))
    {
        return parse_element();
    }
    throw new std::logic_error("parse element error");
}

void Parser::skip_white_space() // 去空格
{
    while(_str[_index] == ' ' || _str[_index] == '\r' || _str[_index] == '\n' || _str[_index] == '\t')
    {
        ++_index;
    }
}
bool Parser::parse_declaration()
{
    if(_str.compare(_index,5,"<?xml") != 0)
    {
        return false;
    }
    _index += 5;
    size_t pos = _str.find("?>",_index);
    if(pos == std::string::npos)
    {
        return false;
    }
    _index = static_cast<int>(pos) + 2;
    return true;
}
bool Parser::parse_comment()
{
    if(_str.compare(_index,4,"<!--") != 0)
    {
        return false;
    }
    _index += 4;
    size_t pos = _str.find("-->",_index);
    if(pos == std::string::npos)
    {
        return false;
    }
    _index = static_cast<int> (pos) + 3;
    return true;
}
Xml Parser::parse_element()
{
    Xml elem;
    ++_index;
    skip_white_space();
    std::string name = parse_element_name();
    elem.name(std::move(name));
    while(_str[_index] != '\0')
    {
        skip_white_space();
        if(_str[_index] == '/')
        {
            if(_str[_index + 1] == '>')
            {
                _index += 2;
                break;
            }
            else
            {
                throw std::logic_error("xml empty element is error");
            }
        }
        else if(_str[_index] == '>')
        {
            ++_index;
            std::string text = parse_element_text();
            if(text != "")
            {
                elem.text(std::move(text));
            }
        }
        else if(_str[_index] == '<')
        {
            if(_str[_index + 1] == '/')
            {
                std::string end_tag = "</" + name + ">";
                size_t pos = _str.find(end_tag,_index);
                if(pos == std::string::npos)
                {
                    throw new std::logic_error("xml element" + name + "end tag not found");
                }
                _index = (pos + end_tag.size());
                break;
            }
            else if(_str.compare(_index,4,"<!--") == 0)
            {
                if(!parse_comment())
                {
                    throw new std::logic_error("xml coment is error");
                }
            }
            else
            {
                elem.append(parse_element());
            }
        }
        else
        {
            std::string key = parse_element_attr_key();
            skip_white_space();
            if(_str[_index] != '=')
            {
                throw new std::logic_error("xml emlment attr is error" + key);
            }
            ++_index;
            skip_white_space();
            std::string val = parse_element_attr_val();
            elem.attr(std::move(key),std::move(val));
        }
    }
    return elem;
}
std::string Parser::parse_element_name()
{
    int pos = _index;
    if(isalpha(_str[_index]) || _str[_index] == '_')
    {
        ++_index;
        while(isalnum(_str[_index]) \
             || _str[_index] == '_' \
             || _str[_index] == '-' \
             || _str[_index] == ':' \
             || _str[_index] == '.')
        {
            ++_index;
        }
    }
    return _str.substr(pos, _index - pos);
}
std::string Parser::parse_element_text()
{
    int pos = _index;
    while(_str[_index] != '<')
    {
        ++_index;
    }
    return _str.substr(pos,_index - pos);
}
std::string Parser::parse_element_attr_key()
{
    int pos = _index;
    if(isalpha(_str[_index]) || _str[_index] == '_')
    {
        ++_index;
        while(isalnum(_str[_index]) \
             || _str[_index] == '_' \
             || _str[_index] == '-' \
             || _str[_index] == ':')
        {
            ++_index;
        }
    }
    return _str.substr(pos, _index - pos);
}
std::string Parser::parse_element_attr_val()
{
    if(_str[_index] != '"')
    {
        throw new std::logic_error("xml element attr vaule should be in double quotes");
    }
    ++_index;
    int pos = _index;
    while(_str[_index] != '"')
    {
        ++_index;
    }
    ++_index;
    return _str.substr(pos,_index - pos - 1);
}