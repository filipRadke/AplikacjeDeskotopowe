#include <iostream>
using namespace std;

using Node = struct Node{
    string data;
    Node* next;
    Node* previous;
};

int main() {
    int len;
    cout << "Please input the list length: ";
    cin >> len;

    //create nodes and set pointers
    Node* head = new Node{"", nullptr, nullptr};

    cout << "Please input value of the first element: ";
    cin >> head->data;

    Node* current = head;
    Node* previous;

    for(int i = 0; i < len-1; i++)
    {
        Node* newNode = new Node{"", nullptr, current};
        cout << "Please input value of the next element: ";
        cin >> newNode->data;

        current->next = newNode;
        previous = current;
        current = newNode;
    }

    current = head; //reset current to head

    while (true)
    {
        string option;
        cout << "Current element value: " << current->data << endl;

        if(current->next != nullptr)
        {
            cout << "There is a next element in the list. Type [n] to go there" << endl;
        }

        if(current->previous != nullptr)
        {
            cout << "There is a previous element in the list. Type [p] to go there" << endl;
        }

        cout << "To exit program type [e]" << endl;

        while(true)
        {
            cout << "Type your option: ";
            cin >> option;
            char choice = option[0];
            switch(choice)
            {
                case 'n':
                    if(current->next != nullptr) {
                        current = current->next;
                        break;
                    } else {
                        cout << "No next element." << endl;
                        break;
                    }
                case 'p':
                    if(current->previous != nullptr) {
                        current = current->previous;
                        break;
                    } else {
                        cout << "No previous element." << endl;
                        break;
                    }
                case 'e':
                    return 0;
                default:
                    cout << "Invalid option. Try again." << endl;
            }
            break;
        }
    }
    return 0;
}