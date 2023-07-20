#include<iostream>

using namespace std;

struct Vector{
    int size;
    int capacity;
    int* array;
};
void vecInit(Vector & vec,int initCapacity = 16){
    vec.size = 0;
    vec.capacity = initCapacity;
    vec.array = new int[initCapacity];
}
int  vecGetSize(Vector & vec){
    return vec.size;
}
void vecExpand(Vector & vec, int newCapacity){
    if(newCapacity <= vec.size) return;
    int* newArray = new int[newCapacity];
    for (int i = 0 ; i< vec.size ; i++){
        newArray[i] = vec.array[i]; 
    }
    delete[] vec.array;
    vec.array = newArray;
    vec.capacity = newCapacity;
}
void vecPushBack(Vector & vec, int num){
    if(vec.size == vec.capacity){
        vecExpand(vec, vec.capacity*2);

    }
    vec.array[vec.size] = num;
    vec.size++;
}
int main() {
    int n;
    int A[];
    Vector vec;
    vecInit(vec);
    cout<<"Nhap so phan tu: ";
    cin>>n;
    for(int i = 0 ; i< n ; i++){
        cout<<"Phan tu thu "<<i<<" : ";cin>>A[i];
    }

    vecPushBack(vec, 1);
    vecPushBack(vec, 4);
    for( int i = 0 ; i < vec.size; i++){
        cout<<vec.array[i];
    }

}
