num_elements = int(input())
quadradonia_list = list(map(int, input().split()))
noglonia_list = list(map(int, input().split()))

quadradonia_list.sort()
noglonia_list.sort()

winner_count = 0
j = 0

for i in range(num_elements):
    while j < num_elements and quadradonia_list[i] >= noglonia_list[j]:
        j += 1
    if j < num_elements and quadradonia_list[i] < noglonia_list[j]:
        winner_count += 1
        j += 1

print(winner_count)
