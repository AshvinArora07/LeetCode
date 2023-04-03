class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //It can be done with TWO  POINTER
        //sorting the people vector
        //if the lightest and the heaviest person can go on the same boat i,e.people[i]+people[j]
        //people[i]+people[j]<=limit incrementing the count of boat.
        
        /*IMPLEMENTATION*/
        int i=0,j=people.size()-1,count=0;
        sort(people.begin(),people.end());
        while(i<=j){
            if(people[i]+people[j]<=limit)
                i++;
            count++;
            j--;// Once we know the lighest and heaviest can travel on one boat we have to decrement the right pointer(j) if people[i]+people[j]>limnit.
        }
        return count;
    }
};