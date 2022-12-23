```c++
void insertionSort(int arr[], int len) {
	int curr, j;
	for (int i = 1; i < len; i++) {
		curr = arr[i];
	    j = i;
		while(j > 0 && arr[j - 1] > curr) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = curr;
	}
}
```