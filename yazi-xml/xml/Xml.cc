#include "Xml.h"
#include "Parser.h"
using namespace yazi::xml;

Vaule::Vaule()
{
}
Vaule::Vaule(bool vaule)
{
    *this = vaule;
}
Vaule::Vaule(int vaule)
{
    *this = vaule;
}
Vaule::Vaule(double vaule)
{
    *this = vaule;
}
Vaule::Vaule(const char* vaule) : _vaule(vaule)
{
}
Vaule::Vaule(const std::string& vaule) : _vaule(vaule)
{
}
Vaule::~Vaule()
{
}

Vaule& Vaule::operator=(bool vaule)
{
    _vaule = vaule ? "true" : "false";
    return *this;
}
Vaule& Vaule::operator=(int vaule)
{
    std::stringstream ss;
    ss << vaule;
    _vaule = ss.str();
    return *this;
}
Vaule& Vaule::operator=(double vaule)
{
    std::stringstream ss;
    ss << vaule;
    _vaule = ss.str();
    return *this;
}
Vaule& Vaule::operator=(const char* vaule)
{
    _vaule = vaule;
    return *this;
}
Vaule& Vaule::operator=(const std::string vaule)
{
    _vaule = vaule;
    return *this;
}

bool Vaule::operator==(const Vaule& other)
{
    return _vaule == other._vaule;
}
bool Vaule::operator!=(const Vaule& other)
{
    return !((*this) == other);
}
Vaule::operator bool()
{
    if (_vaule == "true")
    {
        return true;
    }
    else if (_vaule == "false")
    {
        return false;
    }
    else
    {
        return false;
    }
}
Vaule::operator int()
{
    return std::atoi(_vaule.c_str());
}
Vaule::operator double()
{
    return std::atof(_vaule.c_str());
}
Vaule::operator std::string()
{
    return _vaule;
}

Xml::Xml() : _name(nullptr), _text(nullptr), _attrs(nullptr), _child(nullptr)
{
}
Xml::Xml(const char* name) : _name(nullptr), _text(nullptr), _attrs(nullptr), _child(nullptr)
{
    _name = new std::string(name);
}
Xml::Xml(const std::string& name) : _name(nullptr), _text(nullptr), _attrs(nullptr), _child(nullptr)
{
    _name = new std::string(name);
}
Xml::Xml(const Xml& other)
{
    _name = other._name;
    _text = other._text;
    _attrs = other._attrs;
    _child = other._child;
}
Xml::Xml(const std::string& node, const std::map<std::string, Vaule>& mp, const std::string text): _child(nullptr)
{
    _name = new std::string(node);
    _attrs = new std::map<std::string, Vaule>(mp);
    _text = new std::string(text);
}
Xml& Xml::operator=(const Xml& other)
{
    clear();
    _name = other._name;
    _text = other._text;
    _attrs = other._attrs;
    _child = other._child;
    return *this;
}

std::string Xml::name() const
{
    if (_name == nullptr)
    {
        return "";
    }
    return *_name;
}
void Xml::name(const std::string& name)
{
    if (_name != nullptr)
    {
        delete _name;
        _name = nullptr;
    }
    _name = new std::string(name);
}

std::string Xml::text() const
{
    if (_text == nullptr)
    {
        return "";
    }
    return *_text;
}
void Xml::text(const std::string& text)
{
    if (_text != nullptr)
    {
        delete _text;
        _text = nullptr;
    }
    _text = new std::string(text);
}

Vaule& Xml::attr(const std::string& key)
{
    if (_attrs == nullptr)
    {
        _attrs = new std::map<std::string, Vaule>();
    }
    return (*_attrs)[key];
}
void Xml::attr(const std::string& key, const Vaule& val)
{
    if (_attrs == nullptr)
    {
        _attrs = new std::map<std::string, Vaule>();
    }
    (*_attrs)[key] = val;
}
std::string Xml::str() const
{
    if (_name == nullptr)
    {
        // throw new std::logic_error("element name is empty");
        return "";
    }
    std::stringstream ss;
    ss << "<";
    ss << (*_name);
    if (_attrs != nullptr)
    {
        for (const auto& e : (*_attrs))
        {
            ss << " " << e.first << "=\"" << e.second.GetVaule() << "\"";
        }
        /*for (auto it = _attrs->begin(); it != _attrs->end(); ++it)
        {
            ss << " " << it->first << "=\"" << it->second << "\"";
        }*/
    }
    ss << ">";
    if (_child != nullptr)
    {
        for (const auto& e : (*_child))
        {
            ss << e.str();
        }
    }
    if (_text != nullptr)
    {
        ss << *_text;
    }
    ss << "</" << *_name << ">";
    return ss.str();
}
void Xml::append(const Xml& child)
{
    if (_child == nullptr)
    {
        _child = new std::list<Xml>();
    }
    _child->push_back(child);
}
Xml& Xml::operator[](int index)
{
    if (index < 0)
    {
        throw new std::logic_error("index less than zero");
    }
    if (_child == nullptr)
    {
        _child = new std::list<Xml>();
    }
    int size = static_cast<int>(_child->size());
    if (index >= 0 && index < size)
    {
        auto it = _child->begin();
        for (int i = 0; i < size; ++i)
        {
            ++it;
        }
        return *it;
    }
    if (index >= size)
    {
        for (int i = index; i <= size; ++i)
        {
            _child->push_back(Xml());
        }
    }
    return _child->back();
}

Xml& Xml::operator[](const char* name)
{
    return (*this)[std::string(name)];
}
Xml& Xml::operator[](const std::string name)
{
    if (_child == nullptr)
    {
        _child = new std::list<Xml>();
    }
    // for(const auto &e : (*child))
    // {
    //     if(e.name() == name)
    //     {
    //
    //     }
    // }
    for (auto it = _child->begin(); it != _child->end(); ++it)
    {
        if (it->name() == name)
        {
            return *it;
        }
    }
    _child->push_back(Xml(name));
    return _child->back();
}
void Xml::remove(int index)
{
    if (_child == nullptr)
    {
        return;
    }
    int size = static_cast<int>(_child->size());
    if (index < 0 || index >= size)
    {
        return;
    }
    auto it = _child->begin();
    for (int i = 0; i < index; ++i)
    {
        it++;
    }
    it->clear();
    _child->erase(it);
}
void Xml::remove(const char* name)
{
    remove(std::string(name));
}
void Xml::remove(const std::string& name)
{
    if (_child == nullptr)
    {
        return;
    }
    for (auto it = _child->begin(); it != _child->end();)
    {
        if (it->name() == name)
        {
            it->clear();
            it = _child->erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void Xml::clear()
{
    if (_name != nullptr)
    {
        delete _name;
        _name = nullptr;
    }
    if (_text != nullptr)
    {
        delete _text;
        _text = nullptr;
    }
    if (_attrs != nullptr)
    {
        delete _attrs;
        _attrs = nullptr;
    }
    if (_child != nullptr)
    {
        for (auto it = _child->begin(); it != _child->end(); ++it)
        {
            it->clear();
        }
        delete _child;
        _child = nullptr;
    }
}
bool Xml::load(const std::string& filename)
{
    Parser p;
    if (!p.load_file(filename))
    {
        return false;
    }
    *this = p.parse();
    return true;
}
bool Xml::save(const std::string& filename)
{
    std::ofstream out(filename);
    if (out.fail())
    {
        return false;
    }
    out << str();
    out.close();
    return true;
}
bool Xml::parse(const std::string& str)
{
    Parser p;
    if (!p.load_string(str))
    {
        return false;
    }
    *this = p.parse();
    return true;
}