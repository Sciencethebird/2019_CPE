nums = [0, 2, 3]+[None]*10010
for i in range(3, 10010):
    nums[i] = nums[i-1]+nums[i-2]
#print(nums)


case = input()
case = int(case)

for i in range(case):
    n = input()
    print(nums[int(n)]%1000000007)