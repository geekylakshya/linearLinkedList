#include <iostream>
using namespace std;

//Creating Link Node
class Node{
    public:
    int val;
    Node* next;

    //Constructor
    Node(int data){
        val = data;
        next = NULL;
    }
};

//Insertion at head
void insertAtHead(Node* &head, int val){ //Node* &head pass by refrence because we have to do changes in linked list
    Node *newNode = new Node(val); //This newNode have val and it pointing to NULL currently
    newNode -> next = head; //Now newNode pointing to head node
    head = newNode; //Now head pointer is shifted to newNode

//Time complexity is O(1)[constant] because we dont have to traverse here for insertion

}

//Insertion at tail
void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val); //This newNode have val and it pointing to NULL currently
    // Check if the linked list is empty by examining the head pointer.
    if (!head) {
        // If it's empty, set the head pointer to the new node,
        // effectively making it the first node in the linked list.
        head = newNode;
        // Exit the function as no further adjustments are needed.

        return;
    }
    Node* temp = head; //temp pointer for traversal
    while(temp->next != NULL){ //traverse to reach at the end of liked list
        temp = temp -> next;
    }
    //temp has reached last node
    temp -> next = newNode;
  //Time complexity O(n)
}

//Insertion at arbitrary position
void insertAtArbitrary(Node* &head, int pos ,int val){
        Node* newNode = new Node(val); //creating new node

        //checking head positioon condition
        if (pos == 0){
            insertAtHead(head,val);
            return;
        }

        Node* temp = head; // temp pointer for traversal
        int currentPos = 0;
        while(currentPos != pos-1){
            temp = temp -> next;
            currentPos++;
            //temp pointer point to node at pos-1
        }

        //checking is enterd position is present in linked list or not
        // if (!temp) { // if temp is NULL means the temp pointer is not able to find the given position
        //     cout << "Error: Invalid Position for Insertion." << endl;
        //     free(newNode);
        //     return;
        // }

        newNode -> next = temp -> next; //temp pointer AND newNode now point to its next node

        temp -> next = newNode; //now temp node points to newNode AND lost connection with its previous next Node
//Time complecity is O(pos) AND O(n) is wrost case
}

//Updation at kth position
void updateAtPos(Node* &head, int pos ,int val){
  Node* temp = head;
  int currentPos = 0;
  while(currentPos != pos){
    temp = temp -> next;
    currentPos++;
  }
  temp -> val = val;

  //time complexity is O(k) AND O(n) is wrost case where n is no, of nodes in linked list
}

//Delete node at Head
void deleteAtHead(Node* &head){
    //Check case for empty linked and one element linked list
    if (head == NULL) {
        cout << "Error: Linked list is empty. Cannot delete from an empty list." << endl;
        return;
    }

    // If there's only one element in the list, delete it.
    else if (head -> next == NULL) {
        free(head);
        head = NULL;
        cout << "Deleted From Head Successfully..."<<endl;
        return;
    }

    else{
        Node* temp = head;  //node to be deleted
        head = head -> next;
        free(temp); //free uo the space of deleted node
        cout << "Deleted From Head Successfully..."<<endl;
    }
//time complexity is O(1)
}

//Delete node at Tail
void deleteAtTail(Node* &head){
    //Check case for empty linked and one element linked list
    if (head == NULL) {
        cout << "Error: Linked list is empty. Cannot delete from an empty list." << endl;
        return;
    }

    // If there's only one element in the list, delete it.
    else if (head -> next == NULL) {
        free(head);
        head = NULL;
        cout << "Deleted From Tail Successfully..."<<endl;
        return;
    }

    else{
        Node* secondLast = head;
        while( secondLast -> next -> next != NULL ){ //secondLast Node -> next -> sent
            secondLast = secondLast -> next;
        }
        //Now secondLast points to second last node
        Node* temp = secondLast -> next;  //node to be deleted
        secondLast -> next = NULL ; //shifting tail / NULL to second last node
        free(temp);
        cout << "Deleted From Tail Successfully..."<<endl;
    }
//time complexity is O(n)
}

//Delete node at arbitrary position
void deleteAtPosition(Node* &head, int pos){
    if(pos == 0){
        deleteAtHead(head);
        return;
    }
    Node* previousNode = head;
    int currentPos = 0;
    while(currentPos != pos - 1){ //this stops at pos - 1
        previousNode = previousNode -> next;
        currentPos++;
    }
    //Now previousNode points to pos - 1 node
    Node* temp = previousNode -> next;  //node to be deleted
    previousNode -> next = previousNode -> next -> next ; //shifting pointer to the next node which is goig to delete
    free(temp);
    cout << "Deleted From Given Position Successfully..."<<endl;
//Time complecity is O(pos) AND O(n) is wrost case where n is no. of nodes
}

//Reverse linked list
void reverseIt(Node* &head){
    //here we use three pointer approch
    Node* current = head;
    Node* next;
    Node* previous = NULL ;
    while (current!=NULL ){
        next = current -> next;
        current -> next = previous; // Reverse current node's pointer
        //moving all three pointer by one step
        previous = current;
        current = next;
    }
    head = previous;
}

//printing linked list OR Traversal in singly linked list
void display(Node* head){ //Node* head pass by value because we didn't change in our linked list
    Node* temp = head; //we make a new temp pointer for traversal becoz if we use head for traveral then we lost the starting point of our linked list
    while(temp != NULL){ //NULL means tail of linked list
        cout<< temp-> val<<" -> "; //print val of each node
        temp = temp -> next; //move temp pointer to next node
    }
    cout<<"NULL"<<endl;
}

//main
int main(){
  Node* head = NULL; //create a empty liked list
  //MADE BY LAKSHAY 024 AI-DS-B1
  cout<<"========================================================="<<endl;
  cout<<"             Step into Linked List Operations"<<endl;
  cout<<"========================================================="<<endl;
  while (true) {
        cout << "---------------------------------------------------------" << endl;
        cout << "                   Available Operations" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "1. Insert Node at Head" << endl;
        cout << "2. Insert Node at Tail" << endl;
        cout << "3. Insert Node at Arbitrary Position" << endl;
        cout << "4. Update Value of Node at Arbitrary Position" << endl;
        cout << "5. Delete Node at Head" << endl;
        cout << "6. Delete Node at Tail" << endl;
        cout << "7. Delete Node at Arbitrary Position" << endl;
        cout << "8. Reverse Linked List" << endl;
        cout << "9. Display Linked List" << endl;
        cout<<"\n";

        //counting Size of Nodes
        Node* countNode = head;
        int count = 0; // variable to count nodes
        while(countNode != NULL){
                countNode = countNode -> next;
                count++;
        }

        int choice;
        cout << "Enter Your Choice : ";
        cin >> choice;
        //cout<<"\n";

        if (choice == 0) {
            cout << "Goodbye!" << endl;
            break; // break the while loop
        }

        else if (choice == 1) {
            int value;
            cout << "Enter The Data You Want To Add At Head : ";
            cin >> value;
            insertAtHead(head, value);
            cout << "Inserted At Head Successfully..."<<endl;
        }

        else if (choice == 2) {
            int value;
            cout << "Enter The Data You Want To Add At Tail : ";
            cin >> value;
            insertAtTail(head, value);
            cout << "Inserted At Tail Successfully..."<<endl;
        }

        else if (choice == 3) {
            int pos, value;
            cout << "Enter Position to Insert : ";
            cin >> pos;
            if(pos > count || pos < 0 ){
                cout << "\nError: Invalid position. Please enter a valid position within the range [0, " << count << "]." << endl;
            }
            else{
                cout << "Enter The Data You Want To Add : ";
                cin >> value;
                insertAtArbitrary(head, pos, value);
                cout << "Inserted At Given Position Successfully..."<<endl;
            }
        }

        else if (choice == 4) {
            int pos, value;
            cout << "Enter Position to Update : ";
            cin >> pos;

            if(pos > count - 1 || pos < 0 ){
                cout << "\nError: Invalid position. Please enter a valid position within the range [0, " << count - 1 << "]." << endl;
            }
            else{
                cout << "Enter The New Data : ";
                cin >> value;
                updateAtPos(head, pos, value);
                cout << "Updated Successfully..."<<endl;
            }
        }

        else if(choice == 5){
            deleteAtHead(head);
        }

        else if(choice == 6){
            deleteAtTail(head);
        }

        else if(choice == 7){
            int pos;
            cout<<"Enter Position to Delete a Node : ";
            cin>>pos;
            if(pos > count - 1 || pos < 0 ){
                cout << "\nError: Invalid position. Please enter a valid position within the range [0, " << count - 1 << "]." << endl;
            }
            else{
                deleteAtPosition(head, pos);
            }
        }
        else if(choice == 8){
            cout<<"Linked List Reversed Successfully..."<<endl;
            reverseIt(head);
        }
        else if (choice == 9) {
            display(head);
        }

        else {
            cout << "Error: Invalid choice. Please enter a valid option from the menu." << endl;
        }

    }
    return 0;
}
