#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstdlib>

using namespace std;

bool isSpecial(char);

int main()
{
    ifstream infile;
    infile.open( "password.txt" );
    
    char ch;
    ch = infile.get();
    int alpha = 0,upper = 0,lower = 0,digit = 0,special = 0,char_count = 0,pass_count = 0,valid = 0,total_valid = 0;

    while(infile)
    {        
        while (!isspace(ch))
        {
            cout << ch;
            
            if (isalpha(ch))
            {
                alpha++;
            }
            if (isupper(ch))
            {
                upper++;
            }
            if (islower(ch))
            {
                lower++;
            }
            if (isdigit(ch))
            {
                digit++;
            }
            if (isSpecial(ch))
            {
                special++;
            }
            char_count++;
            
            ch = infile.get();
        }
        
        pass_count++;
        cout << endl;
    
        if (char_count < 6){
            cout << "Not enough characters\n";
            valid++;
        }
        if (alpha == 0){
            cout << "Missing alphabetic character\n";
            valid++;
        }
        if (upper == 0){
            cout << "Missing uppercase letter\n";
            valid++;
        }
        if (lower == 0){
            cout << "Missing lowercase letter\n";
            valid++;
        }
        if (digit == 0){
            cout << "Missing digit\n";
            valid++;
        }
        if (special == 0){
            cout << "Missing special character\n";
            valid++;
        }
        if (valid == 0){
            cout << "Valid password\n";
            total_valid++;
        }
            
        cout << endl;
        
        alpha = 0,upper = 0,lower = 0,digit = 0,special = 0,char_count = 0,valid = 0;
        
                
        
        cout << ch;
    
        
        infile >> ch;

    }
    	infile.close();
        cout << endl;
        cout << "Total number of passwords: " << pass_count << endl << "Valid: " << total_valid << endl << "Invalid: " << (pass_count - total_valid);
            

    
    return 0;
}

bool isSpecial(char ch){
	if((int)ch == 35 || (int)ch == 36 || (int)ch == 37 || (int)ch == 42){
		return true;
	}
	else{
		return false;
	}
}
