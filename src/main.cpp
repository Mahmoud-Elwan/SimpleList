#include "include/list.h"

int main(int arg_count, char *args[]) {

    List simpleList;

    if(arg_count > 1){
        
        simpleList.name = string(args[1]);      //[0] for programm name [1] Username from command line argument
        simpleList.mainList = simpleList.data.read();
        simpleList.find_userList();
        simpleList.print_menu();        
    }
    else{
        cout << "Username is not supplied .. exiting the program" << endl;
    }

    return 0;
}

