#include <iostream>
using namespace std;

using Node = struct Node{
    string data;
    Node* next;
    Node* previous;
};

int main() {
    //create nodes and set pointers
    Node* node1 = new Node{"First element", nullptr, nullptr};
    Node* node2 = new Node{"Second element", nullptr, node1};
    Node* node3 = new Node{"Third element", nullptr, node2};

    node1->next = node2;
    node2->next = node3;

    Node* current = node1;

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
    
    current = node1;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}