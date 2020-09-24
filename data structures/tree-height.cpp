#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;
    int level;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int breadthsearch(Node* node,int t)
{ int height =0;
int maxlev=0;
     if(node==NULL)
        return 0;
node->level=1;
     std::queue<Node*> q1;
     q1.push(node);
     while(!q1.empty())
     {
         Node* temp= new Node;
         temp=q1.front();
         q1.pop();

            for(int i=0;i<temp->children.size();i++)
            {
           if(temp->children[i]!=NULL)
            q1.push(temp->children[i]);
            temp->children[i]->level=temp->level+1;
            }
            maxlev=std::max(temp->level,maxlev);

     }
     return maxlev;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  int root=-1;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
      else
         root=child_index;
    nodes[child_index].key = child_index;
  }
  int maxheight=0;

     maxheight = breadthsearch(&nodes[root],root);

  std::cout << maxheight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}