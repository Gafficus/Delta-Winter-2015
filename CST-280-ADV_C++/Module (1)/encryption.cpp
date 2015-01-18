// This program encrypts and decrypts text using a substitution key 
// Key is provided in file:  "key.txt" 

#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

// Function prototypes 
void getKey(char realText[], char codeText[]); 
void menuAction(char realText[], char codeText[]); 
void encrypt(char message[], char outMessage[],  
             char realText[], char codeText[]); 
void decrypt(char codeMessage[], char outMessage[], 
             char realText[], char codeText[]); 

int main() 
{ 
   char realChar[27]; 
   char codedChar[27]; 
        
   // Build list from file 
   getKey(realChar, codedChar);   
                
   // Menu to prompt for user action   
   menuAction(realChar, codedChar);   

   return 0; 
} 

//*********************************************************** 
// This function reads a file containing the substitution 
// encryption key 
//*********************************************************** 
void getKey(char realText[], char codeText[]) 
{ 
   ifstream InFile ("key.txt"); 

    if (InFile.fail() )             // Test for file existence 
    { 
      cout <<  "Problem opening file"; 
      exit(-1); 
    } 
     
   // Get alphabet string 
   InFile.getline(realText,27); 
    
   // Get substitution key string 
   InFile.getline(codeText,27); 
} 

//*********************************************************** 
// This function prompts the user for an encryption or 
// decryption action and calls the appropriate function 
//*********************************************************** 
void menuAction(char realText[], char codeText[]) 
{ 
   int action;                    // For user action choice 
   char inMessage[101];           // For input message 
   char outMessage[101];          // For output message 

   // Write menu to console 
   cout << "1 to encrypt a clear text message" << endl; 
   cout << "2 to decrypt a coded message" << endl; 
   cout << "Enter action: "; 
     
   cin >> action;                // Get user action 
   cin.ignore(100,'\n');         // Clear input buffer 

   cout << "Enter message: ";    // Prompt for message 
   cin.getline(inMessage,101);   // Get message 

   // Convert message to all caps 
   for (int i = 0; i < strlen(inMessage); i++) 
       inMessage[i] = toupper(inMessage[i]); 
    
   cout << endl << endl; 

   // Determine action and write output 
   switch (action) 
   { 
      case (1):   // Encrypt message and write 
                  encrypt(inMessage,outMessage,realText,codeText); 
                  cout << inMessage << endl; 
                  cout << " ... encoded to ... " << endl; 
                  cout << outMessage << endl << endl; 
                  break; 
      case (2):   // Decrypt message and write 
                  decrypt(inMessage,outMessage,realText,codeText); 
                  cout << inMessage << endl; 
                  cout << " ... decoded to ... " << endl; 
                  cout << outMessage << endl << endl; 
                  break; 
      default:    cout << "Invalid choice - program terminated" << endl;  
   }; 
} 

//*********************************************************** 
// This function encrypts a message written in clear text 
// It uses the substitution key provided 
// Parameters: 
//     message      Incoming clear text message 
//     outMessage   Outgoing encrypted message 
//     realText     Array with alphabet 
//     codeText     Array with substitution code key 
//*********************************************************** 
void encrypt(char message[], char outMessage[],  
             char realText[], char codeText[]) 
{ 
    // Initialize output message to input message 
    strcpy(outMessage,message);        
     
    // Traverse string one character at a time.  Then, scan the 
    // alphabet array to match the character.  Substitude with 
    // the coded character parallel to it. 
    for (int charPtr = 0; charPtr < strlen(message); charPtr++) 
       for (int i = 0; i < 26; i++) 
          if (message[charPtr] == realText[i]) 
              outMessage[charPtr] = codeText[i]; 
} 

//*********************************************************** 
// This function decrypts a coded message and returns the  
// clear text equivalent. It uses the substitution key provided 
// Parameters: 
//     codeMessage  Incoming coded text message 
//     outMessage   Outgoing clear text message 
//     realText     Array with alphabet 
//     codeText     Array with substitution code key 
//*********************************************************** 
void decrypt(char codeMessage[], char outMessage[],  
             char realText[], char codeText[]) 
{ 
    // Initialize output message to input message 
    strcpy(outMessage,codeMessage);        
     
    // Traverse string one character at a time.  Then, scan the 
    // coded key array to match the character.  Substitude with 
    // the character parallel to it in the alphabet array 
    for (int charPtr = 0; charPtr < strlen(codeMessage); charPtr++) 
       for (int i = 0; i < 26; i++) 
          if (codeMessage[charPtr] == codeText[i]) 
              outMessage[charPtr] = realText[i]; 
} 

