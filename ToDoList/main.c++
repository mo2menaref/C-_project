#include "ToDoList.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
Todo test;
   int choice,x;
   string task;
    do { // The Beginning of the loop
            //////////////// The Home of the System ///////////////////////
        cout<<"\n==============================Welcome==============================\n=============================To Do List============================\n";
        cout << "[1] Add Task  [2] Remove Task  [3] Display Tasks  [4] Check Task if Done  [5] Markasdone [6] Total tasks [7] Exit\n\n";
        cout << "Please Enter your choice: ";
        cin >> choice;
         //The Beginning of the options choice
        if(choice==1){// add
            cin.ignore(); //To make ability to write a task after enter the number of choice
            getline(cin,task);
            test.AddTask(task);
        }
        else if(choice==2){ //Remove tasks by displaying them first
            test.DisplayTask();
            cout<<"Enter The task number";
            cin>>x;
            test.RemoveTask(x);
}
        else  if(choice==3){ //showing tasks
            test.DisplayTask();
}
        else  if(choice==4){ //check a specific task if done
            cin>>x;
            test.checkTaskDone(x);
}
        else if(choice==5){ // mark task as done
            test.DisplayTask();
            cout<<"Enter the Task number";
            cin>>x;
            test.MarkasDone(x);
}
else if(choice==6){ // tatal tasks
            cout<<"the Total Tasks is ";
            test.count();
}
        else if(choice==7){
            cout << "Exiting program.\n";
}
else{
            cout << "Invalid choice. Please try again.\n"; //if the user enter invailed input
}
    } while (choice != 7); // the condition of the loop
system("pause");
    return 0;
}