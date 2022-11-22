#include <iostream>
using namespace std;

class Node {
    public:
        int DATA;
        Node *NEXT;
        Node() {
            DATA = 0;
            NEXT = NULL;
        }
};

class LinkedList {
    private:
        Node *HEAD;
    public:
        int length, HL = -1;
        LinkedList() {
            HEAD = NULL;
            length = 0;
        }
        void insert(int data) {
            //Inserts element at the end of list
            Node *temp = new Node;
            temp->DATA = data;
            length++;
            if (HEAD == NULL) {
                HEAD = temp;
                return;
            }
            Node *last = HEAD;
            while(last->NEXT != NULL) {
                last = last->NEXT;
            }
            last->NEXT = temp;
            HL = length-1;
        }

        void insertHead(int data) {
            Node *temp = new Node;
            temp->DATA = data;
            temp->NEXT = HEAD;
            HEAD = temp;
            length++;
            HL = 0;
        }
        void insert(int data, int index) {
            //Inserts new element into the given index
            int count;
            HL = index;
            if (index > (length - 1) || index < -1) {
                //out of range
                HL = -1;
                return;
            }
            else if (index == -1 || index == length - 1) {
                HL = length - 1;
                insert(data);
            }
            else if (index == 0) {
                insertHead(data);
            }
            else {
                Node *temp = HEAD;
                Node *insert = new Node;
                int i = 0;
                do {
                    if (i == index - 1) {
                        insert->NEXT = temp->NEXT;
                        insert->DATA = data;
                        temp->NEXT = insert;
                        length++;
                        return;
                    }
                    i++;
                    temp = temp->NEXT;
                } while (i <= index);
            }
        }
        void display() {
            //Prints all the elements of the list
            Node *last = HEAD;
            int index = 0;
            while(last->NEXT != NULL) {
                cout << "\t";
                if (HL > -1 && HL < length && index == HL) {
                    cout << "---->";
                }
                cout << "List[" << index << "] = " << last->DATA << endl;
                last = last->NEXT;
                index += 1;
            }
            cout << "\tList[" << index << "] = " << last->DATA << "\n\n";
            HL = -1;
        }

        void remove() {
            //removes the last element from the list
            Node *last = HEAD;
            Node *temp;
            while (last->NEXT != NULL) {
                temp = last;
                last = last->NEXT;
            }
            temp->NEXT = NULL;
            delete(last);
            length--;
        }

        void pop() {
            //removes the element at the first
            Node *first = HEAD;
            Node *temp = first->NEXT;
            int value = first->DATA;
            delete(first);
            HEAD = temp;
            length--;
        }
        void pop(int index) {
            int count;
            Node *last;
            Node *temp = HEAD;
            if (index > (length - 1) || index < -1) {
                //Error index out of bounds
                return;
            }
            else if (index == -1) {
                remove();
                return;
            }
            else if (index == 0) {
                pop();
                return;
            }
            else {
                Node *temp = HEAD;
                Node *remove;
                int i = 0;
                do {
                    if (i == index - 1) {
                        remove = temp->NEXT;
                        temp->NEXT = remove->NEXT;
                        delete(remove);
                        length--;
                        return;
                    }
                    i++;
                    temp = temp->NEXT;
                } while (i <= index);
            }
        }
        void deleteFront () {
            Node *ptr = new Node;
            ptr = HEAD;
            HEAD = HEAD->NEXT;
            delete(ptr);
            length -= 1;
        }
};

void getElement(LinkedList &ll, int index = -1) {
    int data;
    cout << "\tEnter element: ";
    cin >> data;
    if (index < -1) {
        cout << "Enter your desired Index: ";
        cin >> index;
    }
    else if (index == -1) {
        index = ll.length - 1;
    }
    ll.insert(data, index);
}

int main() {
    LinkedList ll;
    int n, index, option;

    for (int i = 3; i <= 20; i += 3) {
        ll.insert(i + 5);
        ll.insert(i);
        ll.insert(i - 2);  
    }
    ll.display();

    while (true) {
        cout << "Choose Operation:\n";
        cout << "\t1. Insertion" << endl;
        cout << "\t2. Deletion" << endl;
        cout << "\t3. Quit the program " << endl;
        cin >> option;

        if (option == 2) {
            cout << "\tEnter your Choice:\n";
            cout << "\t\t1. Delete Element at the first" << endl;
            cout << "\t\t2. Delete Element at the end" << endl;
            cout << "\t\t3. Delete Element at a specified index" << endl;
            cin >> option;
        } 
        else if (option == 1) {
            cout << "\tEnter your Choice:\n";
            cout << "\t\t1. Insert Element at the first" << endl;
            cout << "\t\t2. Insert Element at the end" << endl;
            cout << "\t\t3. Insert Element at a specified index" << endl;
            cin >> option;
            option += 3;
        }
        else {
            cout << "\t\t\t\t***Exiting... BYE***";
            break;
            exit(0);
        }

        switch (option) {
        case 1:
            ll.pop();
            cout << "After deleting FIRST item:\n\n";
            break;
        case 2:
            ll.remove();
            cout << "After deleting LAST item:\n\n";
            break;
        case 3: {
            int in;
            cout << "Enter index: ";
            cin >> in;
            ll.pop(in);
            cout << "After deleting item from INDEX = " << in << "\n\n";
            break;
        }
        case 4:
            getElement(ll, 0);
            cout << "After inserting item at the FIRST position:\n\n";
            break;
        case 5:
            getElement(ll);
            cout << "After inserting item at the LAST position:\n\n";
            break;
        case 6:
            getElement(ll, -2);
            cout << "After inserting item in the desired index:\n\n";
            break;
        default:
            cout << "\t\t***INVALID CHOICE***";
            break;
        }
        ll.display();
    }
    return 0;
}
