#pragma once
#include "header.h"
const int  HASHTABLESIZE = 37;

int HashFunction(string url, int prime);
struct Node {
    Node* next = nullptr;
    int index = -1;
};
struct HashTable
{
    bool check = false;
    string key = "";
    Node* next = nullptr;
    int prev = -1;
};


