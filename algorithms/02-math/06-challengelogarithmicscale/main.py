import math


def log_scale(data, base):
    log_scale = []
    for i in data:
        log_scale.append(math.log(i, base))
    return log_scale
        
