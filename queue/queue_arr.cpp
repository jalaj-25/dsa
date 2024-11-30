#include <iostream>
using namespace std;

#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;

bool isFull() {
    if(rear == MAX - 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if(front == -1 || front > rear) {
        return true;
    }
    return false;
}

void enqueue(int data) {
    if(isFull()) {
        cout << "Queue is full" << data << endl;
    } else {
        if(front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        cout << "Enqueued: " << data << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Dequeued: " << queue[front] << endl;
        front++;
    }
}

int peek() {
    if (!isEmpty()) {
        return queue[front];
    }
    cout << "Queue is empty" << endl;
    return -1;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Front\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Front element: " << peek() << endl;
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
