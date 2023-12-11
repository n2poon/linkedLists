#include <iostream>
using namespace std;

struct myStr{
	// Data component
	char letter;
	// Linked list component
	myStr* next;
};

void printList(myStr* curr){
	for (; curr->next != NULL; curr=curr->next)
		cout << curr->letter;
	cout << endl;
	return;
}

int main(){
	
	// Create a list head
	myStr* head = new myStr;
	head->letter = '\0';
	head->next = NULL;

	// Start expanding the list
	myStr* curr = head;
	
	// PART 1: Build the list
	while (cin.peek() != '\n')
	{ // NOTE: peek() only look at the entry and does not get the entry
	  // STEP 1: UPDATE CURRENT ENTRY
		 		// how to we get the new entry and assign it to the character of curr?
				char character = cin.get();
				//to access the value of myStr* type (it's a pointer,) use the -> operator
				curr->letter = character;
		
	  // STEP 2: CREATE NEW LIST ENRY
	  	 		// Create a new entry
				curr->next = new myStr; //setting curr to the next value
	  	 		// Move the pointer to the new list entry
	  			// NULL indicates that this entry is the end of the list

				//Option 1: Advance and then set next to NULL
				// curr = curr->next;
				// curr->next = NULL;


				//Option 2: Set next of the new entry to NULL first, then advance
				curr->next->next = NULL;
				curr = curr->next;

			
	}
	// Flush past the line return detected
		 // to get the line return '\n'
		 cin.get();
		 curr->letter = '\0';
		

	// Display the list
	cout << endl << "You have entered: ";
	printList(head);

	return 0;
}
