#include <iostream>
using namespace std;

// ---------- Linked List Node ----------
struct Node {
    int data;
    Node* next;
};

// ---------- Insert Node at End ----------
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// ---------- Display Linked List ----------
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// ---------- Convert Linked List to Array ----------
int listToArray(Node* head, int arr[]) {
    int i = 0;
    while (head != NULL) {
        arr[i++] = head->data;
        head = head->next;
    }
    return i;
}

// ---------- Quick Sort ----------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// ---------- Merge Sort ----------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ---------- Binary Search ----------
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ---------- Main Function ----------
int main() {
    Node* head = NULL;
    int arr[50];
    int choice, value, key, size;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert into Linked List\n";
        cout << "2. Display Linked List\n";
        cout << "3. Quick Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Binary Search\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insert(head, value);
            break;

        case 2:
            display(head);
            break;

        case 3:
            size = listToArray(head, arr);
            quickSort(arr, 0, size - 1);
            cout << "After Quick Sort:\n";
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;

        case 4:
            size = listToArray(head, arr);
            mergeSort(arr, 0, size - 1);
            cout << "After Merge Sort:\n";
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;

        case 5:
            size = listToArray(head, arr);
            quickSort(arr, 0, size - 1); // Ensure sorted
            cout << "Enter element to search: ";
            cin >> key;

            int result;
            result = binarySearch(arr, size, key);

            if (result != -1)
                cout << "Element found at index: " << result << endl;
            else
                cout << "Element not found\n";
            break;

        case 6:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

