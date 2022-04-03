
#include<iostream>
#include "bst.h"
#include<exception>

 int cnt{0};
 
 
BST::Node::Node(int value, Node* left, Node* right)
{
    this ->value=value;
    this ->left=left;
    this ->right=right;
}
BST::Node::Node(const Node& node)
:value{node.value}
,left{node.left}
,right{node.right}
{

}
BST::Node*& BST::get_root()
{
    
    return this ->root ;
}

 /*size_t BST::length()
 {
     if(auto N :this ->get_root())
 }*/

bool BST::Node::operator<(size_t N)
{
 return N > value;
}
bool BST::Node::operator>(size_t N)
{
    return N < value;
}
bool BST::Node::operator==(size_t N)
{
   return N == value ;
}
bool BST::Node::operator>=(size_t N)
{
    return (N == value || N <value);
}
bool BST::Node::operator<=(size_t N)
{
    return (N ==value || N>value);
}
BST::Node::operator int() const
{
    return this->value;
}

bool BST::add_node(int value)
{
int z{1};
if(root==NULL)
{
    root=new Node{value,nullptr,nullptr};
    return true;
    lens();
}
if(root==nullptr)
   return false;
    if(value > root->value)
      if(root->right == nullptr)
         {
        
          root->right=new Node{value,nullptr,nullptr};
          return true;
          lens();
         }
      else
         {
          BST bst{};
           bst.get_root()=root->right;
         bst. add_node(value);
         }
    else if(value <this->root->value)
      
      if(root->left ==nullptr)
      {
        root->left=new Node{value,nullptr,nullptr};
        return true;
        lens();
       }
      else
       {  
         BST bst{};
         bst.get_root()=root->left;
         bst. add_node(value);
       }
    else
       return false;
return 0;
}
void BST::bfs(std::function<void(Node*& node)> func)
{
 
   
}
size_t BST::length()
{
        
    
    
    
        if(root->left !=nullptr && root->right!=nullptr)
        {
               cnt+=2;
               BST bst1{};
               bst1.get_root()=root->right;
               bst1.length();
               BST bst2{};
               bst2.get_root()=root->left;
               bst2.length();
        }
        else if(root->left !=nullptr && root->right==nullptr)
        {
               cnt+=1;
               BST bst1{};
               bst1.get_root()=root->left;
               bst1.length();
        }
        else if(root->left ==nullptr && root->right !=nullptr)
        {
               cnt+=1;
               BST bst1{};
               bst1.get_root()=root->right;
               bst1.length();
        }
     
        return cnt+1;

    
 //return lens();
}

std::ostream& operator<<(std::ostream& os,const BST::Node node) 	
{
    os << &node <<"      => value : "<<node.value<<"      left : "<<node.left<<"      right : "<<node.right<<"\n";
    return os ;
}
std::ostream& operator<<(std::ostream& os,BST bst)
{
    
   
    os << &bst.get_root() <<"    => value:"<<bst.get_root()->value<<"     left: "<<bst.get_root()->left<<"    right: "<<bst.get_root()->right<<std::endl;
   //// while(bst.get_root()->left !=nullptr || bst.get_root()->right!=nullptr)
   // {
        if(bst.get_root()->left !=nullptr && bst.get_root()->right!=nullptr)
        {
              BST bst1{};
               bst1.get_root()=bst.get_root()->right;
               os << &bst1.get_root() <<"    => value:"<<bst1.get_root()->value<<"     left: "<<bst1.get_root()->left<<"    right: "<<bst1.get_root()->right<<std::endl;
               //std::cout<<bst1<<std::endl;
               
               BST bst2{};
               bst2.get_root()=bst.get_root()->left;
              // os << &bst2.get_root() <<"    => value:"<<bst2.get_root()->value<<"     left: "<<bst2.get_root()->left<<"    right: "<<bst2.get_root()->right<<std::endl;
               std::cout<<bst2<<std::endl;
               
        }
        else if(bst.get_root()->left !=nullptr && bst.get_root()->right==nullptr)
        {
               
               BST bst1{};
               bst1.get_root()=bst.get_root()->left;
               //os << &bst1.get_root() <<"    => value:"<<bst1.get_root()->value<<"     left: "<<bst1.get_root()->left<<"    right: "<<bst1.get_root()->right<<std::endl;
               std::cout<<bst1<<std::endl;
               
        }
         else if(bst.get_root()->left ==nullptr && bst.get_root()->right !=nullptr)
        {
               
               BST bst1{};
               bst1.get_root()=bst.get_root()->right;
               //os << &bst1.get_root() <<"    => value:"<<bst1.get_root()->value<<"     left: "<<bst1.get_root()->left<<"    right: "<<bst1.get_root()->right<<std::endl;
               std::cout<<bst1<<std::endl;
               
        }
        
          
    return os;

 
    /*while(true)
    //{
      //os << &bst.get_root() <<"    => value:"<<bst.get_root()->value<<"     left: "<<bst.get_root()->left<<"    right: "<<bst.get_root()->right<<std::endl;
      if(bst.get_root()->left !=nullptr && bst.get_root()->right!=nullptr)
        {
               
               BST bst1{};
               bst1.get_root()=bst.get_root()->right;
               os << &bst1.get_root() <<"    => value:"<<bst1.get_root()->value<<"     left: "<<bst1.get_root()->left<<"    right: "<<bst1.get_root()->right<<std::endl;
               std::cout<<bst1<<std::endl;
               BST bst2{};
               bst2.get_root()=bst.get_root()->left;
               os << &bst2.get_root() <<"    => value:"<<bst2.get_root()->value<<"     left: "<<bst2.get_root()->left<<"    right: "<<bst2.get_root()->right<<std::endl;
               std::cout<<bst2<<std::endl;
        }
        else if(bst.get_root()->left !=nullptr && bst.get_root()->right==nullptr)
        {
               cnt+=1;
               BST bst1{};
               bst1.get_root()=bst.get_root()->left;
               os << &bst1.get_root() <<"    => value:"<<bst1.get_root()->value<<"     left: "<<bst1.get_root()->left<<"    right: "<<bst1.get_root()->right<<std::endl;
               std::cout<<bst1<<std::endl;
        }
        else if(bst.get_root()->left ==nullptr && bst.get_root()->right !=nullptr)
        {
               cnt+=1;
               BST bst1{};
               bst1.get_root()=bst.get_root()->right;
               os << &bst1.get_root() <<"    => value:"<<bst1.get_root()->value<<"     left: "<<bst1.get_root()->left<<"    right: "<<bst1.get_root()->right<<std::endl;
               std::cout<<bst1<<std::endl;
        }
        else
           os << bst.length();
   // }
    
    return os;*/
}
BST::Node**  BST::find_node(int value)
{
    
 try

{
  if(root->left== nullptr && root->right==nullptr)
     return nullptr;
 
  else if(root->value==value)
  {
    //root=new Node{value,nullptr,nullptr};
    return &root;
    
  }
  else

    if(value > root->value)
      if(root->right->value == value)
         {
        
          //root->right=new Node{value,nullptr,nullptr};
          return &root->right;
          
         }
      else if(root->right != nullptr)
         {
          
          
           BST bst{};
           bst.get_root()=root->right;
           //bst.find_node(value);
          

         }
      else
          return nullptr;
    else if(value <this->root->value)
      
      if(root->left->value ==value)
      {
        //root->left=new Node{value,nullptr,nullptr};
        return &root->left;
        
       }
      else if(root->left != nullptr)
       {
          
        
         BST bst{};
         bst.get_root()=root->left;
         bst.find_node(value);
        
       }
      else
       return nullptr;
    else
        return nullptr;
    
  }

 catch(const std::exception& e)
 {
       return nullptr;
 }
 return 0;
}
BST::Node** BST::find_parrent(int value)
{  
   BST bst{}; 
   bst.get_root()=root;
   if(root->left->value==value || root->right->value==value)
      return &root;
   else 
     while(true)
      {
        std::cout<<"h0"<<std::endl;
        if(value > bst.get_root()->value && bst.get_root()->right != nullptr)
         {
           BST bst1{};
           bst.get_root()=bst.get_root()->right;
           std::cout<<bst.get_root()->value<<std::endl;
           if((bst.get_root()->left->value == value && bst.get_root()->left !=nullptr) || (bst.get_root()->right->value==value  && bst.get_root()->right !=nullptr))
              return &bst.get_root();
         }
        else if(value < bst.get_root()->value && bst.get_root()->left != nullptr)
         {
          
           bst.get_root()=bst.get_root()->left;
           std::cout<<"h2"<<std::endl;
           if( (bst.get_root()->left->value == value && bst.get_root()->left !=nullptr) || (bst.get_root()->right->value==value  && bst.get_root()->right !=nullptr))
           {
             std::cout<<"h3"<<std::endl;
              return &bst.get_root();
           }
         }
      }
        

}
BST::Node** BST::find_successor(int value)
{
  BST bst{};
  BST bst1{};
  auto x{find_node(value)};
   std::cout<<(*x)->value;
  
  auto y=(*x)->left;
  if(y==nullptr)
    return nullptr;
  else
  {  
    
    bst.get_root() = y;
    bst1.get_root()=bst.get_root();
    while(bst1.get_root()->right != nullptr)
    {
      
      bst1.get_root() = bst1.get_root()->right;
      
    }
    return &bst1.get_root();
  }
 
  
}
    
 


    


