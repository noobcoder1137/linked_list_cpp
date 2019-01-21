#include <iostream>

using namespace std;

class Node{
    public :
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList{
    private :
        // pointer which always points to the first node within our linked list
        Node *header;
        // pointer which always points to the end node within our linked list
        Node *tail;
        // keeps tracks of how many nodes are within our list
        int size;

    public :
        // default constructor which initializes our private data members
        LinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
        }
        // deconstructor that does memory cleanup
        // deletes every node within our list when list is out of scope
        ~LinkedList(){
            // pointer which always points to the next node within our list
            Node *next;
            // keep going until header does not equal NULL
            while(header != NULL){
                // advance to pointer to point to next node
                next = header->next;
                // delete node that header is pointing to
                delete header;
                // advance header to point to the next node
                header = next;
            }
        }
        // adds a new node to the end of our list
        void append(int data){
            // newly created node to be inserted
            Node *n = new Node(data);
            // if list is empty set header and tail
            // to both point to n, since n is the only node
            // within our list
            if(header == NULL){
                header = n;
                tail = n;
            }
            // if the list is not empty
            else{
                // make our current last node next pointer
                // point to n
                tail->next = n;
                // update tail to point to our new list node n
                tail = n;
            }
            // increment the size, since we've successfully added a new node
            size++;
        }
        // adds a new node to the beginning of our list
        void prepend(int data){
            // newly created node to be inserted
            Node *n = new Node(data);
            // if list is empty set header and tail
            // to both point to n, since n is the only node
            // within our list
            if(header == NULL){
                header = n;
                tail = n;
            }
            // if list is not empty
            else{
                // temp pointer which saves what header is currently pointing to
                Node *temp = header;
                // update header to point to n, the new node that we want to prepend
                header = n;
                // make our new node n next pointer point, to the previous first node
                n->next = temp;
            }
            // increment the size because we've successfully inserted a new node
            size++;
        }
        // remove the first node from our list
        void removeFirst(){
            // if the list is not empty
            if(header != NULL){
                // create temp pointer to point to current first node
                Node *temp = header;
                // advance header to point to the new first node
                header = header->next;
                // delete previous first node
                delete temp;
                // decrement size since, we've deleted a node
                size--;
            }
        }
        // removes the last node within our list
        void removeLast(){
            // check to see if node only has 1 node within it
            if(header->next == NULL){
                removeFirst();
            }
            // check if more than 1 node
            else if(header != NULL){
               // we need to traverse the list
               // create a temp pointer which points to header, our starting point
               Node *cur = header;
               // keep track of previous pointer from cur
               Node *prev;
               // keep going till we reach the last node
               while(cur->next != NULL){
                // previous pointer points to the current
                prev = cur;
                // advance current to the next node
                cur = cur->next;
               }
               // tail gets updated to the new last node
               tail = prev;
               // remove pointer to the node we are going to delete, set it to null
               // this is important because our toString method is dependent on the next
               // pointer to be NULL in order to know when to stop
               prev->next = NULL;
               // delete the last node
               delete cur;
               // decrement size, since we successfully deleted the a node
               size--;
            }
        }
        // remove a node at a certain position
        void removeAt(int pos){
            // check if the position we want to remove at is invalid or not
            if(pos > size || pos < 1){
                return;
            }
            // check if position is the first node
            else if(pos == 1){
                removeFirst();
            }
            // check if position is the last node
            else if(pos == size){
                removeLast();
            }
            // remove node thats between the first and last node
            else if(header != NULL){
                // We need to traverse the list
                // Make a temp pointer cur point to header, our starting point
                Node *cur = header;
                // while we traverse the list, keep track of previous node from current
                Node *prev;
                // traverse through our list until cur is at the position that we want to remove at from
                for(int i = 1; i < pos; i++){
                    // keep track of previous node before advancing cur
                    prev = cur;
                    // advance to the next node
                    cur = cur->next;
                }
                // make the previous node point to the next node that current has
                prev->next = cur->next;
                // delete node
                delete cur;
                // decrement size since we've successfully deleted a node
                size--;
            }
        }
       // insert a node from a certain position
       void insertAt(int pos, int data){
           // check is valid position to insert at
           if(pos > size + 1 || pos < 1)
             return;
           // check if adding at the end of our list
           else if(pos == size + 1)
             append(data);
           // check if adding to the beginning of our list
           else if(pos == 1)
             prepend(data);
           // check if adding between the beginning and end of our list
           else if(header != NULL){
                // create new node to be inserted
                Node *n = new Node(data);
                // we need to traverse the list, to get to the position where we
                // want to insert our new node

                // make temporary pointer that points to header, our starting point
                Node *cur = header;
                // temporary pointer that will keep track of the previous pointer of header
                Node *pre;
                // traverse the list until current is at the position at which we want to insert at
                for(int i = 1; i < pos;i++){
                    // save what current is currently pointing to
                    pre = cur;
                    // advance to the next node within our list
                    cur = cur->next;
                }
                // make the previous node point to n
                pre->next = n;
                // make n next pointer point to current
                n->next = cur;
                // increment the size since we've successfully added a new node
                size++;
            }
        }
        // returns the size of our list
        int getSize(){
            return size;
        }
        // prints out our list
        void toString(){
            // create temp pointer which points to what header is pointing to,
            // the starting point of our list
            Node *n = header;
            // keep going until
            while(n != NULL){
                // print data out
                cout << n->data  << " ";
                // advance to the next node within our list
                n = n->next;
            }
            cout << endl;
        }


};

int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.toString();
}
