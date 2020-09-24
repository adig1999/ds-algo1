#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

vector<int> inorder(vector<Node> tree)
{
   vector<int>inor;
   std::set<int>done;
   std::stack<int>proc;

   done.insert(-1);
   proc.push(0);
   while(!proc.empty())
   {
       int i=proc.top();
       if(done.find(tree[i].left)!=done.end())
       {
           inor.push_back(tree[i].key);
           done.insert(i);
           proc.pop();

           if(tree[i].right!=-1)
           {
            proc.push(tree[i].right);
           }
       }
       else
       {
        proc.push(tree[i].left);
       }
   }

   return inor;
}

bool IsBinarySearchTree(const vector<Node>& tree) {

vector<int>inor;

inor=inorder(tree);

vector<int>keys;

for(int i=0;i<tree.size();i++)
    keys.push_back(tree[i].key);

    std::sort(keys.begin(),keys.end());

    if(keys==inor)
return true;
    else
    return false;
}

int main() {
  int nodes;
  cin >> nodes;
  if(nodes==0)
  {
      cout << "CORRECT" << endl;
      return 0;
  }
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}


