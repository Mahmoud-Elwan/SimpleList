#include "include/list.h"

void List::print_menu(){
    int choice;

    cout << "********************\n";
    cout << "1 - Print list\n";
    cout << "2 - Add to list\n";
    cout << "3 - Delete from list\n";
    cout << "4 - Quit\n";
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
        exit(0);
        break;
    default:
        break;
    }
}

void List::add_item(){
    cout << "\n\n\n\n\n\n\n\n";
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
        for(unsigned int i=0; i<list.size(); i++){
            cout << i+1 << " - " << list[i] << "\n";
        }
    }
    else{
        cout << "The list is empty\n";
    }
    
    cout << "Select an item number to delete: ";
    unsigned int index;
    cin >> index;
    index = index - 1; // Adjust for 0-based indexing
    if(index >=0 && index < list.size()){
        cout << "'" << list[index] << "' has been deleted from the list\n\n\n\n\n";
        list.erase(list.begin() + index);
    }
    else{
        cout << "Invalid index number\n\n\n\n\n";
    }
    cin.clear();

    print_menu();
}

void List::print_list(){
    cout << "\n\n\n\n\n\n\n\n";
    cout << "*** Printing List ***\n";

    for(unsigned int list_index=0; list_index<list.size(); list_index++){
        cout << list_index+1 << " - " << list[list_index] << "\n";
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