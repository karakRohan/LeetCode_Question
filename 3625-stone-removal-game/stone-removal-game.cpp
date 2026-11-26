
class Solution {
public:
    bool canAliceWin(int n) {
        int move=10,turn=0;
        while (n>=move){
            n=n-move;
            move=move -1;
            turn++;
        }

        return turn%2;
    }
};
