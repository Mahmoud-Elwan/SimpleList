#include "include/list.h"

void List::print_menu(){
    int choice;

    cout << "********************\n";
    cout << "Simple List Project\n";
    cout << "1 - Print list\n";
    cout << "2 - Add to list\n";
    cout << "3 - Delete from list\n";
    cout << "4 - Save list\n";
    cout << "5 - Quit\n";
    cout << "Enter your choice and press return: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        print_list();
        break;
    case 2:
        add_item();
        break;
    case 3:
        delete_item();
        break;
    case 4:
        save_list();
        break;
    case 5:
        //exit(0);
        break;
    default:
        break;
    }
}

void List::add_item(){
    cout << "*** Add Item ***\n";
    cout << "Type in an item and press return: ";

    string item;
    cin >> item;
    list.push_back(item);

    cout << "'" << item << "' has been added to the list\n\n\n\n\n";
    cin.clear();

    print_menu();
}

void List::delete_item(){
    cout << "\n\n\n\n\n\n\n\n";
    cout << "*** Delete Item ***\n";

    if(list.size()){
        for(unsigned int i=1; i<list.size(); i++){
            cout << i << " - " << list[i] << "\n";
        }
    }
    else{
        cout << "The list is empty\n";
    }
    
    cout << "Select an item number to delete: ";
    unsigned int choiceNumber;
    cin >> choiceNumber;
    if(choiceNumber >=1 && choiceNumber < list.size()){
        cout << "'" << list[choiceNumber] << "' has been deleted from the list\n\n\n\n\n";
        list.erase(list.begin() + choiceNumber);
    }
    else{
        cout << "Invalid index number\n\n\n\n\n";
    }
    cin.clear();

    print_menu();
}

void List::print_list(){
    cout << "*** Printing List ***\n";

    for(unsigned int list_index=1; list_index<list.size(); list_index++){
        cout << list_index << " - " << list[list_index] << "\n";
    }

    cout << "Press M to return to the menu: ";
    char choice;
    cin >> choice;
    if(choice == 'M' || choice == 'm'){
        print_menu();
    }
    else{
        cout << "Invalid Choice. Quitting..\n";
    }
}

bool List::find_userList(){
    cout << "loading user info...\n";
    userFound = false;
    for(unsigned int user_index=0; user_index<mainList.size(); user_index++){
        cout << "[" <<user_index+1<< "] " << mainList[user_index][0] << "\n";
        if(mainList[user_index][0] == name){
            userFound = true;
            cout << "User found. Loading your list..\n";
            cout << "*** Welcome " << name << " ***\n";
            curreentUserIndex = user_index;
            list = mainList[user_index];
            break;
        }
    }
    if(userFound == false){
            cout << "User not found. Creating a new list for " << name << "\n";
            list.push_back(name);
            curreentUserIndex = mainList.size();
        }
    return userFound;
}

void List::save_list(){
    cout << "Saving the list...\n";
    if(userFound){
        cout << "Updating existing user list...\n";
        mainList[curreentUserIndex] = list;
    }
    else{
        cout << "Adding new user list...\n";
        mainList.push_back(list);
    }
    data.write(mainList);
    cout << "List saved successfully.\n";
}