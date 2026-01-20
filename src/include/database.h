#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Database {
    private:
    //Only the class itself can access its private members
    protected:
    //Inherited classes can access protected members
    public:
    //Anything can access public members
        
        Database() {
            //Constructor
        }
        ~Database() {
            //Destructor
        }
        
        vector<vector<string>> mainList;
        string name;

        void write(vector<vector<string>> mainList);
        vector<vector<string>> read();
};