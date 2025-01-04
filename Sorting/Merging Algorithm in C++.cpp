#include <iostream>
using namespace std;

void MERGING(int A[], int R, int B[], int S, int C[]) {
    int NA = 0, NB = 0, PTR = 0;
  
    while (NA < R && NB < S) {
        if (A[NA] < B[NB]) {
            C[PTR] = A[NA];
            NA++;
        } else {
            C[PTR] = B[NB];
            NB++;
        }
        PTR++;
    }
    while (NA < R) {
        C[PTR] = A[NA];
        NA++;
        PTR++;
    }
    while (NB < S) {
        C[PTR] = B[NB];
        NB++;
        PTR++;
    }
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int R = sizeof(A) / sizeof(A[0]);
    int S = sizeof(B) / sizeof(B[0]);
    int C[R + S];

    MERGING(A, R, B, S, C);

    cout << "Merged Array: ";
    for (int i = 0; i < R + S; i++) {
        cout << C[i] << " ";
    }

    return 0;
}
