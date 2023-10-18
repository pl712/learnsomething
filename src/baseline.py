def max_area(height):
    # max_area = 0
    # n = len(height)

    # for i in range(n):
    #     for j in range(i + 1, n):
    #         h1 = height[i]
    #         h2 = height[j]
    #         width = j - i
    #         current_area = min(h1, h2) * width
    #         max_area = max(max_area, current_area)

    # return max_area

    res = 0
    l, r = 0, len(height) - 1

    while l < r:
        res = max(res, min(height[l], height[r]) * (r - l))

        if height[l] < height[r]:
            l += 1
        else:
            r -= 1
    
    return res

    #this is LC 11, no?