#ifndef  HTTP_SERVER_CACHE_H
#define  HTTP_SERVER_CACHE_H

#include <iostream>   
#include <map>   
#include <algorithm>  
#include <list>   
#include <string>


//using namespace std;
namespace http{

struct Node{
    std::string  key;
    std::string  value;
};


class LRUCache{
 private:
    int _maxSize ;
    std::list<Node> _cacheList;
    std::map<std::string, std::list<Node>::iterator > _mp;
 public:
    LRUCache(int capacity) {
        _maxSize = capacity;
     }
    LRUCache(){}
    void setsize(int capacity){
        _maxSize = capacity; 
    }
    std::string get(const std::string & key);

    void set(const std::string &key, const std::string &value) ;
   
};

}

#endif  //__CACHE_H_
//
//int main(){
//      LRUCache cache(3);
//      cache.set("1","1"); 
//      cache.set("2","2");
//      cache.set("3","3");
//      cache.set("4","4");
//
//      string str = cache.get("1") ;
//      if (str.empty()){
//          cout << "is empty" << endl;
//      }
//      
//      cout << cache.get("4") << endl;
//
//
//      return 0;
//}

