#include <iostream>
#include <string>
#include "ToDoList.h"
using namespace std;

// Constructor for the Todo class.
Todo::Todo() {
    head = NULL; // Initialize the head pointer to signify an empty list.
}
// Function to check if the list is empty.
bool Todo::isempty() {
    return (head == NULL); // Returns true if the list is empty.
}
// Function to insert a new task at the beginning of the list.
void Todo::insertfirst(string task) {
    Node* newnode = new Node(); // Create a new node.
    newnode->data = task;       // Set the task data.
    newnode->done = false;      // Task is not done by default.

    // If the list is empty, this will be the first node.
    if (isempty()) {
        newnode->next = NULL;
    } else {
        // Otherwise, insert the new node before the current head.
        newnode->next = head;
    }
    head = newnode; // The new node is now the head of the list.
}
// Function to add a task to the end of the list.
void Todo::AddTask(string task) {
    if (isempty())
        insertfirst(task); // If the list is empty, insert at the beginning.
    else {
        // Find the last node in the list.
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Create a new node and add it after the last node.
        Node* newnode = new Node();
        newnode->data = task;
        newnode->done = false;
        temp->next = newnode;
        newnode->next = NULL;
    }
}
// Function to display all tasks in the list.
void Todo::DisplayTask() {
    Node* temp = head;
    int c = 1; // Task counter.
    // Traverse the list and print each task.
    while (temp != NULL) {
        cout <<"["<< c <<"] "<< temp->data;
        if (temp->done) {
            cout << " (Done)" << endl;
        } else {
            cout << " (Not Done)" << endl;
        }
        temp = temp->next;
        c++;
    }
}
// Function to remove a task from the list by its position.
void Todo::RemoveTask(int position) {
    if (isempty()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* temp = head;
    // If the first task is to be removed.
    if (position == 1) {
        head = head->next;
        delete temp; // Free the memory of the removed node.
        return;
    }
    // Find the node before the one to be removed.
    Node* prev = NULL;
    int count = 1;
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    // If the position is out of range.
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    // Remove the node from the list.
    prev->next = temp->next;
    delete temp; // Free the memory of the removed node.
}
// Function to check if a task is marked as done.
void Todo::checkTaskDone(int position) {
    if (isempty()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* temp = head;
    int count = 1;
    // Traverse the list to find the task at the given position.
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    // If the task is found and not done.
    if (temp != NULL && temp->done == false) {
        cout << "Task " << position << " isn't done yet." << endl;
    }
    // If the task is found and done.
    else if (temp != NULL && temp->done == true) {
        cout << "Task " << position << " is done." << endl;
    }
    // If the position is out of range.
    else if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
}
// Function to mark a task as done.
void Todo::MarkasDone(int position) {
    if (isempty()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* temp = head;
    int count = 1;
    // Traverse the list to find the task at the given position.
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    // If the position is out of range.
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    // Mark the task as done.
    temp->done = true;
    cout << "Task " << position << " marked as done." << endl;
}
void Todo::count() {
    Node* temp = head;
    int c = 0; // Task counter.
    while (temp != NULL) {
        temp = temp->next;
        c++;
    }
        cout <<"["<< c <<"] ";
}