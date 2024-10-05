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
void addNodeToHead(Node *&, Node *&);
void addNodeToTail(Node *&, Node *&);

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

void addNodeToHead(Node * &hd, Node * &nv)
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

        // adds node at head
        if (!hd) { // if this is the first node, it's the new head
            hd = nv;
            nv->next = nullptr;
            nv->rating = r;
            nv->comments = c;
        }
        else { // its a second or subsequent node; place at the head
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

void addNodeToTail(Node * &hd, Node * &nv)
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