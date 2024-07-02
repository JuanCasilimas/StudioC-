#include <iostream>

using namespace std;

class ListElement{
public:
    int data;
    ListElement* next; //pointer to first node of the list

    //constructor to initialize the node
    ListElement(int d) : data(d), next(nullptr){}
};

class List{
private:
    ListElement* head;

public:
    //constructor to initialize an empty list
    List() : head(nullptr){}

    //constructor to add an element at the beginning of the list (prepend)
    void prepend(int data){
        ListElement* newelement = new ListElement(data);
        newelement->next = head;
        head = newelement;

    }

    //print elements of the list
    void printlist() const{
        ListElement* h = head;
        while (h != nullptr){
            cout << h->data << ", ";
            h = h->next;
        }
        cout << "###" << endl;
    }

    //destructor to free memory allocate
    ~List(){
        while (head != nullptr){
            ListElement* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(){
    List mylist;

    //add elements
    mylist.prepend(3);
    mylist.prepend(2);
    mylist.prepend(1);

    //print list
    mylist.printlist();

    return 0;
}