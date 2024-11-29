#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> numStack;
    int choice, data;
    while(true) 
    {
        cout << "Stack Operations\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your chocie: ";
        cin >> choice;

        switch(choice) 
        {
            case 1: //push
                cout << "Enter data to push: ";
                cin >> data;
                numStack.push(data);
                cout << "Value entered: " << data << endl;
                break;

            case 2: //pop
                if(numStack.empty()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Value to pop: " << numStack.top() << endl;
                    numStack.pop();
                }
                break;
                
            case 3: //display
                if(numStack.empty()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Value to pop: " << numStack.top() << endl;
                }
                break;
            
            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}