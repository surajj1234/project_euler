#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;

typedef struct Node
{
    Node *  previous;
    int     max_path_sum;
    int     value;
} Node;

class Tree
{
    private:
        int num_nodes;
        int height;
        Node * end;

        bool check_index(int node_index)
        {
            if (node_index == 0 || node_index > num_nodes)
                throw invalid_argument("Index out of bounds!");
            return true;
        }
        int calculateHeight(int index)
        {
            int height = 1;
            int right_leaf = 1;
            while (right_leaf < index)
            {
                height++;
                right_leaf += height;
            }
            return height;
        }
        int rightLeafIndex(int height)
        {
            if (height == 1)
                return 1;
            return rightLeafIndex(height - 1) + height;
        }
        int leftLeafIndex(int height)
        {
            return rightLeafIndex(height) - (height - 1);
        }

    public:
        Tree()
        {
            num_nodes = 0;
            end = NULL;
        }
        ~Tree()
        {
            while (end != NULL)
            {
                Node * previous = end->previous;
                delete(end);
                end = previous;
            }
        }
        int getHeight()
        {
            return height;
        }
        int getSize()
        {
            return num_nodes;
        }
        void appendNode(int value)
        {
            Node * n = new (Node);
            n->previous = end;
            n->value = value;
            end = n;
            num_nodes++;

            int left_sum = 0, right_sum = 0;
            int height = calculateHeight(num_nodes);

            if (!isLeftLeafNode(num_nodes))
            {
                left_sum = getNodeMaxSum(num_nodes - height);
            }
            if (!isRightLeafNode(num_nodes))
            {
                right_sum = getNodeMaxSum(num_nodes - (height - 1));
            }
            int path_sum = max(left_sum, right_sum);
            n->max_path_sum = path_sum + n->value;
        }
        Node * getNodeAt(int node_index)
        {
            check_index(node_index);
            Node * n = end;
            int last_index = num_nodes;
            while (last_index != node_index)
            {
                n = n->previous;
                last_index--;
            }
            return n;
        }
        int getNodeValue(int node_index)
        {
            Node * n = getNodeAt(node_index);
            return n->value;
        }
        int getNodeMaxSum(int node_index)
        {
            Node * n = getNodeAt(node_index);
            return n->max_path_sum;
        }
        bool isLeftLeafNode(int node_index)
        {
            check_index(node_index);
            int height = calculateHeight(node_index);
            return node_index == leftLeafIndex(height);
        }
        bool isRightLeafNode(int node_index)
        {
            check_index(node_index);
            int height = calculateHeight(node_index);
            return node_index == rightLeafIndex(height);
        }
};

vector<int> strToVector(string line);

int main()
{
    Tree tree;
    ifstream file("data/problem18.txt");
    string str;
    while(getline(file, str))
    {
        //cout << str << endl;
        vector<int> row = strToVector(str);
        for (int i = 0; i < row.size(); i++)
        {
            tree.appendNode(row[i]);
        }
    }
    int max_sum = 0;
    for (int i = 1; i <= tree.getSize(); i++)
    {
        int node_sum = tree.getNodeMaxSum(i);
        if (max_sum < node_sum)
        {
            max_sum = node_sum;
        }
        //cout << "index " << i << " value " << tree.getNodeValue(i)
        //     << " LL " << tree.isLeftLeafNode(i)
        //     << " RL " << tree.isRightLeafNode(i)
        //     << " maxSum " << node_sum << endl;
    }
    cout << "Max path sum is " << max_sum << "\n";
    return 0;
}

vector<int> strToVector(string line)
{
    vector<int> vect;
    stringstream ss(line);

    int i;
    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ' ')
            ss.ignore();
    }
    return vect;
}
