def does_name_exist(first_names, last_names, full_name):
    for name in first_names:
        for last_name in last_names:
            if f"{name} {last_name}" in full_name:
                return True
    return False
