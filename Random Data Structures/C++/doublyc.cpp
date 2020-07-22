#include<iostream>
#include<cstdlib>
using namespace std;
struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};
