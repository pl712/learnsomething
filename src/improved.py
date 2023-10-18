def max_area(height):
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
