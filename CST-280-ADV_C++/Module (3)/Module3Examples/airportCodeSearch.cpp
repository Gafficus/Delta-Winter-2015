//***************************************************************
// This program allows a user to search a file of three character
// airport codes to return the city name.  Airports in the U.S. and
// Canada only will be used.
// Information is entered via two files:
//   File 1: World airport codes and city names
//   File 2: North American airport codes and latitude/longitude
//           locations
// The files are merged to create an array of airport records that
// the user can search for airport name and location.
//***************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// GLOBAL DECLARATIONS
const int MAX_ARRAY = 4000;          // Max number of airport list entries

typedef char CodeType[4];            // Data type for 3-char airport code
typedef char CityInfoType[100];      // Data type for city information
typedef char LargeStringType[200];   // Data type for a large general character string

struct Airport                       // To store info for one airport
{
   CodeType     code;
   CityInfoType cityInfo;
   double       latitude;
   double       longitude;
};

// FUNCTION PROTOTYPES
void getBaseAirportData(ifstream& nameFile, ifstream& locFile,
                        Airport airData[], int& numVals);
int searchCode(CodeType airArray[], int numelems, CodeType value);
int searchAirCode(Airport airportData[], int numelems, CodeType value);
void writeSummary(Airport airData);

int main()
{
    // DECLARATIONs
    ifstream nameFileIn, locFileIn;   // Input file identifiers        
    Airport airportData[MAX_ARRAY];   // Array for all airport info
    int numElems;                     // Number of values in array 
    int index;                        // Search outcome
    char continueAnswer;              // For continuation prompt                                                                
    CodeType targetAirCode;           // Airport code (key) of desired city                    

    // MANAGE FILES
    nameFileIn.open("AirportCodes.txt");    // Open basic airport file    
    if (nameFileIn.fail() )                 // Test for file existence
    {
      cout <<  "Problem opening airport name file";
      exit(-1);
    }
    
    locFileIn.open("wxStations.txt");      // Open airport location file 
    if (locFileIn.fail() )                 // Test for file existence
    {
      cout <<  "Problem opening airport location file";
      exit(-1);
    }
   
    // BUILD ARRAY OF RECORDS
    getBaseAirportData(nameFileIn,locFileIn,airportData,numElems);

    // CLOSE FILES
    nameFileIn.close();    
    locFileIn.close();    

    // USER INTERACTION
    do
    {
       // Prompt user for desired airport code
       cout << "Enter your target airport: "; 
       cin.getline(targetAirCode,4);
   
       // Search for airport in data 
       index = searchAirCode(airportData, numElems, targetAirCode);
    
       // Write summary report, or notify user airport not found
       if (index >= 0)
          writeSummary(airportData[index]);
       else
          cout << endl << "Airport code not found" << endl << endl;
          
       // Continuation prompt (then clear input buffer)
       cout << "Do you wish to continue (y or n)?" << endl;
       cin >> continueAnswer; 
       cin.ignore(4,'\n');   
       cout << endl;
    }      
    while (continueAnswer == 'y' || continueAnswer == 'Y');
    
    cout << "Thank you" << endl << endl;
   
    return 0;                
}

//***************************************************************
// This function reads and consolidates information from two text
// data files.  The "nameFile" includes airport codes and city
// descriptions and must be parsed using string operations.  The
// "locFile" includes airport codes and geographical coordinates.
//***************************************************************
void getBaseAirportData(ifstream& nameFile, ifstream& locFile,
                        Airport airData[], int& numVals)
{
   LargeStringType aLine;    // One line of airport info data
   CodeType code;
   int numLocationRecs;      // Number of records in location file
   int i, num, index, length;

   // Parallel arrays to store airport code and location info
   // Will be matched to other file as it is read in
   CodeType airCode[MAX_ARRAY];
   double latitude[MAX_ARRAY];
   double longitude[MAX_ARRAY];

   // Build parallel arrays of airport code and location info
   i = 0;
   locFile >> airCode[i] >> latitude[i] >> longitude[i];          
   while ( ! locFile.eof() )        
   {
      i++;        
      locFile >> airCode[i] >> latitude[i] >> longitude[i];          
   }            
   numLocationRecs = i;
 
   // Begin building array of airport info records by reading lines
   // containing airport code and city name.  Parse out components
   // from string data in file.
   num = 0;
   nameFile.getline(aLine,201);          
   while ( ! nameFile.eof() )        
   {
       // Extract substring for airport ID (positions 0..2)
      for (i = 0; i < 3; i++)
        code[i] = aLine[i];
      code[3] = '\0';             // Add null terminator

      // Match codes to acquire airport city name in other list
      // Search for index in name list.
      index = searchCode(airCode, numLocationRecs, code);
 
      // If in list 
      if (index >= 0)
      {
         // Capture airport ID and location
         strcpy(airData[num].code,airCode[index]);         
         airData[num].latitude  = latitude[index];
         airData[num].longitude = longitude[index];
         
         // Get remaining airport city description information
         length = strlen(aLine);
         int p = 0;                       // To build new string
         for (i = 9; i < length; i++)
         {
            airData[num].cityInfo[p] = aLine[i];
            p++;
         }
         airData[num].cityInfo[p] = '\0';

         num++;                          // Increment for next record
      }
   
      nameFile.getline(aLine,201);       // Read next line in file     
   }          
     
   numVals = num;                        // Keep size of file
}

//***************************************************************
// This function performs a binary search on an ordered list of
// airport codes to match and return the index of the target.
//***************************************************************
int searchCode(CodeType airArray[], int numelems, CodeType value)
{
    int first = 0,                 // First array element
        last = numelems - 1,       // Last array element
        middle,                    // Mid point of search
        position = -1;             // Position of search value
    bool found = false;            // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;                 // Calculate mid point
        if (strcmp(airArray[middle],value) == 0)     // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (strcmp(airArray[middle],value) > 0) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;                      // If value is in upper half
    }
    return position;
}

//***************************************************************
// This function performs a binary search on an ordered list of
// airport codes to match and return the index of the target.
//***************************************************************
int searchAirCode(Airport airportData[], int numelems, CodeType value)
{
    int first = 0,                 // First array element
        last = numelems - 1,       // Last array element
        middle,                    // Mid point of search
        position = -1;             // Position of search value
    bool found = false;            // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;                          // Calculate mid point
        if (strcmp(airportData[middle].code,value) == 0)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (strcmp(airportData[middle].code,value) > 0)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;                              // If value is in upper half
    }
    return position;
}

//***************************************************************
// This function summarizes the information for one airport based
// on the index in the array.
//***************************************************************
void writeSummary(Airport airData)
{
    cout << "Airport ID Code: " << airData.code << endl;
    cout << airData.cityInfo << endl;
    cout << "Latitude: " << fixed << setw(3) << airData.latitude;
    cout << "    Longitude: " << fixed << setw(3) << airData.longitude;
    cout << endl << endl; 
}