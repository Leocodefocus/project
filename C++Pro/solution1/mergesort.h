#ifndef MERGESORT_H
#define MERGESORT_H
int get_random(int m,int n);
int get_sequence(int S[],int k,int m,int n);
void Merge(int S[],int low,int mid,int high);
void Merge_Sort(int S[],int low,int high);
void mergesort(int S[],int k);
int minimum(int S[],int k);
int maximum(int S[],int k);
double average(int S[],int k);
#endif
