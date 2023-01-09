.PHONY:all
all:dict_client dict_server
dict_client:dict_client.cc ./json/json.cc ./json/parser.cc
dict_client.cc:
	g++ -o $@  $^ -std=c++11
dict_server:dict_server.cc ./json/json.cc ./json/parser.cc
	g++ -o $@ $^  -std=c++11 -lpthread
.PHONY:clean
clean:
	rm -rf dict_client dict_server