// negative food rating daldo map mein 
class FoodRatings {
public:
    unordered_map<string,string>fc;
    unordered_map<string,set<pair<int,string>>>crf;
    unordered_map<string,int>fr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings){
    int n=foods.size();
    for(int i=0;i<n;i++)
    {
        string f=foods[i];
        string c=cuisines[i];
        int r= ratings[i];
        crf[c].insert({-r,f});
        fc[f]=c;
        fr[f]=r;
    }
    }
    
    void changeRating(string food, int newRating) {
    string f=food;
    string c=fc[f];
    int old=fr[f];
    fr[f]=newRating;
    crf[c].erase({-old,f});
    crf[c].insert({-newRating,f}); 
    }
    
    string highestRated(string cuisine) {
    return begin(crf[cuisine])->second; 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */