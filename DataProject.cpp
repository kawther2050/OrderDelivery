#include <iostream> 
using namespace std; 
#define MAX 100 //defines array size

struct Order //define order details
{
    string name;
    int id;
    string location;
};

struct Queue 
{  //define Queue structure
	Order Q[MAX]; 
	int front;
	int rear; 
}; 
Queue q;
// function to insert an element at the rear of the queue 
void addOrder(Order order) 
{  
	//check if Circular Queue is full
	if ((q.front == 0 && q.rear == MAX-1) || (q.rear == q.front-1))
	    cout << "\nYou cannot order right now try again latter.\n"; 
	//full if rear returning to the starting point And it became before the front in one location
	else if (q.front == -1) // if it's the first element
    { 
        q.front = q.rear = 0;
        q.Q[q.rear] = order; 
    } 
    else if (q.rear == MAX-1 && q.front != 0) 
    { //if rear reach max and there is available place in front
        q.rear = 0; 
        q.Q[q.rear] = order; 
    }   
    else //if it's not the first element
    { 
        q.rear++;
        q.Q[q.rear] = order; 
    }
}

// function to delete an element from the front of the queue 
void removeOrder() 
{ 
	if (q.front == -1) // check if queue is empty
        cout << "\nThere is no order to remove!\n";
    else
    {
    	string orderName = q.Q[q.front].name; //to mark the order as deleted
	    
		cout<<"The order by "<<orderName<<" has been served.\n";// print the removed order (front element).
	    
	    if (q.front == q.rear) // if one element only in queue
	        q.front = q.rear = -1;// back to the base
	    else if (q.front == MAX-1) 
	        q.front = 0; 
	    else //increment front
	        q.front++; 
	}
}

// print all queue elements 
void display() 
{ 
	if (q.front == -1) 
    	cout << "\nThere is no orders yet.\n"; //check if queue is empty
    else
    {
    	//traverse through the array to display queue elements
	    cout << "\nList of orders:\n"; 
	    if (q.rear >= q.front) 
	    { 
	        for (int i = q.front; i <= q.rear; i++) 
	        {
			    cout << "Order " << i - q.front + 1 << ":\n";
                cout << "Name: " << q.Q[i].name << "\n";
                cout << "ID: " << q.Q[i].id << "\n";
                cout << "Location: " << q.Q[i].location << "\n";
                cout << "---------------------\n";
            }
	    } 
	    else
	    { 
	        for (int i = q.front; i < MAX; i++) 
	        {
			    cout << "Order " << i - q.front + 1 << ":\n";
                cout << "Name: " << q.Q[i].name << "\n";
                cout << "ID: " << q.Q[i].id << "\n";
                cout << "Location: " << q.Q[i].location << "\n";
                cout << "---------------------\n";
            }
	  
	        for (int i = 0; i <= q.rear; i++) 
	        {
			    cout << "Order " << i - q.front + 1 << ":\n";
                cout << "Name: " << q.Q[i].name << "\n";
                cout << "ID: " << q.Q[i].id << "\n";
                cout << "Location: " << q.Q[i].location << "\n";
                cout << "---------------------\n";
            }
	    }
	}
}
// print front of queue
void viewNext() 
{ 
	if (q.front == -1)  //check if queue is empty
		cout << "\nThere is no orders yet.\n";
	else //diplay front queue
	{
		cout << "\nNext order details:\n";
        cout << "Name: " << q.Q[q.front].name << "\n";
        cout << "ID: " << q.Q[q.front].id << "\n";
        cout << "Location: " << q.Q[q.front].location << "\n"; 
	}
}

// print rear of queue 
void viewLast() 
{ 
	if (q.front == -1)   //check if queue is empty
		cout << "\nThere is no orders yet.\n";
	else//display rear queue
	{
		cout << "\nNext order details:\n ";
        cout << "Name: " << q.Q[q.rear].name << "\n";
        cout << "ID: " << q.Q[q.rear].id << "\n";
        cout << "Location: " << q.Q[q.rear].location << "\n"; 
	}
}

void search(int id){
	Order searched;
	bool found=false;
		if (q.front == -1) 
    	cout << "\nThere is no orders yet.\n"; //check if queue is empty
    else
    {
    	//traverse through the queue and if the order is found then it will return it 
	    if (q.rear >= q.front) 
	    { 
	        for (int i = q.front; i <= q.rear; i++) 
	        {
			    if(id==q.Q[i].id){
					found=true;
					searched=q.Q[i];
					break;
				}
            }
	    } 
	    else
	    { 
	        for (int i = q.front; i < MAX; i++) 
	        {
			    if(id==q.Q[i].id){
					found=true;
					searched=q.Q[i];
					break;
				}
            }
	  
	        for (int i = 0; i <= q.rear; i++) 
	        {
			    if(id==q.Q[i].id){
					found=true;
					searched=q.Q[i];
					break;
				}
            }
	    }
	}

	if(found){
		cout<<"The order has been found:\n";
	    cout<<"Name: "<<searched.name<<"\nId: "<<searched.id<<"\nLocation: "<<searched.location<<"\n";
		cout << "---------------------\n";
	}else{
		cout<<"The order has not founded.\n";
	}
}
void cancelOrder(int cancelId) {
    if (q.front == -1) {
        cout << "\nThere are no orders to cancel!\n";
        return;
    }

    bool found = false;
    int i = q.front;

    Queue tempQueue;
    tempQueue.front = -1;
    tempQueue.rear = -1;

    do {
        if (q.Q[i].id != cancelId) {
            if (tempQueue.front == -1) {
                tempQueue.front = tempQueue.rear = 0;
            } else if (tempQueue.rear == MAX - 1)
                tempQueue.rear = 0;
            else
                tempQueue.rear++;

            tempQueue.Q[tempQueue.rear] = q.Q[i];
        } else {
            found = true;
            cout << "Order by " << q.Q[i].name << " { ID: " << cancelId << " } has been cancelled.\n";
        }

        if (i == q.rear)
            break;
        i = (i + 1) % MAX;

    } while (true);

    q = tempQueue;

    if (!found) {
        cout << "Order with ID " << cancelId << " not found.\n";
    }
}
int main() 
{ 
    Order order;
	q.front = q.rear = -1; //Initialize front and rear to -1 
	int choice,tempid;

	do
	{
		//display Queue operations on a menu
		cout << "\n>> Menu <<\n";
		cout << "1. Add a new order.\n";
		cout << "2. Mark served order and delete it.\n";
		cout << "3. View next order.\n";
		cout << "4. View last order\n";
		cout << "5. Display the orders.\n";
		cout << "6. Search a specific order.\n";
		cout << "7. Cancel an order\n";
		cout << "8. Exit\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1: 
			    cout<<"Enter the order details: \n";
                cout<<"Name: ";
                cin>>order.name;
                cout<<"ID: ";
                cin>>order.id;
                cout<<"Location: ";
                cin>>order.location;
                addOrder(order);	
				break;			
			case 2: 
				removeOrder();
				break;
			case 3: 
				viewNext();
				break;
			case 4: // Call Rear Function
				viewLast();
				break;
			case 5: // Call Display Function
				display();
				break;
			case 6://Call the Search Function And Pass The Id to it
			    cout<<"Enter the id of the order that you want to find: ";
				cin>>tempid;
				search(tempid);
				break;
			case 7:
				int cancelId;
				cout<<"Enter the id of the order that you want to cancel: ";
				cin>>cancelId;
				cancelOrder(cancelId);
				break;
			case 8: // Terminates program
				cout << "\nProgram terminated..";
				break;
			default: // Incorrect Input message
				cout << "\nIncorrect choice. Try again!\n";
		}
				
	}while(choice!=8);
	
	return 0;
}

