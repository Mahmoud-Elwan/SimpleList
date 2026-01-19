#include <iostream>
#include <vector>
using namespace std;

class List {
    private:
    //Only the class itself can access its private members
    protected:
    //Inherited classes can access protected members
    public:
    //Anything can access public members
        
        List() {
            //Constructor
        }
        ~List() {
            //Destructor
        }
        
        vector <string> list;
        string name;

        void print_menu();
        void print_list();
        void add_item();
        void delete_item();
};