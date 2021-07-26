// I affirm that all code given below was written
// solely by me, Travis Plunkett, and that any
// help I recieved adhered to the rules stated for
// this exam.

#include <string>

using namespace std;

class Runner{
    private:
    string firstName;
    string lastName;
    int pace;
    public:
    //Constructors
    Runner();
    Runner(string fn, string ln, int p);
    //Return string firstName
    //No parameters
    string getFirstName() const;
    
    //Return string lastName
    //No parameters
    string getLastName() const;
    //Return int pace
    //No parameters
    int getPace() const;
    //Establishes that > operator compares pace of Runners
    bool operator>(const Runner & otherRunner){
        if (this->getPace() > otherRunner.getPace()){
            return true;
        } else {
            return false;
        }
    }
    //Establishes that > operator compares pace of Runners
    bool operator>(const int & otherRunner){
        if (this->getPace() > otherRunner){
            return true;
        } else {
            return false;
        }
    }
    //Establishes that < operator compares pace of Runners
    bool operator<(const Runner & otherRunner){
        if (this->getPace() < otherRunner.getPace()){
            return true;
        } else {
            return false;
        }
    }
    //Establishes that < operator compares pace of Runners with int
    bool operator<(const int & otherRunner){
        if (this->getPace() < otherRunner){
            return true;
        } else {
            return false;
        }
    }
    //Establishes that = operator returns int pace
    void operator=(const Runner & otherRunner){
        this->firstName = otherRunner.getFirstName();
        this->lastName = otherRunner.getLastName();
        this->pace = otherRunner.getPace();
    }
    //Establishes that == operator returns compares int getPace()
    bool operator==(const Runner & otherRunner){
        if (this->getPace() == otherRunner.getPace()){
            return true;
        } else {
            return false;
        }
    }
    //Compares int getPace() with int
    bool operator==(const int & otherPace){
        if(this->getPace()==otherPace){
            return true;
        } else {
            return false;
        }
    }
    //Establishes that >> returns a string of runner data
    string operator>>(const Runner & otherPace){
        string str;
        str += otherPace.getFirstName();
        str += " ";
        str += otherPace.getLastName();
        str += " ";
        str += otherPace.getPace();
        str += " ";
        return str;
    }
};