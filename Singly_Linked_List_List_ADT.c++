#include<iostream>
using namespace std;
//classes
class SLL_ADT;
class Node;

class Node 		//node class
{
	friend class SLL_ADT;	//declaring Node class and SLL_ADT class are friends
	public:
			Node();	//default constructor
			Node(int,Node *);	//parameterised constructor
			Node(const Node &);	//copy constructor
			~Node();	//destructor

			void getdetails();	//to get data
			void putdetails();	//to display data
	private:
			int data;	//value in a node
			Node *next;	//pointer of first node
};

class SLL_ADT
{
	public:
			SLL_ADT();	//default constructor
			SLL_ADT(Node*);	//parameterised constructor
			SLL_ADT(const SLL_ADT&);	//copy constructor
			~SLL_ADT();	//destructor

			int isEmpty();	//to check if the list is empty
			void insertAtFirst(Node*);	//to insert a node at first
			void insertAtLast(Node*);	//to insert a node at last
			void insertByPos(int,Node*);	//to insert a node at the position
			int posOfElement(int);	//to find position of an element in the list
			void insertAfterElement(Node*,int);	//to insert an element after an element in the list
			void insertBeforeElement(Node*,int);	//to insert an element before an element in the list			
			void deleteAtFirst();	//to delete first node
			void deleteAtLast();	//to delete last node
			void deleteByPos(int);	//to delete node at a position
			void deleteAfterElement(int);	//to delete the element after an element in the list
			void deleteBeforeElement(int);	//to delete the element before an element in the list
			void displayList();	//to display the data in every node of the list
			void makeListEmpty();	//to make the lsit empty
	private:
			Node *first;	//address of first node
};

//implementation
//node class member functions
Node::Node()	//default constructor
{
	data=0;
	next=NULL;
}

Node::Node(int d,Node *n)	//parameterised constructor
{
	data=d;
	next=n;
}

Node::Node(const Node &temp)	//copy constructor
{
	data=temp.data;
	next=temp.next;
}

Node::~Node()
{
	data=0;
	next=NULL;
}

void Node::getdetails()		//to input data
{
	cout<<"Enter the value of this node\n";
	cin>>data;
}

void Node::putdetails()	//to print data of node
{
	cout<<data;
}

//SLL_ADT class member functions
SLL_ADT::SLL_ADT()	//default constructor
{
	first=NULL;
}

SLL_ADT::SLL_ADT(Node *f)	//parameterised constructor
{
	first=f;
}

SLL_ADT::SLL_ADT(const SLL_ADT &temp)	//copy constructor
{
	first=temp.first;
}

SLL_ADT::~SLL_ADT()
{
	first=NULL;
}

int SLL_ADT::isEmpty()		//to check if the list is empty
{
	if(first==NULL)
		return 1;
	else
		return 0;
}

void SLL_ADT::insertAtFirst(Node *newNode)	//insert a node at first
{
	Node *temp=newNode;
	if(isEmpty())
		first=temp;
	else
	{
		temp->next=first;
		first=temp;
	}
	cout<<"Element added to the first\n";
}

void SLL_ADT::insertAtLast(Node *newNode)	//insert element at last
{
	Node *temp=first;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newNode;
	delete temp;
	temp=NULL;
	cout<<"Element added to the last\n";
}

void SLL_ADT::insertByPos(int pos,Node *newNode)	//insert element at a position
{
	if(pos==1)
		insertAtFirst(newNode);
	else if(!isEmpty())
	{
		int i=1;
		Node *temp=first;
		while(temp->next!=NULL && i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		if(i==pos-1)
		{
			newNode->next=temp->next;
			temp->next=newNode;
			delete temp;
			temp=NULL;
			cout<<"element is inserted\n";
		}
		else
			cout<<"element can't be inserted\n";
	}
	else
		cout<<"element can't be inserted\n";
}
/*
void SLL_ADT::insertAfterElement(Node *newNode,int ele)	//to insert an element after an element in the list
{
	Node *temp=first;
	while(temp->next!=NULL && temp->data!=ele)
		temp=temp->next;
	if(temp->data==ele)
	{
		newNode->next=temp->next;
		temp->next=newNode;
		cout<<"element inserted successfully";
	}
	else
		cout<<"element can't be inserted";
}
*/
int SLL_ADT::posOfElement(int ele)	//to find the position of an element in the list
{
	Node *temp=first;
	int i=1;
	while(temp->next!=NULL && temp->data!=ele)
	{
		temp=temp->next;
		i++;
	}
	if(temp->data==ele)
		return i;	//position of element in the list
	else
		return -10;	//element is not present
}

void SLL_ADT::insertAfterElement(Node *newNode,int ele)	//to insert an element after an element in the list
{
	int pos=posOfElement(ele);
	insertByPos(pos+1,newNode);
}

/*
void SLL_ADT::insertBeforeElement(Node* newNode,int ele)	//to insert an element before an element in the list
{
	Node *temp=first;
	while(temp->next!=NULL && temp->next->data!=ele)
		temp=temp->next;
	if(temp->next->data==ele)
	{
		newNode->next=temp->next;
		temp->next=newNode;
		cout<<"element inserted successfully";
	}
	else
		cout<<"element can't be inserted";
}
*/

void SLL_ADT::insertBeforeElement(Node *newNode,int ele)	//to insert an element before an element in the list
{
	int pos=posOfElement(ele);
	insertByPos(pos-1,newNode);
}

void SLL_ADT::deleteAtFirst()	//to delete first node
{
	if(!isEmpty())
	{
		Node *temp=first;
		first=temp->next;
		delete temp;
		temp=NULL;
		cout<<"element inserted successfully\n";
	}
	else
		cout<<"element is not present\n";

}

void SLL_ADT::deleteAtLast()
{
	if(!isEmpty())
	{
		Node *temp=first;
		while(temp->next->next!=NULL)
			temp=temp->next;
		delete temp->next;
		temp->next=NULL;
		cout<<"element is deleted\n";
	}
	else
		cout<<"element can't be deleted\n";
}

void SLL_ADT::deleteByPos(int pos)
{
	if(!isEmpty())
	{
		if(pos==1)
			deleteAtFirst();
		else
		{
			int i=1;
			Node *temp=first;
			while(temp->next!=NULL && i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			if(i==pos-1)
			{
				temp->next=temp->next->next;
				cout<<"element is deleted\n";
			}
			else
				cout<<"element can't be deleted\n";
		}
	}
	else
		cout<<"element can't be deleted\n";
}

void SLL_ADT::deleteAfterElement(int ele)
{
	int pos=posOfElement(ele);
	deleteByPos(pos+1);
}

void SLL_ADT::deleteBeforeElement(int ele)
{
	int pos=posOfElement(ele);
	deleteByPos(pos-1);
}

void SLL_ADT::makeListEmpty()
{
	Node *temp=first;
	while(temp->next!=NULL)
		deleteAtFirst();
	cout<<"All elements are deleted\n";
}

void SLL_ADT::displayList()
{
	Node *temp=first;
	while(temp->next!=NULL)
	{
		cout<<temp->data;;
		temp=temp->next;
	}
}


//application

int main()
{
	SLL_ADT list;
	int ch=0;
	while(ch!=-1)
	{
		cout<<"\nChoose an option:\n";
		cout<<"1-to check if list is empty\n";
		cout<<"2-to insert element at first\n";
		cout<<"3-to insert element at last\n";
		cout<<"4-to insert element at a position\n";
		cout<<"5-to insert an element after an element in the list\n";
		cout<<"6-to insert an element before an element in the list\n";
		cout<<"7-to delete element at first\n";
		cout<<"8-to delete element at last\n";
		cout<<"9-to delete element at a position\n";
		cout<<"10-to delete the element after an element in the list\n";
		cout<<"11-to delete the element before an element in the list\n";
		cout<<"12-to find position of an element\n";
		cout<<"13-to display the list\n";
		cout<<"14-to delete all elements of the list\n";
		cout<<"-1 - to exit\n\n";
		cin>>ch;

		if(ch==1)
		{
			if(list.isEmpty())
				cout<<"list is empty\n";
			else
				cout<<"not empty\n";
		}
		else if(ch==2)
		{
			Node newNode;
			newNode.getdetails();
			list.insertAtFirst(&newNode);
		}
		else if(ch==3)
		{
			Node newNode;
			newNode.getdetails();
			list.insertAtLast(&newNode);
		}
		else if(ch==4)
		{
			Node newNode;
			newNode.getdetails();
			int pos;
			cout<<"enter the position\n";
			cin>>pos;
			list.insertByPos(pos,&newNode);
		}
		else if(ch==5)
		{
			Node newNode;
			newNode.getdetails();
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.insertAfterElement(&newNode,ele);
		}
		else if(ch==6)
		{
			Node newNode;
			newNode.getdetails();
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.insertBeforeElement(&newNode,ele);
		}
		else if(ch==7)
			list.deleteAtFirst();
		else if(ch==8)
			list.deleteAtFirst();
		else if(ch==9)
		{
			int pos;
			cout<<"enter the position\n";
			cin>>pos;
			list.deleteByPos(pos);
		}
		else if(ch==10)
		{
			int ele;
			cout<<"enter the element\n";
			cout<<ele;
			list.deleteAfterElement(ele);
		}
		else if(ch==11)
		{
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.deleteBeforeElement(ele);
		}
		else if(ch==12)
		{
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.posOfElement(ele);
		}
		else if(ch==13)
			list.displayList();
		else if(ch==14)
			list.makeListEmpty();
	}
}