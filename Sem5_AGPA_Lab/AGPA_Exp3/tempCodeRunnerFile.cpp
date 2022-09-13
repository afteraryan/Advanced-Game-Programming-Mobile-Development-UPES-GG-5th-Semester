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
        cout<<"\nEnter String: ";
        std::getline(cin,str);
        if(str.length()==LetterLimit)
            break;
        else
            cout<<"Letter Count = "<<LetterLimit<<"!";
    }
    //std::transform(str.begin(), str.end(),str.begin(), ::toupper);
    
    return str;
}

void output(string str)
{
    cout<<str;
}

bool checkSameWord(string answerStr, string userStr)
{
    return(answerStr==userStr);
}

int *  CheckSameLetters(string answerStr, string userStr, int arrFlag[])
{
    for(int i = 0; i<LetterLimit; i++)
    {
        if(answerStr[i]==userStr[i])
        {
            arrFlag[i]=1;           // '1' acts as a Flag
        } 
    }
    return arrFlag;
}

int * CheckSimilar(string answerStr, string userStr, int arrFlag[])
{
    //cout<<endl<<userStr<<endl;
    for(int i=0; i<LetterLimit; i++)
    {
        for(int j=0; j<LetterLimit; j++)
        {
            if(((answerStr[i]==userStr[j]) && (i==j)) && arrFlag[i]!=1 && arrFlag[i]!=1)
            {
                //outputStr[j]=answerStr[j];
                arrFlag[j] = 2;
            }  
        }
    }
    return arrFlag;
}

void MasterChecker(string answerStr, string userStr)
{
    int arrFlag[5]={0,0,0,0,0};
    //arrFlag = CheckSameLetters(answerStr, userStr, arrFlag);
    //arrFlag = CheckSimilar(answerStr, userStr, arrFlag);

    //Same Letters
    for(int i = 0; i<LetterLimit; i++)
    {
        if(answerStr[i]==userStr[i])
        {
            arrFlag[i]=1;           // '1' acts as a Flag
        } 
    }

    //Similar Leters
    for(int i=0; i<LetterLimit; i++)
    {
        for(int j=0; j<LetterLimit; j++)
        {
            if(((answerStr[i]==userStr[j]) && (i!=j)) && (arrFlag[i]==0))
            {
                //outputStr[j]=answerStr[j];
                arrFlag[i] = 2;
            }  
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<arrFlag[i];
    }
    cout<<endl;
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

// void CheckSimilar(string answerStr, string userStr)
// {
//     string outputStr = "xxxxx";
//     int arrColor[5]={0,0,0,0,0};
//     cout<<endl<<userStr<<endl;
//     for(int i=0; i<LetterLimit; i++)
//     {
//         for(int j=0; j<LetterLimit; j++)
//         {
//             if(((answerStr[i]==userStr[j]) && (i==j)) && userStr[i]!='1')
//             {
//                 outputStr[j]=answerStr[j];
//                 arrColor[j] = 1;
//             }  
//             else if((answerStr[i]==userStr[j]) && (i!=j) && (outputStr[j]=='x'))
//             {
//                 outputStr[j]='#';
//                 arrColor[j]=2;
//             }

//         }
//     }
//     outputFunc(userStr, arrColor);
// }


int main()
{
    string userStr, answerStr = "AGREE", outputStr;;
    int triesAvailable=6;  

    while(triesAvailable>0)
    {
        triesAvailable--;
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