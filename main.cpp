///******************************************************************************
//Description: This program will allow the user to write movie reviews
//Author: Jared Melendez
//COMSC 210 Section 5293
//Date: October 4, 2024
//Status: Done
///******************************************************************************

#include <iostream>
using namespace std;
//struct Node
struct Node {
    //Declares attributes
    double rating;
    string comments;
    Node *next;
    //constructor
    Node(double new_rating, string new_comments)
    {
        rating = new_rating;
        comments = new_comments;
        next = nullptr;
    }
};
//Prototype functions
void output(Node *);
Node* addNodeToHead(Node *&);
Node* addNodeToTail(Node *&);
//the main function
int main() {
    //Declares and initilizes variables
    Node *head = nullptr;
    int count = 0;
    int choice1;
    int choice2 = 1;
    //user input
    cout << "Which linked list methode should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice1;
    //switch using choice1
    switch (choice1)
    {
    case 1:
        cin.ignore();
        while (choice2 == 1)
        {
            //calls the addNodeToHead function
            head = addNodeToHead(head);
            cout << "Enter another review? Yes=1/No=2: ";
            cin >> choice2;
        }
        break;
    case 2:
        cin.ignore();
        while (choice2 == 1)
        {
            //calls the addNodeToTail function
            head = addNodeToTail(head);
            cout << "Enter another review? Yes=1/No=2: ";
            cin >> choice2;
        }
        break;
    default:
        break;
    }
    //calls the output function
    output(head);
    
}
//the output function
void output(Node * hd) {
    //checks if list is empty
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    //Declares and initilizes variables
    int count = 1;
    Node * current = hd;
    double sum = 0.0;
    double average = 0.0;
    //Outputs list
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "   > Review #" << count << ": " << current->rating << ": " << current->comments << endl;
        count++;
        sum += current->rating;
        current = current->next;
    }
    //calculates average and outputs it
    average = sum/count;
    cout << "   > Average: " << average << endl;
}
//the addNodeToHead function
Node* addNodeToHead(Node * &hd)
{
    //Declares and initilizes variables
    double r;
    string c;
    //user input
    cout << "Enter review rating 0-5: ";
    cin >> r;
    cout << "Enter review comments: ";
    cin >> c;
    cin.ignore();
    //adds new_node to the head of the list
    Node* new_node = new Node(r, c);
    new_node->next = hd;

    return new_node;
}
//the addNodeToTail function
Node* addNodeToTail(Node * &hd)
{
    //Declares and initilizes variables
    double r;
    string c;
    //user input
    cout << "Enter review rating 0-5: ";
    cin >> r;
    cout << "Enter review comments: ";
    cin >> c;
    cin.ignore();
    //creates new_node
    Node* new_node = new Node(r, c);
    //checks if list is empty
    if (hd == nullptr)
    {
        return new_node;
    }
    //creates last
    Node * last = hd;
    //iterates through the list in till it reachs the end
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;
    //returns hd
    return hd;
}