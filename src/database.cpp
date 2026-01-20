#include "include/database.h"

void Database::write(vector<vector<string>> mainList){
    // Implementation for writing to the database
    ofstream db;
    db.open("db/list.sl");

    if(db.is_open()){
        for(unsigned int user_index=0; user_index<mainList.size(); user_index++){
            db << "#" << mainList[user_index][0] << "\n";
            for(unsigned int list_index=1; list_index<mainList[user_index].size(); list_index++){
                db << mainList[user_index][list_index] << "\n";
            }
            db << "%\n";            
        }
    }    
    else{
        cout << "Can not open the file for writing.\n";
    }
    db.close();
}

vector<vector<string>> Database::read(){
    // Implementation for reading from the database
    string line;
    ifstream db;
    vector <string> userList;

    db.open("db/list.sl");
    if(db.is_open()){
        while(getline(db, line, '\n')){
            if(line.front() == '#'){
                cout << "Found a hashtag: " << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if(line.front() == '%'){
                cout << "Found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else{
                cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }   
        }
    }
    else{
        cout << "Can not open the file for reading.\n";
    }
    db.close();
    return mainList;
}
