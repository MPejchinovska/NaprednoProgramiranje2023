#include <iostream>
#include <string>
using namespace std;

void merge(int *, int, int, int);
void merge_sort(int *, int, int);

int main() {
    string input = "Marijana Pejchinovska INKI1003";
    int n = input.length();

    int myarray[n];
    for (int i = 0; i < n; i++) {
        myarray[i] = (int)input[i];
    }

    merge_sort(myarray, 0, n-1);

    cout << "Sorted ASCII code array: ";
    for (int i = 0; i < n; i++) {
        cout << myarray[i] << " ";
    }

    return 0;
}

void merge_sort(int *arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, high, mid);
    }
}

void merge(int *arr, int low, int high, int mid) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }

    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
    cout<<"Marijana Pejchinovska";
}
// Koristi rekurziven toest algoritam koj moze da se povika samiot sebe za da go postigni rezultatot sto sakame da go dobieme.
// Se razlozva ili deli pogolem problem na pomali delovi koi izgledaat identicno na prventsveniot.
// Razlozenite delcinja gi resavame rekurzivno i gi spojuvame zaednicki resenija za da go resime pocetniot problem ili zadaca koja ni e zadadena.
//Marijana Pejchinovska
