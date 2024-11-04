#include "CitySaves.h"

CitySaves::~CitySaves(){
    for(auto& pair : save){
        delete pair.second;
    }
    save.clear();
}

void CitySaves::addSave(string name, CityMemento* m){
    if(save.find(name) != save.end()){
        cout << "Save with name "<< name  <<" already exists" << endl;
        return;
    }
    save[name] = m;
}

void CitySaves::removeSave(string name){
     size_t numErased = save.erase(name);

    if (numErased > 0) {
        cout << "Save '" << name << "' has been removed." << endl;
    } else {
        cout << "Save '" << name << "' not found." << endl;
    }
}

CityMemento* CitySaves::getSave(string name){
    auto it = save.find(name);
    if(it != save.end()){
        return it->second;
    }
    return nullptr;
}

string CitySaves::toString(){
    string out = "Saves: \n";
    for(const auto& pair : save){
        int index = 1;
        string name = pair.first;
        out += "" + to_string(index) + " " + name + "\n";
        index++;
    }

    return out;
}
