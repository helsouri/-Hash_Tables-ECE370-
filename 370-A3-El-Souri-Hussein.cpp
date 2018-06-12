//This Code was written by Hussein EL-Souri

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#define max_num_lines 50
#define max_entries 100
using namespace std;

int getData(char filename[], string str[max_num_lines])
{
    ifstream ins;
    ins.open(filename);
    int i=0;

    while (!ins.eof())
    {
        getline(ins, str[i]);
        i++;
    }
    return (i);
}

void emptyTable(int numLines, string tempTable[max_entries])
{
    int i;
    for(i=0;i<numLines;i++)
    {
        tempTable[i]="";
    }
}

void printData(int numLines, string tempStr[max_num_lines])
{
    int i,tempLength=0;
    for(i=0;i<numLines;i++)
    {

        cout<<tempStr[i]<<" which has "<<tempStr[i].length()<<" letters"<<endl;
    }
}

void hashTable1(int numLines,string hashData[max_entries], string states[max_num_lines])
{
    int i=0,count1,hashKey=0,tempStrLength=0,index=0,count2=0,whiteSpace=0;
    string tempStr;
    for(count1=0;count1<numLines;count1++)
    {
        tempStr=states[count1];
        tempStrLength=tempStr.length()-1;
        hashKey=((int) tempStr[0] + (int) tempStr[tempStrLength] +i)%100;
        if(hashData[hashKey]=="")
        {
            hashData[hashKey]=tempStr;
            cout<<tempStr<<"::"<<i;
            whiteSpace=15-tempStrLength;
            while(whiteSpace>0)
            {
                cout<<" ";
                whiteSpace--;
            }
            count2++;
            if(count2%4==0)
                {
                    cout<<endl;
                }
        }
        else if(hashData[hashKey]!="")
        {
            index=hashKey;
            i=0;
            while(hashData[index]!="")
            {
                index++;
                i++;
                if(index>max_entries-1)
                {
                    index=0;
                }
             }
            hashData[index]=tempStr;
            cout<<tempStr<<"::"<<i;
            whiteSpace=15-tempStrLength;
            while(whiteSpace>0)
            {
                cout<<" ";
                whiteSpace--;
            }
            count2++;
            if(count2%4==0)
                {
                    cout<<endl;
                }
            }
        }
}

void hashTable2(int numLines,string hashData[max_entries], string states[max_num_lines])
{
    int i=0,count1,hashKey=0,tempStrLength=0,index=0,count2=0,whiteSpace=0;
    int result=0;
    string tempStr;
    for(count1=0;count1<numLines;count1++)
    {
        tempStr=states[count1];
        tempStrLength=tempStr.length()-1;
        result=(int) pow(i,2);
        hashKey=((int) tempStr[0] + (int) tempStr[tempStrLength] + result)%100;
        if(hashData[hashKey]=="")
        {
            hashData[hashKey]=tempStr;
            cout<<tempStr<<"::"<<result;
            whiteSpace=15-tempStrLength;
            while(whiteSpace>0)
            {
                cout<<" ";
                whiteSpace--;
            }
            count2++;
            if(count2%4==0)
                {
                    cout<<endl;
                }
        }
        else if(hashData[hashKey]!="")
        {
            index=hashKey;
            i=0;
            while(hashData[index]!="")
            {
                index++;
                i++;
                if(index>max_entries-1)
                {
                    index=0;
                }
             }
            hashData[index]=tempStr;
            cout<<tempStr<<"::"<<result;
            whiteSpace=15-tempStrLength;
            while(whiteSpace>0)
            {
                cout<<" ";
                whiteSpace--;
            }
            count2++;
            if(count2%4==0)
                {
                    cout<<endl;
                }
            }
        }
}

void searchTable(int numLines,string hashData[max_entries], string states[max_num_lines])
{
    int i,j,count1=0,totalSearch=0;
    for(i=0;i<numLines;i++)
    {
        count1=0;j=0;
        for(j=0;j<max_entries;j++)
        {
            if(states[i]!=hashData[j])
            {
                count1++;
            }
            else if(states[i]==hashData[j])
              {
                  cout<<i<<" The number of searches required to find "<<states[i]<<" is: "<<count1<<endl;
                  totalSearch+=count1;
              }
        }
    }
     cout<<endl<<"** The total number of searches is: "<<totalSearch<<" **";
}
//*******************************Temp Functions***********************************

int menu()
{
    int result=0;
    cout<<"_________________________________"<<endl;
    cout<<"Press 1 to display data as is in text"<<endl;
    cout<<"Press 2 to display linear hash"<<endl;
    cout<<"Press 3 to display quadratic hash"<<endl;
    cout<<"Press 4 to display  search of linear hash"<<endl;
    cout<<"Press 5 to display search of quadratic hash"<<endl;
    cout<<"_________________________________"<<endl;
    cout<<"Result: ";
    cin>>result;
    cout<<"_________________________________"<<endl;
    return(result);
}
void showASCII(string states[max_num_lines])
{
    int i;
    int firstCharASCII,lastCharASCII,strLength=0;
    string tempStr;
    for (i=0;i<max_num_lines-1;i++)
    {
        tempStr=states[i];
        strLength=tempStr.length();
        firstCharASCII=tempStr[0];
        lastCharASCII=tempStr[strLength-1];
        cout<<i<<" : "<<tempStr[0]<<":"<<firstCharASCII<<" "<<tempStr[strLength-1]<<":"<<lastCharASCII<<endl;
    }
}


int main()
{
    //THIS code was written bu Hussein El-Souri
    string states[max_num_lines];
    int numLines=0;
    int option=0;
    char answer='y';
    string hashData1[max_entries], hashData2[max_entries];
    numLines=getData("a3.txt",states);
    emptyTable(numLines,hashData1);
    emptyTable(numLines,hashData2);
    cout<<"This is a program to build and search hash tables"<<endl;
    cout<<"Search results will yeild zero if tables not initially built"<<endl;
    cout<<"Would you like to run this program?(Y for yes N for no)";
    cin>>answer;
    while(answer=='y'||answer=='Y')
    {
        option=menu();
        if(option==1)
        {
            printData(numLines,states);
            cout<<endl<<"_________________________________"<<endl;
        }
        if(option==2)
        {
            cout<<"Linear Hash";
            cout<<endl<<"_________________________________"<<endl;
            hashTable1(numLines,hashData1,states);
            cout<<endl<<"_________________________________"<<endl;
        }
        if(option==3)
        {
            cout<<"Quadratic Hash";
            cout<<endl<<"_________________________________"<<endl;
            hashTable2(numLines,hashData2,states);
            cout<<endl<<"_________________________________"<<endl;
        }
        if(option==4)
        {
            cout<<"Search of Linear Hash";
            cout<<endl<<"_________________________________"<<endl;
            searchTable(numLines,hashData1,states);
            cout<<endl<<"_________________________________"<<endl;
        }
        if(option==5)
        {
                cout<<"Search of Quadratic Hash";
                cout<<endl<<"_________________________________"<<endl;
                searchTable(numLines,hashData2,states);
                cout<<endl<<"_________________________________"<<endl;
        }

        cout<<"Do you want to try again?(Y for yes N for no): ";
        cin>>answer;

    }
    if(answer=='n'||answer=='N')
    {
        cout<<endl<<"Have a good day :)"<<endl;
    }
    return 0;
}
