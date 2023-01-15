#pragma once
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>

namespace yazi
{
    namespace xml
    {
        class Vaule
        {
        public:
            Vaule();
            Vaule(bool vaule);
            Vaule(int vaule);
            Vaule(double vaule);
            Vaule(const char* vaule);
            Vaule(const std::string& vaule);
            ~Vaule();
            
            Vaule& operator=(bool vaule);
            Vaule& operator=(int vaule);
            Vaule& operator=(double vaule);
            Vaule& operator=(const char* vaule);
            Vaule& operator=(const std::string vaule);
            bool operator == (const Vaule& other);
            bool operator != (const Vaule& other);
            operator bool();
            operator int();
            operator double();
            operator std::string();
            std::string GetVaule()const { return _vaule; }
           // friend std::stringstream& operator<<(std::stringstream& ss, const Vaule& vaule);
        private:
            std::string _vaule;
        };

        class Xml
        {
        public:
            Xml();
            Xml(const char* name);
            Xml(const std::string& name);
            Xml(const Xml& other);
            Xml& operator=(const Xml& other);
            //节点名称
            std::string name() const;
            void name(const std::string& name);

            //节点内容
            std::string text()const;
            void text(const std::string& text);

            //节点属性
            Vaule& attr(const std::string& key);
            void attr(const std::string& key,const Vaule& val);


            std::string str()const;

            void append(const Xml& child);
            Xml& operator[](int index);
            Xml& operator[](const char* name);
            Xml& operator[](const std::string name);


            void remove(int index);
            void remove(const char* name);
            void remove(const std::string& name);

            void clear();

            typedef std::list<Xml>::iterator iterator;
            iterator begin()
            {
                return _child->begin();
            }
            iterator end()
            {
                return _child->end();
            }
            iterator erase(iterator it)
            {
                it->clear();
                return _child->erase(it);
            }
            int size() const
            {
                return static_cast<int> (_child->size());
            }
            bool load(const std::string& filename);
            bool save(const std::string& filename);
            bool parse(const std::string& str);
        private:
            std::string* _name;
            std::string* _text;
            std::map<std::string,Vaule>* _attrs;
            std::list<Xml>* _child;
        };
    }
}


