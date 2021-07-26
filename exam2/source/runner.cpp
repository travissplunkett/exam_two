#include <string>
#ifndef RUNNER_H
# define RUNNER_H
#include "runner.h"

using namespace std;

//Constructors
Runner::Runner(){
    firstName = "NA";
    lastName = "NA";
    pace = 1200;
}
Runner::Runner(string fn, string ln, int p){
    firstName = fn;
    lastName = ln;
    pace = p;
}
//Return string firstName
//No parameters
string Runner::getFirstName() const{
    return firstName;
}

//Return string lastName
//No parameters
string Runner::getLastName() const{
    return lastName;
}
//Return int pace
//No parameters
int Runner::getPace() const{
    return pace;
}

#endif