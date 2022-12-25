#include <iostream>
#include <cstring>

using namespace std;

// Structure for a node in the linked list
struct Node
{
    int prn;
    string name;
    Node *next;
};

// Function to add a member to the linked list
// Takes the head of the list and the PRN and name of the member as inputs
void addMember(Node *&head, int prn, string name)
{
    // Create a new node
    Node *newNode = new Node;
    newNode->prn = prn;
    newNode->name = name;
    newNode->next = nullptr;

    // If the list is empty, set the new node as the head
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Traverse the list to find the last node
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Add the new node to the end of the list
    current->next = newNode;
}

// Function to delete a member from the linked list
// Takes the head of the list and the PRN of the member as inputs
void deleteMember(Node *&head, int prn)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // If the head of the list is the member to be deleted, delete it
    if (head->prn == prn)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse the list to find the member to be deleted
    Node *current = head;
    while (current->next != nullptr && current->next->prn != prn)
    {
        current = current->next;
    }

    // If the member was not found, return
    if (current->next == nullptr)
    {
        return;
    }

    // Delete the member and update the links
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Function to compute the total number of members in the linked list
// Takes the head of the list as input
int totalMembers(Node *head)
{
    // If the list is empty, return 0
    if (head == nullptr)
    {
        return 0;
    }

    // Traverse the list and count the number of nodes
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

// Function to display the members of the linked list
// Takes the head of the list as input
void displayMembers(Node *head)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // Traverse the list and print the PRN and name of each member
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->prn << " " << current->name << endl;
        current = current->next;
    }
}

// Function to display the list in reverse order using recursion
// Takes the head of the list as input
void displayReverse(Node *head)
{
    // If the list is empty or the end of the list has been reached, return
    if (head == nullptr)
    {
        return;
    }

    // Recursively call the function on the next node
    displayReverse(head->next);

    // Print the PRN and name of the current node
    cout << head->prn << " " << head->name << endl;
}

// Function to concatenate two linked lists
// Takes the heads of the two lists as inputs
void concatenateLists(Node *&head1, Node *&head2)
{
    // If the first list is empty, set the second list as the head of the concatenated list
    if (head1 == nullptr)
    {
        head1 = head2;
        return;
    }

    // Traverse the first list to find the last node
    Node *current = head1;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Concatenate the second list to the end of the first list
    current->next = head2;
}

int main()
{
    // Create the linked lists for the two divisions
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    // Add some members to the first division
    addMember(head1, 1, "Alice");
    addMember(head1, 2, "Bob");
    addMember(head1, 3, "Charlie");

    // Add some members to the second division
    addMember(head2, 4, "David");
    addMember(head2, 5, "Emily");
    addMember(head2, 6, "Frank");

    // Concatenate the two lists
    concatenateLists(head1, head2);

    // Display the total number of members in the concatenated list
    cout << "Total number of members: " << totalMembers(head1) << endl;

    // Display the members of the concatenated list
    cout << "Members:" << endl;
    displayMembers(head1);

    // Display the list in reverse order
    cout << "Members in reverse order:" << endl;
    displayReverse(head1);

    return 0;
}
