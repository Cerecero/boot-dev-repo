from functools import reduce


def create_tagger(tag):
    def tagger(content):
        return f"<{tag}>{content}</{tag}>"

    return tagger


def create_accumulator(tagger):
    def accumulate(items):
        return reduce(lambda acc, item: acc + tagger(item), items, "")

    return accumulate


tag_data = create_tagger("td")
tag_header = create_tagger("th")
tag_row = create_tagger("tr")
tag_table = create_tagger("table")

accumulate_data_cells = create_accumulator(tag_data)
accumulate_rows = create_accumulator(tag_row)
accumulate_headers = create_accumulator(tag_header)


# don't touch above this line


def create_html_table(data_rows):
    string_rows = accumulate_rows(map(lambda row: accumulate_data_cells(row), data_rows[:]))
    # string_rows = accumulate_rows(list(map(tag_data, data_rows)))
    # print(f"this is map:  {list(map(tag_data, data_rows))}")
    # print(f"this is string_rows {string_rows}")
    # print(f'this is accumulate rows: {accumulate_rows("test")}')
    def create_table_headers(headers):
        nonlocal string_rows
        # print(f"this is string_rows: {string_rows}")
        all_headers= accumulate_headers(headers)
        all_headers = tag_row(all_headers)
        rows = all_headers + string_rows
        # print(f"this is headers: {all_headers}")
        # return accumulate_headers(all_headers)
        return tag_table(rows)


    return create_table_headers
