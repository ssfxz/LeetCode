class Solution {
public:
    bool isNumber(string s) {
        bool ret = false;
        int i = 0;

        // space
        while(s[i] == 32)
        {
            ++i;
        }

        // - or +
        if(s[i] == 45 || s[i] == 43)
        {
            ++i;
        }

        int len = s.size();

        bool hasDot = false;
        bool hasE = false;
        bool hasPart1 = false;
        bool hasPart2 = false;

        for(; i < len; ++i)
        {
            // .
            if(s[i] == 46 )  
            {
                if(hasDot || hasE || (i == 0 && i == len - 1))
                {   
                    return false;
                }
                else
                {
                    hasDot = true;
                }

            }
            // e
            else if(s[i] == 101)
            {
                if(hasE || !hasPart1)
                {   
                    return false;
                }
                else
                {
                    hasE = true;

                }
            }
            // number
            else if(s[i] >= 48 && s[i] <= 57)
            {
                if (!hasE)
                {
                    hasPart1 = true;
                }
                else
                {
                    hasPart2 = true;
                }
            }
            // - or +
            else if(s[i] == 45 || s[i] == 43)
            {
                if (!hasE || !(s[i-1] == 101))
                    return false;
            }
            // space
            else if(s[i] == 32)
            {
                while(s[i] == 32)
                {
                    ++i;
                }
                break;
            }
            else
            {
                return false;
            }
        }

        if (!hasPart1)
        {
            return false;
        }
        else if (hasE && !hasPart2)
        {
            return false;
        }
        else if (i != len)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};