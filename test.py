                                                                                                                                                                            
# intialising global variables
universe = "agct"
sequences = []
set_of_sets = []

# method to find common of two sequencests
def common(temp_neighbors, l2): 
    return [x for x in temp_neighbors if x in l2] 
    
# method to return neighbors of a string 
def generate_neighbors(str, n):
    assert(n <= len(str))

    if n == 0:
        return [str]

    sub_nbs = generate_neighbors(str[1:], n-1)
    seq= [x + r for r in sub_nbs for x in universe if x != str[0]]

    if (n < len(str)):
        sub_nbs = generate_neighbors(str[1:], n)
        seq += [str[0] + r for r in sub_nbs]

    return seq
    
# taking input
N = int(input(" Enter N : "))
L = int(input(" Enter L : "))
D = int(input(" Enter D : "))
# # UNCOMMNET THIS LINE IF YOU WANT TO GENERATE RANDOM SEUQNECES
# # M = int(input(" Enter M : "))

while (N):
    seqq = input(" Enter sequence : ") 
    seqq = seqq.lower()
    sequences.append(seqq)
    N = N - 1

# # THE FOLLOWING LOOP IS EXECUTED WHEN WE WANT TO GENERATE OUTPUT AS MAAM WANTS 
# # while (N):
# #     seqq =  ''.join((random.choice('agct') for i in range(M)))
# #     seqq = seqq.lower()
# #     sequences.append(seqq)
# #     N = N - 1

# initializing L 
for item in sequences:

    sub_strings = [item[i: j] for i in range(len(item)) for j in range(i + 1, len(item) + 1) if len(item[i:j]) == L]

    sequence_neighbors_set = []

    # getting the neighbors of each substring and appending it to a set which has a unique neighbors of all substrings
    for pattern in sub_strings:
        temp_neighbors = generate_neighbors(pattern,D)
        temp_neighbors.append(pattern)
        temp_neighbors = set(temp_neighbors)
        sequence_neighbors_set.append(temp_neighbors)

    # Removing the duplicates....
    duplicate = set()
    for index in sequence_neighbors_set:
        for pattern in index:
            duplicate.add(pattern)
    duplicate = list(duplicate)
    set_of_sets.append(duplicate)

motifs = set_of_sets[0]

for i in range(len(set_of_sets)):
    motifs = common(motifs,set_of_sets[i])
    

print("\n Number of Motifs :  " + str(len(motifs)))
print("\n Motifs:  " + str(motifs))