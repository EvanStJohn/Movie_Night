#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <stack>
#include <QDebug>
#include <fstream>
#include <random.h>
using namespace std;

class ReadFile
{
public:
    ReadFile();
    stack<string> oddStack;
    stack<string> evenStack;
    stack<string> tempStack;
    string grabMovie(int seed);
    string changeStack(stack<string> &stack);
};

#endif // READFILE_H
