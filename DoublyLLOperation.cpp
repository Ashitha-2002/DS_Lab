#include<iostream>

using namespace std;

struct Node {
    int value;
    struct Node * rLink;
    struct Node *lLink;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = tail = NULL;
    }

    Node* createNode(int value)
    {
        Node *node = new Node;
        node->value = value;
        node->lLink = NULL;
        node->rLink = NULL;

		return node;
    }
    
    void insertFirst(int value)
    {
    	Node *newNode = createNode(value);
    	if(head == NULL)
		{
			head = newNode;
			tail = newNode;		
		}	
		else
		{
			head->lLink = newNode;
			newNode->rLink = head;
			head = newNode;
		}
		display();
	}
	
	void insertLast(int value)
    {
    	Node *newNode = createNode(value);
    	if(head == NULL)
		{
			head = newNode;
			tail = newNode;		
		}	
		else
		{
			newNode->lLink = tail;
			tail->rLink = newNode;
			tail = newNode;
		}
		display();
	}
	
	void insertAtPosition(int value, int pos)
    {
    	Node *newNode = createNode(value);
    	Node *current = head;
    	Node *prev = NULL;
    	if(head == NULL)
		{
			head = newNode;
			tail = newNode;		
		}
		else if(pos == 1)
		{
			insertFirst(value);	
		}	
		else
		{
			for( int i = 1; i < pos && current != NULL; i++)	
			{
				prev = current;
        		current = current->rLink;
			}
			
			if(current == NULL)
			{
				cout << "Position not found" << endl;
			}
			else
			{
				newNode->lLink = prev;
				newNode->rLink = current;
				prev->rLink = newNode;
				current->lLink = newNode;
				display();	
			}	
		}
	}
	
	void deleteFirst()
    {
    	Node *current = head;
    	if(head == NULL)
		{
			cout << "Linked List is empty" << endl;	
		}	
		else if(head == tail)	
		{
			head = tail = NULL;
			delete head;
		}
		else
		{
			head->rLink->lLink = NULL;
			head = head->rLink;
			delete current;
		}
		display();
	}
	
	void deleteLast()
    {
    	Node *current = head;
    	Node *prev = NULL;
    	if(head == NULL)
		{
			cout << "Linked List is empty" << endl;			
		}
		else if(head == tail)	
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			while(current->rLink != NULL)
			{
				prev = current;
				current = current->rLink;	
			}
			tail = prev;
			delete current;
			prev->rLink = NULL;
		}
		display();
	}
	
	void deleteAtPosition(int pos)
    {
    	Node *current = head;
    	Node *prev = NULL;
    	if(head == NULL)
		{
			cout << "Linked List is empty" << endl;			
		}
	
		else if(pos == 1)
		{
			deleteFirst();
		}
		else
		{
			for( int i = 1; i < pos && current != NULL; i++)
			{
				prev = current;
				current = current->rLink;	
			}
			if(current == NULL)
			{
				cout << "Position not found" << endl;
			}
			else
			{
				current->rLink->lLink = prev;
				prev->rLink = current->rLink;
				delete current;	
			}
			display();
		}
	}

    void display() {
        Node *current = head;
		
		if(head == NULL)
		{
			cout << "Linked List is empty" << endl;
		}
		else
		{
        	while (current != NULL) 
			{	
           		cout << current->value << "->";
        		current = current->rLink;
        	}
        	cout << "NULL" << endl;
    	}
    }

private:
    Node *head, *tail;
};

int main() 
{
	int choice, data, pos;
	LinkedList ll;
	
	while(1)
	{
		cout << "1. Insert First" << endl;
		cout << "2. Insert Last" << endl;
		cout << "3. Insert At Desired Position" << endl;
		cout << "4. Delete First" << endl;
		cout << "5. Delete Last" << endl;
		cout << "6. Delete At Desired Position" << endl;
		cout << "7. Display" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1: 
				cout << "Enter the value : ";
				cin >> data;
				ll.insertFirst(data);
				break;
			case 2:
				cout << "Enter the value : ";
				cin >> data;
				ll.insertLast(data);
				break;
			case 3:
				cout << "Enter the value : ";
				cin >> data;
				cout << "Enter the position : ";
				cin >> pos;
				ll.insertAtPosition(data, pos);
				break;
			case 4:
				ll.deleteFirst();
				break;
			case 5:
				ll.deleteLast();
				break;
			case 6:
				cout << "Enter the position : ";
				cin >> pos;
				ll.deleteAtPosition(pos);
				break;
			case 7: 
				ll.display();
				break;
			case 8: 
				exit(0);
			default:
				cout<< "Invalid choice" << endl;
				break;
		}
	}
}
