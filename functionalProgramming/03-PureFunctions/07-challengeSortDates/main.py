def sort_dates(dates):
    def sorting(date):
        splitup = date.split("-")
        return splitup[2], splitup[0], splitup[1]
    return sorted(dates, key=sorting)
