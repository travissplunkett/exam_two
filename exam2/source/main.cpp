//EXAM BEGUN AT 5:20PM 7/15/21
//After a week of two wildfires, constant work,
// and lack of computer access,
// (Recall we had communicated.)
//RESUMED DURING A CAR RIDE ON 7/24/21, 8:30AM to 10AM and 8PM to 9:30PM
//RESUMED AFTER WORK ON SUNDAY 7/25/21 6:00PM

#include "runner.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

//Function Declarations

//Opens input stream (ifstream) File
//Returns ifstream file
//Prints (via cout) a message with success status
//Parameters: string filePath
ifstream openFile(string filePath);

//Reads from file and constructs corresponding runner objects
//Parameters: string file
//Returns void
vector<Runner> loadRunners();

//Discerns which index an item belongs
// in a vector, according to
// comparative operators
template <typename T>
int binarySearch(vector<T>& list, T key, int low, int high);

//Sorts the vector<Type> into ascending order
// using <, >, and ==, operators
// Type must include definitions for those operators
//Parameters: vector<Type> unsorted, vector<Type> holdSorted, int arr_size
template <typename Type>
vector<Type> sortWithBinarySearch(vector<Type> unsorted, vector<Type> holdSorted, int arr_size);

//Writes runners to a file in which
// each runner in the vector is listed
// on a seperate line
template <typename Type>
void writeRunners(vector<Type> vec);

//Writes runners to respective runner categories
//Parameters vector<Type>
//Returns void
template <typename Type>
void writeCategories(vector<Type> vec);

//Creates a summarry file of the data manipulated
template <typename Type>
void summary(vector<Type> vec);

////////////MAIN FUNCTION
int main(){

    //Create and initialize vectors for function parameters
    vector<Runner> unsortedRunnerVector = loadRunners();
    vector<Runner> sortedRunnerVector;
    vector<Runner> sortedVec;
    //Run functions
    sortedVec = sortWithBinarySearch(unsortedRunnerVector, sortedRunnerVector, unsortedRunnerVector.size());
    writeRunners(sortedVec);
    writeCategories(sortedVec);
    summary(sortedVec);

    return 0;
}

//Function implementations (Commented in declaration area)

ifstream openFile(string filePath){
    ifstream file(filePath);//Open reading file
    //Report status
    if (file.fail() == false){
        cout << "File oppened successfully" << endl << endl;
        return file;
    } else {
        cout << "Error oppening file" << endl << endl;
    }
}

vector<Runner> loadRunners(){
//Create a vector that fills up with runner objects
    string file = ".\\registrants.txt";
    ifstream runnerFile = openFile(file);//Open for reading
    string first_name;
    string last_name;
    int pace;
    vector<Runner> runnerVector;

//CORRECT CODE, FOR LOADING ALL RUNNERS
    //Constructs a runner, and adds said runner to the vector,
    // so long as there are runners left to extract from the file
    while ((runnerFile >> first_name)&&(runnerFile >> last_name)&&(runnerFile >> pace)){
        runnerVector.push_back(Runner (first_name,last_name,pace));
    }

    return runnerVector;
}

template <typename T>
int binarySearch(vector<T>& list, T key, int low, int high){
    //Sets mid to midpoint between high and low search limits
    int mid  = (low + high) / 2;
    
    //Either manipulates high/low limits
    // or returns an index
    // according to the logical conditions
    // which would warrant such actions
        if(list[mid] == key){// Base case 1
            return mid;
        } else if (list[mid] > key){
            if(mid != 0){
                high = mid - 1;
            } else {
                high = mid;
            }
        } else if (list[mid] < key) {
            if((low != high)){
                low = mid + 1;
            }
        }
        if ((high == low) && (list[high] < key)) {//Base case 2
            return -1*(high + 1);
        }
        else if ((high == low)) {
            if(high != 0){//Base case 3
                return -1*(high);
            }else{
                return high;//Base case 4
            }
        }
        if((mid==low)&&(low!=high)){
            low = high;
        }
        //If hasn't returned, it must have adjusted high and low limits;
        // search again
        return binarySearch(list, key, low, high);
}

template <typename Type>
vector<Type> sortWithBinarySearch(vector<Type> unsorted, vector<Type> holdSorted, int arr_size){
    holdSorted.push_back(unsorted[0]);//Load first value into vector to be hold sorted values
    int low = 0;
    int high; 
    Type key;
    int holdSrchIndx;
    //Set a search key,
    // use binary search to discern it's theoretical, relative index,
    // insert key at said index,
    // repeat until all keys (all unsorted values) have been sorted
    for (int i = 0; i < (arr_size) - 1; i++){
        high = i;
        key = unsorted[i + 1];
        holdSrchIndx = abs(binarySearch(holdSorted, key, low, high));
        //If key should be at the end, plug it into the end of holdSorted
        if(holdSrchIndx == holdSorted.size()){
            holdSorted.push_back(key);
        } else { //Otherwise, move all elements, which should be
                 // to the right of key, rightward once
            holdSorted.push_back(holdSorted[holdSorted.size()-1]);
            for(int j = holdSorted.size() - 2; j >= holdSrchIndx; j--){
                if(j!=0){
                    holdSorted[j] = holdSorted[j-1];
                }
            }
        //Copy value to sorted spot in holdSorted
        holdSorted[holdSrchIndx] = key;
        }
    }
    //Copy holdSorted to unsorted
    for (int k = 0; k < arr_size; k++){
        unsorted[k] = holdSorted[k];
    }
    return unsorted;
}

template <typename Type>
void writeRunners(vector<Type> vec){
    ofstream file(".\\sortedRunners.txt");//Open for output
    //Output runners
    for(int i=0; i<vec.size(); i++){
        file << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;
    }
}

template <typename Type>
void writeCategories(vector<Type> vec){
//Open files for output
    ofstream filea(".\\white.txt");
    ofstream fileb(".\\yellow.txt");
    ofstream filec(".\\green.txt");
    ofstream filed(".\\orange.txt");
    ofstream filee(".\\blue.txt");
    ofstream filef(".\\lilac.txt");
    ofstream fileg(".\\red.txt");

//Output each runner according to pace to corresponding file
    for(int i=0;i<vec.size();i++){
        if(vec[i].getPace()<361){
            filea << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;   
        } else if(vec[i].getPace()<421){
            fileb << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;    
        } else if(vec[i].getPace()<481){
            filec << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;   
        } else if(vec[i].getPace()<541){
            filed << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;   
        } else if(vec[i].getPace()<601){
            filee << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;   
        } else if(vec[i].getPace()<721){
            filef << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;   
        } else if(vec[i].getPace()<1201){
            fileg << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getPace() << endl;   
        }
    }
    return;
}

template <typename Type>
void summary(vector<Type> vec){
    ofstream summary ("summary.txt");//Open for output
    //Calculate/output total runners
    summary << "Total runners: " << vec.size() << endl;
    //String of file names
    string colorFiles[7] = {"white","yellow","green","orange","blue","lilac","red"};
    string name;
    ifstream open;//Open for reading
    int count;
    int timeAfter9 = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    for(int i=0;i<7;i++){
        //Set hour
        hours = 9+(timeAfter9/3600);
        //Open for reading each of the seven files
        summary << colorFiles[i] << " runners: ";
        name.clear();
        name = ".\\";
        name.append(colorFiles[i] + ".txt");
        open.close();
        open.open(name);
        count = 0;
        //Count how many lines (runners) per file
        while (getline(open,name)){
            count ++;
        }
        //Calculate/output time of leaving
        timeAfter9 += (count + 60);
        summary << count << "| Leaving at 0";
        summary << hours << ":";
        if(minutes < 10){ summary << "0";};
        summary << minutes << ":";
        if(seconds <10){ summary << "0";};
        //Set minutes and seconds for next color to leave
        summary << seconds << endl;
        minutes = (timeAfter9 / 60) % 60;
        seconds = timeAfter9 % 60;
    }   
}