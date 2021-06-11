t = int(input())
for _ in range(t) :
    n, m = list(map(int, input().strip().split()))
    modulo = 10 ** 9 + 7
    print(
        pow(
            pow(2, n, modulo) - 1,
            m,
            modulo
        )
    )