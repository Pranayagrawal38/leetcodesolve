class FoodRatings {
public:
 unordered_map<string,int>ratingmp;
 unordered_map<string,string>cmp;
 unordered_map<string,set<pair<int,string>>>mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            ratingmp[foods[i]]=ratings[i];
            cmp[foods[i]]=cuisines[i];
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it=cmp[food];
        auto it2=mp[it].find({-ratingmp[food],food});
        mp[it].erase(it2);
        ratingmp[food]=newRating;
        mp[it].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it=mp[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */