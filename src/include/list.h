#include "database.h"

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
        
        Database data;
        vector<vector<string>> mainList;
        vector <string> list;
        string name;
        unsigned int curreentUserIndex;
        bool userFound = false;

        void print_menu();
        void print_list();
        void add_item();
        void delete_item();
        bool find_userList();
        void save_list();
};