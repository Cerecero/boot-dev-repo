def check_mount_rental(time_used, time_purchased):
    if time_used >= time_purchased:
        print("before comp")
        return "overtime charged"
    print("after comparassion")
    return "no charges yet"
