from queue import Queue


def matchmake(queue, user):
    if user[1] == 'join':
        queue.push(user[0])
    elif user[1] == 'leave':
        queue.search_and_remove(user[0])
    if queue.size() >= 4:
        return f"{queue.pop()} matched {queue.pop()}!"
    return "No match found"
