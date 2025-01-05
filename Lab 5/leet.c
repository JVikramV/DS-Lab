int backspaceCompare(char* s, char* t) {
    char s1[100]; 
    char t1[100];
    int i, j;


    i = 0;
    for (int k = 0; s[k] != '\0'; ++k) {
        if (s[k] == '#') {
            if (i > 0) {
                --i;
            }
        } else {
            s1[i++] = s[k];
        }
    }
    s1[i] = '\0';

 
    j = 0;
    for (int k = 0; t[k] != '\0'; ++k) {
        if (t[k] == '#') {
            if (j > 0) {
                --j;
            }
        } else {
            t1[j++] = t[k];
        }
    }
    t1[j] = '\0';

    return strcmp(s1, t1) == 0;
}
