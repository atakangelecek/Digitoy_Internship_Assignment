#include <iostream>
#include <vector>

using namespace std;

class Table{
    // Table class 
    private:
        int bet_value;
        bool fast, one_to_one, return_match;
    public:
        Table(){}
        // Parametrized constructor that takes parameters and assigns members to them.
        Table(int bet, bool fast, bool one_to_one, bool revenge){
            this->bet_value = bet;
            this->fast = fast;
            this->one_to_one = one_to_one;
            this->return_match = revenge;
        }
        // getter functions to reach private members.
        int get_bet_value(){
            return bet_value;
        }
        bool get_fast(){
            return fast;
        }
        bool get_one_to_one(){
            return one_to_one;
        }
        bool get_return_match(){
            return return_match;
        }
};


void filter(vector <Table> list){
    int bet_value;
    string s1, s2, s3;
    bool fast, onetoone, revenge;
    
    // Taking bet value from user.
    cout<< "Bahis: ";
    cin>> bet_value;

    // If bet value is not in desired range then taking input again. 
    while(((200 <= bet_value) && (bet_value <= 5000) )== false){
        cout<< "Bir daha deneyin..."<<endl;
        cout << "Bahis: ";
        cin >> bet_value;
    }
    
    // Taking necessary inputs from user.
    cout<< "Hizli: ";
    cin >> s1;

    cout<< "Teke Tek: ";
    cin >> s2;

    cout<< "Rovans: ";
    cin >> s3;

    // Assigning our boolean values according to user's input.
    fast = (s1 == "Evet") ? true : false; 
    onetoone = (s2 == "Evet") ? true : false;
    revenge = (s3 == "Evet") ? true : false;

    // Finding tables that matches with the inputs entered by the user.
    int num = 1;
    for(int i=0; i<list.size(); i++){
        if(list[i].get_bet_value() == bet_value && list[i].get_fast() == fast && list[i].get_one_to_one() == onetoone && list[i].get_return_match() == revenge){
            cout<< "Table: " << list[i].get_bet_value() << " " << list[i].get_fast() << " " << list[i].get_one_to_one() << " " << list[i].get_return_match() << endl;
        num++;
        }
    }
    // Output format ->  Table: Bahis Hızlı(1 for true, 0 for false) Teke Tek(1 for true, 0 for false) Rövanş(1 for true, 0 for false)
}

int main(){
    
    // list that will hold table variables.
    vector<Table> list;

    // Creating table variables and pushing them to our list.
    for(int i= 0; i<5200; i+=500){
        for(int j=0; j<2; j++){
            bool first;
            if(j == 0){
                first = true;
            }
            else{
                first = false;
            }
            
            for(int k=0; k<2; k++){
                bool second;
                if(k == 0){
                    second = true;
                }
                else{
                    second = false;
                }
                
                for(int m=0; m<2; m++){
                    bool third;
                    if(m == 0){
                        third = true;
                    }
                    else{
                        third = false;
                    }
                    Table table(i, first, second, third);
                    list.push_back(table);
                }

            }
            
        }
    
    }
    // Call to filter function that will give the desired output.
    filter(list);
}



