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
    double rating;
    string comments;
    Node *next;

    Node(double new_rating, string new_comments)
    {
        rating = new_rating;
        comments = new_comments;
        next = nullptr;
    }
};

void output(Node *);
Node* addNodeToHead(Node *&);
Node* addNodeToTail(Node *&);

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
        addNodeToHead(head);
        break;
    case 2:
        addNodeToTail(head);
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
    int count = 0;
    Node * current = hd;
    double sum = 0.0;
    double average = 0.0;
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "   > Review #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        count++;
        sum += current->rating;
        current = current->next;
    }
    average = sum/count;
    cout << "   > Average: " << average << endl;
}

Node* addNodeToHead(Node * &hd)
{
    double r;
    string c;
    string choice = "y";

    while (choice.compare("y") == 0)
    {
        cout << "Enter review rating 0-5: ";
        cin >> r;
        cout << "Enter review comments: ";
        getline(cin, c);
        cin.ignore();

        Node* new_node = new Node(r, c);
        new_node->next = hd;

        cout << "Enter another review? Y/N: ";
        getline(cin, choice);
        cin.ignore();
    }
    return new_node
}

Node* addNodeToTail(Node * &hd)
{
    double r;
    string c;
    string choice = "y";
    Node* last = hd;

    while (choice.compare("y") == 0)
    {
        cout << "Enter review rating 0-5: ";
        cin >> r;
        cout << "Enter review comments: ";
        getline(cin, c);
        cin.ignore();

        // adds node at head
        if (!hd) { // if this is the first node, it's the new head
            hd = nv;
            nv->next = nullptr;
            nv->rating = r;
            nv->comments = c;
        }
        else { // its a second or subsequent node; place at the head
            while (last->next != nullptr)
            {
                /* code */
            }
            
            nv->next = hd;
            nv->rating = r;
            nv->comments = c;
            hd = nv;
        }

        cout << "Enter another review? Y/N: ";
        getline(cin, choice);
        cin.ignore();
    }
}