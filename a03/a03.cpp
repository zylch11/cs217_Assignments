#include <iostream>
using namespace std;

// node structure here

struct node {
    int val;
    node* next;
};

class List {
    node* head = NULL;
    node* last = NULL;
public:
    void push(int val);
    void print_list();
    int delete_after_node( node* );
    node* find_last_node();
    int pop();
    
    void print_ptrs();
};

void List::push(int val) {
    node *temp = new node;      // create new node
    temp->val = val;
    temp->next = NULL;

    if (head == NULL) {         // for when list is empty
        head = temp;
        last = temp;
    } else {                    // for all other cases
        last->next = temp;
        last = last->next;
    }
}

void List::print_list() {
    node* temp = head;
    cout<<"[ ";
    while( temp != NULL ) {
        cout << temp->val << "\t" ;
        temp = temp->next;
    }
    cout << "]"<<endl;
}

int List::delete_after_node(node *current) { 
    node* temp = current->next; 
    int temp_val = current->next->val;
    current->next = current->next->next; 
    delete temp;
    return temp_val;
}

node* List::find_last_node() {
	node* current = head;
	if ( current->next->next != NULL ) {
		current = current->next;
	}
	else
		return current;
}

int List::pop() {
	int temp_val;
	if ( head->next == NULL ) {
		temp_val = 	head->val;
		head= last = NULL;
		delete last;
		delete head;
	}
	else
		temp_val = delete_after_node( find_last_node() );
	return temp_val;
}

void List::print_ptrs() {
	cout << "Head: " << head << " Last: " << last << endl;
}

int main() {
    // Part - 1 Starts here ----------------------
    List l;

    l.push(5);
    l.push(15);
    l.push(30);
    l.print_list();
	
    // Part - 1 Ends here ----------------------



    // Part - 2 Starts here ----------------------

    cout << "Poppping: " << l.pop() << endl;
    l.print_list();

    cout << "Poppping: " << l.pop() << endl;
    l.print_list();

    cout << "Poppping: " << l.pop() << endl;         // this will give an error at first
    l.print_list();
     
    // Part - 2 Ends here ----------------------

    return 0;
}

