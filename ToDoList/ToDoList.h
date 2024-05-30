#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    bool done;
    Node* next;
};

class Todo {
public:
    Node* head;
    Todo();//A constructor
    bool isempty();//Needed in several functions
    void insertfirst(string task); //Needed in the AddTask function
    
    void AddTask(string task) ; //insert Tasks
    void RemoveTask(int position); //to delete taske
    void DisplayTask(); //Show Tasks
    void checkTaskDone(int position); //check if tasks is done or not
    void MarkasDone(int position);  //make a taske as done
    void count();
};