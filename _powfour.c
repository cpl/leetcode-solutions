// https://leetcode.com/problems/power-of-four/description/

bool isPowerOfFour(int num) {
    if(num & (num - 1)) return false;
    return num & 0x55555555;
}
