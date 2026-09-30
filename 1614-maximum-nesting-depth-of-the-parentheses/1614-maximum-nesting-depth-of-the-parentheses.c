int maxDepth(char* s) {
    int depth = 0;
    int maxdepth = 0;
    for (int i = 0; i < strlen(s); i++){
        if(s[i]=='('){
            depth++;
        }else if(s[i]==')'){
            depth--;
        }
        if(depth > maxdepth) maxdepth = depth; 
    }
    return maxdepth;
}