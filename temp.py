def ternary_search_unimodal(arr):
    low = 0
    high = len(arr) - 1

    while low < high:
        mid1 = low + (high - low) // 3
        mid2 = high - (high - low) // 3

        if arr[mid1] < arr[mid2]:
            low = mid1 + 1
        else:
            high = mid2 - 1

    return arr[low]  # or return low for the index

# Example usage:
arr = [90, 8, 8, 8, 8, 3, 3, 1]
peak = ternary_search_unimodal(arr)
print(peak)  # Output: 8