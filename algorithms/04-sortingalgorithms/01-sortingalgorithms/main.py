class Influencer:
    def __init__(self, num_selfies, num_bio_links):
        self.num_selfies = num_selfies
        self.num_bio_links = num_bio_links

    def __repr__(self):
        return f"({self.num_selfies}, {self.num_bio_links})"

# dont touch above this line

def vanity(influencer):
    return influencer.num_selfies + (influencer.num_bio_links * 5)

def vanity_sort(influencers):
    return sorted(influencers, key=vanity)



# def vanity(influencer):
#     vanity_score = influencer.num_selfies + (influencer.num_bio_links * 5)
#     return vanity_score
#
# def vanity_sort(influencers):
#     list_influencers = []
#     for influencer in influencers:
#         list_influencers.append(influencer)
#     sorted_list = sorted(list_influencers, key=lambda influencer: vanity(influencer) )
#     return sorted_list
