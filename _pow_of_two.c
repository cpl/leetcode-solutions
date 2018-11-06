bool isPowerOfTwo(int n) {
    if(n == 1)
        return true;
    if(n <= 0)
        return false;

    return(n & n-1) == 0;
}
