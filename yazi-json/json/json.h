#pragma once
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;

namespace yazi
{
    namespace json
    {
        class Json
        {
        public:
            typedef std::vector<Json>::iterator iterator;
            iterator begin()
            {
                return _vaule._array->begin();
            }
            iterator end()
            {
                return _vaule._array->end();
            }
            enum Type
            {
                json_null = 0,
                json_bool,
                json_int,
                json_double,
                json_string,
                json_array,
                json_object
            };
            Json();
            Json(bool vaule);
            Json(int vaule);
            Json(double vaule);
            Json(const char* vaule);
            Json(const std::string& vaule);
            Json(Type type);
            Json(const Json& other);

            operator bool();
            operator int();
            operator double();
            operator string();
            Json& operator[](int index);
            Json& operator[](const char* key);
            Json& operator[](const std::string& key);
            void operator=(const Json& other);
            bool operator==(const Json& other);
            bool operator!=(const Json& other);
            //Json& operator*();
            void append(const Json& other);
            size_t size() const;
            string str()const;
            void copy(const Json& other);
            void clear();
            bool isNull()const { return _type == json_null; }
            bool isBool()const { return _type == json_bool; }
            bool isInt()const { return _type == json_int; }
            bool isDouble()const { return _type == json_double; }
            bool isString()const { return _type == json_string; }
            bool isArray()const { return _type == json_array; }
            bool isObject()const { return _type == json_object; }

            bool asBool() const;
            int asInt()const;
            double asDouble()const;
            std::string asString()const;


            bool has(int index);
            bool has(const char* key);
            bool has(const std::string& key);


            void remove(int index);
            void remove(const char* key);
            void remove(const std::string& key);


            void parse(const std::string& str);
        private: 
            union Vaule
            {
                bool _bool;
                int _int;
                double _double;
                std::string* _string;
                std::vector<Json>* _array;
                std::map<std::string, Json>* _object;
            };
            Type _type;
            Vaule _vaule;
        };
    }
}