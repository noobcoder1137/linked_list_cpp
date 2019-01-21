#include <iostream>

using namespace std;

class Node{
    public:
        // Pointer thats points to the previous node
        Node *prev;
        // Pointer that points to the next node
        Node *next;
        int data;

        Node(int data){
            this->data = data;
            prev = NULL;
            next = NULL;
        }
};

class DoublyLinkedList{
    private:
        // header is responsible to keep track of first Node within our list
        Node *header;
        // tail is responsible to keep track of last Node within out list
        Node *tail;
        // size is responsible to keep track of number of Nodes within our list
        int size;

    public:
        DoublyLinkedList(){
            // initialize our data members
            header = NULL;
            tail = NULL;
            size = 0;
        }
        // returns the size of our list
        int getSize(){
            return size;
        }

        void append(int data){
            // Create New Node To be Inserted
            Node *n = new Node(data);
            // Check if Linked List is Empty
            if(header == NULL){
                // Since N is the only Node within the list
                // Make header pointer which points to the first node
                // And Make Tail pointer which points to the last node
                // Both Point to N
                header = n;
                tail = n;
            }
            // List has more than 1 Node
            else{
                // Make the current last node point to the node we want to append to the list
                tail->next = n;
                // Make our newly appended node point to the previous last node
                n->prev = tail;
                // Make Tail point to the newly appended Node, Because N is the new last Node
                tail = n;
            }
            // increment size because we've successfully appended a new Node to our list
            size++;
        }

        // Prepends a node to the beginning of the list
        void prepend(int data){
            // Create Node that we want to prepend to the list
            Node *n = new Node(data);
            // if the list is empty
            if(header == NULL){
                // Since N is the only Node within the list
                // Make header pointer which points to the first node
                // And Make Tail pointer which points to the last node
                // Both Point to N
                header = n;
                tail = n;
            }
            else{
                // Make first Node within our list point to the node that we want to prepend to the list
                header->prev = n;
                // Make the Node that we want to prepend point to the previous first node within the list
                n->next = header;
                // Update header pointer to point to the newly prepended Node n, Since n is the new first node
                header = n;
            }
            // increment size because we've successfully prepended a new Node to our list
            size++;
        }
        // prints out list from start to finish
        void toString(){
            // Have a temporary pointer get what header is pointing to
            // Header is our starting point since header always points to the first
            // Node within our list
            Node *n = header;
            // Loop used to iterate through our list
            // Once n == Null it means we've reached the end of the list
            // Keep going until n does not equal null
            while(n != NULL){
                //Print w/e data is at current node that n is point to
                cout << n->data  << " ";
                //Advance to next node
                n = n->next;
            }
            cout << endl;
        }
        // prints out list in reverse. From End to the beginning
        void toStringReverse(){
            // Have a temporary pointer point to tail
            // Since tail always points to the last node
            Node *n = tail;
            // Loop used to iterate through our list
            // Once n == Null it means we've reached the end of the list
            // Keep going until n does not equal null
            while(n != NULL){
                //Print w/e data is at the current node that n is pointing to
                cout << n-> data << " ";
                //Advance to the next node
                n = n->prev;
            }
            cout << endl;
        }




        // removes the first Node within our list
        void removeFirst(){
            // check if list only has 1 node within it
            if(header->next == NULL){
                // Since there is only 1 node, we can safely assume that header is pointing to it
                // Delete what header is pointing to.
                delete header;
                // reset our header and tail pointers
                // since there are no nodes within it
                header = NULL;
                tail = NULL;
                // decrement size since we've successfully removed the first node
                size--;
            }
            // if there is more than 1 node within our list
            else if(header != NULL){
                // Advance our header pointer to the next node
                // This will become our new first node
                header = header->next;
                // Delete the previous last Node, which is the previous
                // first node within out list
                delete header->prev;
                // Set our current first node previous pointer to NULL
                // This is important because we are dependent on this
                // for when we call our toStringReverse method
                header->prev = NULL;
            }
        }
        // removes the last node within our list
        void removeLast(){
            // check if list only has 1 node within it
            if(header->next == NULL){
                // Since there is only 1 node, we can safely assume that header is pointing to it
                // Delete what header is pointing to.
                delete header;
                // reset our header and tail pointers
                // since there are no nodes within it
                header = NULL;
                tail = NULL;
                // decrement size since we've successfully removed the first node
                size--;
            }
            // if there is more than 1 node within our list
            else if(header != NULL){
                // advance tail to point to the node before the current last node
                // this node will become our new last node
                tail = tail->prev;
                // delete the next node which is the previous last node
                // that we want to remove from our list
                delete tail->next;
                // set our new last nodes next pointer to NULL
                // This is important because we are dependent on this
                // for when we call our toString method
                tail->next = NULL;
                // decrement size since we've successfully removed the last node
                size--;
            }
        }
        // insert node at certain position
        void insertAt(int pos, int data){
            // check if position is within bounds
            // starting position is 1 so if pos is less than 1 its invalid
            // Max pos we can do is size + 1, anything higher than that would
            // require the use of creating dummy empty nodes which would be wasteful
            if(pos < 1 || pos > size + 1)
                return;
            // if pos is 1 call our prepend method
            // this makes sure that header is pointing to what its supposed to
            else if(pos == 1)
                prepend(data);
            // if pos is size + 1 we can easily add this node by calling our append method
            // this makes sure that tail is pointing to what its supposed to
            else if(pos == size + 1)
                append(data);
            // checks to see if pos is inbetween 1 and size + 1
            else if(header != NULL){
                // create new node to be inserted
                Node *n = new Node(data);
                // temporary pointer that points to the first node
                Node *cur = header;
                // iterate through list to get to pos that we want
                // to insert our newly created node n
                for(int i = 1; i < pos; i++){
                    cur = cur->next;
                }
                // make previous node from current position point to n,
                // the node we wish to insert
                cur->prev->next = n;
                // make n previous pointer point to current previous pointer
                n->prev = cur->prev;
                // make n point to current
                n->next = cur;
                // have current previous pointer point to n
                cur->prev = n;
                // increment the size because we've successfully inserted a node
                size++;
            }
        }

        void removeAt(int pos){
            // check if position is within bounds
            // starting position is 1 so if pos is less than 1 its invalid
            // Max pos we can do is size + 1, anything higher than that would
            // require the use of creating dummy empty nodes which would be wasteful
            if(pos < 1 || pos > size)
                return;
            // check if first node, if so call the removeFirst method
            else if(pos == 1)
                removeFirst();
            // check if last node, if so call the removeLast method
            else if(pos == size)
                removeLast();
            // check if position is between the 1st and last node
            else if(header != NULL){
                // create temp pointer to point to header
                Node *cur = header;
                // traverse the list until we reach the position we wish to remove at
                for(int i = 1; i < pos; i++){
                    cur = cur->next;
                }
                // since cur is the node we want to delete
                // we need to make the previous node from cur point to
                // the next node in line from cur
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                // delete node that we wanted to remove at certain position
                delete cur;
                // decrement the size, since we removed a node
                size--;
            }
        }

};

int main(){
    DoublyLinkedList list;
    list.prepend(13);
    list.prepend(15);
    list.prepend(13);
    list.removeAt(2);
    list.toString();
}
