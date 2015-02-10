#include <iostream> 
#include <string> 
#include <cmath> 
using namespace std; 

#include "sun.h"  
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// Function prototype 
void sunriseset (double, double, int, int, int, int&, int&); 
void adjusttime (int, char, bool, TextTime); 
char DigitChar(int); 

void sunriseset (double lat, double lon, int mo, int da, int yr, 
                int& RI, int& SE) 
{ 
    double FC,TN,X,Y,T,T9,S,A,Z,YD,WD,pi; 
    double MA,A0,A1,ML,L0,L1,C,N,E,EO,W; 
    double DL,TL,OB,DE,RA,S0,H,ZT; 
//    double Q,TA,RV,JD; 
    int sw,sw1; 
    void f1(void); 
    pi = 3.141592654; 
    FC = 2 * pi;OB=0.409095; 
    L0=4.88376619;L1=0.017202791; 
    A0=6.23471229;A1=0.01720197; 
    E =0.016728; 
    EO=0.00218; 

    TN = (lon/FC) + 0.5; 
    X = 1; Y = 1; 
    sw = 0;goto f1; 
    f1_1: 
    T9 = T; 
    X = da; Y = mo; 
    sw = 1;goto f1; 
    f1_2: 
    YD=T-T9+1; 
    X=floor(T+1)/7;Y=floor(X); 
    WD=floor(7*(X-Y)+0.5); 
    T=T+3449.5+TN; 
    X=YD-WD; 
    goto f2; 
    f2_1:// Q=ML-RA; 
    X=-0.0143; 
    goto f4; 
    f4_1: 
    if (fabs(Y)>=1) 
    { 
        RI = -9999; 
        SE = -9999; 
    } 
    S0=Z;H=-S0; 
    sw1=0;goto f5; 
    f5_1: 
    X=ZT+EO; 
    sw1=0;goto f6; 
    f6_1: 
    RI=int(X*100+Y); 
    H=S0; 
    sw1=1;goto f5; 
    f5_2: 
    X=ZT+EO; 
    sw1=1;goto f6; 
    f6_2:SE=int(X*100+Y); 
    goto f_end; 

    // Subroutine f1 (810) 
    f1:T = 367*(yr-1980); 
    T=T-floor(7*(yr+floor((Y+9)/12))/4); 
    if ((Y-9) > 0) S= 1;if((Y-9) < 0) S=-1; if ((Y-9) == 0) S= 0; 
    A=fabs(Y-9); 
    Z=floor((yr+S*floor(A/7))/100); 
    T=T-floor(3*(Z+1)/4); 
    T=T+floor(275*Y/9)+X - 0.5; 
    // JD=T+2447689; 
    if (sw == 0) goto f1_1; 
    if (sw == 1) goto f1_2; 

    // Subroutine f2 (900) 
    f2:MA=A0+A1*T; 
    ML=L0+L1*T; 
    X=sin(ML);Y=cos(ML); 
    sw = 0;goto f3; 
    f3_1: 
    ML=Z; 
    DL=2*E*sin(MA)+1.25*(E*E)*sin(2*MA); 
    // TA=MA+DL; 
    TL=ML+DL; 
    // RV=(1-(E*E))/(1+E*cos(TA)); 
    X=sin(TL)*sin(OB);Y=sqrt(1-(X*X)); 
    sw=1; 
    goto f3; 
    f3_2: 
    DE=Z;if (Z>pi) Z=-FC; 
    X=sin(TL)*cos(OB);Y=cos(TL); 
    sw=2; 
    goto f3; 
    f3_3: 
    RA=Z; 
    goto f2_1; 

    // Subroutine f3 (570) 
    f3:C=0;N=0; 
    if (Y != 0.0) 
        Z=X/Y; 
    else 
    { 
        Z=0;C=1; 
        if (X<0) N=1; 
    } 
    Z=atan(Z); 
    if (C==1) Z=pi/2-Z; 
    if (N==1) Z=-1*Z; 
    if (Y<0) Z=Z+pi; 
    if (Z<0) Z=Z+2*pi; 
    if (sw==0) goto f3_1; 
    if (sw==1) goto f3_2; 
    if (sw==2) goto f3_3; 
    if (sw==3) goto f3_4; 
    if (sw==4) goto f3_5; 

    // Subroutine f4 (770) 
    f4:Y=(X-sin(lat)*sin(DE))/(cos(lat)*cos(DE)); 
    if (fabs(Y)<=1) 
    { 
        X=sqrt(1-(Y*Y)); 
        sw = 3; 
        goto f3; 
        f3_4:sw=3; 
    } 
        goto f4_1; 

    // Subroutine f5 (710) 
    f5:ZT=H+RA+lon-ML-pi; 
    X=sin(ZT);Y=cos(ZT); 
    sw=4;goto f3; 
    f3_5:ZT=Z; 
    if (sw1 == 0) goto f5_1; 
    if (sw1 == 1) goto f5_2; 

    //Subroutine f6 (740) 
    f6:W=X*24/FC;X=floor(W); 
    Z=(W-X)*60;Y=floor(Z); 
    Z=floor((Z-Y)*60); 
    if (sw1 == 0) goto f6_1; 
    if (sw1 == 1) goto f6_2; 

    f_end:Z=1; 
} 

char DigitChar (int inDig) 
{ 
    char dig = inDig + 48; 
    return dig; 
} 

void adjusttime (int time, char tzone, bool DST, TextTime timeout) 
{ 
    char addchar[2]; 
    char suffix[3]; 
    TextTime tempTime; 
    strcpy(suffix,""); 
    int i,j; 
    int adjust = 0;        // Assume UTC - no adjustment 
    switch (tzone) 
    { 
        case 'E':   if (DST) 
                        adjust = 400;  
                    else 
                        adjust = 500;  
                    break; 
        case 'C':   if (DST) 
                        adjust = 500;  
                    else 
                        adjust = 600;  
                    break; 
        case 'M':   if (DST) 
                        adjust = 600;  
                    else 
                        adjust = 700;  
                    break; 
        case 'P':   if (DST) 
                        adjust = 700;  
                    else 
                        adjust = 800;  
    }; 

    time = time - adjust; 
    if (time < 0) 
        time +=2400; 
    if (tzone == 'U') 
        strcpy(suffix,"Z"); 
    else 
    { 
        if (time > 1200) 
            strcpy(suffix,"pm"); 
        else 
            strcpy(suffix,"am"); 
        time %= 1200; 
        if (time < 100) 
            time += 1200; 
    } 
    strcpy(tempTime,""); 
    strcpy(addchar," "); 
    if (time > 1000) 
    { 
        addchar[0] = DigitChar(time / 1000); 
        strcpy(tempTime,addchar); 
    } 
    else if (tzone == 'U') 
        strcpy(tempTime,"0"); 
    addchar[0] = DigitChar((time % 1000) / 100); 
    strcat(tempTime,addchar); 
    addchar[0] = DigitChar((time % 100) / 10); 
    strcat(tempTime,addchar); 
    addchar[0] = DigitChar(time % 10); 
    strcat(tempTime,addchar); 
    strcat(tempTime,suffix); 

    if (tzone != 'U')  
    { 
        if (time > 1000) 
            i = 2; 
        else 
            i = 1; 
        j = strlen(tempTime); 
        while (j >= i) 
        { 
            tempTime[j+1] = tempTime[j]; 
            j--; 
        } 
        tempTime[i] = ':'; 
    }     
    strcpy(timeout,tempTime); 
} 


void Sun_Rise_Set(  double latitude, double longitude, 
                    int mon, int day, int year, 
                    char timeZone, bool DST, 
                    TextTime sun_rise, TextTime sun_set) 
{ 
    int rise,set; 

    // Convert to radians 
    latitude = latitude * 3.14 / 180; 
    longitude = longitude * 3.14 / 180; 
    sunriseset(latitude,longitude,mon,day,year,rise,set); 
     
    adjusttime(rise, timeZone, DST, sun_rise); 
    adjusttime(set,  timeZone, DST, sun_set ); 
} 

