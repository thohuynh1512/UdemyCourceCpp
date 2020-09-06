/*
this challenge is about using a collection (list) of integers and allowing the user
to select options from a menu to perform operations on the list

Your program should display a menu options to the user as follows:

P - Print numbers
A - Add a number
M - Display mean of the numbers
S - Display the smallest number
L - Display the largest number
Q - Quit

Enter you choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed
If an illegal is made, you should display "Unknown selection, please try again" and the menu options should be 
displayed again

if the user enters "P" or 'p', you should display all of the elements (ints) in the list
if the list is empty, you should display "[] - the list is empty"
if the list is not empty then all the list element should be displayed inside square brackets separated by a space
for example { 1 2 3 4 5}

if the user enter 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
you should display "5 added"
Duplicate list enters are OK

if the user enter "M" or 'm' -> calculate the mean or average of the elements in the list and display it.
if the list is empty you should play "Unable to calculate the mean - no data"

if the user enter 'S' -> display the smallest element in the list
For example, if the list contains [2 4 5 1] -> display "The smallest number is 1"
if the list is empty, display "Unable to determine the smallest number - list is empty"

if the user enter 'L' -> display the largest element in the list
For example, if the list contains [2 4 5 1] -> display "The largest number is 5"
if the list is empty, display "Unable to determine the largest number - list is empty"

if the user enter 'q' -> display "Goodbye" and the program should be terminate

Before you begin, write out the steps you need to take and decide in what order they should be done
Think about what loops you should use as well as what you will use for your selection logic
 * 
 * 
Additional functionality if you wish to extend this program
- search for a number in the list and if found display the number of times it occurs in the list
- cleaning out the list (make it empty again) (hint: the vector class has a clear() method)
- don't allow duplicate entries
- come up with your own ideas
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    char selection;
    vector<int> list {1,2,1,3,1,4,2,3};

    while(true){
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "F - Display the number of times a specific number occurs in the list" << endl;
        cout << "C - Cleaning out the list" << endl;
        cout << "D - Don't allow duplicate entries" << endl;
        cout << "R - Remove duplicated entries" << endl;
        cout << "Q - Quit" << endl;

        cout << "\nEnter your choice: ";
        cin >> selection;


        if (selection == 'A' || selection == 'a'){
            //prompt the user for an integer to add to the list then display it was added
            int numberToAdd;
            cout << "\nEnter an integer to add to the list: ";
            cin >> numberToAdd;
            list.push_back(numberToAdd);
            cout << numberToAdd << " added" << endl;
        }
        else if (selection == 'P' || selection == 'p'){
            if (list.empty()){
                cout << "\n[] - the list is empty" << endl;
            }
            else{
                //all the list elements are displayed inside square brackets separated by a space
                cout << "{ ";
                for (auto  element : list){
                    cout << element << " ";
                }
                cout << "}";
            }
        }
        else if (selection == 'M' || selection == 'm') {
            if (list.empty() == true) {
                cout << "\nUnable to calculate the mean - no data" << endl;
            }
            else{
                //calculate the mean or average of the elements in the list and display it
                double sum{0};
                for (auto  element : list){
                    sum += element;
                }
                cout << "\nthe mean is " << sum/list.size() << endl;
            }
        }
        else if (selection == 'S' || selection == 's') {
            if (list.empty() == true) {
                cout << "\nUnable to determine the smallest number - list is empty" << endl;
            }
            else{
                //display the smallest element in the list
                int min{list[0]};
                for (auto  element : list){
                    if (element < min){
                        min = element;
                    }
                }
                cout << "\nthe smallest number is " << min << endl;
            }
        }
        else if (selection == 'L' || selection == 'l') {
            if (list.empty() == true) {
                cout << "\nUnable to determine the largest number - list is empty" << endl;
            }
            else{
                //display the largest element in the list
                int max{list[0]};
                for (auto  element : list){
                    if (element > max){
                        max = element;
                    }
                }
                cout << "\nthe largest number is " << max << endl;
            }
        }
        //search for a number in the list and if found display the number of times it occurs in the list
        else if (selection == 'F' || selection == 'f'){
            if (list.empty() == true){
                cout << "\nUnable to determine the found number - list is empty" << endl;
            }
            else{
                int numberToFind;
                int count{0};
                cout << "\nEnter your number which you need to find: ";
                cin >> numberToFind;
                for (auto element : list){
                    if (numberToFind == element){
                        count++;
                    }
                }
                if (count != 0)
                {
                    cout << "number " << numberToFind << " occurs " << count << "times in the list " << endl;
                }
                else{
                    cout << "Your number, you need to find, is not existed in list" << endl;
                }
            }
        }
        //cleaning out the list
        else if (selection == 'C' || selection == 'c'){
            list.clear();
            cout << "\nlist is cleaned out" << endl;
        }
        //do not allow duplicated entries
        else if (selection == 'D' || selection == 'd'){
            int n;
            int element;
            while(true){
                bool is_Duplicated{false};

                cout << "\nenter an un-duplicated number: ";

                cin >> n;
                // [1,2,3,4....m], m = 1.000.000, input n = 1 => duyet qua 1 trieu phan tu ?
                for (auto i : list){
                    if (n == i){
                        is_Duplicated = true;
                        break;
                    }
                }

                if (is_Duplicated){
                    cout << "\nYour entered number is duplicated, please enter number again" << endl;
                }
                else{
                    list.push_back(n);
                    cout << n << " added" << endl;
                    break;
                }
            }
        }
        //R - Remove duplicated entries
        else if (selection == 'R' || selection == 'r'){
            set <int> s;

            for (auto n : list){
                s.insert(n);
            }
            list.assign(s.begin(), s.end());
        }
        else if (selection == 'Q' || selection == 'q'){
            cout << "Goodbye";
            break;
        }
        else{
            cout << "\nUnknown selection, please try again" << endl;
        }
    }


}