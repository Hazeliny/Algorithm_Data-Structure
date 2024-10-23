/*
struct listNode {
    int val;
    listNode *next;
    listNode(int x) : val(x), next(nullptr) {} // constructor
    };

listNode* n0 = new listNode(1);
listNode* n1 = new listNode(3);
listNode* n2 = new listNode(2);
listNode* n3 = new listNode(5);
listNode* n4 = new listNode(4);
n0->next = n1;
n1->next = n2;
n2->next = n3;
n3->next = n4;

// doubly linked list
struct listNode {
    int val;
    listNode *next;
    listNode *prev;
    listNode(int x) : val(x), next(nullptr), prev(nullptr) {} // constructor
    };
*/

#include "../inc/algo.hpp"

class listNode {
    public:
        int val;
        listNode *next;
        listNode(int x) : val(x), next(nullptr) {}
};
class linkedList {
    private: 
        listNode *head;
    public:
        linkedList() : head(nullptr) {}
        ~linkedList() {
            freeMemory();
        }
        void insert(listNode *n0, listNode *newNode) {
            if (n0 == nullptr)
                return ;
            listNode *n1 = n0->next;
            newNode->next = n1;
            n0->next = newNode;
        }
        void remove(listNode *n0) {
            if (n0 == nullptr || n0->next == nullptr)
                return ;
            listNode *n1 = n0->next;
            n0->next = n1->next;
            delete n1; // free memory of the removed node
        }
        // access the node at index and return its pointer, nullptr if index is out of range
        listNode* access(int index) {
            listNode *curr = head;
            for (int i = 0; i < index; i++) {
                if (curr == nullptr)
                    return (nullptr);
                curr = curr->next;
            }
            return (curr);
        }
        // return the index of the first occurrence of target in the linked list, -1 if not found
        int find(int target) {
            listNode *curr = head;
            int index = 0;
            while (curr != nullptr) {
                if (curr->val == target)
                    return (index);
                curr = curr->next;
                index++;
            }
            return (-1);
        }
        void append(int val) {
            listNode *newNode = new listNode(val);
            if (head == nullptr)
                head = newNode;
            else {
                listNode *curr = head;
                while (curr->next !=nullptr)
                    curr = curr->next;
                curr->next = newNode;
            }
        }
        void print() {
            listNode *curr = head;
            while (curr != nullptr) {
                cout << curr->val << "->";
                curr = curr->next;
            }
            cout << "nullptr" << endl;
        }
        listNode* getHead() {
            return (head);
        }
        void freeMemory() {
            listNode *curr = head;
            while (curr != nullptr) {
                listNode *nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
            head = nullptr;
        }
};

int main() {
    linkedList list;
    list.append(1);
    list.append(3);
    list.append(2);
    list.append(5);
    list.append(4);
    cout << "The initialized linked list is: " << endl;
    list.print();

    // insert a node with value 0 after the head node
    list.insert(list.getHead(), new listNode(0));
    cout << "Linked list after inserting a node behind the head node with value 0 is: " << endl;
    list.print();

    // remove the first node after the head node
    list.remove(list.getHead());
    cout << "Linked list after removing the node after the head is: " << endl;
    list.print();

    // access the node at index 3 and return this node's pointer
    listNode *node = list.access(3);
    if (node)
        cout << "The value of the node at index 3 in the linked list is: " << node->val << endl;
    else
        cout << "Node not found at index 3" << endl;

    int index = list.find(2);
    if (index != -1)
        cout << "The index of the node with value 2 in the linked list is: " <<index << endl;
    else
        cout << "Vlaue 2 not found in the linked list" << endl;
    
    return (0);
}