#include<iostream>
using namespace std;
class Node
{

	private:

	int data;
	Node *next;
	public:
        friend class Linklist;
};

class Linklist
{
	friend class Dequeue;
	private:
	Node *head;
	public:
	Linklist()
	{
		head = NULL;
	}
	~Linklist()
	{
		while(!empty())
		removefront();
	}
	int count()
	{
		int count=0;
		Node*temp=head;
		while(temp!=NULL)
		{
			temp=temp->next;
			count++;
		}
		return count;
	}
	bool empty()
	{
		return head==NULL;
	}
	int front()
	{
		return head->data;
	}
	int back()
	{
		Node *temp = head;
		while(temp->next!=NULL)  //traverse
		{
			temp = temp->next;
		}
		return temp->data;
	}
	void addfront(int el)
	{
		Node *newNode = new Node;
		newNode->data=el;
		newNode->next=head;
		head=newNode;
	}
	void removefront()
	{
		if(empty())
		{
			cout<<"List is empty"<<endl;
		}
		else
		{
		Node *temp=head;
		head=temp->next;
		delete temp;
		}
	}
	void addend(int el)
	{
		if(empty())
		{
			addfront(el);
		}
		else
		{
		Node *newNode = new Node;
		newNode->data=el;
		Node *temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = NULL;
	}
	}
	void removend()
	{
		if(empty())
		{
			cout<<"List is empty"<<endl;
		}
		else if(count()==1)
		{
		removefront();
		}
		else
		{
			Node *temp = head;
			while(temp->next->next!=NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
	}
	void display()
	{
	    Node* temp=head;
	while(temp!=0){
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;

	}
};

class Dequeue
{
	private:
	Linklist l;
	public:
	Dequeue()
	{
	}
	int size()
	{
		return l.count();
	}
	bool empty()
	{
		return l.empty();
	}
	int front()
	{
		return l.front();
	}
	int back()
	{
		return l.back();
	}
	void insert_front(int el)
	{
		l.addfront(el);
	}
	void insert_back(int el)
	{
		l.addend(el);
	}
	void remove_front()
	{
		l.removefront();
	}
	void remove_back()
	{
		l.removend();
	}
	void print()
	{
		l.display();
	}
};
int main()
{
	 int choice,s,dtype;
    char ch;
    int n;
	Dequeue a;

	do
	{
	cout<<"1 Insert at Front"<<endl;
	cout<<"2.Remove from front"<<endl;
	cout<<"3.Add at back"<<endl;
	cout<<"4.Remove from back"<<endl;
	cout<<"5.Empty"<<endl;
	cout<<"6.Size"<<endl;
	cout<<"7.Front"<<endl;
	cout<<"8. Back"<<endl;
	cout<<"9.Print"<<endl;
	cout<<"Enter your choice"<<endl<<endl;
	cin>>choice;
	switch(choice)
	{
	  case 1:


	  cout<<"Enter element"<<endl;
	  cin>>n;
	  a.insert_front(n);


	  break;
	  case 2:

	  a.remove_front();
	  break;
	  case 3:

	  	cout<<"Enter element"<<endl;
	  	cin>>n;
	  	a.insert_back(n);


	  break;
	  case 4:
	  	a.remove_back();


	  break;
	  case 5:
	  if(a.empty())
	  cout<<"Queue is empty"<<endl;
	  else
	  cout<<"Queue is not empty"<<endl;


	  break;
	  case 6:
	  	cout<<"Size of dequeu is "<<a.size()<<endl;

	  break;
	  case 7:

	  	cout<<"Element at front is "<<a.front()<<endl;


	  break;
	  case 8:

	  	cout<<"Element at back is "<<a.back()<<endl;
	break;
	  case 9:
	  a.print();
	  break;

	  default:
	  cout<<"Wrong Choice "<<endl;
	  break;
	}
	cout<<"Enter y/y"<<endl;
	cin>>ch;
	}
   while(ch=='y'||ch=='Y');
}
