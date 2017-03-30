#include "cache.h"
namespace http{

    std::string LRUCache::get(const std::string & key){
        std::map<std::string, std::list<Node>::iterator >::iterator it = _mp.find(key);
        if (it == _mp.end())     //没有命中
        {
            return "";
        }
        else{
            std::list<Node>::iterator listit = _mp[key];
            Node newnode;
            newnode.key = key;
            newnode.value = listit->value;
            _cacheList.erase(listit);              //先删除命中的节点 
            _cacheList.push_front(newnode);  //将命中的节点放到链表头部
            _mp[key] = _cacheList.begin();
        }
        return _cacheList.begin()->value;
        
    }

    void LRUCache::set(const std::string &key, const std::string &value) {
        std::map<std::string, std::list<Node>::iterator >::iterator it = _mp.find(key);
        if (it == _mp.end())  //没有命中
        {  
            if (_cacheList.size() == _maxSize) //cache满了 
            {
                _mp.erase(_cacheList.back().key);  
                _cacheList.pop_back();
            }
            Node newnode;
            newnode.key = key;
            newnode.value = value;  
            _cacheList.push_front(newnode);
            _mp[key] = _cacheList.begin();
        }
        else{
            std::list<Node>::iterator listit = _mp[key];
            _cacheList.erase(listit);              //先删除命中的节点 
            Node newnode;  
            newnode.key = key;
            newnode.value = value;
            _cacheList.push_front(newnode);  //将命中的节点放到链表头部
            _mp[key] = _cacheList.begin();  //为了映射 
        }
    }

}//http





















