n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
# Write Your Code Here
count = 0
for i in range(n):
    for j in range(i, n):
        if i != j:
            if a[i] > a[j]:
                temp = a[i]
                a[i] = a[j]
                a[j] = temp
                count += 1

print(f"Array is sorted in {count} steps.")
print(f"First Element: {a[0]}")
print(f"Last Element: {a[-1]}")
