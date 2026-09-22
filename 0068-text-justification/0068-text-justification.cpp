class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            while (j < n) {
                int len = letters + words[j].size() + (j - i);

                if (len > maxWidth)
                    break;

                letters += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int spaces = maxWidth - letters;
            string line;

            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1)
                        line += " ";
                }

                line += string(maxWidth - line.size(), ' ');
            } else {
                int gaps = wordCount - 1;
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1) {
                        int count = spacesPerGap;

                        if (extraSpaces > 0) {
                            count++;
                            extraSpaces--;
                        }

                        line += string(count, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};