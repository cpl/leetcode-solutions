// https://leetcode.com/problems/reverse-bits/description/

uint32_t reverseBits(uint32_t n) {
    n = n >> 16 | n << 16;
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

/*
        bswap   edi
        mov     edx, edi
        sal     edi, 4
        shr     edx, 4
        and     edi, -252645136
        and     edx, 252645135
        or      edi, edx
        mov     edx, edi
        sal     edi, 2
        shr     edx, 2
        and     edi, -858993460
        and     edx, 858993459
        or      edx, edi
        mov     eax, edx
        add     edx, edx
        shr     eax
        and     edx, -1431655766
        and     eax, 1431655765
        or      eax, edx
        ret
*/
