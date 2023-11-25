// Creating a class name linkList for making a list easy to handle
#include <iostream>

using namespace std;

// This is template class of the linkList;
template <typename dataType>
class linkList
{
public:
    // Structure for Linked List
    struct node
    {
        // Template value for store the input value
        dataType data;

        // Front Pointer for insertion for same varible, [{(Can be removed if not needed)}]
        node *front;

        // Rear pointer for insertion for same pointer variable, [Can write as (node *next;)]
        node *rear;

        // Parmeter constructor for creation and selection for value
        node(dataType value)
        {
            data = value;
            front = nullptr;
            rear = nullptr;
        }
    };

private:
    /*
        => Creation of the head object of the node and tail
            1. haed object for add the head and the the haed's value, which will happen in O(1)
            2. tail object for add the rest value pof insertion
    */

    // Head object for the node and the class at O(1)
    node *head;

    // Another object of node for insertion at O(1)
    node *tail;

public:
    // Default constructor, which is making head and tail NULL when object creation of class
    linkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Checking the node is NULL or not
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Method for push the value from start
    void pushFront(dataType value)
    {
        // creation of a new node
        node *newNode = new node(value);
        if (newNode) // checking the node if node is create or node has any value or not
        {
            if (isEmpty())
            {
                // whatever the value is if node is creating first time haed and tail must be equal
                head = tail = newNode;
            }
            else
            {
                // Algo for insertion the starting
                newNode->rear = head;
                head->front = newNode;
                head = newNode;
            }
        }
        else
        {
            cout << "can't push any elements." << endl;
        }
    }

    // Method for push the value at last
    void pushBack(dataType value)
    {
        // Creation of a New Node
        node *newNode = new node(value);
        if (newNode) //  checking the node if node is created or node
        {
            if (isEmpty())
            {
                // whatever the value is if node is creating first time haed and tail must be equal
                head = tail = newNode;
            }
            else
            {
                // Adding tha element at the end of the node
                tail->rear = newNode;
                newNode->front = tail;
                tail = newNode;
            }
        }
        else
        {
            cout << "Can't push any element" << endl;
        }
    }

    // This method will pop the first element from the start in link list
    void popFront()
    {
        if (isEmpty())
        {
            cout << "Can't pop any Element from start" << endl;
        }
        else
        {
            if (head != nullptr)
            {
                node *nodeToBeDelete = head;

                head = head->rear;
                delete nodeToBeDelete;
            }
        }
    }
    // This method will pop the last element from last in link list
    void popBack()
    {
        if (isEmpty())
        {
            cout << "Can't pop value at the last." << endl;
        }
        if (tail != nullptr)
        {
            // This algo should change
            node *forDeleteNode = tail;
            tail = tail->front;
            tail->rear = nullptr;
            delete forDeleteNode;
        }
        // return forReturnValue;
    }

    // This method is use for print the value
    void printValue()
    {
        for (node *tempHead = head; tempHead != nullptr; tempHead = tempHead->rear)
        {
            cout << tempHead->data << " ";
        }
        head ? cout << endl : cout << "";
    }
    ~linkList()
    {
        node *temp;
        while (head)
        {
            temp = head;
            head = head->rear;
            delete temp;
        }
    }
};
