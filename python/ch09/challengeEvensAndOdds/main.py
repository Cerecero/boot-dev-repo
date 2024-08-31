def get_odds_and_evens(numbers):
    num_odds = 0
    num_evens = 0

    # Don't touch above this line

    for number in numbers:
        if number % 2 == 0:
            num_evens += 1
        elif number % 2 == 1:
            num_odds += 1
    return num_odds, num_evens

# run_cases = [
#     [1, 7, 2, 5, 3, 4],


# get_odds_and_evens(run_cases)
