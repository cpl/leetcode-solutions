// https://leetcode.com/problems/validate-ip-address/description/


#include <stdio.h>
#include <ctype.h>


char* IPv4 = "IPv4";
char* IPv6 = "IPv6";
char* None = "Neither";


char* validIPv4(char* IP) {
    int cnt = 0; printf("ipv4\n");
    while(*IP) {
        printf("enter: %c\n", *IP);
        
        if(!isdigit(*IP) || (*IP == '0' && IP[1] != '.')){
            return None;
        }

        int val = 0; cnt++; int scnt = 0;

        while(isdigit(*IP)) {
            scnt++;
            val = val*10 + (int)(*IP++%'0');
        }

        if(scnt > 3) {
            return None;
        }        

        if(*IP != '.' || val > 255)
            return (*IP || cnt != 3) ? None : IPv4;

        IP++;
    }

    return None;
}


char* validIPv6(char* IP) {
    int cnt = 0;
    while(*IP) {  
        int val = 0; cnt++; int scnt = 0;

        printf("enter: %c\n", *IP);        

        if(*IP == ':') {
            return None;
        }
      
        
        while(isxdigit(*IP)) {
            scnt++;
            val = val*10;
            val += (*IP >= '0' && *IP <= '9') ? *IP%'0' : tolower(*IP)%'a'+10;
            IP++;
        }
        
        if(scnt > 4) {
            return None;
        }

        if(*IP != ':' || val > 65535) {
            printf("%d %d %c\n", cnt, val, *IP);
            return (cnt != 7 || *IP != 0) ? None : IPv6;
        }

        IP++;
    }

    return None;
}


char* validIPAddress(char* IP) {
    IPv4 = "IPv4";
    IPv6 = "IPv6";
    
    if(*IP == '0')
        return None;

    int val = 0; int scnt = 0;
    while(isxdigit(*IP)) {
        if(!isdigit(*IP))
            IPv4 = IPv6;
        scnt++;
        val = val*10 + (*IP >= '0' && *IP <= '9') ? *IP%'0' : tolower(*IP)%'a'+10; IP++;
    }

    if(*IP == '.' && val <= 255 && IPv6 != IPv4 && scnt < 4)
        return validIPv4(++IP);
    else
    if (*IP == ':' && val <= 65535 && scnt < 5)
        return validIPv6(++IP);

    return None;
}
