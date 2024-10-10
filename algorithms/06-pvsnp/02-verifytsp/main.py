def verify_tsp(paths, dist, actual_path):
    total_distance = 0
    
    for i in range(len(actual_path) - 1):
        city_a = actual_path[i]
        city_b = actual_path[i + 1]
        
        total_distance += paths[city_a][city_b]
    
    if total_distance < dist:
        return True
    else:
        return False
