#include "json.h"
#include "parser.h"
using namespace yazi::json;

Json::Json() : _type(json_null)
{
}
Json::Json(bool vaule) : _type(json_bool)
{
    _vaule._bool = vaule;
}
Json::Json(int vaule) : _type(json_int)
{
    _vaule._int = vaule;
}
Json::Json(double vaule) : _type(json_double)
{
    _vaule._double = vaule;
}
Json::Json(const char* vaule) : _type(json_string)
{
    _vaule._string = new std::string(vaule);
}
Json::Json(const std::string& vaule) : _type(json_string)
{
    _vaule._string = new std::string(vaule);
}
Json::Json(Type type) : _type(type)
{
    switch (_type)
    {
    case json_null:
        break;
    case json_bool:
        _vaule._bool = false;
        break;
    case json_int:
        _vaule._int = 0;
        break;
    case json_double:
        _vaule._double = 0.0;
        break;
    case json_string:
        _vaule._string = new std::string("");
        break;
    case json_array:
        _vaule._array = new std::vector<Json>();
        break;
    case json_object:
        _vaule._object = new std::map<std::string, Json>();
        break;
    default:
        break;
    }
}
Json::Json(const Json& other)
{
    copy(other);
}

Json::operator bool()
{
    if (_type != json_bool)
    {
        throw new logic_error("type error,not bool vaule");
    }
    return _vaule._bool;
}
Json::operator int()
{
    if (_type != json_int)
    {
        throw new logic_error("type error,not int vaule");
    }
    return _vaule._int;
}
Json::operator double()
{
    if (_type != json_double)
    {
        throw new logic_error("type error,not double vaule");
    }
    return _vaule._double;
}
Json::operator string()
{
    if (_type != json_string)
    {
        throw new logic_error("type error,not  string vaule");
    }
    return *(_vaule._string);
}

Json& Json::operator[](int index)
{
    if (_type != json_array)
    {
        clear();
        _type = json_array;
        _vaule._array = new std::vector<Json>();
    }
    // if(index < 0)
    // {
    //     throw new logic_error("array[] index < 0");
    // }
    size_t size = (_vaule._array)->size();
    if (index >= size) // 扩容
    {
        for (size_t i = size; i <= index; ++i)
        {
            (_vaule._array)->push_back(Json());
        }
    }
    return (_vaule._array)->at(index);
}
Json& Json::operator[](const char* key)
{
    std::string name(key);
    return (*(this))[name];
}
Json& Json::operator[](const std::string& key)
{
    if (_type != json_object)
    {
        clear();
        _type = json_object;
        _vaule._object = new std::map<std::string, Json>();
    }
    return (*(_vaule._object))[key];
}
void Json::operator=(const Json& other)
{
    clear();
    copy(other);
}
void Json::append(const Json& other)
{
    if (_type != json_array)
    {
        _type = json_array;
        _vaule._array = new std::vector<Json>();
    }
    (_vaule._array)->push_back(other);
}
size_t Json::size() const
{
    if (_type != json_array)
    {
        throw new logic_error("type error,not array vaule");
    }
    return (_vaule._array)->size();
}
string Json::str() const
{
    std::stringstream ss;
    switch (_type)
    {
    case json_null:
        ss << "null";
        break;
    case json_bool:
        if (_vaule._bool)
        {
            ss << "true";
        }
        else
        {
            ss << "false";
        }
        break;
    case json_int:
        ss << _vaule._int;
        break;
    case json_double:
        ss << _vaule._double;
        break;
    case json_string:
        ss << '\"' << *(_vaule._string) << '\"';
        break;
    case json_array:
    {
        ss << '[';
        for (auto it = (_vaule._array)->begin(); it != (_vaule._array)->end(); ++it)
        {
            if (it != (_vaule._array)->begin())
            {
                ss << ',';
            }
            ss << it->str();
        }
        ss << ']';
        break;
    }
    case json_object:
    {
        ss << '{';
        for (auto it = (_vaule._object)->begin(); it != (_vaule._object)->end(); ++it)
        {
            if (it != (_vaule._object)->begin())
            {
                ss << ',';
            }
            ss << '\"' << it->first << '\"' << ':' << it->second.str();
        }
        ss << '}';
        break;
    }
    default:
        break;
    }
    return ss.str();
}
void Json::copy(const Json& other)
{
    _type = other._type;
    switch (_type)
    {
    case json_null:
        break;
    case json_bool:
        _vaule._bool = other._vaule._bool;
        break;
    case json_int:
        _vaule._int = other._vaule._int;
        break;
    case json_double:
        _vaule._double = other._vaule._double;
        break;
    case json_string:
        _vaule._string = other._vaule._string;
        break;
    case json_array:
        _vaule._array = other._vaule._array;
        break;
    case json_object:
        _vaule._object = other._vaule._object;
        break;
    default:
        break;
    }
}
void Json::clear()
{
    switch (_type)
    {
    case json_null:
        break;
    case json_bool:
        _vaule._bool = false;
        break;
    case json_int:
        _vaule._int = 0;
        break;
    case json_double:
        _vaule._double = 0.0;
        break;
    case json_string:
        delete _vaule._string;
        break;
    case json_array:
    {
        for (auto it = _vaule._array->begin(); it != _vaule._array->end(); ++it)
        {
            it->clear();
        }
        delete _vaule._array;
        break;
    }
    case json_object:
    {
        for (auto it = _vaule._object->begin(); it != _vaule._object->end(); ++it)
        {
            (it->second).clear();
        }
        delete _vaule._object;
        break;
    }
    default:
        break;
    }
    _type = json_null;
}

bool Json::operator==(const Json& other) //浅拷贝(效率)
{
    if (_type != other._type)
    {
        return false;
    }
    switch (_type)
    {
    case json_null:
        return true;
    case json_bool:
        return _vaule._bool == other._vaule._bool;
    case json_int:
        return _vaule._int == other._vaule._int;
    case json_double:
        return _vaule._double == other._vaule._double;
    case json_string:
        return *(_vaule._string) == *(other._vaule._string);
    case json_array:
    {
       /*if(_vaule._array->size() != other._vaule._array->size())
       {
           return false;
       }
       for (size_t i = 0; i < _vaule._array->size(); ++i)
       {
           if ((*(_vaule._array))[i] != (* (other._vaule._array))[i])
           {
               return false;
           }
       }
       return true;*/
        return _vaule._array == other._vaule._array;
    }
    case json_object:
    {
        return _vaule._object == other._vaule._object;
    }
    default:
        break;
    }
    return false;
}
bool Json::operator!=(const Json& other)
{
    return !(*this == other);
}
bool Json::asBool() const
{
    if (_type != json_bool)
    {
        throw new std::logic_error("type error,not bool vaule");
    }
    return _vaule._bool;
}
int Json::asInt()const
{
    if (_type != json_int)
    {
        throw new std::logic_error("type error,not int vaule");
    }
    return _vaule._int;
}
double Json::asDouble()const
{
    if (_type != json_double)
    {
        throw new std::logic_error("type error,not double vaule");
    }
    return _vaule._double;
}
std::string Json::asString()const
{
    if (_type != json_string)
    {
        throw new std::logic_error("type error,not string vaule");
    }
    return *(_vaule._string);
}
bool Json::has(int index)
{
    if (_type != json_array)
    {
        return false;
    }
    int size = static_cast<int>((_vaule._array)->size());
    return (index >= 0 && index < size);
}
bool Json::has(const char* key)
{
    string name(key);
    return has(name);
}
bool Json::has(const std::string& key)
{
    if (_type != json_object)
    {
        return false;
    }
    return (_vaule._object)->find(key) != (_vaule._object)->end();
}

void Json::remove(int index)
{
    if (_type != json_array)
    {
        return;
    }
    int size = static_cast<int>((_vaule._array)->size());
    if (index < 0 || index >= size)
    {
        return;
    }
    (_vaule._array)->at(index).clear();
    (_vaule._array)->erase((_vaule._array)->begin() + index);
}
void Json::remove(const char* key)
{
    string name(key);
    return remove(name);
}
void Json::remove(const std::string& key)
{
    auto it = (_vaule._object)->find(key);
    if (it == (_vaule._object)->end())
    {
        return;
    }
    (*(_vaule._object))[key].clear();
    (_vaule._object)->erase(key);
}

void Json::parse(const std::string& str)
{
    Parser p;
    p.load(str);
    *this = p.parse();
}