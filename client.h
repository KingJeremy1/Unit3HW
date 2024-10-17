#ifndef Client_h
#define Client_h 

#include <string> // to use strings in this code
                  // i.e.: client's name and ssn 

using namespace std;

// the client structure
struct Client{
    string client_Name;         //this will store the client's name
    string ssn;                 // for the SSN ofc
    double bank_account_number; // for bank acct num
    double balance;             // for the balance on the account
};

// the class for bank
class Bank{
    private:
    int num_clients;    // the num of clients
    Client* clients;    // creating a dynamic array of clients

public:
// our constructor
Bank(string file_name):
    num_clients(0), clients(nullptr) 
    {
        load_clients_info(file_name); // this is gonna load client's info from a file during construction
    }

// our destructor
~Bank(){
    delete [] clients;
    clients = nullptr;
}                // this is 2 delete whatever is hanging around that's no longer needed 
                        // to avoid any memory leaks


// the deep copy constructor, this is gonna be used to help make sure that each object 
// has its own seperate copy of the data
Bank(const Bank& other);


// now we have our public methods
//p.s. "file_name" is a placeholder for our actual final file name (.txt file)

void load_clients_info (string file_name);              //load client info from a file 
Client* get_clients_info();                             //will give you access to the array of clients from bank class
double deposit(double account_number, double amount);   //our function to deposit

string withdraw(double account_number, double amount);  //our function to withdraw
//it's a string because we want to return a message once the process is complete or not

void saving_info(string file_name);                     // save clients info to file
void find_client(double account_number);                // find and return a client's info
void add_new_client(const Client& new_client);          // to add a new client

};
#endif 
