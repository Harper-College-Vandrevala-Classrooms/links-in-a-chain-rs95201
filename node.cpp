#include <iostream>
#include <string>
using namespace std;

class ChainLink 
{
private:
    string color;
public:
    ChainLink(string color) 
    {
        this->color = color;
    }
    string get_color() 
    {
        return this->color;
    }
};

class Node 
{
public:
    ChainLink* data;  
    Node* next;      
    Node(ChainLink* data, Node* next = nullptr) 
    {
        this->data = data;
        this->next = next;
    }
    ChainLink* get_data() 
    {
        return this->data;
    }
    Node* get_next() 
    {
        return this->next;
    }
};

class LinkedList 
{
private:
    Node* head;  
    Node* tail;
public:
    LinkedList() 
    {
        head = nullptr; 
        tail = nullptr;
    }
    void append(ChainLink* new_data) 
    {
        Node* new_node = new Node(new_data);  

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node; 
        } 
        else 
        {
            tail->next = new_node;  
            tail = new_node; 
        }
    }

    ChainLink* get_at_index(int index) 
    {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) 
        {
            if (count == index) 
            {
                return temp->get_data();
            }
            count++;
            temp = temp->get_next();
        }
        return nullptr;
    }

    void display() 
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->get_data()->get_color() << " ";
            temp = temp->get_next();
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    ChainLink* link_one = new ChainLink("red");
    list.append(link_one);

    ChainLink* link_two = new ChainLink("blue");
    list.append(link_two);

    ChainLink* link_three = new ChainLink("green");
    list.append(link_three);

    cout << "LinkedList: ";
    list.display();

    ChainLink* retrieved_link = list.get_at_index(1);
    if (retrieved_link != nullptr) 
    {
        cout << "ChainLink at index 1: " << retrieved_link->get_color() << endl;
    } 
    else 
    {
        cout << "No ChainLink found at index 1." << endl;
    }

    ChainLink* another_retrieved_link = list.get_at_index(2);
    if (another_retrieved_link != nullptr) {
        cout << "ChainLink at index 2: " << another_retrieved_link->get_color() << endl;
    } 
    else 
    {
        cout << "No ChainLink found at index 2." << endl;
    }


    delete link_one;
    delete link_two;
    delete link_three;

    return 0;
}
