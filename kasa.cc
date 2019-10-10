#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <regex>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <map>

using namespace std;

/**
 * tab to 4 spacje xDDD
 */

const regex reg1("\\d+(\\s(5:5[5-9]|([6-9]|1[0-9]|20):\\d\\d|21:1[0-9]|21:2[0-1])\\s([a-zA-Z]|\\^)([a-zA-Z]|\\s|\\^)*)+");
const regex reg2("[a-zA-Z]([a-zA-Z]|\\s)*\\s([1-9]\\d*|0)\\.\\d\\d\\s[1-9][0-9]*");
const regex reg3("\\?(\\s[a-zA-Z]|\\^)([a-zA-Z]|\\s|\\^)*\\s\\d+)+");

// zaimplementuj te 3 funkcje xdddddddddd
// zwracaja true jesli linijka poprawna, false w przeciwnym
bool checkBusRouteCommand(string command) {
    return regex_match(command, reg1);
}

bool checkNewTicketCommand(string command) {
    return regex_match(command, reg2);
}

bool checkTicketRequestCommand(string command) {
    return regex_match(command, reg3);
}


inline void printErr(int lineId, string line) {
    cerr << "Error in line " << lineId << ": " << line;
}

set <string> names;
map <string, int> timetable;



void getInput() {

    int lineId = 0;
    string line;
     
    while(getline(cin, line)) {
    
        lineId++;
        
        // pusta linijka
        if(line.empty()) {
            continue;
        }
        
        // determinowanie typu komendy za pomoca pierwszego znaku
        if(isdigit(line[0])) {
            if(!checkBusRouteCommand(line)) {
                printErr(lineId, line);
                continue;
            }        
            
        } 
        else if(isalpha(line[0]) || line[0] == '_' || line[0] == '^') {
            if(!checkNewTicketCommand(line)) {
                printErr(lineId, line);
                continue;
            }
            
        }
        else if(line[0] == '?') {
            if(!checkTicketRequestCommand(line)) {
                printErr(lineId, line);
                continue;
            }
            
        }
        else {
            printErr(lineId, line);
            continue;           
        }
    }
}

int main() {

    getInput();    
    return 0;
}
