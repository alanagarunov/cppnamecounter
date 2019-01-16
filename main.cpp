#include "mainheader.h"
 
int main()
{
    map<string, int> inputs;
    vector<pair<int,string>> items;
    string tempstr;
    ifstream path;
    int charcount = 0;
    int x;
    path.open("<path_to_text_file>");  //replace with the path to the file you want
    if(!path)
    {
        cout << "not a path" << "\n";
        exit(1);
    }
    while(getline(path, tempstr))
    {
 
        for(size_t i = 0; i < tempstr.length(); i++)
        {
                charcount++;
        }
        if(charcount >= 50) //we count characters because we want to count actual sentences from the text file
        {
            int pos = tempstr.find(" ");
            string tempstr2 = tempstr.substr(pos);
            pos = tempstr2.find(":");
            string tempstr3 = tempstr2.substr(1,pos);
            inputs[tempstr3]++;
        }
    }
 
        for(map<string, int>::iterator i = inputs.begin(); i != inputs.end(); i++)
        {
            int number = (*i).second;
            string name = (*i).first;
            items.push_back(make_pair(number, name));
            //cout << (*i).first << "\t: " << (*i).second << "\n"; this here will work without the bottom rest of the code
            //but for it to be a bit neater, we sort by value. Uncomment to sort by name.
        }
 
        sort(items.begin(), items.end()); //flips and sorts the map
        for(int j = 0; j < items.size(); j++)
        {
            cout << items[j].first << "\t: " << items[j].second << "\n";
        }
 
 }
