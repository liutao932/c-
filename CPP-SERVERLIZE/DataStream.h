#pragma once
#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include "Serializable.h"
#include <algorithm>
namespace yazi
{
    namespace serialize
    {
        class DataStream
        {
        public:
            enum DataType
            {
                BOOL = 0,
                CHAR,
                INT32,
                INT64,
                FLOAT,
                DOUBLE,
                STRING,
                VECTOR,
                LIST,
                MAP,
                SET,
                CUSTOM
            };
            enum ByteOrder
            {
                BigEndian,
                LittleEndian
            };
            DataStream() { _byteorder = byteorder();}
            ~DataStream() {}
            /*编码*/
            void write(const char* data, int len);
            void write(const bool value);
            void write(const char value);
            void write(const int32_t vaule);
            void write(const int64_t vaule);
            void write(const float vaule);
            void write(const double vaule);
            void write(const char* vaule);
            void write(const std::string& vaule);
            template <class T>
            void write(const std::vector<T>& vaule);
            template <class T>
            void write(const std::list<T>& vaule);
            template <class K, class V>
            void write(const std::map<K, V>& vaule);
            template <class T>
            void write(const std::set<T>& vaule);

            void write(const Serializable& vaule);

            template<typename T, typename ...Args>
            void write_args(const T& vaule, const Args&... args);
            void write_args();
            void show() const;

            /*解码*/
            bool read(char* data, int len);
            bool read(bool& vaule) const;
            bool read(char& vaule) const;
            bool read(int32_t& vaule) const;
            bool read(int64_t& vaule) const;
            bool read(float& vaule) const;
            bool read(double& vaule) const;
            bool read(char* vaule) const;
            bool read(std::string& vaule) const;

            template <class T>
            bool read(std::vector<T>& vaule);

            template <class T>
            bool read(std::list<T>& vaule);

            template <class K, class V>
            bool read(std::map<K, V>& vaule);

            template <class T>
            bool read(std::set<T>& vaule);

            bool read(Serializable& vaule);
            template<typename T, typename ...Args>
            void read_args(T& vaule, Args&... args);
            void read_args();

            DataStream& operator<<(const bool& vaule);
            DataStream& operator<<(const char& vaule);
            DataStream& operator<<(const int32_t& vaule);
            DataStream& operator<<(const int64_t& vaule);
            DataStream& operator<<(const float& vaule);
            DataStream& operator<<(const double& vaule);
            DataStream& operator<<(const char* vaule);
            DataStream& operator<<(const std::string& vaule);
            template <class T>
            DataStream& operator<<(const std::vector<T>& vaule);

            template <class T>
            DataStream& operator<<(const std::list<T>& vaule);

            template <class T>
            DataStream& operator<<(const std::set<T>& vaule);

            template <class K, class V>
            DataStream& operator<<(const std::map<K, V>& vaule);
            DataStream& operator<<(const Serializable& vaule);

            DataStream& operator>>(bool& vaule);
            DataStream& operator>>(char& vaule);
            DataStream& operator>>(int32_t& vaule);
            DataStream& operator>>(int64_t& vaule);
            DataStream& operator>>(float& vaule);
            DataStream& operator>>(double& vaule);
            DataStream& operator>>(char* vaule);
            DataStream& operator>>(std::string& vaule);

            template <class T>
            DataStream& operator>>(std::vector<T>& vaule);

            template <class T>
            DataStream& operator>>(std::list<T>& vaule);

            template <class T>
            DataStream& operator>>(std::set<T>& vaule);

            template <class K, class V>
            DataStream& operator>>(std::map<K, V>& vaule);
            DataStream& operator>>(Serializable& vaule);

        private:
            void reserve(int len);
            ByteOrder byteorder();
        private:
            std::vector<char> _buf;
            mutable size_t _pos = 0;
            ByteOrder _byteorder;
        };


        DataStream::ByteOrder DataStream::byteorder()
        {
            int n = 0x12345678;
            char str[4];
            memcpy(str,&n,sizeof(int));
            if(str[0] == 0x12)
            {
                return ByteOrder::BigEndian;
            }
            return ByteOrder::LittleEndian;
            
        }
        DataStream& DataStream::operator<<(const bool& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const char& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const int32_t& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const int64_t& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const float& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const double& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const char* vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const std::string& vaule)
        {
            write(vaule);
            return *this;
        }

        template <class T>
        DataStream& DataStream::operator<<(const std::vector<T>& vaule)
        {
            write(vaule);
            return *this;
        }

        template <class T>
        DataStream& DataStream::operator<<(const std::list<T>& vaule)
        {
            write(vaule);
            return *this;
        }

        template <class T>
        DataStream& DataStream::operator<<(const std::set<T>& vaule)
        {
            write(vaule);
            return *this;
        }

        template <class K, class V>
        DataStream& DataStream::operator<<(const std::map<K, V>& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator<<(const Serializable& vaule)
        {
            write(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(bool& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(char& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(int32_t& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(int64_t& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(float& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(double& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(char* vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(std::string& vaule)
        {
            read(vaule);
            return *this;
        }

        template <class T>
        DataStream& DataStream::operator>>(std::vector<T>& vaule)
        {
            read(vaule);
            return *this;
        }

        template <class T>
        DataStream& DataStream::operator>>(std::list<T>& vaule)
        {
            read(vaule);
            return *this;
        }

        template <class T>
        DataStream& DataStream::operator>>(std::set<T>& vaule)
        {
            read(vaule);
            return *this;
        }

        template <class K, class V>
        DataStream& DataStream::operator>>(std::map<K, V>& vaule)
        {
            read(vaule);
            return *this;
        }
        DataStream& DataStream::operator>>(Serializable& vaule)
        {
            read(vaule);
            return *this;
        }
        void DataStream::reserve(int len)
        {
            int size = static_cast<int>(_buf.size());
            int cap = static_cast<int>(_buf.capacity());
            while (size + len > cap)
            {
                cap = (cap == 0 ? 1 : cap * 2);
            }
            _buf.reserve(cap);
        }
        void DataStream::write(const char* data, int len)
        {
            reserve(len);
            int size = static_cast<int>(_buf.size());
            _buf.resize(size + len);
            memcpy(&_buf[size], data, len);
        }
        void DataStream::write(const bool value)
        {
            char type = DataStream::BOOL;
            write(static_cast<char*>(&type), sizeof(char));
            write(reinterpret_cast<const char*>(&value), sizeof(bool));
        }
        void DataStream::write(const char value)
        {
            char type = DataStream::CHAR;
            write(static_cast<char*>(&type), sizeof(char));
            write(reinterpret_cast<const char*>(&value), sizeof(char));
        }
        void DataStream::write(const int32_t vaule)
        {
            char type = DataStream::INT32;
            write(static_cast<char*>(&type), sizeof(char));
            if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&type;
                char* last = first + sizeof(int32_t);
                std::reverse(first,last);
            }
            write(reinterpret_cast<const char*>(&vaule), sizeof(int32_t));
        }
        void DataStream::write(const int64_t vaule)
        {
            char type = DataStream::INT64;
            write(static_cast<char*>(&type), sizeof(char));
             if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&type;
                char* last = first + sizeof(int64_t);
                std::reverse(first,last);
            }
            write(reinterpret_cast<const char*>(&vaule), sizeof(int64_t));
        }
        void DataStream::write(const float vaule)
        {
            char type = DataStream::FLOAT;
            write(static_cast<char*>(&type), sizeof(char));
            if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&type;
                char* last = first + sizeof(float);
                std::reverse(first,last);
            }
            write(reinterpret_cast<const char*>(&vaule), sizeof(float));
        }
        void DataStream::write(const double vaule)
        {
            char type = DataStream::DOUBLE;
            write(static_cast<char*>(&type), sizeof(char));
            if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&type;
                char* last = first + sizeof(double);
                std::reverse(first,last);
            }
            write(reinterpret_cast<const char*>(&vaule), sizeof(double));
        }
        void DataStream::write(const char* vaule)
        {
            char type = DataStream::STRING;
            write(static_cast<char*>(&type), sizeof(char));
            int len = static_cast<int>(strlen(vaule));
            write(len);
            write(vaule, len);
        }
        void DataStream::write(const std::string& vaule)
        {
            char type = DataStream::STRING;
            write(static_cast<char*>(&type), sizeof(char));
            int len = static_cast<int>(vaule.size());
            write(len);
            write(vaule.data(), len);
        }
        template <class T>
        void DataStream::write(const std::vector<T>& vaule)
        {
            char type = DataStream::VECTOR;
            write(static_cast<char*>(&type), sizeof(char));
            int len = vaule.size();
            write(len);
            for (size_t i = 0; i < vaule.size(); ++i)
            {
                write(vaule[i]);
            }
        }
        template <class T>
        void DataStream::write(const std::list<T>& vaule)
        {
            char type = DataStream::LIST;
            write(static_cast<char*>(&type), sizeof(char));
            int len = vaule.size();
            write(len);
            for (auto it = vaule.begin(); it != vaule.end(); ++it)
            {
                write(*it);
            }
        }
        template <class T>
        void DataStream::write(const std::set<T>& vaule)
        {
            char type = DataStream::SET;
            write(static_cast<char*>(&type), sizeof(char));
            int len = static_cast<int>(vaule.size());
            write(len);
            for (auto it = vaule.begin(); it != vaule.end(); ++it)
            {
                write(*it);
            }
        }
        template <class K, class V>
        void DataStream::write(const std::map<K, V>& vaule)
        {
            char type = DataStream::MAP;
            write(static_cast<char*>(&type), sizeof(char));
            int len = vaule.size();
            write(len);
            for (auto it = vaule.begin(); it != vaule.end(); ++it)
            {
                write(it->first);
                write(it->second);
            }
        }
        void DataStream::write(const Serializable& vaule)
        {
            vaule.serizlize(*this);
        }

        template<typename T, typename ...Args>
        void DataStream::write_args(const T& vaule, const Args&... args)
        {
            write(vaule);
            write_args(args...);
        }
        void DataStream::write_args()
        {

        }
        bool DataStream::read(bool& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::BOOL)
            {
                return false;
            }
            ++_pos;
            vaule = _buf[_pos];
            ++_pos;
            return true;
        }
        bool DataStream::read(char* data, int len)
        {
            memcpy(data, static_cast<char*>(&_buf[_pos]), len);
            _pos += len;
            return true;
        }
        bool DataStream::read(char& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::CHAR)
            {
                return false;
            }
            ++_pos;
            vaule = _buf[_pos];
            ++_pos;
            return true;
        }
        bool DataStream::read(int32_t& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::INT32)
            {
                return false;
            }
            ++_pos;
            vaule = *(reinterpret_cast<const int32_t*>(&_buf[_pos]));
            if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&(_pos);
                char* last = first + sizeof(int32_t);
                std::reverse(first,last);
            }
            _pos += 4;
            return true;
        }
        bool DataStream::read(int64_t& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::INT64)
            {
                return false;
            }
            ++_pos;
            vaule = *(reinterpret_cast<const int64_t*>(&_buf[_pos]));
            if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&(_pos);
                char* last = first + sizeof(int64_t);
                std::reverse(first,last);
            }
            _pos += 8;
            return true;
        }
        bool DataStream::read(float& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::FLOAT)
            {
                return false;
            }
            ++_pos;
            vaule = *(reinterpret_cast<const float*>(&_buf[_pos]));
            if(_byteorder == ByteOrder::BigEndian)
            {
               char* first = (char*)&(_pos);
                char* last = first + sizeof(float);
                std::reverse(first,last);
            }
            _pos += 4;
            return true;
        }
        bool DataStream::read(double& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::DOUBLE)
            {
                return false;
            }
            ++_pos;
            vaule = *(reinterpret_cast<const double*>(&_buf[_pos]));
            if(_byteorder == ByteOrder::BigEndian)
            {
                char* first = (char*)&(_pos );
                char* last = first + sizeof(double);
                std::reverse(first,last);
            }
            _pos += 8;
            return true;
        }

        bool DataStream::read(char* vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::CHAR)
            {
                return false;
            }
            ++_pos;
            int len;
            read(len);
            vaule = (char*)&_buf[_pos];
            if (len < 0)
            {
                return false;
            }
            _pos += len;
            return true;
        }
        bool DataStream::read(std::string& vaule) const
        {
            if (DataType(_buf[_pos]) != DataType::STRING)
            {
                return false;
            }
            ++_pos;
            int len;
            read(len);
            if (len < 0)
            {
                return false;
            }
            vaule.assign((char*)&(_buf[_pos]), len);
            _pos += len;
            return true;
        }
        template <class T>
        bool DataStream::read(std::vector<T>& vaule)
        {
            vaule.clear();
            if (_buf[_pos] != DataType::VECTOR)
            {
                return false;
            }
            ++_pos;
            int len;
            read(len);
            for (size_t i = 0; i < len; ++i)
            {
                T v;
                read(v);
                vaule.push_back(v);
            }
            return true;
        }
        template <class T>
        bool DataStream::read(std::list<T>& vaule)
        {
            vaule.clear();
            if (_buf[_pos] != DataType::LIST)
            {
                return false;
            }
            ++_pos;
            int len;
            read(len);
            for (size_t i = 0; i < len; ++i)
            {
                T v;
                read(v);
                vaule.push_back(v);
            }
            return true;
        }
        template <class K, class V>
        bool DataStream::read(std::map<K, V>& vaule)
        {
            vaule.clear();
            if (_buf[_pos] != DataType::MAP)
            {
                return false;
            }
            ++_pos;
            int len;
            read(len);
            for (int i = 0; i < len; ++i)
            {
                K k;
                read(k);
                V v;
                read(v);
                vaule[k] = v;
            }
            return true;
        }

        template <class T>
        bool DataStream::read(std::set<T>& vaule)
        {
            vaule.clear();
            if (_buf[_pos] != DataType::SET)
            {
                return false;
            }
            ++_pos;
            int len;
            read(len);
            for (int i = 0; i < len; ++i)
            {
                T t;
                read(t);
                vaule.insert(t);
            }
            return true;
        }
        bool DataStream::read(Serializable& vaule)
        {
            return vaule.unserialize(*this);
        }
        template<typename T, typename ...Args>
        void DataStream::read_args(T& vaule, Args&... args)
        {
            read(vaule);
            return read_args(args...);
        }
        void DataStream::read_args()
        {

        }

        void DataStream::show() const
        {
            int size = static_cast<int>(_buf.size());
            std::cout << "data size = " << size << std::endl;
            int index = 0;
            while (index < size)
            {
                switch ((DataType)_buf[index])
                {
                case DataType::BOOL:
                {
                    if ((int)_buf[++index] == 0)
                    {
                        std::cout << (int)_buf[index] << std::endl;
                    }
                    else
                    {
                        std::cout << (int)_buf[index] << std::endl;
                    }
                    ++index;
                    break;
                }
                case DataType::CHAR:
                {
                    std::cout << _buf[++index] << std::endl;
                    ++index;
                    break;
                }
                case DataType::INT32:
                {
                    std::cout << *(int32_t*)(&_buf[++index]) << std::endl;
                    index += 4;
                    break;
                }
                case DataType::INT64:
                {
                    std::cout << *(int64_t*)(&_buf[++index]) << std::endl;
                    index += 8;
                    break;
                }
                case DataType::FLOAT:
                {
                    std::cout << *(float*)(&_buf[++index]) << std::endl;
                    index += 4;
                    break;
                }
                case DataType::DOUBLE:
                {
                    std::cout << *(double*)(&_buf[++index]) << std::endl;
                    index += 8;
                    break;
                }
                case DataType::STRING:
                {
                    if ((DataType)_buf[++index] == DataType::INT32)
                    {
                        int len = *(int32_t*)(&_buf[++index]);
                        std::cout << len << std::endl;
                        index += 4;
                        std::cout << string(&_buf[index], len) << std::endl;
                        index += len;
                        break;
                    }
                    else
                    {
                        throw "parse string error";
                    }
                    break;
                }
                default:
                    break;
                }
            }
        }
    }
}