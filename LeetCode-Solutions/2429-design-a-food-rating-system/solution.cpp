#define ist pair<int,string>
#define fi first
#define se second
class FoodRatings {
public:
    map<string,set<ist>> mp;
    map<string,int> mark;
    map<string,string> markCountry;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for ( int i = 0 ; i < n ; ++i ) {
            markCountry[foods[i]] = cuisines[i];
            mark[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string country = markCountry[food];
        mp[country].erase({-mark[food],food});
        mark[food] = newRating;
        mp[country].insert({-newRating,food});

        
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin() -> se;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
