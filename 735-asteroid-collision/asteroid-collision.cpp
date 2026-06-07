class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool collide=true;
        while(collide){
            collide=false;
            for(int i=0;i<(int)asteroids.size()-1;i++){
                if(asteroids[i]>0 && asteroids[i+1]<0){
                    collide=true;
                    int l=asteroids[i];
                    int r=asteroids[i+1];
                    if(abs(l)==abs(r))
                       asteroids.erase(asteroids.begin()+i,asteroids.begin()+i+2);
                    else if(abs(l)>abs(r))
                       asteroids.erase(asteroids.begin()+i+1);
                    else
                       asteroids.erase(asteroids.begin()+i);
                    break;
                }
            }
        }
        return asteroids;
    }
};