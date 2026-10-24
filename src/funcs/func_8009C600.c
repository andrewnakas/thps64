/* cflags: -O2 */
#include "common.h"

s32 func_8009C600(f32 **a, s32 n) {
    s32 indxc[256];
    s32 indxr[256];
    s32 ipiv[256];
    s32 j, k, l, ll, i, icol, irow;
    f32 big, dum, pivinv, temp, t;

    {
        s32 m;
        for (m = 0; m < n; m++) {
            ipiv[m] = -1;
        }
    }
    i = 0;
    while (1) {
        if (i >= n) break;
        big = 0.0f;
        j = 0;
        while (1) {
            if (j >= n) break;
            if (ipiv[j] != 0) {
                s32 kk = 0;
                while (1) {
                    if (kk >= n) break;
                    if (ipiv[kk] == -1) {
                        t = a[j][kk];
                        if (t < 0.0f) {
                            t = -t;
                        }
                        if (t >= big) {
                            big = t;
                            irow = j;
                            icol = kk;
                        }
                    } else if (ipiv[kk] > 0) {
                        return 0;
                    }
                    kk++;
                }
            }
            j++;
        }
        ++ipiv[icol];
        if (irow != icol) {
            s32 q = 0;
            while (1) {
                if (q >= n) break;
                {
                    f32 x = a[irow][q];
                    a[irow][q] = a[icol][q];
                    a[icol][q] = x;
                }
                q++;
            }
        }
        indxr[i] = irow;
        indxc[i] = icol;
        if (a[icol][icol] == 0.0f) {
            return 0;
        }
        pivinv = 1.0f / a[icol][icol];
        a[icol][icol] = 1.0f;
        {
            s32 q;
            for (q = 0; q < n; q++) {
                a[icol][q] *= pivinv;
            }
        }
        ll = 0;
        while (1) {
            if (ll >= n) break;
            if (ll != icol) {
                dum = a[ll][icol];
                a[ll][icol] = 0.0f;
                {
                    s32 q;
                    for (q = 0; q < n; q++) {
                        a[ll][q] -= a[icol][q] * dum;
                    }
                }
            }
            ll++;
        }
        i++;
    }
    l = n - 1;
    while (1) {
        if (l < 0) break;
        if (indxr[l] != indxc[l]) {
            k = 0;
            while (1) {
                if (k >= n) break;
                temp = a[k][indxr[l]];
                a[k][indxr[l]] = a[k][indxc[l]];
                a[k][indxc[l]] = temp;
                k++;
            }
        }
        l--;
    }
    return 1;
}
