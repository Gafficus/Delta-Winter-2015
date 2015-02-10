// Sunrise/Sunset module 
// 
// Author:  T. Klingler 
//-------------------------------------------------------------- 

// Misc constants (as needed) 
//const double pi = 3.1415962536; 

//-------------------------------------------------------------- 
// Time zone data type: 
//    E Eastern time zone 
//    C Central time zone 
//    M Mountain time zone 
//    P Pacific time zone 
//    U Universal (Greenwich Mean) time 

//-------------------------------------------------------------- 

// Texttime data type (time returned as string) 
typedef char TextTime[8]; 

//--------------------------------------------------------------// 
// This function receives a date and geographical coordinates   // 
// returns the sunrise and sunset for that day and location     // 
// Input:                                                       // 
//        latitude:   Latitude of site (pos. float in degrees)  // 
//        longitude:  Longitude of site (pos. float in degrees) // 
//        mon:        Month (integer 1..12)                     // 
//        day:        Day of month (1..31)                      // 
//        year:       Year (4-digit integer 19xx or 20xx)       // 
//        timeZone:   Code for time zone                        // 
//        DST         bool indicating if daylight savings time  // 
//                    is active.                                // 
//    Output:                                                   // 
//        sun_rise    Sunrise value (string)                    // 
//        sun_set     Sunset value (string)                     // 
//    Preconditions:                                            // 
//        * Date is valid; year is four-digit                   // 
//        * Latitude and longitude is 0.0 .. 90.0 degrees       // 
//        * Time zone codes must be 'E', 'C', 'M', or 'P' only) // 
//    Postconditions:                                           // 
//        * Date and geog. coords. unchanged                    // 
//                                                              // 
//  Algorithm extracted from a BASIC program in Weatherwise     // 
//  Magazine.  It was converted to Pascal in 1995 and then to   // 
//  this C++ version.                                           // 

void Sun_Rise_Set(  double latitude, double longitute, 
                    int mon, int day, int year, 
                    char timeZone, bool DST, 
                    TextTime sun_rise, TextTime sun_set); 

