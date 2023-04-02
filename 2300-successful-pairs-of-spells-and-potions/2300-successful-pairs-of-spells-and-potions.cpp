class Solution {
public:
    //T: O(m log m + n log n), S:O(n + log m)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {   
        unordered_map<int, pair<int,int>> m; //{index,numpair}
        //Now creating a copy of spells vector
        vector<int> numspair(spells);
        //Now storing the spells and mapping its index onto the map
        for(int i=0;i<spells.size();i++){ // O(m)
            m[spells[i]]={i,-1};
        }
        //Now sorting both the vectors
        //Considering the length m of spells
        sort(spells.begin(),spells.end()); // O(m log m)
        //Considering the length n of potions
        sort(potions.begin(),potions.end());// O(n log n)
        
        int potionptr=potions.size()-1;
        
        // Two Pointer Approach
        //Starting spell pointer from left
        // And potion pointer from right
        for(int i=0;i<spells.size();i++){  //O(m)
            int spell=spells[i];
            while(potionptr>=0 && (long long) spell*potions[potionptr]>=success){
                potionptr--;
            }
            m[spell]={m[spell].first,potions.size()-1-potionptr};
           /*cout<<"Value:"<<spell<<"-->"<<"Index:"<<m[spell].first<<"-->"<<"count:"<<m[spell].second<<endl;------>this shows how count is being stored for every index and the index's value*/
        }
        int index=0;
        for(int spell: numspair){ // O(m)
            numspair[index++]=m[spell].second;
        }
        return numspair;
    }
};