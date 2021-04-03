def get_dist(x, y) :
    
    price = [[0.0 for _ in  range(len(y) + 1)] for __ in range(len(x) + 1)]
    order = [["" for _ in  range(len(y) + 1)] for __ in range(len(x) + 1)]

    for i in range(len(y) + 1) :
        order[0][i] = "Insert"
        price[0][i] = i * 1

    for i in range((len(x)) + 1) :
        price[i][0] = i * 1
        order[i][0] = "Delete"

    for i in range(1, len(x) + 1) : 
        for j in range(1, len(y) + 1) :
            
            if x[i - 1] == y[j - 1] :
                price[i][j] = price[i - 1][j - 1] + 0
                order[i][j] = "Copy"
            
            else :
                price_replace = price[i - 1][j - 1] + 2

                delete_cost = price[i - 1][j] + 1

                Insert_cost = price[i][j - 1] + 1

                if price_replace > Insert_cost :
                    order[i][j] = "Insert"
                    price[i][j] = Insert_cost

                else :
                    order[i][j] = "Replace"
                    price[i][j] = price_replace

                if price[i][j] > delete_cost :
                    order[i][j] = "Delete"
                    price[i][j] = delete_cost
            
            if i > 1 and j > 1 and x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1] and price[i - 2][j - 2] + 1.5 < price[i][j] :
                price[i][j] = price[i - 2][j - 2] + 1.5
                order[i][j] = "Twiddle"


    for i in range (len(x)) :

        if price[i][len(y)] + 5 < price[len(x)][len(y)] :
            price[len(x)][len(y)] = price[i][len(y)] + 5
            order[len(x)][len(y)] = "Kill " + str(i + 1)

    return price[len(x)][len(y)], order

def show_seq(order, xSize, ySize) :
    if not xSize and not ySize :
        return

    x = 0
    y = 0

    if order[xSize][ySize] == "Copy" or order[xSize][ySize] == "Replace" :
        x = xSize - 1
        y = ySize - 1

    elif order[xSize][ySize] == "Twiddle" :
        x = xSize - 2
        y = ySize - 2

    elif order[xSize][ySize] == "Delete" :
        x = xSize - 1
        y = ySize

    else :
        x = xSize
        y = ySize - 1

    show_seq(order, x, y)

    print(order[xSize][ySize])



x = input("Enter x : ").strip()
y = input("Enter y : ").strip()


cost, order = get_dist(x, y)

show_seq(order, len(x), len(y))

print("Optimal Total Cost", cost)
