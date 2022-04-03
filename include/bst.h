#ifndef BST_H
#define BST_H
#include<iostream>
#include<functional>
#include <compare>

class BST
{
public:
   class Node
   {
    public:
	Node(int value, Node* left, Node* right);
	Node()= default;
	Node(const Node& node);
    bool operator<(size_t N);
    bool operator>(size_t N);
    bool operator==(size_t N);
    bool operator>=(size_t N);
    bool operator<=(size_t N);
    operator int() const;



	int value;
	Node* left;
	Node* right;
     };
    BST()=default;
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
    int lens();

private:
    Node* root;
};
std::ostream& operator<<(std::ostream& os,const BST::Node node);
std::ostream& operator<<(std::ostream& os,const BST bst);
extern int cnt;
#endif
