#ifndef Sort_h
#define Sort_h

/** @brief swap the value（call by add.）
 * @param x pointer to x
 * @param y pointer to y
 *
 * @return Void.
 */
void swap(int *x, int *y);

/** @brief Insert the current value into the previously sorted array
 *         time complexity: best：O(N), worst：O(N^2)
 *
 * @param arr pointer to arr
 * @param len arr's length
 *
 * @return Void.
 */
void insertionSort(int arr[], int len);

/** @brief For the current position, select the minimum value placement of the subsequent array
 *         time complexity: best：O(N^2), worst：O(N^2)
 *
 * @param arr pointer to arr
 * @param len arr's length
 *
 * @return Void.
 */
void selectionSort(int arr[], int len);

/** @brief The maximum value per round is placed last
 *         time complexity: best：O(N), worst：O(N^2)
 *
 * @param arr pointer to arr
 * @param len arr's length
 *
 * @return Void.
 */
void bubbleSort(int arr[], int len);

/** @brief Divide the current array into two halves, and then sort and merge them by value
 *
 * @param arr pointer to arr
 * @param left the begin index of current arr
 * @param middle the middle index of current arr
 * @param left the left index of current arr
 *
 * @return Void.
 */
void merge(int arr[], int left, int middle, int right);

/** @brief merge sort array recursively
 *         time complexity: best：O(N^log(n)), worst：O(N^log(n))
 *
 * @param arr pointer to arr
 * @param left the begin index of current arr
 * @param left the left index of current arr
 *
 * @return Void.
 */
void mergeSort(int arr[], int left, int right);

/** @brief Put the rightmost value into the correct position
 *         (The left side of the value is smaller than him, and the right side of the value is larger than him)
 *         time complexity: best：O(N^log(n)), worst：O(N^log(n))
 *
 * @param arr pointer to arr
 * @param left the begin index of current arr
 * @param left the left index of current arr
 *
 * @return Void.
 */
int partition(int arr[], int left, int right);

/** @brief quick sort array recursively
 *         time complexity: best：O(N^log(n)), worst：O(N^2)
 *
 * @param arr pointer to arr
 * @param left the begin index of current arr
 * @param left the left index of current arr
 *
 * @return Void.
 */
void quickSort(int arr[], int left, int right);

/** @brief Print the array
 *
 * @param arr pointer to arr
 * @param len arr's length
 *
 * @return Void.
 */
void printArr(int arr[], int len);

#endif