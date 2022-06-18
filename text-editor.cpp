#include <bits/stdc++.h>
#include <stack>
using namespace std;

/**
* DATA STRUCTURES ASSIGNMENT (EVEN-2022)
* Topic: Text editor in C++ using Queue
* Members: 19BEC075(Nakrani Himanshu)
*          19BEC089(Parmar Raj)
*          19BEC088(Parmar Chinmay)
*/


class textEditor
{
    private:
    queue<char> leftQueue; //Left Queue
    queue<char> rightQueue; //Right Queue


    public:
        void insertWord(char word[]);
        void insertCharacter(char character);
        bool deleteCharacter();
        bool backSpaceCharacter();
        void moveCursor(int position);
        void moveLeft(int position);
        void moveRight(int position);
        void findAndReplaceChar(char findWhat, char replaceWith);
//        void display();
        void examineFront();
        void Display_text();
}; //End of class


void textEditor::examineFront()
{
    if(leftQueue.empty())
        cout << "leftQueue: empty\t";
    else
        cout << "leftQueue: " << leftQueue.front() << "," << leftQueue.size() << "\t\t";
    if(rightQueue.empty())
        cout << "rightQueue: empty\n";
    else
        cout << "rightQueue: " << rightQueue.front() << "," << rightQueue.size() << endl;
} //End of function


void textEditor::insertWord(char word[])
{
    int i=0;

    while(word[i]!='\0') 
    {
        insertCharacter(word[i]);
        i++;
    }
} //End of function


void textEditor::insertCharacter(char character)
{
    leftQueue.push(character);
} //End of function


bool textEditor::deleteCharacter()
{    
    if (rightQueue.empty())
        return false;
    else
        rightQueue.pop();
    return true;
}//End of function


bool textEditor::backSpaceCharacter()
{
    if (leftQueue.empty())
        return false;
    else
        leftQueue.pop();
    return true;
}//End of function


void textEditor::moveCursor(int position)
{
    int leftSize, rightSize, count;
    leftSize = leftQueue.size();
    rightSize = rightQueue.size();
    if (position < leftSize)
        moveLeft(position);
    else 
    {
        count = position - leftSize;
        moveRight(count);
    }
}//End of function


void textEditor::Display_text()
{
    while(!rightQueue.empty())
    {
        cout << rightQueue.front() << "";
        rightQueue.pop();
    }
    while(!leftQueue.empty())
    {
        cout << leftQueue.front() << "";
        leftQueue.pop();
    }
    cout << endl;
}

void textEditor::moveLeft(int position)
{
    int leftSize;
    leftSize = leftQueue.size();
    while(position!=leftSize)
    {
        rightQueue.push(leftQueue.front());
        leftQueue.pop();
        leftSize = leftQueue.size();
    }
}//End of function


void textEditor::moveRight(int count)
{
    int rightSize, i=1;
    rightSize = rightQueue.size();
    if (count > rightSize)
        cout << "Cannot move the cursor, right, to the specified position";
    else
    {
        while(i<=count) 
        {
            leftQueue.push(rightQueue.front());
            rightQueue.pop();
            i++;
        } //End of while
    } //End of else
}//End of function


void textEditor::findAndReplaceChar(char findWhat, char replaceWith)
{
    int count=1, originalCursorPoistion = leftQueue.size();
    moveCursor(0); //Move characters from left Queue to right Queue

    //Move characters from right Queue to left Queue and examine
    while(!rightQueue.empty()) 
    {
        if(rightQueue.front()==findWhat) 
        {
            deleteCharacter();
            insertCharacter(replaceWith);
        }
        else
            moveCursor(count);
            count++;
    } //End of while
    moveCursor(originalCursorPoistion); //Retain the original cursor position
} //End of function



int main() 
{
    int i=0, choice=0, temp=0;
    char text[80];
    textEditor txt;

    cout << "Enter data into your file: ";
    cin.getline(text,80);
    txt.insertWord(text);
    txt.examineFront();
    
    do
    {
        cout << "*** --- --- --- --- --- --- --- --- ***";
        cout << "\nChoose a function to run:";
        cout << "\n1. Add lines to file\n2. Move the cursor position";
        cout << "\n3. Delete from the cursor position\n4. Backspace from the cursor position";
        cout << "\n5. Replace a character\n6. Display the text";
        cout << "\n*** --- --- --- --- --- --- --- --- ***\nChoice:"<<endl;
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Insert the data to be added: ";
                cin.ignore();
                cin.getline(text,80);
                txt.insertWord(text);
                txt.examineFront();
                break;
                
            case 2:
                cout << "Move cursor to the position: ";
                cin >> temp;
                txt.moveCursor(temp); 
                txt.examineFront();
                break;
                
            case 3:
                cout << "Number of characters to delete: ";
                cin >> temp;
                for(i=0;i<temp;i++)
                {
                    if(!txt.deleteCharacter())
                        cout << "There is nothing to delete. Move your cursor accordingly to delete the character";
                    else
                        cout << "Delete characters using DEL: ";
                        txt.examineFront();
                }
                break;
                
            case 4:
                cout << "Number of characters to backspace: ";
                cin >> temp;
                for(i=0;i<temp;i++)
                {
                    if(!txt.backSpaceCharacter())
                        cout << "There is nothing to delete. Move your cursor accordingly to delete the character";
                    else
                        cout << "Delete characters using Backspace: ";
                        txt.examineFront();
                }
                break;
            
            case 5:
                char  replace, replaceWith;
                cout<<"Enter the character to replace:";
                cin>>replace;
                cout<<"Enter the character to replace with:";
                cin>>replaceWith;
                txt.findAndReplaceChar(replace, replaceWith);
                cout << "Replace occurrences of"<<replace<<"with"<<replaceWith<<": ";
                txt.examineFront();
                break;
                
            case 6:
                txt.Display_text();
                break;
                
            default:
                cout<<"Invalid choice. Choose a proper option";   
        }
    }while(choice!=0);

    return 0;
} //End of main
