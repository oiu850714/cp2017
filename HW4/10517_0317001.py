def combine_cal_inversion(left_arr: list, right_arr: list):
    global inversion_pairs



def merge_sort_inversion(arr: list):
    if len(arr) <= 1:
        return
    left_arr = arr[:len(arr)//2]
    right_arr = arr[len(arr)//2:]
    merge_sort_inversion(left_arr)
    merge_sort_inversion(right_arr)

    #print("left: ", left_arr, "right: ", right_arr)

    global inversion_pairs

    left_ptr = 0
    right_ptr = 0

    for i in range(len(arr)):
        if right_ptr == len(right_arr):
            #inversion_pairs += (len(left_arr) - left_ptr)
            #not need!
            arr[i] = left_arr[left_ptr]
            left_ptr += 1
        elif left_ptr == len(left_arr):
            arr[i] = right_arr[right_ptr]
            right_ptr += 1
        elif(right_arr[right_ptr] < left_arr[left_ptr]):
            inversion_pairs += (len(left_arr) - left_ptr)
            arr[i] = right_arr[right_ptr]
            right_ptr += 1
        else:
            arr[i] = left_arr[left_ptr]
            left_ptr += 1






    pass



case = int(input())

while case:
    n = int(input())
    arr = [int(i) for i in input().split()]

    inversion_pairs = 0

    merge_sort_inversion(arr)

    print(inversion_pairs)
    case -= 1
