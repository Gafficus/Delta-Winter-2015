// This program reads a file of coded data including a large list of
// records that include a name, a birthdate, and an 8-char password.
// It then performs various operations on the data.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "date.h"
#include "StringTokenizer.h"

struct dataFormat
{
    string firstName;
    string lastName;
    Date theDate;
    string thePassword;
};

const int MAX_LIST_SIZE = 1200;

// Function prototypes
void buildArray(dataFormat dataList[], int& numElems);
dataFormat setFromCoded(string inString);

//-------------------------------------------------------------------------
int main()
{   
    dataFormat dataList[MAX_LIST_SIZE];
    int listSize, i;
   
    // Build list of values
    buildArray(dataList,listSize);
    
    // ----------------------------------------------
    // Perform various transactions to data structure
    // ----------------------------------------------
    
    // Find all first names = "Jennifer"
    for (i=0; i < listSize; i++)        
       if (dataList[i].firstName == "Jennifer")
           cout << dataList[i].firstName << " " << dataList[i].lastName << endl;
    cout << endl << endl;
    
    // Find owner of a specific password
    cout << "Has password: BGLeCuVs" << endl;
    for (i=0; i < listSize; i++)
         if (dataList[i].thePassword == "BGLeCuVs")
            cout << dataList[i].firstName << " " << dataList[i].lastName << endl;
    cout << endl << endl;
    
    // Find all entries with with a specific target date
    cout << "Entries with dates on 2/29/1992" << endl;
    Date targetDate(2,29,1992);
    for (i=0; i < listSize; i++)
        if (dataList[i].theDate.equalTo(targetDate))
            cout << dataList[i].firstName << " " << dataList[i].lastName;
    cout << endl << endl;

   system("pause");
   return 0;
}

//-------------------------------------------------------------------------
// This function builds an array of name/date/password records
void buildArray(dataFormat dataList[], int& numElems)
{
    // Declaration
    string inString;
    int index = 0;
    
    ifstream inFile("randomData.txt");
  
    if (inFile.fail())
    {
        cout << "File not found" << endl << endl;
        exit(-1);
    }

    getline(inFile,inString);                    // Priming read
    while( ! inFile.eof())
    {        
        dataList[index] = setFromCoded(inString);
        getline(inFile,inString);                 // Continuation read
        index++;
    }
    numElems = index;
}


//-------------------------------------------------------------------------
// This function receives a coded string and parses out the components of
// a calendar date along with the first and last name.  It buils a date object
// and returns the object and name components.
dataFormat setFromCoded(string inString)
{
    string outFirstname,outLastname;   // Temporary holding strings
    string outDate,outPass;       
    int tempMonth,tempDay,tempYear;    // Temporary date components
    dataFormat outDataRec;             // Record for return value
   
    // Instantiate string tokenizer object for comma tokens
    StringTokenizer tokenizer(inString,',');

    outFirstname = tokenizer.getStringToken();
    outLastname  = tokenizer.getStringToken();
    outDate      = tokenizer.getStringToken();
    outPass      = tokenizer.getStringToken();
  
    // Further parse out date components form mm/dd/yy.
    // Tokenize to integers.
    StringTokenizer dateTokens(outDate,'/');
    tempMonth = dateTokens.getIntToken();
    tempDay   = dateTokens.getIntToken();
    tempYear  = dateTokens.getIntToken();
    Date workDate(tempMonth,tempDay,tempYear);  // Build date object
   
    // Construct record to return
    outDataRec.firstName   = outFirstname;
    outDataRec.lastName    = outLastname;
    outDataRec.thePassword = outPass;
    outDataRec.theDate     = workDate;
    
    return outDataRec;
}

