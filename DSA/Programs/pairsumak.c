#include<stdio.h>
void merge(int arr[], int l, int m, int r){
	int n = r - l + 1;
	int temp_arr[n];	
	int i = l, j = m + 1, k = 0;
	while(i <= m && j <= r)
		if(arr[i] < arr[j])
			temp_arr[k++] = arr[i++];
		else 
			temp_arr[k++] = arr[j++];
	while(i <= m)
		temp_arr[k++] = arr[i++];
	while(j <= r)
		temp_arr[k++] = arr[j++];	
	for(int i = 0; i < n; i++)
		arr[l + i] = temp_arr[i];		
}
void mergesort(int arr[], int l, int r){
	if (l < r){
		int m = (l + r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int main(){
	int arr[] = {1, 2, 4, 7, 8}, n = sizeof(arr) / sizeof(arr[0]), l = 0, r = n - 1, found = 0;
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	mergesort(arr, l, r);
	for(int k = 0; k < n; k++)
		while(l <= r)
			if(arr[l] + arr[r] > arr[k])
				r--;
			else if (arr[l] + arr[r] < arr[k])
				l++;
			else{  
				found = 1;
				break;
			}
	if(found)
		printf("We have found a pair whose sum is also in the sequence!\n");
	else  
		printf("We didn't find a pair whose sum is also in the sequence!\n");
	return 0;
}
