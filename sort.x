struct Array{
	char val[40];
};

typedef struct Array Array;

program SORT_PROG{
    version Bubble_Sort_algo{
        Array Bsort(Array) = 1;
    } = 1;
    version Merge_Sort_algo{
        Array Msort(Array) = 1;
    } = 2;
} = 0x31415926;