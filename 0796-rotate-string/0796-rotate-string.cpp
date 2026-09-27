
class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        return (s + s).find(goal) != std::string::npos;
    }
};