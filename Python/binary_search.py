def bin_search(arr, x, beg, last):   #O(Log(n))
						#recursive soln where u just change mid, checking after each element in a sorted array that if the current range is less or greater than the required
	if last>=beg:          #if greater then just make the last index as an index less than mid
		mid = beg + (last - beg)//2        #else just make beg index as an index more than mid
		if arr[mid]==x:
			return mid
		elif arr[mid]>x:
			return bin_search(arr, x, beg, mid-1)
		else:
			return bin_search(arr, x, mid+1, last)
	else:
		return -1

array = list(map(int, input().split()))
num = int(input("Number you want to look for in the array: "))
print(bin_search(array, num, 0, len(array)-1))
