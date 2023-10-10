import numpy as np

def slices(n_elements, start_index, slice_elements):
    """
    Slice indices of a sequence of n_elements
        * into slices of slice_elements indices,
            * (except the last one which may have less)
        * starting from index start_index

    Arguments:
    n_elements:  positive integer
    start_index: start index of the first slice
    slice_elements: number of indices in each slice,
                    except the last once which may have less

    Returns:
    The return type is left to the implementation.
    """
    # Generate evenly spaced array [start_index,n_elements)
    slices_array = np.arange(start=start_index, stop=n_elements)
    # Create list with subarrays
    sub_slices = [slices_array[i:i + slice_elements] for i in range(0, len(slices_array), slice_elements)]
    return sub_slices


print("Example 1:")
for slice_count, slice in enumerate(slices(n_elements=6, start_index=0, slice_elements=3)):
    print(f"Indices of Slice {slice_count}: ", end="")
    for index in slice:
        print(index, end=" ")
    print()

print("Example 2:")
for slice_count, slice in enumerate(slices(n_elements=6, start_index=1, slice_elements=3)):
    print(f"Indices of Slice {slice_count}: ", end="")
    for index in slice:
        print(index, end=" ")
    print()

print("Example 3:")
for slice_count, slice in enumerate(slices(n_elements=10, start_index=1, slice_elements=4)):
    print(f"Indices of Slice {slice_count}: ", end="")
    for index in slice:
        print(index, end=" ")
    print()
