#include "readfile.h"

ReadFile::ReadFile()
{
    ifstream file("C:\\Users\\evan4\\Documents\\Movie\\input.txt");
    string str;
    int i = 1;

    while (std::getline(file, str)) {
            if (i % 2 == 0)
                evenStack.push(str);
            else
                oddStack.push(str);
            i++;
        }
    qDebug() << evenStack.size();
}

string ReadFile::grabMovie(int seed)
{
    string result;

    if(evenStack.empty() && oddStack.empty())
    {
        result = "no more movies remaining";
    }
    else if(((seed % 2 == 0) && (evenStack.size() > 0)) || oddStack.empty())
    {
        result = changeStack(evenStack);
    }
    else if(((seed % 2 == 1) && (oddStack.size() > 0)) || evenStack.empty())
    {
        result = changeStack(oddStack);
    }
    else
        result = "";

    return result;
}

string ReadFile::changeStack(stack<string> &stack)
{
    Random rand;
    string result;
    int index = rand.getRandom(stack.size());

    for (int i = 0; i < index-1; i++)
    {
        tempStack.push(stack.top());
        stack.pop();
    }

    result = stack.top();
    stack.pop();

    while(!tempStack.empty())
    {
        stack.push(tempStack.top());
        tempStack.pop();
    }

    return result;
}
