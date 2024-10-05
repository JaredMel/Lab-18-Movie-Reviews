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
    int choice1;
    int choice2 = 1;

    cout << "Which linked list methode should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice1;

    switch (choice1)
    {
    case 1:
        cin.ignore();
        while (choice2 == 1)
        {
            head = addNodeToHead(head);
            cout << "Enter another review? Yes=1/No=2: ";
            cin >> choice2;
        }
        break;
    case 2:
        cin.ignore();
        while (choice2 == 1)
        {
            head = addNodeToTail(head);
            cout << "Enter another review? Yes=1/No=2: ";
            cin >> choice2;
        }
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
    double sum = 0.0;
    double average = 0.0;
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "   > Review #" << count << ": " << current->rating << ": " << current->comments << endl;
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

    cout << "Enter review rating 0-5: ";
    cin >> r;
    cout << "Enter review comments: ";
    cin >> c;
    cin.ignore();

    Node* new_node = new Node(r, c);
    new_node->next = hd;

    return new_node;
}

Node* addNodeToTail(Node * &hd)
{
    double r;
    string c;

    cout << "Enter review rating 0-5: ";
    cin >> r;
    cout << "Enter review comments: ";
    cin >> c;
    cin.ignore();

    Node* new_node = new Node(r, c);
    if (hd == nullptr)
    {
        return new_node;
    }
    Node * last = hd;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;

    return hd;
}