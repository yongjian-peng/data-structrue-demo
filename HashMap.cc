#include "stdc++.h"

using namespace std;

//自定义的哈希函数类
class HashFunc
{
public:
    int operator()(const int key)
    { //对于int类型的key对应的hash函数，随便编的，不要在意这些细节
        return 3 * key + 1;
    }
};

template <typename Key, typename Value> //这是链表节点，包括key和value
class HashNode
{
public:
    Key key;
    Value value;
    HashNode *next;
    HashNode(Key _key, Value _value) : key(_key), value(_value), next(NULL) {}
    ~HashNode() {}
};

template <typename Key, typename Value, typename HashFunc>
class HashMap
{
public:
    int size;
    HashFunc hash; // hash是自定义的哈希函数，重载了类的()相当于重新定义了一个函数
    HashNode<Key, Value> **table;
    Value valuenull;

    HashMap(int _size);
    ~HashMap();
    //插入操作
    bool insert(Key key, Value value);
    //删除操作
    bool del(Key &key);
    //查找，下面的[]运算符重载与之功能相同
    Value &find(Key &key);
    Value &operator[](Key &key);
    void print(); //打印
};

template <typename Key, typename Value, typename HashFunc>
HashMap<Key, Value, HashFunc>::HashMap(int _size) : size(_size), hash()
{
    //对table初始化
    table = new HashNode<Key, Value> *[_size];
    for (int i = 0; i < _size; i++)
    {
        table[i] = NULL;
    }
}

template <typename Key, typename Value, typename HashFunc>
HashMap<Key, Value, HashFunc>::~HashMap()
{
    for (int i = 0; i < size; i++)
    {
        HashNode<Key, Value> *cur = table[i];
        while (cur)
        {
            HashNode<Key, Value> *temp = cur;
            cur = cur->next;
            delete temp;
            temp = NULL;
        }
    }
    delete table;
}

template <typename Key, typename Value, typename HashFunc>
bool HashMap<Key, Value, HashFunc>::insert(Key key, Value value)
{                                 //增加一个key-value对
    int index = hash(key) % size; //求出来对于每个key哈希到的地址索引
    HashNode<Key, Value> *hnode = new HashNode<Key, Value>(key, value);
    hnode->next = table[index];
    table[index] = hnode;
    return true;
}
template <typename Key, typename Value, typename HashFunc>
bool HashMap<Key, Value, HashFunc>::del(Key &key)
{ //删除
    int index = hash(key) % size;
    HashNode<Key, Value> *cur = table[index];
    if (cur == NULL)
        return false;

    HashNode<Key, Value> *pre = cur;
    cur = cur->next;
    while (cur)
    {
        if (cur->key == key)
        { //找到匹配的键值对了
            pre->next = cur->next;
            delete cur;
            cur = NULL;
            return true;
        }
        else
        {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return false;
}
template <typename Key, typename Value, typename HashFunc>
Value &HashMap<Key, Value, HashFunc>::find(Key &key)
{ //查找
    int index = hash(key) % size;
    if (table[index] == NULL)
        return valuenull;
    HashNode<Key, Value> *cur = table[index];
    while (cur)
    {
        if (cur->key == key)
            return cur->value;
        else
            cur = cur->next;
    }
    return valuenull; //没找到返回空
}

template <typename Key, typename Value, typename HashFunc>
Value &HashMap<Key, Value, HashFunc>::operator[](Key &key)
{ //重载[]通过索引来访问
    return find(key);
}

template <typename Key, typename Value, typename HashFunc> //可以打印当前有多少key-value键值对
void HashMap<Key, Value, HashFunc>::print()
{
    for (int i = 0; i < size; i++)
    {
        HashNode<Key, Value> *cur = table[i];
        while (cur)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
}