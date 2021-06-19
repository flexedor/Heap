#include <stdio.h>
#include <stdlib.h>

const int total_size = 1000;

struct Heap
{
    int* array;
    int total_size;
    int size_used;
    bool rising;
};
void swap_place(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
void heapify(Heap* heap, int root)
{
    int largest = root;
    int left_child = (2 * largest) + 1;
    int right_child = (2 * largest) + 2;

    if (heap->rising)
    {
        if (left_child < heap->size_used && heap->array[left_child] > heap->array[largest])
        {
            largest = left_child;
        }
        if (right_child < heap->size_used && heap->array[right_child] > heap->array[largest])
        {
            largest = right_child;
        }
    }
    else
    {
        if (left_child < heap->size_used && heap->array[left_child] < heap->array[largest])
        {
            largest = left_child;
        }
        if (right_child < heap->size_used && heap->array[right_child] < heap->array[largest])
        {
            largest = right_child;
        }
    }

    if (largest != root)
    {
        swap_place(&(heap->array[root]), &(heap->array[largest]));
        heapify(heap, largest);
    }
}

void push(Heap* heap)
{
    int child_num = 0;
    scanf_s("%d", &child_num);
    heap->array[heap->size_used] = child_num;
    int i = heap->size_used;
    heap->size_used++;
    int father = (i - 1) / 2;

    while (father >= 0)
    {
        if (heap->rising == true) //max to min heap
        {
            if (heap != NULL && heap->array[i] > heap->array[father])
            {
                swap_place(&(heap->array[i]), &(heap->array[father]));
                i = father;
                father = (i - 1) / 2;
            }
            else
            {
                break;
            }
        }
        else //min to max heap
        {
            if (heap != NULL && heap->array[i] < heap->array[father])
            {
                swap_place(&(heap->array[i]), &(heap->array[father]));
                i = father;
                father = (i - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
}
void pop(Heap* heap)
{
    int low_max = 0;
    if (heap->size_used > 0) // tylko gdy bedzie wiecej niz 0 miejsc uzytych
    {
        low_max = heap->array[0];
        swap_place(&(heap->array[0]), &(heap->array[heap->size_used - 1]));
        heap->size_used--;
        if (heap->size_used != 0)
        {
            heapify(heap, 0);
        }
        printf("%d", low_max);
    }
    printf(" \n");
}

void build(Heap* heap)
{
    for (int i = (heap->size_used / 2) - 1; i >= 0; i--)
    {
        heapify(heap, i);
    }
}

void print_heap(Heap* heap)
{
    for (int i = 0; i < heap->size_used; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main()
{
    Heap* heap = NULL;
    heap =new Heap;

    
    //init
  
    heap->array = new int[total_size];
    heap->total_size = total_size;
    heap->rising = true;
    heap->size_used = 0;
    //

    char option = 'x';
    bool stop = false;
    while (!stop)
    {
        option = getchar();
        if (option == '+')
        {
           
            push(heap);
        }
        else if (option == '-')
        {
            pop(heap);
        }
        else if (option == 'p')
        {
            print_heap(heap);
        }
        else if (option == 'r')
        {
            int size = 0;
            scanf_s("%d", &size);
            heap->size_used = 0;
            for (int i = 0; i < size; i++)
            {
                int number;
                scanf_s("%d", &number);
                heap->array[i] = number;
                heap->size_used++;
            }
            build(heap);
        }
        else if (option == 's')
        {
            heap->rising = !heap->rising;
            build(heap);
        }
        else if (option == 'q')
        {
            stop = true;
        }
    }
    delete heap;
    return 0;
}