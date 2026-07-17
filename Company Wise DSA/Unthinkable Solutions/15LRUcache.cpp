#include<unordered_map>
#include<iostream>
using namespace std;

class LRUcache{
public:
    struct Node{
        int key,val;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    LRUcache(int cap){
        capacity = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int,Node*> map;

    void put(int k,int v){
        if(map.find(k)!=map.end()){
            Node* node = map[k];
            deleteNode(node);
            map.erase(k);
            delete node;
        }
        if(map.size()==capacity){
            Node* node = tail->prev;
            map.erase(node->key);
            deleteNode(node);
            delete node;
        }
        Node* newNode = new Node(k,v);
        addNode(newNode);
        map[k] = newNode;
    }

    int get(int k){
        if(map.find(k)!=map.end()){
            Node* node = map[k];
            int ans = node->val;
            deleteNode(node);
            addNode(node);
            return ans;
        }
        return -1;
    }
};

int main(){
    LRUcache *obj = new LRUcache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1);

    obj->put(3,3);
    return 0;
}