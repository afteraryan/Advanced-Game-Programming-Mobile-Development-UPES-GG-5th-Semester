#include<iostream>
#include<string>
#include<cstring>
#include <conio.h>
#include<windows.h>
#include <algorithm>

const int LetterLimit = 5;

using namespace std;

void textcolor (int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}

string inputUser(string str)
{
    while (1)
    {
        cout<<"Enter String: ";
        std::getline(cin,str);
        if(str.length()==LetterLimit)
            break;
        else
            cout<<"Letter Count = "<<LetterLimit<<"!";
    }
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
    
    return str;
}

bool checkSameWord(string answerStr, string userStr)
{
    return(answerStr==userStr);
}

void MasterChecker(string answerStr, string userStr)
{
    int arrFlag[5]={0,0,0,0,0};
    bool arrIsClue[5] = {false, false, false, false};
    for(int i = 0; i<LetterLimit; i++)
    {
        if(answerStr[i]==userStr[i])
        {
            arrFlag[i]=1; // '1' acts as a Flag
            arrIsClue[i]=true;          
        } 
    }

    //Similar Leters
    for(int i=0; i<LetterLimit; i++)
    {
        if(arrFlag[i]==0)
        {
            for(int j=0; j<LetterLimit; j++)
            {
                if(((userStr[i]==answerStr[j]) && (i!=j)) && !arrIsClue[j])
                {
                    arrFlag[i] = 2;
                    arrIsClue[j] = true;
                    //break;
                }  
            }
        }
            
    }

    //Output

    for(int i=0; i<5; i++)
    {
        if(arrFlag[i]==0)
        {
            textcolor(4);//Red
            cout<<userStr[i];
        }
        else if(arrFlag[i]==2)
        {
            textcolor(6);//Yellow
            cout<<userStr[i];
        }
        else if(arrFlag[i]==1)
        {
            textcolor(10);//Green
            cout<<userStr[i];
        }
    }
    textcolor(7);//White
}

int main()
{
    string userStr, answerStr = "AGREE", outputStr;;
    int triesAvailable=6;  

    while(triesAvailable>0)
    {
        triesAvailable--;
        cout<<"\n\nTry Number: "<<6-triesAvailable<<endl;
        userStr = inputUser(userStr);
        if(checkSameWord(answerStr, userStr))
        {
            cout<<"Right Answer!!";
            break;
        }
        else   
            MasterChecker(answerStr, userStr);
    }


    return 0;
}