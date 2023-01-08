#include "parser.h"
using namespace yazi::json;
Parser::Parser() : _str(""), _index(0)
{
}
void Parser::load(const std::string& str)
{
    _str = str;
    _index = 0;
}
Json Parser::parse()
{
    char ch = get_next_token();
    switch (ch)
    {
    case 'n':
        --_index;
        return parse_null();
    case 't':
    case 'f':
        --_index;
        return parse_bool();
    case '-':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        --_index;
        return parse_number();
    case '"':
        return Json(parse_string());
    case '[':
        return parse_array();
    case '{':
        return parse_object();
    default:
        break;
    }
    throw new std::logic_error("unexpected char");
}
void Parser::skip_white_space()
{
    while (_str[_index] == ' ' || _str[_index] == '\n' || _str[_index] == '\r' || _str[_index] == '\t')
    {
        ++_index;
    }
}
char Parser::get_next_token()
{
    skip_white_space();
    return _str[_index++];
}
Json Parser::parse_null()
{
    if (_str.compare(_index, 4, "null") == 0)
    {
        _index += 4;
        return Json();
    }
    throw new std::logic_error("parse null error");
}
Json Parser::parse_bool()
{
    if (_str.compare(_index, 4, "true") == 0)
    {
        _index += 4;
        return Json(true);
    }
    else if (_str.compare(_index, 5, "false") == 0)
    {
        _index += 5;
        return Json(false);
    }
    else
    {
        throw new std::logic_error("parse bool error");
    }
}
Json Parser::parse_number()
{
    int pos = _index;
    if (_str[_index] == '-')
    {
        ++_index;
    }
    if (isdigit(_str[_index]) == 0)
    {
        throw new std::logic_error("parse number error");
    }
    while (isdigit(_str[_index]) != 0)
    {
        ++_index;
    }
    if (_str[_index] != '.')
    {
        int i = std::atoi(_str.c_str() + pos);
        return Json(std::move(i));
    }
    if (isdigit(_str[++_index]) == 0)
    {
        throw new std::logic_error("parse number error");
    }
    while (isdigit(_str[_index]) != 0)
    {
        ++_index;
    }
    double f = std::atof(_str.c_str() + pos);
    return Json(std::move(f));
}
std::string Parser::parse_string()
{
    std::string out;
    while (true)
    {
        char ch = _str[_index++];
        if (ch == '"')
        {
            break;
        }
        if (ch == '\\')
        {
            ch = _str[_index++];
            switch (ch)
            {
            case '\n':
                out += '\n';
                break;
            case '\r':
                out += '\r';
                break;
            case '\t':
                out += '\t';
                break;
            case '\b':
                out += '\b';
                break;
            case '\f':
                out += '\f';
                break;
            case '"':
                out += "\\\"";
                break;
            case '\\':
                out += "\\\\";
                break;
            case 'u':
                out += "\\u";
                for (int i = 0; i < 4; ++i)
                {
                    out += _str[_index++];
                }
                break;
            default:
                break;
            }
        }
        else
        {
            out += ch;
        }
    }
    return std::move(out);
}
Json Parser::parse_array()
{
    Json arr(Json::json_array);
    char ch = get_next_token();
    if (ch == ']')
    {
        return arr;
    }
    --_index;
    while (true)
    {
        arr.append(parse());   //递归解析
        ch = get_next_token();
        if (ch == ']')
        {
            break;
        }
        if (ch != ',')
        {
            throw new std::logic_error("parse array error");
        }
        //++_index;//ERROR
    }
    return arr;
}
Json Parser::parse_object()
{
    Json obj(Json::json_object);
    char ch = get_next_token();
    if(ch == '}')
    {
        return obj;
    }
    --_index;
    while(true)
    {
        ch = get_next_token();
        if(ch != '"')
        {
            throw new std::logic_error("parse object error");
        }
        std::string key = parse_string();
        ch = get_next_token();
        if(ch != ':')
        {
            throw new std::logic_error("parse object error");
        }
        obj[key] = parse();
        ch = get_next_token();
        if(ch == '}')
        {
            break;
        }
        if(ch != ',')
        {
            throw new std::logic_error("parse object error");
        }
        //++_index;//ERROR
    }
    return obj;
}