#include <iostream>
#include <cstring>

using namespace std;

// Structure for a node in the linked list
struct Node
{
    string name;
    bool likesVanilla;
    bool likesButterscotch;
    Node *next;
};

// Function to add a student to the linked list
// Takes the head of the list and the name, and booleans indicating whether the student likes vanilla or butterscotch as inputs
void addStudent(Node *&head, string name, bool likesVanilla, bool likesButterscotch)
{
    // Create a new node
    Node *newNode = new Node;
    newNode->name = name;
    newNode->likesVanilla = likesVanilla;
    newNode->likesButterscotch = likesButterscotch;
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

// Function to compute and display the set of students who like either vanilla or butterscotch or both
// Takes the head of the list as input
void studentsWhoLikeEither(Node *head)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // Traverse the list and print the name of each student who likes either vanilla or butterscotch
    Node *current = head;
    cout << "Students who like either vanilla or butterscotch:" << endl;
    while (current != nullptr)
    {
        if (current->likesVanilla || current->likesButterscotch)
        {
            cout << current->name << endl;
        }
        current = current->next;
    }
}

// Function to compute and display the set of students who like both vanilla and butterscotch
// Takes the head of the list as input
void studentsWhoLikeBoth(Node *head)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // Traverse the list and print the name of each student who likes both vanilla and butterscotch
    Node *current = head;
    cout << "Students who like both vanilla and butterscotch:" << endl;
    while (current != nullptr)
    {
        if (current->likesVanilla && current->likesButterscotch)
        {
            cout << current->name << endl;
        }
        current = current->next;
    }
}

// Function to compute and display the set of students who like only vanilla, not butterscotch
// Takes the head of the list as input
void studentsWhoLikeOnlyVanilla(Node *head)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // Traverse the list and print the name of each student who likes only vanilla, not butterscotch
    Node *current = head;
    cout << "Students who like only vanilla, not butterscotch:" << endl;
    while (current != nullptr)
    {
        if (current->likesVanilla && !current->likesButterscotch)
        {
            cout << current->name << endl;
        }
        current = current->next;
    }
}

// Function to compute and display the set of students who like only butterscotch, not vanilla
// Takes the head of the list as input
void studentsWhoLikeOnlyButterscotch(Node *head)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // Traverse the list and print the name of each student who likes only butterscotch, not vanilla
    Node *current = head;
    cout << "Students who like only butterscotch, not vanilla:" << endl;
    while (current != nullptr)
    {
        if (current->likesButterscotch && !current->likesVanilla)
        {
            cout << current->name << endl;
        }
        current = current->next;
    }
}

// Function to compute and display the number of students who like neither vanilla nor butterscotch
// Takes the head of the list as input
void studentsWhoLikeNeither(Node *head)
{
    // If the list is empty, return
    if (head == nullptr)
    {
        return;
    }

    // Traverse the list and count the number of students who like neither vanilla nor butterscotch
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        if (!current->likesVanilla && !current->likesButterscotch)
        {
            count++;
        }
        current = current->next;
    }

    // Print the number of students who like neither vanilla nor butterscotch
    cout << "Number of students who like neither vanilla nor butterscotch: " << count << endl;
}

int main()
{
    // Create the linked lists for the two sets of students
    Node *setA = nullptr;
    Node *setB = nullptr;

    // Add some students to set A
    addStudent(setA, "Alice", true, false);
    addStudent(setA, "Bob", true, true);
    addStudent(setA, "Charlie", false, false);

    // Add some students to set B
    addStudent(setB, "David", false, true);
    addStudent(setB, "Emily", true, true);
    addStudent(setB, "Frank", false, false);

    // Compute and display the set of students who like either vanilla or butterscotch
    studentsWhoLikeEither(setA);

    // Compute and display the set of students who like both vanilla and butterscotch
    studentsWhoLikeBoth(setA);

    // Compute and display the set of students who like only vanilla, not butterscotch
    studentsWhoLikeOnlyVanilla(setA);

    // Compute and display the set of students who like only butterscotch, not vanilla
    studentsWhoLikeOnlyButterscotch(setB);

    // Compute and display the number of students who like neither vanilla nor butterscotch
    studentsWhoLikeNeither(setB);

    return 0;
}
