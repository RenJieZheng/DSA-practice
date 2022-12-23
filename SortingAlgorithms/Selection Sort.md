```c++
void selectionSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			swap(&arr[min_idx], &arr[i]);
		}
	}
}

//Swap function
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
```