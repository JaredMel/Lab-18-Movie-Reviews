///******************************************************************************
//Description: This program will 
//Author: Jared Melendez
//COMSC 210 Section 5293
//Date: October 4, 2024
//Status: WIP
///******************************************************************************

#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    int rating;
    string comments;
    Node *next;
};

void output(Node *);
void addNodeToHead(Node *&, Node *&, int);
void addNodeToTail(Node *&, Node *&, int);

int main() {
    Node *head = nullptr;
    int count = 0;
    int choice;

    cout << "Which linked list methode should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addNodeToHead();
        break;
    case 2:
        addNodeToTail();
        break;
    default:
        break;
    }
    output(head);
    
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;

    while (current) {
        cout << "   > Review #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        current = current->next;
    }
    cout << endl;
}

void addNodeToHead(Node * &hd, Node * &nv, int val)
{
    // adds node at head
        if (!hd) { // if this is the first node, it's the new head
            hd = nv;
            nv->next = nullptr;
            nv->value = val;
        }
        else { // its a second or subsequent node; place at the head
            nv->next = hd;
            nv->value = val;
            hd = nv;
        }
}