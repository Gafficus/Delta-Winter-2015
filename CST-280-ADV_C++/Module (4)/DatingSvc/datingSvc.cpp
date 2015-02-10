// This program performs a best match for a customer of a dating service
// by scanning a dataset of client preferences and matching them against
// the current customer's.  The set intersection with the most elements
// will be used to define the best match.
#include <fstream>
#include <iostream>
using namespace std;

#include "charSet2.h"
#include "StringTokenizer.h"

const int MAX_CUSTOMERS = 300;   // Assume never more than 300 total customers

// Function prototypes
void loadClientPrefs(CharSet& clientPrefs, int& clientID);
void loadCustomerData(CharSet custData[], int custID[],int& numCustomers);

int main()
{
    CharSet clientPrefs;                // Set for current client's preferences
    CharSet customerDB[MAX_CUSTOMERS];  // Array of customer data to match against
    CharSet intersectionSet;            // For testing set intersections - best match
    int     customerID[MAX_CUSTOMERS];  // Array of customer IDs (parallel to set array)
    int totalCustomers = 0;             // Current customers in file
    int clientID;                       // ID of application client
    int bestID, maxMatches;             // For determining best match
    
     // Load data from files
    loadClientPrefs(clientPrefs, clientID);   
    loadCustomerData(customerDB, customerID, totalCustomers);

    // Determine best match
    bestID     = -1;            // To store index of best match in customer arrays
    maxMatches = -1;            // To store max. number of matches (by set intersection)
    for (int i = 0; i < totalCustomers; i++)
    {
        intersectionSet = clientPrefs * customerDB[i]; // Determine set intersection
        if (intersectionSet.numElems() > maxMatches)
        {
            maxMatches = intersectionSet.numElems();   // Capture number of matches
            bestID     = i;                            // Capture index of customer
        }
    }   
     
    // Report results
    cout << "For client:        " << clientID << endl;
    cout << "  with attributes: ";
    clientPrefs.Write();
    cout << endl << endl;
     
    cout << "Best match is:     " << customerID[bestID] << endl;
    cout << "  with attributes: ";
    customerDB[bestID].Write();     
    cout << endl << endl;

    return 0;
}


//----------------------------------------------------------------
// This function current client preferences from file  
// One character set object is returned.
void loadClientPrefs(CharSet& clientPrefs, int& clientID)
{
   char     aPref;
   ifstream clientFile ("prefs.txt");

   if (clientFile.fail() )         // Test for file existence
   {
      cout <<  "Problem opening file";
      exit(-1);
   }
   // Read and capture first line - client ID
   clientFile >> clientID;
   
   // Read and process file
   clientFile >> aPref;
   while( !clientFile.eof())
   {
      clientPrefs.Insert(aPref);    // Insert preference code into set
      clientFile >> aPref;
   }

   clientFile.close();
}


//----------------------------------------------------------------
// This function loads thetotal dataset of all customer preferences 
// An array of character set objects is returned
void loadCustomerData(CharSet custData[], int custID[],int& numCustomers)
{
   ifstream custDataFile("clientDB.txt");
   string prefsString;
   char aPref;
   int i;
 
   if (custDataFile.fail() )         // Test for file existence
   {
      cout <<  "Problem opening file";
      exit(-1);
   }
   
   // Read and process file; tokenize characters in string
   // Insert characters into a chracter set
   i = 0;
   getline(custDataFile,prefsString);                 // Priming read
   while( !custDataFile.eof() && i < MAX_CUSTOMERS)
   {
      StringTokenizer prefsTokenString(prefsString);        
      int numberPrefs = prefsTokenString.numberTokens() - 1; // Number of attributes
                                                             // (1st token = cust DI)
      // Extract first token as ID number                                               
      custID[i] = prefsTokenString.getIntToken();
      
      // Extract and insert all preference codes into character set                                                
      for (int j = 1; j <= numberPrefs; j++)
      {
          aPref = prefsTokenString.getCharToken();
          custData[i].Insert(aPref);     
      }

      i++;
      getline(custDataFile,prefsString);         // Continuation read
   } 
   numCustomers = i;                             // Capture number of customers in file  

   custDataFile.close();
}


