#include <iostream>
#include <string> 
using namespace std; 

// prototype go here 
int index(char*, char);
int count_digits(char*);
int find_length(char*);


int main() { 
    string haystack; 
    char needle; 

    // Also try different values for the string and character
    haystack = "A quick brown fox (id: 45) jumped over a lazy dog (id: 9)"; 
    needle = 'x'; 

    int loc, count; 
    loc = index(&haystack[0], needle); 
    cout << "Loc: " << loc << endl;

    count = count_digits(&haystack[0]); 
    cout << "Count: " << count << endl;  


    return 0; 
}


// functions go here 

//Index Function
int index(char* haystack_pointer, char given) {
	int haystack_len;
	
	haystack_len = find_length(haystack_pointer);
	
	for(int i=0; i<haystack_len; i++) {
		if(*(haystack_pointer + i) == given)
			return i;
	}

	return -1;
}

// count_digits function
int count_digits(char* haystack_pointer) {
	int count = 0, ascii_val;
	int haystack_len;
	
	haystack_len = find_length(haystack_pointer);
	
	for(int i=0; i<haystack_len; i++) {
		
		ascii_val = int(*(haystack_pointer + i));
		
		if(ascii_val > 47 && ascii_val < 58)
			count++;
	}
	
	return count;
}

// find_length function
int find_length(char* haystack_pointer) {
	int len_count = 0;
	while(*haystack_pointer != '\0') {
		len_count++;
		haystack_pointer++;
	}

	return len_count;
}
