//My first solution used 3 loops, but it's not a good answer
bool isAnagram(char* s, char* t) {

    if( s == NULL || t == NULL ){
        return false;
    }
    int s_length = strlen(s);
    int t_length = strlen(t);
    if(s_length <= 0 || t_length <= 0){
        return false;
    }

    for(int i = 0; i < s_length; i++){
        char temp = s[i];
        int temp_count_1 = 0;
        int temp_count_2 = 0;
        for(int k = 0; k < s_length; k++){
            char temp_k = s[k];
            if(temp == temp_k){
                temp_count_1++;
            }
            
        }         

        for(int j = 0; j < t_length; j++){
            char temp_j = t[j];
            if(temp == temp_j){
                temp_count_2++;
            }
            
        }
        if(temp_count_1 != temp_count_2){
            return false;
        }
    }
    return true;
}

// A wise answer learning from internet

#define CHAR_COUNT 256
bool isAnagram(char* s, char* t) {

    if (strlen(s) != strlen(t)) {
        return false;
    }
    // Create an array to count the frequency of characters
    int count[CHAR_COUNT] = {0};

    // Traverse both strings and count the frequencies of characters
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
        count[t[i]]--;
    }

    // Check if all counts are zero, meaning both strings have the same character frequencies
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;    
}    

