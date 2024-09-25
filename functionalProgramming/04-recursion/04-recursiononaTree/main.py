def list_files(current_filetree, current_path=""):
    file_list = []  # This will hold the paths to the files
    
    for node, subtree in current_filetree.items():
        # Construct the current full path for this node
        full_path = f"{current_path}/{node}"
        
        if subtree is None:  # If it's a file (subtree is None)
            file_list.append(full_path)
        else:  # If it's a directory (subtree is a dictionary)
            # Recursively call list_files on the subtree and extend the results to file_list
            file_list.extend(list_files(subtree, full_path))
    
    return file_list
